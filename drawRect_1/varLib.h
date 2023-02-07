#ifndef VARLIB_H
#define VARLIB_H
#include "Inc/halcon/Halcon.h"
#include "Inc/halcon/halconcpp/HalconCpp.h"
#include <QPoint>
#include <QDir>
#include <QVector>
#include <QTextCodec>
#include <Inc/opencv2/opencv.hpp>
#include <Inc/opencv2/core/core.hpp>
#include <Inc/opencv2/highgui.hpp>
#include <Inc/opencv2/imgproc/imgproc.hpp>
#include <halconfunlib.h>
#include <QGraphicsView>
#include <QGraphicsScene>

using namespace cv;
using namespace HalconCpp;
using namespace std;
namespace HalconFunLib {

extern bool                         m_Flag;             // 测试变量，可删除。
extern HObject                      ho_Image;           // 存储单张图片
extern HObject                      ho_Edges;           // 边缘图片
extern HObject                      ho_Holes;           // 图片中的小洞。
extern HObject                      SelectedObject;     // 选择的区域。
extern HObject                      RegionDilation;     // 膨胀区域。
extern HObject                      RegionThreshold;    // 二值化选择区域
extern HObject                      RegionOpening;      // 开运算区域
extern HObject                      RegionReduced;      // 裁剪区域
extern HObject                      RegionReduced2;      // 裁剪区域
extern HObject                      Edges;              // 亚像素边缘

extern HTuple                       Row;
extern HTuple                       Column;
extern HTuple                       Phi;        //角度
extern HTuple                       Length1;    // 宽
extern HTuple                       Length2;    // 高
extern HTuple                       PointOrder; //
extern HObject                      Rectangle2;

extern Hlong                        windID;             // graphicWindow窗口ID
extern int                          nGraphicWidth;      // graphicWindow窗口的宽
extern int                          nGraphicHeight;     // graphicWindow窗口的高
extern HTuple                       hv_WindowHandle;    // 显示图像窗口句柄
extern HTuple                       hv_Row;             // 圆形的中心行坐标。
extern HTuple                       hv_Column;          // 圆形的中心列坐标。
extern HTuple                       hv_Radius;          // 圆形的半径。
extern HTuple                       hv_Number;          // 圆形区域的数量。
extern HTuple                       hv_DistanceMin;     // 最小距离
extern HTuple                       hv_DistanceMax;     // 最大距离
extern HTuple                       valString;          // 字符串
extern HTuple                       Ascent;             // 上边缘
extern HTuple                       Descent;            // 下边缘
extern HTuple                       Width1;             // 字符串的宽
extern HTuple                       Height1;            // 字符串的高
extern HTuple                       GrayValue1;         // 灰度值大小
extern HTuple                       GrayValue2;         // 灰度值大小
extern HTuple                       hv_ImageWidth;      // 图像的宽度
extern HTuple                       hv_ImageHeight;     // 图像的高度
extern HTuple                       hv_RColor;          // R通道
extern HTuple                       hv_GColor;          // G通道
extern HTuple                       hv_BColor;          // B通道
extern HTuple                       hv_HomMat2D;        // 仿射变换矩阵

extern QPoint                       pFirstPoint;        // 第一个点
extern QPoint                       pSecondPoint;       // 第二个点
extern vector<cv::Point>            vectPoint;          // 点集合
extern QTextCodec*                  codec;              // 编码指针对象，用来打印输出中文。

extern QString                      dirPath;            //文件夹路径
extern QString                      filePath;           //文件路径

extern QStringList                  filters;            // 文件过滤器
extern QString                      fileList;           // 文件列表集合
extern HTuple                       pathList;           // 文件路径列表

extern int                          PointFirst_RGB_R;       //第一个点的RGB模式R通道值
extern int                          PointFirst_RGB_G;       //第一个点的RGB模式G通道值
extern int                          PointFirst_RGB_B;       //第一个点的RGB模式B通道值
extern int                          PointSecond_RGB_R;      //第二个点的RGB模式R通道值
extern int                          PointSecond_RGB_G;      //第二个点的RGB模式G通道值
extern int                          PointSecond_RGB_B;      //第二个点的RGB模式B通道值

extern float                        PointFirst_Lab_L;       //第一个点的Lab模式L通道值
extern float                        PointFirst_Lab_a;       //第一个点的Lab模式a通道值
extern float                        PointFirst_Lab_b;       //第一个点的Lab模式b通道值
extern float                        PointSecond_Lab_L;      //第二个点的Lab模式L通道值
extern float                        PointSecond_Lab_a;      //第二个点的Lab模式a通道值
extern float                        PointSecond_Lab_b;      //第二个点的Lab模式b通道值

extern int                          FirstPoint_Column;      //第一个点的column
extern int                          FirstPoint_Row;         //第一个点的row
extern int                          SecondPoint_Column;     //第二个点的column
extern int                          SecondPoint_Row;        //第二个点的row

extern vector<Mat>                  vec_subImages_mat;      // 子图像集合
//extern vector<QPixmap>              vec_subImages_QPix[9];     // 子图像集合


extern vector<Mat>                  vec_singleChannels;

extern vector<Mat>                  ichannels;
extern QGraphicsScene               *ImgScene;
extern bool                         isDrawing;
}


#endif // VARLIB_H
