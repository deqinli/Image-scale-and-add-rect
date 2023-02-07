#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_var();
    setConnection();
    init_toolBars();

    init_QGraphicsView();
    init_ImageWidget();







}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_var()
{
    itemGroup = new QGraphicsItemGroup;
}

void MainWindow::init_toolBars()
{
    labViewCord=new QLabel("View Coord:");
    labViewCord->setMinimumWidth(150);
    ui->statusBar->addWidget(labViewCord);

    labSceneCord=new QLabel("Scene Coord:");
    labSceneCord->setMinimumWidth(150);
    ui->statusBar->addWidget(labSceneCord);

    labItemCord=new QLabel("item coord:");
    labItemCord->setMinimumWidth(150);
    ui->statusBar->addWidget(labItemCord);
}

void MainWindow::init_ImageWidget()
{
    width_GView = ui->GView->width();
    height_GView = ui->GView->height();
    //m_ImgWidget->setImgPosition(width_GView/2,height_GView/2);

    Mat src = imread("../images/sample.bmp");
    srcImage = src.clone();


    QPixmap pix = Mat2QPixmap(src);
    ImgScene = new QGraphicsScene;
    m_ImgWidget = new ImageWidget(&pix);
    m_ImgWidget->setQGraphicsViewWH(width_GView,height_GView);
    m_ImgWidget->setPos(width_GView/2,height_GView/2);
    ImgScene->setSceneRect(0,0,width_GView,height_GView);

    ImgScene->addItem(m_ImgWidget);
    ui->GView->setScene(ImgScene);
}

void MainWindow::setConnection()
{
    QObject::connect(ui->GView,SIGNAL(mouseMovePoint(QPoint)),this,SLOT(on_mouseMovePoint(QPoint)));
    QObject::connect(ui->GView,&QWGraphicsView::mouseClicked,this,&MainWindow::on_mouseclicked);

    QObject::connect(ui->btnAddRect,SIGNAL(clicked(bool)),this,SLOT(on_btn_addRect_clicked()));
    QObject::connect(ui->btnRemove,SIGNAL(clicked(bool)),this,SLOT(on_btnRemove_clicked()));
}

void MainWindow::init_itemGroup()
{
    QGraphicsRectItem *rectItem1 = new QGraphicsRectItem;
    itemGroup->addToGroup(rectItem1);
    ImgScene->addItem(itemGroup);

}



void MainWindow::init_QGraphicsView()
{
    ui->GView->setCursor(Qt::CrossCursor);
    ui->GView->setMouseTracking(true);
    ui->GView->setDragMode(QGraphicsView::RubberBandDrag);
}

void MainWindow::on_mouseMovePoint(QPoint point)
{
    labViewCord->setText(QString::asprintf("View coord: %d,%d",point.x(),point.y()));
    QPointF pointScene = ui->GView->mapToScene(point);
    labSceneCord->setText(QString::asprintf("Scene coord: %.0f,%.0f",pointScene.x(),pointScene.y()));
}

void MainWindow::on_mouseclicked(QPoint point)
{
    ImgScene->removeItem(itemGroup);
    QPointF pointScene = ui->GView->mapToScene(point);
    QPointF ptf_GView = ui->GView->pos();
    QGraphicsItem *item = NULL;
    item = ImgScene->itemAt(pointScene,ui->GView->transform());
    QPointF pointItem;
    if(item != NULL)
    {
        pointItem = item->mapFromScene(pointScene);
        labItemCord->setText(QString::asprintf("Item Coord: %0.f,%0.f",pointItem.x()+m_ImgWidget->getPixmap().width()/2,pointItem.y() + m_ImgWidget->getPixmap().height()/2));
    }

    QRect rect(pointScene.x()-20,pointScene.y()-40,40,80);
    //ImgScene->removeItem(rectItem);
    QList<QGraphicsItem *> childItems = itemGroup->childItems();

    for(int i=0;i<childItems.size();i++)
    {
        itemGroup->removeFromGroup(childItems[i]);
    }

    rectItem = new QGraphicsRectItem(rect);
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::blue);
    rectItem->setPen(pen);
    itemGroup->addToGroup(rectItem);
    ImgScene->addItem(itemGroup);
    //cv::Rect mat_rect(pointScene.x()-20,pointScene.y()-40,40,80);
    //QPointF ptf =
    /*
    cv::Mat mat_cropImg = mat_scaledImg(mat_rect);
    qDebug() << "mat_cropImg: ("<<mat_scaledImg.cols << ", " << mat_scaledImg.rows<<")";
    qDebug() << "rectItem: ("<< rectItem->mapToScene(rectItem->pos());

    cv::Point2f ptfRect_leftTop,ptfRect_rightBottom;
    ptfRect_leftTop.x = (pointScene.x()*1.0f-20) / ui->GView->width() * srcImage.cols;
    ptfRect_leftTop.y = (pointScene.y()*1.0f-40) / ui->GView->height() * srcImage.rows;
    ptfRect_rightBottom.x = (pointScene.x()*1.0f+20) / ui->GView->width() * srcImage.cols;
    ptfRect_rightBottom.y = (pointScene.y()*1.0f+40) / ui->GView->height() * srcImage.rows;

    float fRect_width = abs(ptfRect_rightBottom.x - ptfRect_leftTop.x);
    float fRect_height = abs(ptfRect_rightBottom.y - ptfRect_leftTop.y);

    cv::Rect rectSrcImg(ptfRect_leftTop.x,ptfRect_leftTop.y,fRect_width,fRect_height);
    cv::Mat rectImg = srcImage(rectSrcImg);


    cv::imwrite("D:/rectImg.bmp",rectImg);
    */

}

