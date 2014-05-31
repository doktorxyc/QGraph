#include "QGraphOptions.h"

QT_BEGIN_NAMESPACE

QGraphOptions::QGraphOptions(QWidget *w)
{
	iGridSize = 20;
	dGridWidth  = 0.1;
	dEdgeWidth  = 2.0;

	bDrawGrid = true;
	bDrawEdge = true;
}


QGraphOptions::~QGraphOptions(void)
{
}

QT_END_NAMESPACE