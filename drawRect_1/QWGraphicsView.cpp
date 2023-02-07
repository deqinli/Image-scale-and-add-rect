#include "QWGraphicsView.h"
#include <varLib.h>
#include <QGraphicsRectItem>
#include <QGraphicsItem>

using namespace HalconFunLib;
QWGraphicsView::QWGraphicsView(QWidget *paren):QGraphicsView(paren)
{

}

void QWGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    //QPoint point = event->pos();
    //emit mouseMovePoint(point);
    QGraphicsView::mouseMoveEvent(event);
}

void QWGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        QPoint point = event->pos();
        emit mouseClicked(point);
    }
    QGraphicsView::mousePressEvent(event);
}

//void QWGraphicsView::mouseMovePoint(QPoint point)
//{
//    QPoint pp = point;
//}

//void QWGraphicsView::mouseClicked(QPoint point)
//{
//    QPoint pa = point;
//}


void QWGraphicsView::zoomIn(qreal delta)
{
    zoom(delta);
}
void QWGraphicsView::zoomOut(qreal delta)
{
    zoom(1.0/delta);
}
void QWGraphicsView::zoom(qreal scaleFactor)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    qreal factor = transform().scale(scaleFactor,scaleFactor).mapRect(QRectF(0,0,1,1)).width();
    if(factor < 0.01 || factor > 2000)
    {
        return;
    }
    scale(scaleFactor,scaleFactor);
}
