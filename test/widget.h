#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT        // 信号与槽

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
