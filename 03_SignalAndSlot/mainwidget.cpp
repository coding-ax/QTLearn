#include "mainwidget.h"
#include<QPushButton>
#include<QDebug>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    // 以下用法错误： 因为是局部 变量会被销毁
    b1.setParent(this);
    b1.setText("close");
    b1.move(100,100);


    b2 = new QPushButton(this);
    b2->setText("你好");

    connect(&b1,&QPushButton::pressed,this,&MainWidget::close);
    /* $b1：信号发出者：指针类型
     * &QPushButton：处理的信号  &发送者的类名::信号名字 同样是函数指针类型
     * this: 信号接收者
     *  &MainWidget::close： 槽函数，信号处理函数  &接受者的类名::槽函数的名字
    */

    /** 自定义槽
    *  QT5:任意的成员函数，普通全局函数，静态函数
    * 槽函数需要和信号一致（参数，返回值）
    * 由于信号都是没有返回值，所以槽函数一定没有返回值
    */
    connect(b2,&QPushButton::released,this,&MainWidget::mySlot);
    connect(b2,&QPushButton::released,&b1,&QPushButton::hide);
    /*
    *  信号：短信内容
    *  槽函数：接收短信的手机
    */

    setWindowTitle("BOSS");
//    this->setWindowTitle();

    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50,50);


    // 显示子窗口
    //    w.show();
    connect(&b3,&QPushButton::released,this,&MainWidget::openSub);

    //处理子窗口的信号

    //函数指针：
//    void (SubWidget::*funSignal)() = &SubWidget::mySignal;
//    connect(&subWin,funSignal,this,&MainWidget::dealSub);

//    void (SubWidget::*testSignal)(int, QString) = &SubWidget::mySignal;
//    connect(&subWin,testSignal,this,&MainWidget::dealSlot);

//    QT4 用法：
//    connect(&subWin,SIGNAL(mySignal()),this,SLOT(dealSub));
//    connect(&subWin,SIGNAL(mySignal(int,QString)),this,SLOT(dealSub(int,QString)));
    // 但是该用法不会进行错误检查，编译时候会默认转换为字符串类型从而导致不必要的出错

    // Lambda表达式  (匿名函数变量）
    // c++ 11新增的新特性   需要在项目文件添加： CONFIG += C++11
    //QT配合信号一起使用，非常方便

    QPushButton *b4 =new QPushButton(this);
    b4->setText("Lambda表达式");
    b4->move(150,150);
    // Lambda表达式 [](){}
    // 其中在[]中以数组的形式写下内部要使用的外部变量，在()写下函数的参数，在{}中写函数主体字段
    // 可以使用 =    (但是只读,需要[]()之后加入关键字mutable)
    // 把外部所有变量均传入
    // this: 类中所有成员以值传递方式
    // &: 把外部所有局部变量，引用符号
    connect(b4,&QPushButton::released,this,[b4]() mutable
    {
        b4->setText("hhhh");
        qDebug()<<"11111111";
    });
//    connect(b4,&QPushButton::released,this,[=](){
//        b4->setText("hhhh");
//        qDebug()<<"11111111";
//    });

    resize(400,300);
}

void MainWidget::mySlot(){
    b2->setText("改变就是好事");
}
void MainWidget::openSub(){
    this->subWin.show();
    this->hide();
}
void MainWidget::dealSub(){
    this->subWin.hide();
    this->show();
}

void MainWidget::dealSlot(int a,QString str){
    // str.toUtf8() -> 字节数组QByteArray
    // ...data()  ->QByteArray -> char *
    qDebug() << a << str.toUtf8().data();
}

MainWidget::~MainWidget()
{

}

