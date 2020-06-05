#ifndef LEVELSELECT_H
#define LEVELSELECT_H

#include <QWidget>
#include <QPainter>

class LevelSelect : public QWidget
{
    Q_OBJECT
public:
    explicit LevelSelect(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);



signals:
    void go_back();

};

#endif // LEVELSELECT_H
