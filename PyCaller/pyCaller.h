#include "Python.h"
#include "frameobject.h"
#include "traceback.h"
#include <string>
#include <list>
#include <atomic>
#include <iostream>
#include <type_traits>

#ifdef CALLPYTHON_EXPORTS
#define CALLPYTHON_API __declspec(dllexport)
#else
#define CALLPYTHON_API __declspec(dllimport)
#endif
#ifdef _DEBUG
#define DEBUGINFO(param)  std::cout<<  param <<std::endl
#else
#define DEBUGINFO(param)  
#endif // _DEBUG
//extern std::atomic<int> PyReosureCounter;
//template  < typename _T> ;

class CALLPYTHON_API PyCaller 
{
public:
	using PYPARAMPAIR	= std::pair<std::string, std::string > ;
	using PYPARAMLIST	= std::list<PYPARAMPAIR> ;
	using PyResult		= PyObject*	;
public:
	PyCaller();
	PyCaller(const std::string& PythonPath);
	PyCaller(const PyCaller&) = delete;
	~PyCaller();
	static std::atomic<int> PyReosureCounter;
	int  runPyFile(const std::string &pyfilename);
	void setPyPath(const std::string &Pypath="./");
	std::list<std::string> GetPyFileDict(std::string &modulename);
	template<typename T, typename ...argtype>
	bool runPyFunction(T&& firstParam, argtype&& ...pyArg);
private:
	template<typename T>
	bool runPyFunction(T&& firstParam);
	template <typename Tvalue>
	PyObject* buildPyVaule(Tvalue&& buildValue);
	template <>
	PyObject* buildPyVaule(std::string&& buildValue);
	template <>
	PyObject* buildPyVaule(const char*&& buildValue);
	int importModule(const std::string& modulename);
	template<typename T>
	bool pyResultCast(T&& vaule, PyResult resultToParse);
	template<>
	bool pyResultCast(std::string&& vaule, PyResult resultToParse);
	bool pyResultCast(const char* vaule, PyResult resultToParse);
	void emptyCallStoreVar();
private:
	std::string		m_pyModuleName{};
	std::string		m_functionName{};
	PyObject		*m_callArgs{ nullptr };
	unsigned int	m_parameterCounter{ 0 };
};
template<>
bool PyCaller::pyResultCast(std::string&& vaule, PyResult resultToParse)
{
	if (!resultToParse)
	{
		return false;
	}
	char *res = { nullptr };
	int parseRes = 0;
	parseRes = PyArg_Parse(resultToParse, "s", &res);
	if (res)
	{
		vaule = std::string(res);
		return true;
	}
	return false;
}

template<typename T>
bool PyCaller::pyResultCast(T&& vaule, PyResult resultToParse)
{
	if (!resultToParse)
	{
		return false;
	}
	char *res = { nullptr };
	int parseRes = 0;
	if (typeid(T) == typeid(int) || typeid(T) == typeid(long  long) || typeid(T) == typeid(long))
	{
		PyLong_Check(resultToParse);
		vaule = std::move(PyLong_AsLongLong(resultToParse));
		return true;
	}
	else if (typeid(T) == typeid(double) || typeid(T) == typeid(float) || typeid(T)==typeid(long double))
	{
		PyFloat_Check(resultToParse);
		vaule = std::move(PyFloat_AsDouble(resultToParse));
		return true;
	}
	else if (typeid(T) == typeid(unsigned int) || typeid(T) == typeid(unsigned long long))
	{
		vaule = std::move(PyLong_AsUnsignedLongLong(resultToParse)); //PyArg_Parse(resultToParse, "K", &res);
		return true;
	}
	return false;

}

inline bool PyCaller::pyResultCast(const char* vaule, PyResult resultToParse)
{
	vaule = nullptr;
	return false;
}

