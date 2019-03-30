#pragma once
#include <QtCore\qobject.h>
#include <QtCore\qlogging.h>
#ifdef _DEBUG
#define TRACE(x) qDebug()<< x <<"\r\n"
#else
#define TRACE(x)
#endif