#include "HalconFunlib.h"
#include "varLib.h"

using namespace HalconFunLib;

// 将HObject格式图像转为opencv中mat格式图像。
cv::Mat HalconFunLib::HObject2Mat(HObject hoImage)
{
    HTuple hvChannel;
    HString cType;
    Mat image;
    HObject srcImage;
    srcImage = hoImage;
    ConvertImageType(hoImage,&srcImage,"byte");
    CountChannels(srcImage,&hvChannel);
    Hlong width = 0;
    Hlong height = 0;
    if (1 == hvChannel[0].I())
    {
        HImage hImage(srcImage);
        void *ptr = hImage.GetImagePointer1(&cType,&width,&height);
        int W = width;
        int H = height;
        image.create(H,W,CV_8UC1);
        unsigned char *pdata = static_cast<unsigned char *>(ptr);
        memcpy(image.data,pdata,W*H);
    }
    else if (3 ==hvChannel[0].I()) {
        void *Rptr;
        void *Gptr;
        void *Bptr;
        HImage hImage(srcImage);
        hImage.GetImagePointer3(&Rptr,&Gptr,&Bptr,&cType,&width,&height);
        int W = width;
        int H = height;
        image.create(H,W,CV_8UC3);
        vector<cv::Mat> VecM(3);
        VecM[0].create(H,W,CV_8UC1);
        VecM[1].create(H,W,CV_8UC1);
        VecM[2].create(H,W,CV_8UC1);
        unsigned char *R = (unsigned char *)Rptr;
        unsigned char *G = (unsigned char *)Gptr;
        unsigned char *B = (unsigned char *)Bptr;
        memcpy(VecM[2].data,R,W*H);
        memcpy(VecM[1].data,G,W*H);
        memcpy(VecM[0].data,B,W*H);
        cv::merge(VecM,image);
    }
    return image;
}

//将Mat格式图像转为HObject格式图片。
HObject HalconFunLib::Mat2HObject(Mat &srcImage)
{
    HObject Hobj = HObject();

    //三通道图像
    if (3 == srcImage.channels())
    {

        Mat imgB;
        Mat imgG;
        Mat imgR;
        //分离三通道图像转换为3个三通道图像。
        split(srcImage,ichannels);
        imgB = ichannels[0];
        imgG = ichannels[1];
        imgR = ichannels[2];

        int height = srcImage.rows;
        int width = srcImage.cols;

        uchar *dataRed = new uchar[width*height];
        uchar *dataGreen = new uchar[width*height];
        uchar *dataBlue = new uchar[width*height];
        //三通道图像
        for (int i=0;i<height;i++)
        {
            memcpy(dataRed+width*i,imgR.ptr()+imgR.step*i,width);
            memcpy(dataGreen+width*i,imgG.ptr()+imgG.step*i,width);
            memcpy(dataBlue+width*i,imgB.ptr()+imgB.step*i,width);
        }
        GenImage3(&Hobj,"byte",width,height,(Hlong)(dataRed),(Hlong)(dataGreen),(Hlong)(dataBlue));

        delete [] dataRed;
        delete [] dataGreen;
        delete [] dataBlue;
    }

    // 单通道图像
    if (1==srcImage.channels())
    {
        int height = srcImage.rows;
        int width = srcImage.cols;
        uchar *dataGray = new uchar[width*height];

        for (int i=0;i<height;i++)
        {
            memcpy(dataGray + width*i,srcImage.ptr()+srcImage.step*i,width);
        }
        GenImage1(&Hobj,"byte",width,height,(Hlong)(dataGray));
        delete [] dataGray;
    }
    return Hobj;
}

