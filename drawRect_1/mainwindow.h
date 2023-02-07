#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QLabel>
#include <QResizeEvent>
#include <Inc/halcon/Halcon.h>
#include <Inc/halcon/halconcpp/HalconCpp.h>
#include <QString>
#include <QPoint>
#include <QPointF>
#include <HalconFunlib.h>
#include <varLib.h>
#include "QWGraphicsView.h"
#include <ImageWidget.h>


using namespace cv;
using namespace HalconCpp;
using namespace HalconFunLib;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

    QLabel *labViewCord;
    QLabel *labSceneCord;
    QLabel *labItemCord;

    QGraphicsScene *ImgScene;
    ImageWidget *m_ImgWidget;
    int width_GView;
    int height_GView;
    int width_box;
    int height_box;
    Mat srcImage;
    cv::Mat mat_scaledImg;
    QGraphicsRectItem *rectItem;
    QGraphicsItemGroup *itemGroup;



    //void initGraphicsSystem();

protected:
    //void resizeEvent(QResizeEvent *event);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void init_var();
    void init_toolBars();
    void init_ImageWidget();
    void init_QGraphicsView();
    void setConnection();
    void init_itemGroup();


private slots:
    void on_mouseMovePoint(QPoint point);
    void on_mouseclicked(QPoint point);

    void on_btn_addRect_clicked();
    void on_btnRemove_clicked();
    void on_btnGetCoord_clicked();
    void on_btnReset_clicked();

private:
    Ui::MainWindow *ui;

    bool getLinePoint(Mat src, QPoint &P1, QPoint &P2);
    bool drawLineOnGraphicsView(QPoint &P1, QPoint &P2);
};

#endif // MAINWINDOW_H
