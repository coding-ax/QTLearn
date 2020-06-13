#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 菜单栏
//    QMenuBar *mBar = new QMenuBar(this);
    QMenuBar *mBar = menuBar();
    resize(960,540);
    //添加菜单
    QMenu *pFile = mBar->addMenu("文件");
    // 添加动作
    QAction *pNew = pFile->addAction("新建");
    connect(pNew,&QAction::triggered,this,[=]() mutable
    {
        qDebug()<<"新建被按下";
    });
    //添加分割线
    pFile->addSeparator();

    QAction *pOpen = pFile->addAction("打开");
    connect(pOpen,&QAction::triggered,this,[=]()mutable
    {
            qDebug()<<"打开被按下";
    });

    // 工具栏
    QToolBar *toolBar = addToolBar("toolBar");
    // 工具栏添加快捷键
    toolBar->addAction(pNew);

    QPushButton *b = new QPushButton(toolBar);
    b->setText("^_^");
    toolBar->addWidget(b);
    connect(b,&QPushButton::clicked,[=]()
    {
        b->setText("@_@");
    });

     // 状态栏
    QStatusBar *sBar = statusBar();
    QLabel *laber = new QLabel(this);
    laber->setText("Normal text file");
    // addWidget 从左往右添加
    sBar->addWidget(laber);

    sBar->addWidget(new QLabel("hello",this));

    sBar->addPermanentWidget(new QLabel("右边",this));


    // 核心控件
    QTextEdit *text = new QTextEdit(this);
    setCentralWidget(text);
    // 浮动窗口
    QDockWidget *qdock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,qdock);

    qdock->setWidget(new QTextEdit(this));
}

MainWindow::~MainWindow()
{

}
