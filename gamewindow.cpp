#include "gamewindow.h"

static const int TowerCost = 300;

GameWindow::GameWindow(int LevelNumber)
    : LevelNumber(LevelNumber)
    ,m_playerGold(1000)
    , m_waves(0)
    , m_playerHp(5)
    , m_gameEnded(false)
    , m_gameWin(false)
{
    this->setFixedSize(800,600);

   /* QTimer* timer2 = new QTimer(this);      //用于插入怪物定时器
    timer2->start(2000);

    connect(timer2,&QTimer::timeout,[=]()
    {
        switch (LevelNumber) {
        case 0:
        {

        }
        case 1:
        {

        }

        case 2:
        {

        }



        default:
            break;
        }
    });*/
    preLoadWavesInfo();
    loadTowerPositions();
    addWayPoints();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateMap()));
    timer->start(30);
    // 设置300ms后游戏启动
    QTimer::singleShot(300, this, SLOT(gameStart()));

}
void GameWindow::paintEvent(QPaintEvent *)
{
    QPixmap cachePix(":/image/map2.jpg");
    QPainter cachePainter(&cachePix);

    foreach (const TowerPosition &towerPos, m_towerPositionList)
        towerPos.draw(&cachePainter);

    foreach (const Tower *tower, m_towersList)
        tower->draw(&cachePainter);

    //foreach (const WayPoint *wayPoint, m_wayPointsList)
        //wayPoint->draw(&cachePainter);

    foreach (const Enemy *enemy, m_enemyList)
        enemy->draw(&cachePainter);

    foreach (const Bullet *bullet, m_bulletList)
        bullet->draw(&cachePainter);


    QPainter painter(this);
    painter.drawPixmap(0, 0, cachePix);


}
void GameWindow::loadTowerPositions()
{
    QPoint pos[] =
    {
        QPoint(50, 240),
        QPoint(165, 240),
        QPoint(165, 320),
        QPoint(372, 210),
        QPoint(472, 210),
        QPoint(572, 210),
        QPoint(272, 415),
        QPoint(372, 415),
        QPoint(472, 415),
        QPoint(572, 415),
        QPoint(672, 415),
    };
    int len	= sizeof(pos) / sizeof(pos[0]);

    for (int i = 0; i < len; ++i)
        m_towerPositionList.push_back(pos[i]);

}

void GameWindow::addWayPoints()
{
    WayPoint *wayPoint1 = new WayPoint(QPoint(9, 167));
    m_wayPointsList.push_back(wayPoint1);

    WayPoint *wayPoint2 = new WayPoint(QPoint(298, 167));
    m_wayPointsList.push_back(wayPoint2);
    wayPoint2->setNextWayPoint(wayPoint1);

    WayPoint *wayPoint3 = new WayPoint(QPoint(298, 360));
    m_wayPointsList.push_back(wayPoint3);
    wayPoint3->setNextWayPoint(wayPoint2);

    WayPoint *wayPoint4 = new WayPoint(QPoint(708, 360));
    m_wayPointsList.push_back(wayPoint4);
    wayPoint4->setNextWayPoint(wayPoint3);

    WayPoint *wayPoint5 = new WayPoint(QPoint(708, 32));
    m_wayPointsList.push_back(wayPoint5);
    wayPoint5->setNextWayPoint(wayPoint4);
}
void GameWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    auto it = m_towerPositionList.begin();
    while (it != m_towerPositionList.end())
    {
        if (canBuyTower() && it->containPoint(pressPos) && !it->hasTower())
        {
            //m_audioPlayer->playSound(TowerPlaceSound);
            m_playerGold -= TowerCost;
            it->setHasTower();

            Tower *tower = new Tower(it->centerPos(), this);
            m_towersList.push_back(tower);
            update();
            break;
        }

        ++it;
    }
}

bool GameWindow::canBuyTower() const
{
    if (m_playerGold >= TowerCost)
        return true;
    return false;
}



void GameWindow::doGameOver()
{
    if (!m_gameEnded)
    {
        m_gameEnded = true;
        // 此处应该切换场景到结束场景
        // 暂时以打印替代,见paintEvent处理
    }
}

void GameWindow::awardGold(int gold)
{
    m_playerGold += gold;
    update();
}




void GameWindow::getHpDamage(int damage/* = 1*/)
{
    //m_audioPlayer->playSound(LifeLoseSound);
    m_playerHp -= damage;
    if (m_playerHp <= 0)
        doGameOver();
}

void GameWindow::removedEnemy(Enemy *enemy)
{
    Q_ASSERT(enemy);

    m_enemyList.removeOne(enemy);
    delete enemy;

    if (m_enemyList.empty())
    {
        ++m_waves;
        if (!loadWave())
        {
            m_gameWin = true;
            // 游戏胜利转到游戏胜利场景
            // 这里暂时以打印处理
        }
    }
}

void GameWindow::removedBullet(Bullet *bullet)
{
    Q_ASSERT(bullet);

    m_bulletList.removeOne(bullet);
    delete bullet;
}

void GameWindow::addBullet(Bullet *bullet)
{
    Q_ASSERT(bullet);

    m_bulletList.push_back(bullet);
}

void GameWindow::updateMap()
{
    foreach (Enemy *enemy, m_enemyList)
        enemy->move();
    foreach (Tower *tower, m_towersList)
        tower->checkEnemyInRange();
    update();
}

void GameWindow::preLoadWavesInfo()
{
    QFile file(":/image/Waves.plist");
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "TowerDefense", "Cannot Open TowersPosition.plist");
        return;
    }

    PListReader reader;
    reader.read(&file);

    // 获取波数信息
    m_wavesInfo = reader.data();

    file.close();
}

bool GameWindow::loadWave()
{
    if (m_waves >= m_wavesInfo.size())
        return false;

    WayPoint *startWayPoint = m_wayPointsList.back();
    QList<QVariant> curWavesInfo = m_wavesInfo[m_waves].toList();

    for (int i = 0; i < curWavesInfo.size(); ++i)
    {
        QMap<QString, QVariant> dict = curWavesInfo[i].toMap();
        int spawnTime = dict.value("spawnTime").toInt();

        Enemy *enemy = new Enemy(startWayPoint, this);
        m_enemyList.push_back(enemy);
        QTimer::singleShot(spawnTime, enemy, SLOT(doActivate()));
    }

    return true;
}

QList<Enemy *> GameWindow::enemyList() const
{
    return m_enemyList;
}

void GameWindow::gameStart()
{
    loadWave();
}
