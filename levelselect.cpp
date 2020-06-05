#include "levelselect.h"
#include "mybutton.h"
#include "gamewindow.h"


LevelSelect::LevelSelect(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(800,600);
    myButton *gobackbtn = new myButton(":/image/backto.png");
    gobackbtn->setParent(this);
    connect(gobackbtn,&myButton::clicked,this,[=](){
        emit go_back();
    });

    //关卡按钮1-7

    {
    myButton *btn_level1 = new myButton(":/image/num1.png");
    btn_level1->setParent(this);
    btn_level1->move(100,300);
    GameWindow *scene_game1 = new GameWindow(0);
    connect(btn_level1,&QPushButton::clicked,this,[=](){
        this->hide();
        scene_game1->show();
    });

    myButton *btn_level2 = new myButton(":/image/num2.png");
    btn_level2->setParent(this);
    btn_level2->move(200,300);
    GameWindow *scene_game2 = new GameWindow(1);
    connect(btn_level2,&QPushButton::clicked,this,[=](){
        this->hide();
        scene_game2->show();
    });

    myButton *btn_level3 = new myButton(":/image/num3.png");
    btn_level3->setParent(this);
    btn_level3->move(300,300);
    GameWindow *scene_game3 = new GameWindow(2);
    connect(btn_level3,&QPushButton::clicked,this,[=](){
        this->hide();
        scene_game3->show();
    });

    myButton *btn_level4 = new myButton(":/image/num4.png");
    btn_level4->setParent(this);
    btn_level4->move(400,300);
    GameWindow *scene_game4 = new GameWindow(3);
    connect(btn_level4,&QPushButton::clicked,this,[=](){
        this->hide();
        scene_game4->show();
    });

    myButton *btn_level5 = new myButton(":/image/num5.png");
    btn_level5->setParent(this);
    btn_level5->move(500,300);
    GameWindow *scene_game5 = new GameWindow(4);
    connect(btn_level5,&QPushButton::clicked,this,[=](){
        this->hide();
        scene_game5->show();
    });

    myButton *btn_level6 = new myButton(":/image/num6.png");
    btn_level6->setParent(this);
    btn_level6->move(600,300);
    GameWindow *scene_game6 = new GameWindow(5);
    connect(btn_level6,&QPushButton::clicked,this,[=](){
        this->hide();
        scene_game6->show();
    });

    myButton *btn_level7 = new myButton(":/image/num7.png");
    btn_level7->setParent(this);
    btn_level7->move(700,300);
    GameWindow *scene_game7 = new GameWindow(6);
    connect(btn_level7,&QPushButton::clicked,this,[=](){
        this->hide();
        scene_game7->show();
    });
   }
}
void LevelSelect::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap(":/image/map_field_3.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
