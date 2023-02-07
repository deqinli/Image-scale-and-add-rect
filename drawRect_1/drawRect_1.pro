#-------------------------------------------------
#
# Project created by QtCreator 2021-09-06T08:37:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = drawRect_1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/Inc/
INCLUDEPATH += $$PWD/Inc/halcon/
INCLUDEPATH += $$PWD/Inc/opencv/
INCLUDEPATH += $$PWD/Inc/opencv2/

LIBS += -L$$PWD/Lib/halcon_lib/ -lhalcon
LIBS += -L$$PWD/Lib/halcon_lib/ -lhalconcpp

CONFIG(debug,debug|release){
LIBS += -L$$PWD/Lib/opencv_lib -lopencv_world340d
}
CONFIG(release,debug|release){
LIBS += -L$$PWD/Lib/opencv_lib -lopencv_world340
}

DESTDIR += ../bin

SOURCES += \
    ImageWidget.cpp \
        main.cpp \
        mainwindow.cpp \
    HalconFunlib.cpp \
    varLib.cpp \
    QWGraphicsView.cpp

HEADERS += \
    ImageWidget.h \
        mainwindow.h \
    Inc/halcon/halconc/Hdevthread.h \
    Inc/halcon/halconc/Hvector.h \
    Inc/halcon/halconcpp/HalconAPI.h \
    Inc/halcon/halconcpp/HalconCpp.h \
    Inc/halcon/halconcpp/HalconCppForwards.h \
    Inc/halcon/halconcpp/HalconCppIncludes.h \
    Inc/halcon/halconcpp/HBarCode.h \
    Inc/halcon/halconcpp/HBarrier.h \
    Inc/halcon/halconcpp/HBeadInspectionModel.h \
    Inc/halcon/halconcpp/HBgEsti.h \
    Inc/halcon/halconcpp/HCalibData.h \
    Inc/halcon/halconcpp/HCameraSetupModel.h \
    Inc/halcon/halconcpp/HCamPar.h \
    Inc/halcon/halconcpp/HClassBox.h \
    Inc/halcon/halconcpp/HClassGmm.h \
    Inc/halcon/halconcpp/HClassKnn.h \
    Inc/halcon/halconcpp/HClassLUT.h \
    Inc/halcon/halconcpp/HClassMlp.h \
    Inc/halcon/halconcpp/HClassSvm.h \
    Inc/halcon/halconcpp/HClassTrainData.h \
    Inc/halcon/halconcpp/HColorTransLUT.h \
    Inc/halcon/halconcpp/HComponentModel.h \
    Inc/halcon/halconcpp/HComponentTraining.h \
    Inc/halcon/halconcpp/HComputeDevice.h \
    Inc/halcon/halconcpp/HCondition.h \
    Inc/halcon/halconcpp/HDataBase.h \
    Inc/halcon/halconcpp/HDataCode2D.h \
    Inc/halcon/halconcpp/HDeformableModel.h \
    Inc/halcon/halconcpp/HDeformableSurfaceMatchingResult.h \
    Inc/halcon/halconcpp/HDeformableSurfaceModel.h \
    Inc/halcon/halconcpp/HDescriptorModel.h \
    Inc/halcon/halconcpp/HDevThread.h \
    Inc/halcon/halconcpp/HDevWindowStack.h \
    Inc/halcon/halconcpp/HDict.h \
    Inc/halcon/halconcpp/HDlClassifier.h \
    Inc/halcon/halconcpp/HDlClassifierResult.h \
    Inc/halcon/halconcpp/HDlClassifierTrainResult.h \
    Inc/halcon/halconcpp/HDlModel.h \
    Inc/halcon/halconcpp/HDrawingObject.h \
    Inc/halcon/halconcpp/HDualQuaternion.h \
    Inc/halcon/halconcpp/HEvent.h \
    Inc/halcon/halconcpp/HException.h \
    Inc/halcon/halconcpp/HFeatureSet.h \
    Inc/halcon/halconcpp/HFile.h \
    Inc/halcon/halconcpp/HFramegrabber.h \
    Inc/halcon/halconcpp/HFunction1D.h \
    Inc/halcon/halconcpp/HGnuplot.h \
    Inc/halcon/halconcpp/HHandle.h \
    Inc/halcon/halconcpp/HHandleBase.h \
    Inc/halcon/halconcpp/HHomMat2D.h \
    Inc/halcon/halconcpp/HHomMat3D.h \
    Inc/halcon/halconcpp/HImage.h \
    Inc/halcon/halconcpp/HInfo.h \
    Inc/halcon/halconcpp/HIOChannel.h \
    Inc/halcon/halconcpp/HIODevice.h \
    Inc/halcon/halconcpp/HIOStream.h \
    Inc/halcon/halconcpp/HLexicon.h \
    Inc/halcon/halconcpp/HMatrix.h \
    Inc/halcon/halconcpp/HMeasure.h \
    Inc/halcon/halconcpp/HMessage.h \
    Inc/halcon/halconcpp/HMessageQueue.h \
    Inc/halcon/halconcpp/HMetrologyModel.h \
    Inc/halcon/halconcpp/HMisc.h \
    Inc/halcon/halconcpp/HMutex.h \
    Inc/halcon/halconcpp/HNCCModel.h \
    Inc/halcon/halconcpp/HObject.h \
    Inc/halcon/halconcpp/HObjectBase.h \
    Inc/halcon/halconcpp/HObjectModel3D.h \
    Inc/halcon/halconcpp/HOCRBox.h \
    Inc/halcon/halconcpp/HOCRCnn.h \
    Inc/halcon/halconcpp/HOCRKnn.h \
    Inc/halcon/halconcpp/HOCRMlp.h \
    Inc/halcon/halconcpp/HOCRSvm.h \
    Inc/halcon/halconcpp/HOCV.h \
    Inc/halcon/halconcpp/HOperatorOverloads.h \
    Inc/halcon/halconcpp/HOperatorSet.h \
    Inc/halcon/halconcpp/HOperatorSetLegacy.h \
    Inc/halcon/halconcpp/HPose.h \
    Inc/halcon/halconcpp/HQuaternion.h \
    Inc/halcon/halconcpp/HRegion.h \
    Inc/halcon/halconcpp/HSampleIdentifier.h \
    Inc/halcon/halconcpp/HScatteredDataInterpolator.h \
    Inc/halcon/halconcpp/HScene3D.h \
    Inc/halcon/halconcpp/HSerial.h \
    Inc/halcon/halconcpp/HSerializedItem.h \
    Inc/halcon/halconcpp/HShapeModel.h \
    Inc/halcon/halconcpp/HShapeModel3D.h \
    Inc/halcon/halconcpp/HSheetOfLightModel.h \
    Inc/halcon/halconcpp/HSmartPtr.h \
    Inc/halcon/halconcpp/HSocket.h \
    Inc/halcon/halconcpp/HStereoModel.h \
    Inc/halcon/halconcpp/HString.h \
    Inc/halcon/halconcpp/HStructuredLightModel.h \
    Inc/halcon/halconcpp/HSurfaceMatchingResult.h \
    Inc/halcon/halconcpp/HSurfaceModel.h \
    Inc/halcon/halconcpp/HSystem.h \
    Inc/halcon/halconcpp/HTemplate.h \
    Inc/halcon/halconcpp/HTextModel.h \
    Inc/halcon/halconcpp/HTextResult.h \
    Inc/halcon/halconcpp/HTextureInspectionModel.h \
    Inc/halcon/halconcpp/HTextureInspectionResult.h \
    Inc/halcon/halconcpp/HTuple.h \
    Inc/halcon/halconcpp/HTupleElement.h \
    Inc/halcon/halconcpp/HTupleLegacy.h \
    Inc/halcon/halconcpp/HVariationModel.h \
    Inc/halcon/halconcpp/HVector.h \
    Inc/halcon/halconcpp/HWindow.h \
    Inc/halcon/halconcpp/HXLD.h \
    Inc/halcon/halconcpp/HXLDCont.h \
    Inc/halcon/halconcpp/HXLDDistTrans.h \
    Inc/halcon/halconcpp/HXLDExtPara.h \
    Inc/halcon/halconcpp/HXLDModPara.h \
    Inc/halcon/halconcpp/HXLDPara.h \
    Inc/halcon/halconcpp/HXLDPoly.h \
    Inc/halcon/hdevengine/HDevEngineCpp.h \
    Inc/halcon/hlib/CIOFrameGrab.h \
    Inc/halcon/hlib/CIOFrameGrabDefines.h \
    Inc/halcon/hlib/CIOIIDevice.h \
    Inc/halcon/hlib/CIOIIDeviceDefines.h \
    Inc/halcon/hlib/CORE1.h \
    Inc/halcon/hlib/DBNew.h \
    Inc/halcon/hlib/HAlloc.h \
    Inc/halcon/hlib/HBaseGP.h \
    Inc/halcon/hlib/HComputeDeviceExt.h \
    Inc/halcon/hlib/HError.h \
    Inc/halcon/hlib/HInstance.h \
    Inc/halcon/hlib/HInstanceDefines.h \
    Inc/halcon/hlib/HMessageQueue.h \
    Inc/halcon/hlib/HObjectModel3D.h \
    Inc/halcon/hlib/HpThread.h \
    Inc/halcon/hlib/HRLClip.h \
    Inc/halcon/hlib/HXLD.h \
    Inc/halcon/hlib/IOSpy.h \
    Inc/halcon/Halcon.h \
    Inc/halcon/HalconC.h \
    Inc/halcon/HalconCDefs.h \
    Inc/halcon/HBase.h \
    Inc/halcon/HConst.h \
    Inc/halcon/HCtype.h \
    Inc/halcon/HDeclSpec.h \
    Inc/halcon/HErrorDef.h \
    Inc/halcon/HExtern.h \
    Inc/halcon/HIntDef.h \
    Inc/halcon/HInterfaceC.h \
    Inc/halcon/HMacro.h \
    Inc/halcon/HParallel.h \
    Inc/halcon/HProto.h \
    Inc/halcon/HSync.h \
    Inc/halcon/HVersNum.h \
    Inc/halcon/IPType.h \
    Inc/opencv/cv.h \
    Inc/opencv/cv.hpp \
    Inc/opencv/cvaux.h \
    Inc/opencv/cvaux.hpp \
    Inc/opencv/cvwimage.h \
    Inc/opencv/cxcore.h \
    Inc/opencv/cxcore.hpp \
    Inc/opencv/cxeigen.hpp \
    Inc/opencv/cxmisc.h \
    Inc/opencv/highgui.h \
    Inc/opencv/ml.h \
    Inc/opencv2/calib3d/calib3d.hpp \
    Inc/opencv2/calib3d/calib3d_c.h \
    Inc/opencv2/core/hal/hal.hpp \
    Inc/opencv2/core/hal/interface.h \
    Inc/opencv2/core/hal/intrin.hpp \
    Inc/opencv2/core/hal/intrin_cpp.hpp \
    Inc/opencv2/core/hal/intrin_neon.hpp \
    Inc/opencv2/core/hal/intrin_sse.hpp \
    Inc/opencv2/core/hal/intrin_vsx.hpp \
    Inc/opencv2/core/utils/filesystem.hpp \
    Inc/opencv2/core/utils/logger.defines.hpp \
    Inc/opencv2/core/utils/logger.hpp \
    Inc/opencv2/core/utils/trace.hpp \
    Inc/opencv2/core/affine.hpp \
    Inc/opencv2/core/base.hpp \
    Inc/opencv2/core/bufferpool.hpp \
    Inc/opencv2/core/core.hpp \
    Inc/opencv2/core/core_c.h \
    Inc/opencv2/core/cuda.hpp \
    Inc/opencv2/core/cuda.inl.hpp \
    Inc/opencv2/core/cuda_stream_accessor.hpp \
    Inc/opencv2/core/cuda_types.hpp \
    Inc/opencv2/core/cv_cpu_dispatch.h \
    Inc/opencv2/core/cv_cpu_helper.h \
    Inc/opencv2/core/cvdef.h \
    Inc/opencv2/core/cvstd.hpp \
    Inc/opencv2/core/cvstd.inl.hpp \
    Inc/opencv2/core/directx.hpp \
    Inc/opencv2/core/eigen.hpp \
    Inc/opencv2/core/fast_math.hpp \
    Inc/opencv2/core/ippasync.hpp \
    Inc/opencv2/core/mat.hpp \
    Inc/opencv2/core/mat.inl.hpp \
    Inc/opencv2/core/matx.hpp \
    Inc/opencv2/core/neon_utils.hpp \
    Inc/opencv2/core/ocl.hpp \
    Inc/opencv2/core/ocl_genbase.hpp \
    Inc/opencv2/core/opengl.hpp \
    Inc/opencv2/core/operations.hpp \
    Inc/opencv2/core/optim.hpp \
    Inc/opencv2/core/ovx.hpp \
    Inc/opencv2/core/persistence.hpp \
    Inc/opencv2/core/ptr.inl.hpp \
    Inc/opencv2/core/saturate.hpp \
    Inc/opencv2/core/softfloat.hpp \
    Inc/opencv2/core/sse_utils.hpp \
    Inc/opencv2/core/traits.hpp \
    Inc/opencv2/core/types.hpp \
    Inc/opencv2/core/types_c.h \
    Inc/opencv2/core/utility.hpp \
    Inc/opencv2/core/va_intel.hpp \
    Inc/opencv2/core/version.hpp \
    Inc/opencv2/core/vsx_utils.hpp \
    Inc/opencv2/core/wimage.hpp \
    Inc/opencv2/dnn/all_layers.hpp \
    Inc/opencv2/dnn/dict.hpp \
    Inc/opencv2/dnn/dnn.hpp \
    Inc/opencv2/dnn/dnn.inl.hpp \
    Inc/opencv2/dnn/layer.details.hpp \
    Inc/opencv2/dnn/layer.hpp \
    Inc/opencv2/dnn/shape_utils.hpp \
    Inc/opencv2/features2d/features2d.hpp \
    Inc/opencv2/flann/all_indices.h \
    Inc/opencv2/flann/allocator.h \
    Inc/opencv2/flann/any.h \
    Inc/opencv2/flann/autotuned_index.h \
    Inc/opencv2/flann/composite_index.h \
    Inc/opencv2/flann/config.h \
    Inc/opencv2/flann/defines.h \
    Inc/opencv2/flann/dist.h \
    Inc/opencv2/flann/dummy.h \
    Inc/opencv2/flann/dynamic_bitset.h \
    Inc/opencv2/flann/flann.hpp \
    Inc/opencv2/flann/flann_base.hpp \
    Inc/opencv2/flann/general.h \
    Inc/opencv2/flann/ground_truth.h \
    Inc/opencv2/flann/hdf5.h \
    Inc/opencv2/flann/heap.h \
    Inc/opencv2/flann/hierarchical_clustering_index.h \
    Inc/opencv2/flann/index_testing.h \
    Inc/opencv2/flann/kdtree_index.h \
    Inc/opencv2/flann/kdtree_single_index.h \
    Inc/opencv2/flann/kmeans_index.h \
    Inc/opencv2/flann/linear_index.h \
    Inc/opencv2/flann/logger.h \
    Inc/opencv2/flann/lsh_index.h \
    Inc/opencv2/flann/lsh_table.h \
    Inc/opencv2/flann/matrix.h \
    Inc/opencv2/flann/miniflann.hpp \
    Inc/opencv2/flann/nn_index.h \
    Inc/opencv2/flann/object_factory.h \
    Inc/opencv2/flann/params.h \
    Inc/opencv2/flann/random.h \
    Inc/opencv2/flann/result_set.h \
    Inc/opencv2/flann/sampling.h \
    Inc/opencv2/flann/saving.h \
    Inc/opencv2/flann/simplex_downhill.h \
    Inc/opencv2/flann/timer.h \
    Inc/opencv2/highgui/highgui.hpp \
    Inc/opencv2/highgui/highgui_c.h \
    Inc/opencv2/imgcodecs/imgcodecs.hpp \
    Inc/opencv2/imgcodecs/imgcodecs_c.h \
    Inc/opencv2/imgcodecs/ios.h \
    Inc/opencv2/imgproc/detail/distortion_model.hpp \
    Inc/opencv2/imgproc/hal/hal.hpp \
    Inc/opencv2/imgproc/hal/interface.h \
    Inc/opencv2/imgproc/imgproc.hpp \
    Inc/opencv2/imgproc/imgproc_c.h \
    Inc/opencv2/imgproc/types_c.h \
    Inc/opencv2/ml/ml.hpp \
    Inc/opencv2/ml/ml.inl.hpp \
    Inc/opencv2/objdetect/detection_based_tracker.hpp \
    Inc/opencv2/objdetect/objdetect.hpp \
    Inc/opencv2/objdetect/objdetect_c.h \
    Inc/opencv2/photo/cuda.hpp \
    Inc/opencv2/photo/photo.hpp \
    Inc/opencv2/photo/photo_c.h \
    Inc/opencv2/shape/emdL1.hpp \
    Inc/opencv2/shape/hist_cost.hpp \
    Inc/opencv2/shape/shape.hpp \
    Inc/opencv2/shape/shape_distance.hpp \
    Inc/opencv2/shape/shape_transformer.hpp \
    Inc/opencv2/stitching/detail/autocalib.hpp \
    Inc/opencv2/stitching/detail/blenders.hpp \
    Inc/opencv2/stitching/detail/camera.hpp \
    Inc/opencv2/stitching/detail/exposure_compensate.hpp \
    Inc/opencv2/stitching/detail/matchers.hpp \
    Inc/opencv2/stitching/detail/motion_estimators.hpp \
    Inc/opencv2/stitching/detail/seam_finders.hpp \
    Inc/opencv2/stitching/detail/timelapsers.hpp \
    Inc/opencv2/stitching/detail/util.hpp \
    Inc/opencv2/stitching/detail/util_inl.hpp \
    Inc/opencv2/stitching/detail/warpers.hpp \
    Inc/opencv2/stitching/detail/warpers_inl.hpp \
    Inc/opencv2/stitching/warpers.hpp \
    Inc/opencv2/superres/optical_flow.hpp \
    Inc/opencv2/video/background_segm.hpp \
    Inc/opencv2/video/tracking.hpp \
    Inc/opencv2/video/tracking_c.h \
    Inc/opencv2/video/video.hpp \
    Inc/opencv2/videoio/cap_ios.h \
    Inc/opencv2/videoio/videoio.hpp \
    Inc/opencv2/videoio/videoio_c.h \
    Inc/opencv2/videostab/deblurring.hpp \
    Inc/opencv2/videostab/fast_marching.hpp \
    Inc/opencv2/videostab/fast_marching_inl.hpp \
    Inc/opencv2/videostab/frame_source.hpp \
    Inc/opencv2/videostab/global_motion.hpp \
    Inc/opencv2/videostab/inpainting.hpp \
    Inc/opencv2/videostab/log.hpp \
    Inc/opencv2/videostab/motion_core.hpp \
    Inc/opencv2/videostab/motion_stabilizing.hpp \
    Inc/opencv2/videostab/optical_flow.hpp \
    Inc/opencv2/videostab/outlier_rejection.hpp \
    Inc/opencv2/videostab/ring_buffer.hpp \
    Inc/opencv2/videostab/stabilizer.hpp \
    Inc/opencv2/videostab/wobble_suppression.hpp \
    Inc/opencv2/calib3d.hpp \
    Inc/opencv2/core.hpp \
    Inc/opencv2/cvconfig.h \
    Inc/opencv2/dnn.hpp \
    Inc/opencv2/features2d.hpp \
    Inc/opencv2/flann.hpp \
    Inc/opencv2/highgui.hpp \
    Inc/opencv2/imgcodecs.hpp \
    Inc/opencv2/imgproc.hpp \
    Inc/opencv2/ml.hpp \
    Inc/opencv2/objdetect.hpp \
    Inc/opencv2/opencv.hpp \
    Inc/opencv2/opencv_modules.hpp \
    Inc/opencv2/photo.hpp \
    Inc/opencv2/shape.hpp \
    Inc/opencv2/stitching.hpp \
    Inc/opencv2/superres.hpp \
    Inc/opencv2/video.hpp \
    Inc/opencv2/videoio.hpp \
    Inc/opencv2/videostab.hpp \
    Inc/opencv2/world.hpp \
    HalconFunlib.h \
    varLib.h \
    QWGraphicsView.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    Lib/opencv_lib/opencv_world340.lib \
    Lib/opencv_lib/opencv_world340d.lib \
    Lib/Halcon_lib/halcon.lib \
    Lib/Halcon_lib/halconc.lib \
    Lib/Halcon_lib/halconcpp.lib \
    Lib/Halcon_lib/halconcppxl.lib \
    Lib/Halcon_lib/halconcxl.lib \
    Lib/Halcon_lib/halconxl.lib \
    Lib/Halcon_lib/hdevenginecpp.lib \
    Lib/Halcon_lib/hdevenginecppxl.lib \
    Lib/Halcon_lib/libiomp5md.lib