template<typename T>
inline bool PyCaller::runPyFunction(T&& firstParam)
{

	try
	{
		PyObject* pModule = nullptr;
		pModule = PyImport_ImportModule(m_pyModuleName.c_str());
		if (pModule == nullptr)
		{
			DEBUGINFO("import python module:" + m_pyModuleName + " failed.");
			emptyCallStoreVar();
			return  false;
		}
		PyObject* pFunc = PyObject_GetAttrString(pModule, m_functionName.c_str());
		if (pFunc == nullptr)
		{
			DEBUGINFO("import python module:" + m_functionName + " failed.");
			emptyCallStoreVar();
			return false;
		}
		if (!PyCallable_Check(pFunc))
		{
			return false;
		}
		PyObject *callResult = PyObject_CallObject(pFunc, m_callArgs);
		if (!callResult)
		{
			PyObject *perror = nullptr;
			perror = PyErr_Occurred();
			PyObject *type, *value, *traceback;
			type = nullptr;
			value = nullptr;
			traceback = nullptr;
			if (perror)
			{
				std::string tracebackfull = "fail:";
				//goto fetcherror;
#pragma region GetThreadState
				PyThreadState *tstate = PyThreadState_GET();
				if (NULL != tstate)
				{
					PyTracebackObject* tracebackObject = (PyTracebackObject*)tstate->curexc_traceback;
					if (nullptr == tracebackObject)
					{
						//Py_CLEAR(tstate);
						goto fetcherror;
					}
					PyFrameObject *frame = tracebackObject->tb_frame;
					while (NULL != frame) {
						/*
							frame->f_lineno will not always return the correct line number
							you need to call PyCode_Addr2Line().
						*/
						int line = PyCode_Addr2Line(tracebackObject->tb_frame->f_code, tracebackObject->tb_frame->f_lasti);
						std::string str_filename = PyUnicode_AsUTF8(tracebackObject->tb_frame->f_code->co_filename);
						std::string funcname = PyUnicode_AsUTF8(tracebackObject->tb_frame->f_code->co_name);
						tracebackfull += "fetch Error in  File: " + str_filename + "\r\nfunction: " + funcname +
							"\r\nLine: " + std::to_string(line) + "\r\n";
						frame = frame->f_back;
					}
					Py_CLEAR(frame);
					Py_CLEAR(tracebackObject);
					//Py_CLEAR(tstate);

				}
#pragma endregion GetThreadState
				fetcherror :
						   PyErr_Fetch(&type, &value, &traceback);
						   if (type || value || traceback)
						   {
							   std::string errorinfo_1, errorinfo_2, errorinfo_3;
							   if (type && (std::string(type->ob_type->tp_name) == std::string("str")))
							   {
								   errorinfo_1 = PyUnicode_AsUTF8(type);
							   }
							   if (value && (std::string(value->ob_type->tp_name) == std::string("str")))
							   {
								   errorinfo_1 = PyUnicode_AsUTF8(value);
							   }
							   if (traceback && (std::string(traceback->ob_type->tp_name) == std::string("str")))
							   {
								   errorinfo_2 = PyUnicode_AsUTF8(traceback);
							   }
							   tracebackfull += " error cause:" + errorinfo_1 + errorinfo_2 + errorinfo_3 + "\r\n";
							   std::cerr << tracebackfull;
							   Py_CLEAR(type);
							   Py_CLEAR(value);
							   Py_CLEAR(traceback);
							   Py_CLEAR(pFunc);
							   Py_CLEAR(pModule);
						   }
						   return  false;
#ifdef _DEBUG
						   PyErr_Print();
#endif // DEBUG
			}
		}
		Py_CLEAR(pFunc);
		Py_CLEAR(pModule);
		pyResultCast(firstParam, callResult);
		emptyCallStoreVar();
		return true;
	}
	catch (const std::exception&)
	{
		emptyCallStoreVar();
		return false;
	}
	return false;
}

