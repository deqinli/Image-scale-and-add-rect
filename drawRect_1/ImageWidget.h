#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtGui>
#include <QPixmap>
#include <QPainter>
#include <QRectF>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsItem>


enum Enum_ZoomState{
    NO_STATE,
    RESET,
    ZOOM_IN,
    ZOOM_OUT
};

class ImageWidget : public QGraphicsItem
{
    //Q_OBJECT
public:
    ImageWidget(QPixmap *pixmap);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void wheelEvent(QGraphicsSceneWheelEvent *event);
    void ResetItemPos();
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
    qreal getScaleValue() const;
    void setQGraphicsViewWH(int nWidth, int nHeight);
    void setImgPosition(int nImgInitPosition_x, int nImgInitPosition_y);
    QPixmap getPixmap();
public:


private:
    qreal       m_scaleValue;
    qreal       m_scaleDefault;
    QPixmap     m_pix;
    int         m_zoomState;
    bool        m_isMove;
    QPointF     m_startPos;
    int nImgInitPosition_x;
    int nImgInitPosition_y;
};

#endif // IMAGEWIDGET_H
