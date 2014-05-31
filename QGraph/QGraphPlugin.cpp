#include "QGraph.h"

#include <QtCore/QtPlugin>
#include "QGraphPlugin.h"

QT_BEGIN_NAMESPACE

QGraphPlugin::QGraphPlugin(QObject *parent)
	: QObject(parent)
{
	initialized = false;
}

void QGraphPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
	if (initialized)
		return;

	initialized = true;
}

bool QGraphPlugin::isInitialized() const
{
	return initialized;
}

QWidget *QGraphPlugin::createWidget(QWidget *parent)
{
	return new QGraph(parent);
}

QString QGraphPlugin::name() const
{
	return QStringLiteral("QGraph");
}

QString QGraphPlugin::group() const
{
	return QStringLiteral("My Plugins");
}

QIcon QGraphPlugin::icon() const
{
	return QIcon();
}

QString QGraphPlugin::toolTip() const
{
	return QString();
}

QString QGraphPlugin::whatsThis() const
{
	return QString();
}

bool QGraphPlugin::isContainer() const
{
	return false;
}

QString QGraphPlugin::domXml() const
{
	return QStringLiteral("<widget class=\"QGraph\" name=\"qGraph\">\
		 <property name=\"geometry\">\
		  <rect>\
		   <x>0</x>\
		   <y>0</y>\
		   <width>100</width>\
		   <height>100</height>\
		  </rect>\
		 </property>\
		</widget>");
}

QString QGraphPlugin::includeFile() const
{
	return QStringLiteral("QGraph.h");
}

QT_END_NAMESPACE