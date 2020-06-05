#ifndef TOWER_H
#define TOWER_H

#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QObject>
#include <QPainter>
#include <QTimer>
#include <QtMath>
#include "enemy.h"

class Tower : QObject
{
    Q_OBJECT
public:
    Tower(QPoint pos, GameWindow *game, const QPixmap &sprite = QPixmap(":/image/greenbottle.png"));
    ~Tower();

    void draw(QPainter *painter) const;

    void checkEnemyInRange();
    void targetKilled();
    void attackEnemy();
    void chooseEnemyForAttack(Enemy *enemy);
    void removeBullet();
    void damageEnemy();
    void lostSightOfEnemy();
    bool collisionWithCircle(QPoint point1, int radius1, QPoint point2, int radius2)
    {
        const int xdif = point1.x() - point2.x();
        const int ydif = point1.y() - point2.y();
        const int distance = qSqrt(xdif * xdif + ydif * ydif);

        if (distance <= radius1 + radius2)
            return true;
        return false;
    }                                //碰撞检测

private slots:
   void shootWeapon();

private:
    bool			m_attacking;
    int				m_attackRange;	// 代表塔可以攻击到敌人的距离
    int				m_damage;		// 代表攻击敌人时造成的伤害
    int				m_fireRate;		// 代表再次攻击敌人的时间间隔
    qreal			m_rotationSprite;

    Enemy *			m_chooseEnemy;
    GameWindow *	m_game;
    QTimer *		m_fireRateTimer;

    const QPoint	m_pos;
    const QPixmap	m_sprite;

    static const QSize ms_fixedSize;
};

#endif // TOWER_H
