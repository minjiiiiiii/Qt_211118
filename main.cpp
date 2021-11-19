//#include <QtGui/QApplication>
#include "mainwindow.h"
//#include <QtWidgets/QApplication>
#include <QApplication>
#include <glib.h>
#include <gst/gst.h>
#include <gst/video/videooverlay.h>


#include <QTimer>
#include <QWidget>


//#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
