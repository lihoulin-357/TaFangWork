#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QList>
#include <QPixmap>
#include <QPoint>
#include <QMouseEvent>
#include <QMessageBox>
#include "towerposition.h"
#include "tower.h"
#include "waypoint.h"
#include "bullet.h"
#include "enemy.h"
#include "plistreader.h"
class GameWindow : public QWidget
{
    Q_OBJECT
public:
        GameWindow(int);            //构造
        void paintEvent(QPaintEvent* );
        void mousePressEvent(QMouseEvent *);
        void getHpDamage(int damage = 1);
        void removedEnemy(Enemy *enemy);
        void removedBullet(Bullet *bullet);
        void addBullet(Bullet *bullet);
        void awardGold(int gold);

         QList<Enemy *> enemyList() const;
private:
    const int LevelNumber;      //标识关卡
    QList<TowerPosition> m_towerPositionList;

    QList<Tower *> m_towersList;
    QList<WayPoint *> m_wayPointsList;
    QList<Enemy *> m_enemyList;

    void loadTowerPositions();
    bool canBuyTower() const;


    void addWayPoints();


    void drawWave(QPainter *painter);
    void drawHP(QPainter *painter);
    void drawPlayerGold(QPainter *painter);
    void doGameOver();
    void preLoadWavesInfo();
    bool loadWave();

    int	m_playerGold;
    int	m_waves;
    int	m_playerHp;
    bool m_gameEnded;
    bool m_gameWin;

    QList<QVariant>			m_wavesInfo;
    QList<Bullet *>			m_bulletList;

private slots:
    void updateMap();
    void gameStart();


signals:

};

#endif // GAMEWINDOW_H
