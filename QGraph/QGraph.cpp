#include "QGraph.h"

QT_BEGIN_NAMESPACE

QGraph::QGraph(QWidget *parent)
	: QWidget(parent), QGraphOptions(this)
{
// 	for (int i = 0; i < 1600; i++)
// 	{
// 		addPoint (6*i,80);
// 		addPoint (30*i,50);
// 	}
	xyc = 0;
	setMouseTracking (true);
}

QGraph::~QGraph()
{
}

// Property
void QGraph::setGridSize(const int &size)
{
	iGridSize = size;
	repaint ();
}

void QGraph::setDrawGrid(const bool &draw)
{
	bDrawGrid = draw;
	repaint ();
}

void QGraph::setDrawEdge(const bool &draw)
{
	bDrawEdge = draw;
	repaint ();
}

void QGraph::setGridWidth(const double &size)
{
	dGridWidth = size;
	repaint ();
}

void QGraph::setEdgeWidth(const double &size)
{
	dEdgeWidth = size;
	repaint ();
}
// Property


void QGraph::resizeEvent(QResizeEvent *event)
{
	rects.clear ();
	for (int i = 0; i < height ()/iGridSize; i++)
	{
		rects.push_back (QRect(0,iGridSize*i,iGridSize,iGridSize));

		for (int i2 = 0; i2 < width ()/iGridSize; i2++)
		{
			rects.push_back (QRect(iGridSize*i2,iGridSize*i,iGridSize,iGridSize));
		}
	}
}

void QGraph::mousePressEvent(QMouseEvent *event)
{
	if (event->button () == Qt::MouseButton::LeftButton)
	{
		
	}
	xyc++;
}

void QGraph::mouseMoveEvent(QMouseEvent *event)
{
	xyc++;
}

void QGraph::paintEvent(QPaintEvent *event)
{
	QTime t;
	t.start ();

	

	QPainter p(this);
	p.setRenderHint (QPainter::Antialiasing);

	if (bDrawGrid)
		paintDrawGrid (p);

	if (bDrawEdge)
		paintDrawEdge (p);

	paintDrawVecLines (p);

	p.drawText (QRect(10,10,500,50), "Time: " + QString::number(t.elapsed ()));
	p.drawText (QRect(10,20,500,50), "xyc: " + QString::number(xyc));
}

void QGraph::paintDrawGrid(QPainter &p)
{
	QPen pBackUp = p.pen ();
	QPen pGrid(Qt::gray, dGridWidth);

	p.setPen (pGrid);

	p.drawRects (rects);
	p.setPen (pBackUp);
}

void QGraph::paintDrawEdge(QPainter &p)
{
	QPen pBackUp = p.pen ();
	QPen pEdge(Qt::darkMagenta,dEdgeWidth);

	p.setPen (pEdge);
	p.drawLine (1, 0, 1, height ());
	p.drawLine (1, height ()-1, width (), height ()-1);
	p.setPen (pBackUp);
}

void QGraph::paintDrawVecLines(QPainter &p)
{
	QPen pBackUp = p.pen ();
	QPen pLine(Qt::red,1);

	p.setPen (pLine);
	

	p.drawLines (points);
	//p.drawPoints (&points[0],points.size ());
	p.setPen (pBackUp);
}

void QGraph::addPoint(const QPoint &point)
{
	if (points.size () > 1)
	{
		QPoint p(points[points.size ()-2].x (), points[points.size ()-2].y ());
		QPoint p2(points[points.size ()-1].x (), points[points.size ()-1].y ());
		points.push_back (p);
		points.push_back (p2);
 	}
	points.push_back (point);
	repaint ();
}

void QGraph::addPoint(const int &x, const int &y)
{
	addPoint (QPoint(x,y));
}

void QGraph::clearPoints()
{
	points.clear ();
}


QT_END_NAMESPACE