#include "ImageWidget.h"

#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QGraphicsSceneDragDropEvent>
#include <QDrag>
#include <math.h>
#include <QApplication>

ImageWidget::ImageWidget(QPixmap *pixmap)
{
    m_pix = *pixmap;
    setAcceptDrops(true);
    m_scaleDefault = 0;
    m_scaleValue = 0;
    m_isMove = false;
}

QRectF ImageWidget::boundingRect() const
{
    return QRectF(-m_pix.width() / 2, -m_pix.height() / 2,m_pix.width(),m_pix.height());
}

void ImageWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-m_pix.width() / 2, -m_pix.height() / 2, m_pix);
}

void ImageWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(QApplication::keyboardModifiers() == Qt::ControlModifier) // 键盘ctrl键被按下
    {
        if(event->button() == Qt::LeftButton) // 鼠标左键被按下
        {
            m_startPos = event->pos(); // 获取鼠标当前坐标
            m_isMove = true;
        }
    }

    else if(QApplication::keyboardModifiers() == Qt::AltModifier)
    {
        if(event->button() == Qt::LeftButton)
        {
            m_startPos = event->pos();
            //emit mousepres_signal()
        }
    }
    else if(event->button() == Qt::RightButton)
    {
        ResetItemPos();
    }

}


void ImageWidget::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_isMove)
    {
        QPointF point = (event->pos() - m_startPos) * m_scaleValue;
        moveBy(point.x(),point.y());
    }
}

void ImageWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_isMove = false;
}

void ImageWidget::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if((event->delta() > 0) && (m_scaleValue) >= 200) // 最大放大到原始图像的50倍
    {
        return;
    }
    else if((event->delta() < 0) && (m_scaleValue <= m_scaleDefault)) // 图像缩小到自适应大小之后欧就不在缩小
    {
        ResetItemPos();
    }
    else
    {
        qreal qrealOriginScale = m_scaleValue;
        if(event->delta() > 0)
        {
            m_scaleValue *= 1.1;
        }
        else
        {
            m_scaleValue *= 0.9;
        }
        setScale(m_scaleValue);
        if(event->delta() > 0)
        {
            moveBy(-event->pos().x()*qrealOriginScale*0.1,-event->pos().y()*qrealOriginScale*0.1);//使图片缩放的效果看起来像是以鼠标所在点为中心进行缩放的
        }
        else
        {
            moveBy(event->pos().x()*qrealOriginScale*0.1, event->pos().y()*qrealOriginScale*0.1);//使图片缩放的效果看起来像是以鼠标所在点为中心进行缩放的
        }
    }
}

void ImageWidget::setQGraphicsViewWH(int nWidth, int nHeight)
{
    int nImgWIdth = m_pix.width();
    int nImgHeight = m_pix.height();
    qreal temp1 = nWidth * 1.0 / nImgWIdth;
    qreal temp2 = nHeight * 1.0 / nImgHeight;

    if(temp1 > temp2)
    {
        m_scaleDefault = temp2;
    }
    else
    {
        m_scaleDefault = temp1;
    }
    setScale(m_scaleDefault);
    m_scaleValue = m_scaleDefault;
}

void ImageWidget::ResetItemPos()
{
    m_scaleValue = m_scaleDefault;
    setScale(m_scaleDefault);
    setPos(350,350);
}

qreal ImageWidget::getScaleValue() const
{
    return m_scaleValue;
}

QPixmap ImageWidget::getPixmap()
{
    return m_pix;
}

void ImageWidget::setImgPosition(int nImgInitPosition_x, int nImgInitPosition_y)
{
    this->nImgInitPosition_x = nImgInitPosition_x;
    this->nImgInitPosition_y = nImgInitPosition_y;
}
