#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
        resize(960,540);
        QMenuBar *mBar = menuBar();
        setMenuBar(mBar);
        QMenu *menu = mBar->addMenu("对话框");
        QAction *p1 = menu->addAction("模态对话框");
        connect(p1,&QAction::triggered,[=]() mutable
        {
            QDialog dlg;
            dlg.exec();
             qDebug()<<"111111111";
        });


        QAction *p2 = menu->addAction("非模态对话框");
        connect(p2,&QAction::triggered,[=]() mutable
        {
//              dlg2.show();
//            qDebug()<<"嘟嘟嘟嘟嘟";
//            QDialog *p = new QDialog(this);
//            p->show();
            QDialog *p =new QDialog;
            p->setAttribute(Qt::WA_DeleteOnClose);
            p->show();

        });


        QAction *p3 = menu->addAction("标准对话框");
        connect(p3,&QAction::triggered,[=]() mutable
        {
            QMessageBox::about(this,"about","关于Qt");

        });


        QAction *p4 = menu->addAction("问题对话框");
        connect(p4,&QAction::triggered,[=]() mutable
        {
           int ret =  QMessageBox::question(this,"question","Are you OK?",
                                    QMessageBox::Ok,
                                            QMessageBox::Cancel);
           switch (ret) {
           case   QMessageBox::Yes:
             qDebug()<<" i am ok ";
               break;
            case QMessageBox::No:
               qDebug()<<"i am not ok";
               break;
            case  QMessageBox::Cancel:
               qDebug()<<"不想回答你";
               break;
           default :
               qDebug()<<" I am sorry to hear that";
               break;
           }
        });


        QAction *p5 = menu->addAction("文件对话框");
        connect(p5,&QAction::triggered,[=]() mutable
        {
            QString path = QFileDialog::getOpenFileName(
                        this,
                        "open",
                        "../",
                        "souce(*.cpp *.h);;Text(*.txt);;all(*.*)"
                        );
            qDebug()<<path;
        });
}

MainWindow::~MainWindow()
{

}
