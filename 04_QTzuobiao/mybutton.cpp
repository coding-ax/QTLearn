#include "mybutton.h"
#include<QPushButton>
#include<QDebug>
MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}
MyButton::~MyButton()
{
    qDebug()<<"按钮析构";
}