// 将Mat转为QImage
QImage HalconFunLib::Mat2QImage(const Mat &mat)
{
    switch (mat.type())
    {
    case CV_8UC4:
    {
        QImage image(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image;
    }
    case CV_8UC3:
    {
        QImage image(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    case CV_8UC1:
    {
        QVector<QRgb> sColorTable;
        if (sColorTable.isEmpty())
        {
            for (int i=0; i < 256; i++)
            {
                sColorTable.push_back(qRgb(i, i, i));
            }
        }
        QImage image(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
        image.setColorTable(sColorTable);
        return image;
    }
    default:
        qDebug("Image format is not supported: depth=%d and %d channels\n", mat.depth(), mat.channels());
        break;
    }
    return QImage();
}

// 将Mat转为QPixmap
QPixmap HalconFunLib::Mat2QPixmap(const Mat &mat)
{
    return QPixmap::fromImage(Mat2QImage(mat));
}

// Short Description: Switch dev_update_pc, dev_update_var and dev_update_window to 'off'.
void HalconFunLib::DevUpdateOff ()
{

    //This procedure sets different update settings to 'off'.
    //This is useful to get the best performance and reduce overhead.
    //
    // dev_update_pc(...); only in hdevelop
    // dev_update_var(...); only in hdevelop
    // dev_update_window(...); only in hdevelop
    return;
}

// Short Description: This procedure displays 'Click 'Run' to continue' in the lower right corner of the screen.
void HalconFunLib::DispContinueMessage (HTuple hv_WindowHandle, HTuple hv_Color, HTuple hv_Box)
{

    // Local iconic variables

    // Local control variables
    HTuple  hv_GenParamName, hv_GenParamValue, hv_ContinueMessage;

    //This procedure displays 'Press Run (F5) to continue' in the
    //lower right corner of the screen.
    //It uses the procedure disp_message.
    //
    //Input parameters:
    //WindowHandle: The window, where the text shall be displayed
    //Color: defines the text color.
    //   If set to '' or 'auto', the currently set color is used.
    //Box: If set to 'true', the text is displayed in a box.
    //
    //Convert the parameter Box to generic parameters.
    hv_GenParamName = HTuple();
    hv_GenParamValue = HTuple();
    if (0 != ((hv_Box.TupleLength())>0))
    {
        if (0 != (HTuple(hv_Box[0])==HTuple("false")))
        {
            //Display no box
            hv_GenParamName = hv_GenParamName.TupleConcat("box");
            hv_GenParamValue = hv_GenParamValue.TupleConcat("false");
        }
        else if (0 != (HTuple(hv_Box[0])!=HTuple("true")))
        {
            //Set a color other than the default.
            hv_GenParamName = hv_GenParamName.TupleConcat("box_color");
            hv_GenParamValue = hv_GenParamValue.TupleConcat(HTuple(hv_Box[0]));
        }
    }
    if (0 != ((hv_Box.TupleLength())>1))
    {
        if (0 != (HTuple(hv_Box[1])==HTuple("false")))
        {
            //Display no shadow.
            hv_GenParamName = hv_GenParamName.TupleConcat("shadow");
            hv_GenParamValue = hv_GenParamValue.TupleConcat("false");
        }
        else if (0 != (HTuple(hv_Box[1])!=HTuple("true")))
        {
            //Set a shadow color other than the default.
            hv_GenParamName = hv_GenParamName.TupleConcat("shadow_color");
            hv_GenParamValue = hv_GenParamValue.TupleConcat(HTuple(hv_Box[1]));
        }
    }
    //
    if (0 != (hv_Color==HTuple("")))
    {
        //disp_text does not accept an empty string for Color.
        hv_Color = HTuple();
    }
    //
    //Display the message.
    hv_ContinueMessage = "Press Run (F5) to continue";
    DispText(hv_WindowHandle, hv_ContinueMessage, "window", "bottom", "right", hv_Color,
             hv_GenParamName, hv_GenParamValue);
    return;
}

// Short Description: This procedure writes a text message.
void HalconFunLib::DispMessage (HTuple hv_WindowHandle, HTuple hv_String, HTuple hv_CoordSystem,
                                HTuple hv_Row, HTuple hv_Column, HTuple hv_Color, HTuple hv_Box)
{


    HTuple  hv_GenParamName, hv_GenParamValue;


    if (0 != (HTuple(hv_Row==HTuple()).TupleOr(hv_Column==HTuple())))
    {
        return;
    }
    if (0 != (hv_Row==-1))
    {
        hv_Row = 12;
    }
    if (0 != (hv_Column==-1))
    {
        hv_Column = 12;
    }
    //
    //Convert the parameter Box to generic parameters.
    hv_GenParamName = HTuple();
    hv_GenParamValue = HTuple();
    if (0 != ((hv_Box.TupleLength())>0))
    {
        if (0 != (HTuple(hv_Box[0])==HTuple("false")))
        {
            //Display no box
            hv_GenParamName = hv_GenParamName.TupleConcat("box");
            hv_GenParamValue = hv_GenParamValue.TupleConcat("false");
        }
        else if (0 != (HTuple(hv_Box[0])!=HTuple("true")))
        {
            //Set a color other than the default.
            hv_GenParamName = hv_GenParamName.TupleConcat("box_color");
            hv_GenParamValue = hv_GenParamValue.TupleConcat(HTuple(hv_Box[0]));
        }
    }
    if (0 != ((hv_Box.TupleLength())>1))
    {
        if (0 != (HTuple(hv_Box[1])==HTuple("false")))
        {
            //Display no shadow.
            hv_GenParamName = hv_GenParamName.TupleConcat("shadow");
            hv_GenParamValue = hv_GenParamValue.TupleConcat("false");
        }
        else if (0 != (HTuple(hv_Box[1])!=HTuple("true")))
        {
            //Set a shadow color other than the default.
            hv_GenParamName = hv_GenParamName.TupleConcat("shadow_color");
            hv_GenParamValue = hv_GenParamValue.TupleConcat(HTuple(hv_Box[1]));
        }
    }
    //Restore default CoordSystem behavior.
    if (0 != (hv_CoordSystem!=HTuple("window")))
    {
        hv_CoordSystem = "image";
    }
    //
    if (0 != (hv_Color==HTuple("")))
    {
        //disp_text does not accept an empty string for Color.
        hv_Color = HTuple();
    }
    //
    DispText(hv_WindowHandle, hv_String, hv_CoordSystem, hv_Row, hv_Column, hv_Color,
             hv_GenParamName, hv_GenParamValue);
    return;
}

// Short Description: Set font independent of OS
void HalconFunLib::SetDisplayFont (HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font, HTuple hv_Bold,
                                   HTuple hv_Slant)
{

    // Local iconic variables

    // Local control variables
    HTuple  hv_OS, hv_Fonts, hv_Style, hv_Exception;
    HTuple  hv_AvailableFonts, hv_Fdx, hv_Indices;

    //This procedure sets the text font of the current window with
    //the specified attributes.
    //
    //Input parameters:
    //WindowHandle: The graphics window for which the font will be set
    //Size: The font size. If Size=-1, the default of 16 is used.
    //Bold: If set to 'true', a bold font is used
    //Slant: If set to 'true', a slanted font is used
    //
    GetSystem("operating_system", &hv_OS);
    if (0 != (HTuple(hv_Size==HTuple()).TupleOr(hv_Size==-1)))
    {
        hv_Size = 16;
    }
    if (0 != ((hv_OS.TupleSubstr(0,2))==HTuple("Win")))
    {
        //Restore previous behaviour
        hv_Size = (1.13677*hv_Size).TupleInt();
    }
    else
    {
        hv_Size = hv_Size.TupleInt();
    }
    if (0 != (hv_Font==HTuple("Courier")))
    {
        hv_Fonts.Clear();
        hv_Fonts[0] = "Courier";
        hv_Fonts[1] = "Courier 10 Pitch";
        hv_Fonts[2] = "Courier New";
        hv_Fonts[3] = "CourierNew";
        hv_Fonts[4] = "Liberation Mono";
    }
    else if (0 != (hv_Font==HTuple("mono")))
    {
        hv_Fonts.Clear();
        hv_Fonts[0] = "Consolas";
        hv_Fonts[1] = "Menlo";
        hv_Fonts[2] = "Courier";
        hv_Fonts[3] = "Courier 10 Pitch";
        hv_Fonts[4] = "FreeMono";
        hv_Fonts[5] = "Liberation Mono";
    }
    else if (0 != (hv_Font==HTuple("sans")))
    {
        hv_Fonts.Clear();
        hv_Fonts[0] = "Luxi Sans";
        hv_Fonts[1] = "DejaVu Sans";
        hv_Fonts[2] = "FreeSans";
        hv_Fonts[3] = "Arial";
        hv_Fonts[4] = "Liberation Sans";
    }
    else if (0 != (hv_Font==HTuple("serif")))
    {
        hv_Fonts.Clear();
        hv_Fonts[0] = "Times New Roman";
        hv_Fonts[1] = "Luxi Serif";
        hv_Fonts[2] = "DejaVu Serif";
        hv_Fonts[3] = "FreeSerif";
        hv_Fonts[4] = "Utopia";
        hv_Fonts[5] = "Liberation Serif";
    }
    else
    {
        hv_Fonts = hv_Font;
    }
    hv_Style = "";
    if (0 != (hv_Bold==HTuple("true")))
    {
        hv_Style += HTuple("Bold");
    }
    else if (0 != (hv_Bold!=HTuple("false")))
    {
        hv_Exception = "Wrong value of control parameter Bold";
        throw HException(hv_Exception);
    }
    if (0 != (hv_Slant==HTuple("true")))
    {
        hv_Style += HTuple("Italic");
    }
    else if (0 != (hv_Slant!=HTuple("false")))
    {
        hv_Exception = "Wrong value of control parameter Slant";
        throw HException(hv_Exception);
    }
    if (0 != (hv_Style==HTuple("")))
    {
        hv_Style = "Normal";
    }
    QueryFont(hv_WindowHandle, &hv_AvailableFonts);
    hv_Font = "";
    {
        HTuple end_val48 = (hv_Fonts.TupleLength())-1;
        HTuple step_val48 = 1;
        for (hv_Fdx=0; hv_Fdx.Continue(end_val48, step_val48); hv_Fdx += step_val48)
        {
            hv_Indices = hv_AvailableFonts.TupleFind(HTuple(hv_Fonts[hv_Fdx]));
            if (0 != ((hv_Indices.TupleLength())>0))
            {
                if (0 != (HTuple(hv_Indices[0])>=0))
                {
                    hv_Font = HTuple(hv_Fonts[hv_Fdx]);
                    break;
                }
            }
        }
    }
    if (0 != (hv_Font==HTuple("")))
    {
        throw HException("Wrong value of control parameter Font");
    }
    hv_Font = (((hv_Font+"-")+hv_Style)+"-")+hv_Size;
    SetFont(hv_WindowHandle, hv_Font);
    return;
}

// Short Description: Open a new graphics window that preserves the aspect ratio of the given image.
void HalconFunLib::DevOpenWindowFitImage(HObject ho_Image, HTuple hv_Row, HTuple hv_Column,
                                         HTuple hv_WidthLimit, HTuple hv_HeightLimit, HTuple *hv_WindowHandle)
{

    // Local iconic variables

    // Local control variables
    HTuple  hv_MinWidth, hv_MaxWidth, hv_MinHeight;
    HTuple  hv_MaxHeight, hv_ResizeFactor, hv_ImageWidth, hv_ImageHeight;
    HTuple  hv_TempWidth, hv_TempHeight, hv_WindowWidth, hv_WindowHeight;

    //This procedure opens a new graphics window and adjusts the size
    //such that it fits into the limits specified by WidthLimit
    //and HeightLimit, but also maintains the correct image aspect ratio.
    //
    //If it is impossible to match the minimum and maximum extent requirements
    //at the same time (f.e. if the image is very long but narrow),
    //the maximum value gets a higher priority,
    //
    //Parse input tuple WidthLimit
    if (0 != (HTuple((hv_WidthLimit.TupleLength()) == 0).TupleOr(hv_WidthLimit<0)))
    {
        hv_MinWidth = 500;
        hv_MaxWidth = 800;
    }
    else if (0 != ((hv_WidthLimit.TupleLength()) == 1))
    {
        hv_MinWidth = 0;
        hv_MaxWidth = hv_WidthLimit;
    }
    else
    {
        hv_MinWidth = ((const HTuple&)hv_WidthLimit)[0];
        hv_MaxWidth = ((const HTuple&)hv_WidthLimit)[1];
    }
    //Parse input tuple HeightLimit
    if (0 != (HTuple((hv_HeightLimit.TupleLength()) == 0).TupleOr(hv_HeightLimit<0)))
    {
        hv_MinHeight = 400;
        hv_MaxHeight = 600;
    }
    else if (0 != ((hv_HeightLimit.TupleLength()) == 1))
    {
        hv_MinHeight = 0;
        hv_MaxHeight = hv_HeightLimit;
    }
    else
    {
        hv_MinHeight = ((const HTuple&)hv_HeightLimit)[0];
        hv_MaxHeight = ((const HTuple&)hv_HeightLimit)[1];
    }
    //
    //Test, if window size has to be changed.
    hv_ResizeFactor = 1;
    GetImageSize(ho_Image, &hv_ImageWidth, &hv_ImageHeight);
    //First, expand window to the minimum extents (if necessary).
    if (0 != (HTuple(hv_MinWidth>hv_ImageWidth).TupleOr(hv_MinHeight>hv_ImageHeight)))
    {
        hv_ResizeFactor = (((hv_MinWidth.TupleReal()) / hv_ImageWidth).TupleConcat((hv_MinHeight.TupleReal()) / hv_ImageHeight)).TupleMax();
    }
    hv_TempWidth = hv_ImageWidth*hv_ResizeFactor;
    hv_TempHeight = hv_ImageHeight*hv_ResizeFactor;
    //Then, shrink window to maximum extents (if necessary).
    if (0 != (HTuple(hv_MaxWidth<hv_TempWidth).TupleOr(hv_MaxHeight<hv_TempHeight)))
    {
        hv_ResizeFactor = hv_ResizeFactor*((((hv_MaxWidth.TupleReal()) / hv_TempWidth).TupleConcat((hv_MaxHeight.TupleReal()) / hv_TempHeight)).TupleMin());
    }
    hv_WindowWidth = hv_ImageWidth*hv_ResizeFactor;
    hv_WindowHeight = hv_ImageHeight*hv_ResizeFactor;
    //Resize window
    SetWindowAttr("background_color", "black");
    OpenWindow(hv_Row, hv_Column, hv_WindowWidth, hv_WindowHeight, 0, "visible", "", &(*hv_WindowHandle));
    HDevWindowStack::Push((*hv_WindowHandle));
    if (HDevWindowStack::IsOpen())
        SetPart(HDevWindowStack::GetActive(), 0, 0, hv_ImageHeight - 1, hv_ImageWidth - 1);
    return;
}

// Short Description: close zoom window and reset part
void HalconFunLib::CloseZoomWindow(HTuple hv_WindowHandleZoom, HTuple hv_FormerWidth, HTuple hv_FormerHeight)
{

    HDevWindowStack::SetActive(hv_WindowHandleZoom);
    if (HDevWindowStack::IsOpen())
        CloseWindow(HDevWindowStack::Pop());
    if (HDevWindowStack::IsOpen())
        SetPart(HDevWindowStack::GetActive(), 0, 0, hv_FormerHeight - 1, hv_FormerWidth - 1);
    return;
}

// Short Description: open window and set part
void HalconFunLib::OpenZoomWindow(HTuple hv_RowPos, HTuple hv_ColPos, HTuple hv_RowROI1, HTuple hv_ColROI1,
                                  HTuple hv_RowROI2, HTuple hv_ColROI2, HTuple hv_ZoomFactor, HTuple *hv_WindowHandleZoom)
{

    SetWindowAttr("background_color", "black");
    OpenWindow(hv_RowPos, hv_ColPos, (hv_ColROI2 - hv_ColROI1)*hv_ZoomFactor, (hv_RowROI2 - hv_RowROI1)*hv_ZoomFactor, 0, "visible", "", &(*hv_WindowHandleZoom));
    HDevWindowStack::Push((*hv_WindowHandleZoom));
    if (HDevWindowStack::IsOpen())
        SetPart(HDevWindowStack::GetActive(), hv_RowROI1.TupleRound(), hv_ColROI1.TupleRound(),
                hv_RowROI2.TupleRound(), hv_ColROI2.TupleRound());
    return;
}
