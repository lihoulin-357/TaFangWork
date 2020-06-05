#include "homewindow.h"
#include "ui_homewindow.h"
#include "mybutton.h"
#include "levelselect.h"


HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);

    myButton *btn_start = new myButton(":/image/start.png");
    btn_start->setParent(this);
    btn_start->move(300,250);
    LevelSelect *scene_select = new LevelSelect;
    connect(btn_start,&QPushButton::clicked,this,[=](){
        this->hide();
        scene_select->show();
    });

    connect(scene_select,&LevelSelect::go_back,[=](){
        scene_select->hide();
        this->show();
    });                                                   //start按钮&LevelSelect <->HomeWindow


    myButton *btn_exit = new myButton(":/image/exit.png");
    btn_exit->setParent(this);
    btn_exit->move(700,500);
    connect(btn_exit,&QPushButton::clicked,this,[=](){
        this->close();
    });                                                    //exit按钮


}

HomeWindow::~HomeWindow()
{
    delete ui;
}

void HomeWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap(":/image/menu.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
