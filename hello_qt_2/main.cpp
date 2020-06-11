#include<QApplication>
#include<QWidget>  // 窗口控制基类
#include<QPushButton>
int main(int argc, char **argv){
    QApplication app(argc,argv);

    QWidget w;
    w.setWindowTitle("标题设置");  // 设置标题
    w.show();

    QPushButton b;
    b.setText("……"); // 设置内容
    /**
    *如果不指定父对象，对象和对象（窗口和窗口）没有关系 保持独立
    * 指定父对象有两种方法： 1.setParent
    *                     2.通过构造函数传参
    */
    // 注意要传入的是地址
    b.setParent(&w); // 指定父对象
    b.move(100,100); // 移动坐标
    b.show();

    QPushButton b1(&w);
    b1.setText("aa");
    b1.show();



    return app.exec();

}
