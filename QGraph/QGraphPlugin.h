#ifndef QGRAPHPLUGIN_H
#define QGRAPHPLUGIN_H

#include "C:/Qt/qt-everywhere-opensource-src-5.2.1/qttools/src/designer/src/lib/uilib/customwidget.h"

QT_BEGIN_NAMESPACE

class QGraphPlugin : public QObject, public QDesignerCustomWidgetInterface
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface" FILE "qgraphplugin.json")
	Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
	QGraphPlugin(QObject *parent = 0);

	bool isContainer() const;
	bool isInitialized() const;
	QIcon icon() const;
	QString domXml() const;
	QString group() const;
	QString includeFile() const;
	QString name() const;
	QString toolTip() const;
	QString whatsThis() const;
	QWidget *createWidget(QWidget *parent);
	void initialize(QDesignerFormEditorInterface *core);

private:
	bool initialized;
};
QT_END_NAMESPACE
#endif // QGRAPHPLUGIN_H
