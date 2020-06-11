#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<QPushButton>
#include "subwidget.h"  //子窗口文件
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void mySlot();
    void openSub();
    void dealSub();
    void dealSlot(int,QString);
 private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;


    // 子窗口
    SubWidget subWin;
};

#endif // MAINWIDGET_H
