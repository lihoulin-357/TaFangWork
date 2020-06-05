#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "levelselect.h"


QT_BEGIN_NAMESPACE
namespace Ui { class HomeWindow; }
QT_END_NAMESPACE

class HomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    HomeWindow(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);


    ~HomeWindow();

private:
    Ui::HomeWindow *ui;
};
#endif // HOMEWINDOW_H
