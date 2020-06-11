#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w; // 执行到MainWidget的构造函数，代码应该写在这里面
    w.show();

    return a.exec();
}
