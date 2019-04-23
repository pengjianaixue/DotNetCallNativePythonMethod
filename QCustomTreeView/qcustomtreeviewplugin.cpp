#include "qcustomtreeview.h"
#include "qcustomtreeviewplugin.h"

#include <QtPlugin>

QCustomTreeViewPlugin::QCustomTreeViewPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QCustomTreeViewPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool QCustomTreeViewPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QCustomTreeViewPlugin::createWidget(QWidget *parent)
{
    return new QCustomTreeView(parent);
}

QString QCustomTreeViewPlugin::name() const
{
    return QLatin1String("QCustomTreeView");
}

QString QCustomTreeViewPlugin::group() const
{
    return QLatin1String("");
}

QIcon QCustomTreeViewPlugin::icon() const
{
    return QIcon(QLatin1String(":/treeview.png"));
}

QString QCustomTreeViewPlugin::toolTip() const
{
    return QLatin1String("");
}

QString QCustomTreeViewPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool QCustomTreeViewPlugin::isContainer() const
{
    return false;
}

QString QCustomTreeViewPlugin::domXml() const
{
    return QLatin1String("<widget class=\"QCustomTreeView\" name=\"qCustomTreeView\">\n</widget>\n");
}

QString QCustomTreeViewPlugin::includeFile() const
{
    return QLatin1String("qcustomtreeview.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(qcustomtreeviewplugin, QCustomTreeViewPlugin)
#endif // QT_VERSION < 0x050000
