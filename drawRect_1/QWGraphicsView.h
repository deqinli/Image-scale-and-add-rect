#ifndef QWGRAPHICSVIEW_H
#define QWGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QEvent>
#include <QMouseEvent>
#include <QWidget>
#include <QPoint>
#include <QPixmap>
#include <QPushButton>

class QWGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    QWGraphicsView(QWidget *parent=0);

    int x,y,w,h;
    QPixmap pix;
    QPoint lastPoint;
    QPoint endPoint;

    //qreal scale;
    QPushButton *button;
    QPixmap tempPix;

    void zoomIn(qreal delta);
    void zoomOut(qreal delta);
    void zoom(qreal scaleFactor);

protected:
    void mouseMoveEvent(QMouseEvent *even);
    void mousePressEvent(QMouseEvent *event);
signals:
    void mouseMovePoint(QPoint point);
    void mouseClicked(QPoint point);
};

#endif // QWGRAPHICSVIEW_H
