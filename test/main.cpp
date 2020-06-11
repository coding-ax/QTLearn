#include "widget.h"
#include <QApplication>
// QApplication 应用程序类
// Qt头文件没有.h
// 头文件和类名一样
int main(int argc, char *argv[])
{
    // 有且只有一个应用程序类的对象
    QApplication a(argc, argv);

    // Widget继承于QWidget
    Widget w;

    // 窗口默认是隐藏的 需要显示打开
    w.show();
    // 让程序一直执行，等待用户操作
    return a.exec();
}
