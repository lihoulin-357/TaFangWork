#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QtMath>

class WayPoint;
class QPainter;
class GameWindow;
class Tower;

class Enemy : public QObject
{
    Q_OBJECT
public:
    Enemy(WayPoint *startWayPoint, GameWindow *game, const QPixmap &sprite = QPixmap(":/image/bigGhost.png"));
    ~Enemy();

    void draw(QPainter *painter) const;
    void move();
    void getDamage(int damage);
    void getRemoved();
    void getAttacked(Tower *attacker);
    void gotLostSight(Tower *attacker);
    QPoint pos() const;
    bool collisionWithCircle(QPoint point1, int radius1, QPoint point2, int radius2)
    {
        const int xdif = point1.x() - point2.x();
        const int ydif = point1.y() - point2.y();
        const int distance = qSqrt(xdif * xdif + ydif * ydif);

        if (distance <= radius1 + radius2)
            return true;
        return false;
    }                                //碰撞检测

public slots:
    void doActivate();

private:
    bool			m_active;
    int				m_maxHp;
    int				m_currentHp;
    qreal			m_walkingSpeed;
    qreal			m_rotationSprite;

    QPoint			m_pos;
    WayPoint *		m_destinationWayPoint;
    GameWindow *	m_game;
    QList<Tower *>	m_attackedTowersList;

    const QPixmap	m_sprite;
    static const QSize ms_fixedSize;
};

#endif // ENEMY_H
