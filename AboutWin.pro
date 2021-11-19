# -------------------------------------------------
# Project created by QtCreator 2011-12-28T14:02:50
# -------------------------------------------------
greaterThan(QT_MAJOR_VERSION ,4):QT += widgets
TARGET = AboutWin
CONFIG += link_pkgconfig


TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    aboutme.cpp \
    gst.cpp
HEADERS += mainwindow.h \
    aboutme.h
FORMS += mainwindow.ui \
    aboutme.ui

RESOURCES += \
    resource2.qrc \
    resource_211116.qrc

target.path = /root
INSTALLS += target

PKGCONFIG += gstreamer-1.0 gstreamer-video-1.0 glib-2.0


INCLUDEPATH += /usr/local/include/opencv4/

LIBS +=-L/usr/local/lib \
-lopencv_core\
 -lopencv_imgproc\
 -lopencv_highgui\
 -lopencv_ml\
-lopencv_video\
-lopencv_videoio\
-lopencv_gapi\
-lopencv_stitching \
-lopencv_aruco \
-lopencv_bgsegm \
-lopencv_bioinspired \
-lopencv_ccalib \
-lopencv_dnn_objdetect \
-lopencv_dpm \
-lopencv_face \
-lopencv_fuzzy \
-lopencv_hfs \
-lopencv_img_hash \
 -lopencv_line_descriptor \
-lopencv_reg \
-lopencv_rgbd \
-lopencv_saliency \
-lopencv_stereo \
-lopencv_structured_light \
-lopencv_phase_unwrapping \
-lopencv_superres \
-lopencv_optflow \
-lopencv_surface_matching \
-lopencv_tracking \
-lopencv_datasets \
-lopencv_text \
-lopencv_dnn \
-lopencv_plot \
-lopencv_videostab \
-lopencv_video \
-lopencv_photo \
-lopencv_xfeatures2d \
-lopencv_shape \
-lopencv_ximgproc \
-lopencv_xobjdetect \
-lopencv_objdetect \
-lopencv_calib3d \
-lopencv_features2d \
-lopencv_imgcodecs \
-lopencv_flann\
-lopencv_xphoto
