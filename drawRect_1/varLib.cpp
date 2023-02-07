#include "varLib.h"

bool                                HalconFunLib::m_Flag=false;             // 测试变量，可删除。
HObject                             HalconFunLib::ho_Image;                 // 存储单张图片
HObject                             HalconFunLib::ho_Edges;                 // 边缘图片
HObject                             HalconFunLib::ho_Holes;                 // 图片中的小洞
HObject                             HalconFunLib::SelectedObject;           // 选择的区域
HObject                             HalconFunLib::RegionDilation;           // 膨胀的区域
HObject                             HalconFunLib::RegionThreshold;          // 二值化选择区域
HObject                             HalconFunLib::RegionOpening;            // 开运算区域
HObject                             HalconFunLib::RegionReduced;            // 裁剪区域
HObject                             HalconFunLib::RegionReduced2;            // 裁剪区域
HObject                             HalconFunLib::Edges;                    // 亚像素边缘

HTuple                              HalconFunLib::Row;
HTuple                              HalconFunLib::Column;
HTuple                              HalconFunLib::Phi;        //角度
HTuple                              HalconFunLib::Length1;    // 宽
HTuple                              HalconFunLib::Length2;    // 高
HTuple                              HalconFunLib::PointOrder; //
HObject                             HalconFunLib::Rectangle2;


Hlong                               HalconFunLib::windID;                   // graphicWindow窗口ID
int                                 HalconFunLib::nGraphicWidth;            // graphicWindow窗口的宽
int                                 HalconFunLib::nGraphicHeight;           // graphicWindow窗口的高
HTuple                              HalconFunLib::hv_WindowHandle;          // 显示图像窗口的句柄
HTuple                              HalconFunLib::hv_Row;                   // 圆形的中心行坐标。
HTuple                              HalconFunLib::hv_Column;                // 圆形的中心列坐标。
HTuple                              HalconFunLib::hv_Radius;                // 圆形的半径。
HTuple                              HalconFunLib::hv_Number;                // 圆形区域的数量。
HTuple                              HalconFunLib::hv_DistanceMin;           // 最小距离
HTuple                              HalconFunLib::hv_DistanceMax;           // 最大距离
HTuple                              HalconFunLib::valString;                // 字符串
HTuple                              HalconFunLib::Ascent;                   // 上边缘
HTuple                              HalconFunLib::Descent;                  // 下边缘
HTuple                              HalconFunLib::Width1;                   // 字符串的宽
HTuple                              HalconFunLib::Height1;                  // 字符串的高
HTuple                              HalconFunLib::GrayValue1;               // 灰度值大小
HTuple                              HalconFunLib::GrayValue2;               // 灰度值大小
HTuple                              HalconFunLib::hv_ImageWidth;            // 图像的宽度
HTuple                              HalconFunLib::hv_ImageHeight;           // 图像的高度
HTuple                              HalconFunLib::hv_RColor;                // R通道
HTuple                              HalconFunLib::hv_GColor;                // G通道
HTuple                              HalconFunLib::hv_BColor;                // B通道
HTuple                              HalconFunLib::hv_HomMat2D;              // 仿射变换矩阵

QPoint                              HalconFunLib::pFirstPoint;              // 第一个点
QPoint                              HalconFunLib::pSecondPoint;             // 第二个点
vector<cv::Point>                   HalconFunLib::vectPoint;                // 点集合
QTextCodec*                         HalconFunLib::codec = QTextCodec::codecForName("GBK");             // 编码指针对象，用来打印输出中文。

QString                             HalconFunLib::dirPath;                  //文件夹路径
QString                             HalconFunLib::filePath;                 //文件路径
QStringList                         HalconFunLib::filters;                  // 文件过滤器
QString                             HalconFunLib::fileList;                 // 文件列表集合
HTuple                              HalconFunLib::pathList;                 // 文件路径列表

int                                 HalconFunLib::PointFirst_RGB_R;         //第一个点的RGB模式R通道值
int                                 HalconFunLib::PointFirst_RGB_G;         //第一个点的RGB模式G通道值
int                                 HalconFunLib::PointFirst_RGB_B;         //第一个点的RGB模式B通道值
int                                 HalconFunLib::PointSecond_RGB_R;        //第二个点的RGB模式R通道值
int                                 HalconFunLib::PointSecond_RGB_G;        //第二个点的RGB模式G通道值
int                                 HalconFunLib::PointSecond_RGB_B;        //第二个点的RGB模式B通道值
float                               HalconFunLib::PointFirst_Lab_L;         //第一个点的Lab模式L通道值
float                               HalconFunLib::PointFirst_Lab_a;         //第一个点的Lab模式a通道值
float                               HalconFunLib::PointFirst_Lab_b;         //第一个点的Lab模式b通道值
float                               HalconFunLib::PointSecond_Lab_L;        //第二个点的Lab模式L通道值
float                               HalconFunLib::PointSecond_Lab_a;        //第二个点的Lab模式a通道值
float                               HalconFunLib::PointSecond_Lab_b;        //第二个点的Lab模式b通道值
int                                 HalconFunLib::FirstPoint_Column;        //第一个点的column
int                                 HalconFunLib::FirstPoint_Row;           //第一个点的row
int                                 HalconFunLib::SecondPoint_Column;       //第二个点的column
int                                 HalconFunLib::SecondPoint_Row;          //第二个点的row
vector<Mat>                         HalconFunLib::vec_subImages_mat;        // 子图像集合
//vector<QPixmap>                     HalconFunLib::vec_subImages_QPix[9];       // 子图像集合

vector<Mat>                         HalconFunLib::vec_singleChannels;
vector<Mat>                         HalconFunLib::ichannels;
QGraphicsScene*                     HalconFunLib::ImgScene;
bool                                HalconFunLib::isDrawing;
