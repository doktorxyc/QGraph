#pragma once
#include <QtCore/QString.h>
#include <QtGui/QPainter.h>
#include <QtWidgets/QWidget.h>

QT_BEGIN_NAMESPACE

class QWidget;

class QGraphOptions
{
public:
	QGraphOptions(QWidget *w);
	~QGraphOptions(void);


	int  iGridSize;

	double  dGridWidth;
	double  dEdgeWidth;

	int iScrollSpeed;

// 	QString sxSuffix;
// 	QString sySuffix;

	bool bDrawGrid;
	bool bDrawEdge;
};

QT_END_NAMESPACE