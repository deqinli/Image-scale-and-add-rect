#ifndef HALCONFUNLIB_H
#define HALCONFUNLIB_H


#include <QDebug>
#include <Inc/opencv2/opencv.hpp>
#include <Inc/opencv2/core/core.hpp>
#include <Inc/opencv2/highgui.hpp>
#include <Inc/opencv2/imgproc/imgproc.hpp>
#include "Inc/halcon/Halcon.h"
#include "Inc/halcon/halconcpp/HalconCpp.h"
#include <QImage>
#include <QPixmap>



using namespace cv;
using namespace HalconCpp;
using namespace std;

namespace HalconFunLib
{
//将HObject格式图像转为opencv中的mat格式。
cv::Mat HObject2Mat(HObject hoImage);

//将Mat格式图像转为HObject格式图片。
HObject Mat2HObject(Mat &srcImage);

// 将Mat格式转换为Qimage
QImage Mat2QImage(const Mat &mat);

//将Mat转为QPixmap
QPixmap Mat2QPixmap(const Mat &mat);

// Short Description: Switch dev_update_pc, dev_update_var and dev_update_window to 'off'.
void DevUpdateOff ();

// Short Description: This procedure displays 'Click 'Run' to continue' in the lower right corner of the screen.
void DispContinueMessage (HTuple hv_WindowHandle, HTuple hv_Color, HTuple hv_Box);

// Short Description: This procedure writes a text message.
void DispMessage (HTuple hv_WindowHandle, HTuple hv_String, HTuple hv_CoordSystem, HTuple hv_Row, HTuple hv_Column, HTuple hv_Color, HTuple hv_Box);

// Short Description: Set font independent of OS
void SetDisplayFont (HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font, HTuple hv_Bold, HTuple hv_Slant);

// Short Description: Open a new graphics window that preserves the aspect ratio of the given image.
void DevOpenWindowFitImage(HObject ho_Image, HTuple hv_Row, HTuple hv_Column, HTuple hv_WidthLimit, HTuple hv_HeightLimit, HTuple *hv_WindowHandle);

// Short Description: close zoom window and reset part
void CloseZoomWindow(HTuple hv_WindowHandleZoom, HTuple hv_FormerWidth, HTuple hv_FormerHeight);

// Short Description: open window and set part
void OpenZoomWindow(HTuple hv_RowPos, HTuple hv_ColPos, HTuple hv_RowROI1, HTuple hv_ColROI1, HTuple hv_RowROI2, HTuple hv_ColROI2, HTuple hv_ZoomFactor, HTuple *hv_WindowHandleZoom);

}

#endif // HALCONFUNLIB_H