//template<typename T>
//bool PyCaller::runPyFunction(const std::string &moduleName, const std::string &functionName, const PYPARAMLIST& callParamter, T& resultrSave)
//{
//	PyObject* pModule = nullptr;
//	pModule = PyImport_ImportModule(moduleName.c_str());
//	if (pModule == nullptr)
//	{
//		DEBUGINFO("import python module:"+ moduleName +" failed.");
//		return  false;
//
//	}
//	PyObject* pFunc = PyObject_GetAttrString(pModule, functionName.c_str());
//	if (pFunc == nullptr)
//	{
//
//		DEBUGINFO("import python func:" + functionName + " failed" );
//		return false;
//	}
//	try
//	{
//		unsigned int paramNum = callParamter.size();
//		PyObject *pArgs = PyTuple_New(paramNum);
//		size_t paramnumconunter = 0;
//		for (auto &paramPair : callParamter)
//		{
//
//			if (paramPair.first == "i")
//			{
//				int paramtransfer = std::stoi(paramPair.second);
//				PyTuple_SetItem(pArgs, paramnumconunter, Py_BuildValue(paramPair.first.c_str(), paramtransfer));//0—sequence num  i-  type int
//			}
//			else if (paramPair.first == "I" || paramPair.first == "k")
//			{
//				size_t paramtransfer = std::stoul(paramPair.second);
//				PyTuple_SetItem(pArgs, paramnumconunter, Py_BuildValue(paramPair.first.c_str(), paramtransfer));//0—sequence num  i-  type int
//			}
//			else if (paramPair.first == "l" || paramPair.first == "L")
//			{
//				long long paramtransfer = std::stoll(paramPair.second);
//				PyTuple_SetItem(pArgs, paramnumconunter, Py_BuildValue(paramPair.first.c_str(), paramtransfer));//0—sequence num  i-  type int
//			}
//			else if (paramPair.first == "s")
//			{
//				PyTuple_SetItem(pArgs, paramnumconunter, Py_BuildValue(paramPair.first.c_str(), paramPair.second.c_str()));//0—sequence num  i-  type int
//			}
//			else if (paramPair.first == "d")
//			{
//				long double  paramtransfer = std::stold(paramPair.second);
//				PyTuple_SetItem(pArgs, paramnumconunter, Py_BuildValue(paramPair.first.c_str(), paramtransfer));
//			}
//			paramnumconunter++;
//		}
//		if (!PyCallable_Check(pFunc))
//		{
//			return false;
//		}
//		PyObject *callResult = PyObject_CallObject(pFunc, pArgs);
//		if (!callResult)
//		{
//			PyObject *perror = nullptr;
//			perror = PyErr_Occurred();
//			PyObject *type, *value, *tracebackObject;
//			type = nullptr;
//			value = nullptr;
//			tracebackObject = nullptr;
//			if (perror)
//			{
//				std::string tracebackfull = "fail:";
//#pragma region GetThreadState
//				PyThreadState *tstate = PyThreadState_GET();
//				if (NULL != tstate)
//				{
//					PyTracebackObject* tracebackObject = (PyTracebackObject*)tstate->curexc_traceback;
//					if (nullptr == tracebackObject)
//					{
//						goto fetcherror;
//					}
//					PyFrameObject *frame = tracebackObject->tb_frame;
//					while (NULL != frame) {
//						/*
//						frame->f_lineno will not always return the correct line number
//						you need to call PyCode_Addr2Line().
//						*/
//						int line = PyCode_Addr2Line(tracebackObject->tb_frame->f_code, tracebackObject->tb_frame->f_lasti);
//						std::string str_filename = PyUnicode_AsUTF8(tracebackObject->tb_frame->f_code->co_filename);
//						std::string funcname = PyUnicode_AsUTF8(tracebackObject->tb_frame->f_code->co_name);
//						tracebackfull += "fetch Error in  File: " + str_filename + "\r\nfunction: " + funcname +
//							"\r\nLine: " + std::to_string(line) + "\r\n";
//						frame = frame->f_back;
//					}
//					Py_XDECREF(tracebackObject);
//					Py_XDECREF(frame);
//					Py_XDECREF(tstate);
//
//				}
//#pragma endregion GetThreadState
//				/*#pragma region GetFull TraceBack
//				PyObject *trace_moudle = PyImport_ImportModule("tracebackObject");
//				if (!trace_moudle)
//				{
//				return "Fetch Error";
//				}
//
//				PyObject * python_func = PyObject_GetAttrString(trace_moudle,"format_exception");
//				if (python_func && PyCallable_Check(python_func))
//				{
//
//				PyObject *pyres = nullptr;
//				pyres = PyObject_CallFunctionObjArgs(python_func, type, value, tracebackObject, NULL);
//				if (pyres)
//				{
//				PyObject *pyo_tarceback = PyObject_Str(pyres);
//				std::string tracebackObject = PyUnicode_AsUTF8(pyo_tarceback);
//				Py_DECREF(pyres);
//				Py_DECREF(python_func);
//				return tracebackObject;
//				}
//				else
//				{
//				return std::string("fetch full tracebackObject fail");
//				}
//
//				}
//				#pragma endregion GetFull TraceBack*/
//			fetcherror:
//				PyErr_Fetch(&type, &value, &tracebackObject);
//				if (type || value || tracebackObject)
//				{
//					std::string errorinfo_1, errorinfo_2, errorinfo_3;
//					if (type && (std::string(type->ob_type->tp_name) == std::string("str")))
//					{
//						errorinfo_1 = PyUnicode_AsUTF8(type);
//					}
//					if (value && (std::string(value->ob_type->tp_name) == std::string("str")))
//					{
//						errorinfo_1 = PyUnicode_AsUTF8(value);
//					}
//					if (tracebackObject && (std::string(tracebackObject->ob_type->tp_name) == std::string("str")))
//					{
//						errorinfo_2 = PyUnicode_AsUTF8(tracebackObject);
//					}
//					/*PyErr_NormalizeException(&type, &value, &tracebackObject);*/
//					tracebackfull += " error cause:" + errorinfo_1 + errorinfo_2 + errorinfo_3;
//					std::cerr << tracebackfull;
//					Py_CLEAR(pArgs);
//					Py_CLEAR(pFunc);
//					Py_CLEAR(pModule);
//					return  false;
//				}
//#ifdef _DEBUG
//				PyErr_Print();
//#endif // DEBUG
//			}
//		}
//		Py_CLEAR(pArgs);
//		Py_CLEAR(pFunc);
//		Py_CLEAR(pModule);
//		pyResultCast(resultrSave, callResult);
//		return true;
//	}
//	catch (const std::exception& e)
//	{
//		std::cerr << (e.what());
//	}
//}

