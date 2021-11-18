# -------------------------------------------------
# Project created by QtCreator 2011-12-28T14:02:50
# -------------------------------------------------
greaterThan(QT_MAJOR_VERSION ,4):QT += widgets
TARGET = AboutWin
CONFIG += link_pkgconfig


TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    aboutme.cpp
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