void MainWindow::on_btnReset_clicked()
{
    qDebug() << "reset";
    //ui->GView->resizeAnchor();
    //ui->GView->zoomIn(0.9);
    //ui->GView->resize(width_GView,height_GView);
    m_ImgWidget->setPos(width_GView/2,height_GView/2);

}

//void MainWindow::resizeEvent(QResizeEvent *event)
//{

//}

void MainWindow::on_btn_addRect_clicked()
{
    width_box = 40;
    height_box = 80;
    QRectF rect(0,0,width_box,height_box);

    rectItem = new QGraphicsRectItem(rect);
    rectItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::blue);
    rectItem->setPen(pen);
    ImgScene->addItem(rectItem);

    QPointF PP = ui->GView->mapFromScene(rectItem->pos().toPoint());
    qDebug()<<"hello addRect:("<<PP.x()<<","<<PP.y()<<")";
    //ui->GView->setFi
}


//删除框
void MainWindow::on_btnRemove_clicked()
{
    QList<QGraphicsItem *> itemList = ImgScene->selectedItems();
    for(int i=0;i<itemList.size();i++)
    {
        ImgScene->removeItem(itemList[i]);
        delete itemList[i];
    }
    //HObject Ho_src = Mat2HObject(srcImage);
    //WriteImage(Ho_src,"bmp",0,"D:/code/Qt_WorkSpace/GViewDrawRect/drawRect_1/Image/HObject.bmp");
}

// 获取坐标点
void MainWindow::on_btnGetCoord_clicked()
{
#if 0
    QPointF point;
    QPoint P1,P2;
    QList<QGraphicsItem *> itemList = ImgScene->items();
    vec_subImages_mat.clear();
    for(int index=0;index<itemList.size();index++)
    {
        point=ui->GView->mapToScene((itemList[index]->pos()).toPoint());
        qDebug()<<"coord: ("<<point.x()<<","<<point.y()<<")";

        int new_Row_lu,new_Col_lu,new_width,new_height;

        new_Col_lu = point.x() / ImgScene->width() * srcImage.cols;
        new_Row_lu = point.y() / ImgScene->height() * srcImage.rows;
        new_width = width_box / ImgScene->width() * srcImage.cols;
        new_height = height_box / ImgScene->height() * srcImage.rows;

        Mat rectImg = srcImage(cv::Rect(new_Col_lu,new_Row_lu,new_width,new_height));
        //getLinePoint(rectImg,P1,P2);
        //vec_subImages_mat.push_back(rectImg);
        QString qStr = "E:/20230201_" + QString::number(index) + ".bmp";
        string str = qStr.toStdString();
        imwrite(str,rectImg);
    }
#else
    QPointF point;
    QList<QGraphicsItem *> itemList = ImgScene->items();
    vec_subImages_mat.clear();
    for(int i=0;i<itemList.size();i++)
    {
        point=ui->GView->mapToScene((itemList[i]->pos()).toPoint());
        if(point != QPoint(0,0))
        {

        }
        qDebug()<< "on_btnGetCoord_clicked:" <<point;
    }

#endif
}

bool MainWindow::getLinePoint(Mat src, QPoint &P1, QPoint &P2)
{
    HObject Edges,Region,ObjectSelected;
    HTuple Area,Row,Column,Indices,Number,Row21,Column21,Row22,Column22,Nr,Nc,Dist;
    ho_Image = Mat2HObject(src);
    EdgesSubPix(ho_Image,&Edges,"sobel_fast",10,8,50);
    GenRegionContourXld(Edges,&Region,"filled");
    AreaCenter(Region,&Area,&Row,&Column);
    TupleSortIndex(Area,&Indices);
    CountObj(Edges,&Number);
    SelectObj(Edges,&ObjectSelected,Indices[Number-1]+1);
    FitLineContourXld(ObjectSelected,"tukey",-1,0,5,2,&Row21,&Column21,&Row22,&Column22,&Nr,&Nc,&Dist);

    P1 = QPoint(Column21.D(),Row21.D());
    P2 = QPoint(Column22.D(),Row22.D());

    qDebug()<<P1.x()<<","<<P1.y();
    qDebug()<<P2.x()<<","<<P2.y();

    drawLineOnGraphicsView(P1,P2);
    return true;
}

bool MainWindow::drawLineOnGraphicsView(QPoint &P1, QPoint &P2)
{
    float sceneCol1 = P1.x() / srcImage.cols * ImgScene->width();
    float sceneRow1 = P1.y() / srcImage.rows * ImgScene->height();
    QPoint line_P1 = QPoint(sceneCol1,sceneRow1);

    float sceneCol2 = P2.x() / srcImage.cols * ImgScene->width();
    float sceneRow2 = P2.y() / srcImage.rows * ImgScene->height();
    QPoint line_P2 = QPoint(sceneCol2,sceneRow2);


    QPointF GP1F = ui->GView->mapToScene(line_P1);
    QPointF GP2F = ui->GView->mapToScene(line_P2);
    QPoint GP1 = GP1F.toPoint();
    QPoint GP2 = GP2F.toPoint();

    QGraphicsLineItem *lineItem = new QGraphicsLineItem(QLine(GP1,GP2));
    lineItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::red);
    lineItem->setPen(pen);
    ImgScene->addItem(lineItem);

    return true;


}
