#include "mywidget.h"
#include"mybutton.h"
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

    // 1>指定父对象后  2>继承自QObject
    // 子对象如果是动态分配空间的new,不需要手动释放delete
    // 系统会自动释放
    MyButton *b3 =new MyButton(this);
    b3->setText("123");
    b3->move(20,20);
    connect(b3,&MyButton::clicked,this,[=]()  mutable
    {
        delete b3;
    });
}

MyWidget::~MyWidget()
{

}
