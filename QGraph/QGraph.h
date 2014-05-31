#ifndef QGRAPH_H
#define QGRAPH_H


#include <QtGui/qevent.h>
#include <QtCore/qdatetime.h>

#include "QGraphOptions.h"

QT_BEGIN_NAMESPACE


class QGraph : public QWidget, public QGraphOptions
{
	Q_OBJECT

public:
	QGraph(QWidget *parent = 0);
	~QGraph();

	/* Property */
	Q_PROPERTY(int GridSize READ gridSize WRITE setGridSize)
	Q_PROPERTY(double GridWidth READ gridWidth WRITE setGridWidth)
	Q_PROPERTY(double EdgeWidth READ edgeWidth WRITE setEdgeWidth)
	Q_PROPERTY(bool DrawGrid READ drawGrid WRITE setDrawGrid)
	Q_PROPERTY(bool DrawEdge READ drawEdge WRITE setDrawEdge)
	Q_PROPERTY(int ScrollSpeed READ scrollSpeed WRITE setScrollSpeed)
	//

	inline int  gridSize() const { return iGridSize; }
	void setGridSize(const int &size);

	inline double  gridWidth() const { return dGridWidth; }
	void setGridWidth(const double &size);
	inline double  edgeWidth() const { return dEdgeWidth; }
	void setEdgeWidth(const double &size);

	inline bool drawGrid() const { return bDrawGrid; }
	void setDrawGrid(const bool &draw);

	inline bool drawEdge() const { return bDrawEdge; }
	void setDrawEdge(const bool &draw);

	inline int  scrollSpeed() const { return iScrollSpeed; }
	void setScrollSpeed(const int &speed);
	// Property


	void addPoint(const QPoint &point);
	void addPoint(const int &x, const int &y);
	void clearPoints();

private:
	QVector<QRect>  rects;
	QVector<QPoint> points;

	int view;

private:
	void paintDrawGrid (QPainter &p);
	void paintDrawEdge (QPainter &p);
	void paintDrawVecLines (QPainter &p);

protected:
	void resizeEvent (QResizeEvent *event);
	void paintEvent (QPaintEvent *event);
	void mousePressEvent (QMouseEvent *event);
	void mouseMoveEvent (QMouseEvent *event);
};
QT_END_NAMESPACE
#endif // QGRAPH_H
