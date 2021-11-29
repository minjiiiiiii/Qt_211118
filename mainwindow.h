#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

#include <aboutme.h> //add the include .h file of your form

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void openAbout(); //make a new function to call the window

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    AboutMe     *winAbout; //make a new declaration for the new window


private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_login_clicked();
   // void on_pushButton_3_clicked();
   // void on_checkBox_stateChanged(int arg1);
   // void on_pushButton_4_clicked();
};

#endif // MAINWINDOW_H