template<typename Tvalue>
PyObject* PyCaller::buildPyVaule(Tvalue&& buildValue)
{
	if (!std::is_unsigned<Tvalue>::value)
	{
		if (typeid(Tvalue) == typeid(int) || typeid(Tvalue) == typeid(long long) || typeid(Tvalue) == typeid(long))
		{
			Tvalue paramtransfer = buildValue;
			return Py_BuildValue("l", paramtransfer);
			
		}
		else if (typeid(Tvalue) == typeid(double) || typeid(Tvalue) == typeid(float))
		{
			Tvalue paramtransfer = buildValue;
			return Py_BuildValue("d", paramtransfer);
		}
	}
	else if (std::is_unsigned<Tvalue>::value)
	{
		if (typeid(Tvalue) == typeid(unsigned int) || typeid(Tvalue) == typeid(unsigned long long) || typeid(Tvalue) == typeid(unsigned long))
		{
			Tvalue paramtransfer = buildValue;
			return Py_BuildValue("I", paramtransfer);
		}
	}
	
	return nullptr;
}

template<>
inline PyObject * PyCaller::buildPyVaule(std::string&& buildValue)
{
	return Py_BuildValue("s", buildValue.c_str());
}

template<>
inline PyObject * PyCaller::buildPyVaule(const char*&& buildValue)
{
	return Py_BuildValue("s", buildValue);
}

template<typename T,typename ...argtype>
bool PyCaller::runPyFunction(T&& firstParam,  argtype&&... pyArg)
{
#ifdef _DEBUG
	int pyArgNum = sizeof...(pyArg);
#endif // _DEBUG
	if (m_pyModuleName.empty())
	{
		m_pyModuleName = firstParam;
		return runPyFunction(pyArg...);
	}
	else if (m_functionName.empty())
	{
		m_functionName = firstParam;
		return runPyFunction(pyArg...);
	}
	else
	{
		if (!m_callArgs)
		{
			unsigned int paramNum = sizeof...(pyArg);
			m_callArgs = PyTuple_New(paramNum);
			if (!m_callArgs)
			{
				emptyCallStoreVar();
				return false;
			}
		}
		PyTuple_SetItem(m_callArgs, m_parameterCounter, buildPyVaule(firstParam));
		++m_parameterCounter;
		return runPyFunction(pyArg...);
	}
}

//extern CALLPYTHON_API int nCallPython;
//CALLPYTHON_API int fnCallPython(void);
#ifdef __cplusplus
	extern "C" {
#endif // _cplusplus
	
	CALLPYTHON_API std::string Runfunction(std::string mudulename, std::string functionname, PyCaller::PYPARAMLIST ParamList);
	CALLPYTHON_API bool FinalizePyIter();
#ifdef __cplusplus
			}
#endif // _cplusplus

	
