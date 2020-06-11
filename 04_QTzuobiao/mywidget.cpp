#include "mywidget.h"
#include<QPushButton>
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    /*对于父窗口（主窗口） 坐标系统相对于屏幕
     * 原点：相对于屏幕左上角
     * x：往右递增
     * y：往左递增
    */
    move(0,0);

    /*对于子窗口 坐标系统相对于父窗口
     * 原点：相对于屏幕左上角
     * x：往右递增
     * y：往左递增
    */
    QPushButton *b1 = new QPushButton(this);
    b1->move(100,100);
    b1->resize(200,100);
    b1->setText("^…^");

    /*套娃之主*/
    QPushButton *b2 = new QPushButton(b1);
    b2->move(10,10);
    b2->setText("@…@");


}

MyWidget::~MyWidget()
{

}
