# TaFangWork
第一版说明
一、思路
1、homewindow->levelselect->gamewindow
2、自定义mybutton用于前两个界面的按钮
3、加载可以安放塔的位置TowerPosition(手动读入)

4、塔Tower
①目标是有多种功能的塔，目前只有一种普通塔
②点击塔的位置即可安装普通塔
对象有：坐标点，尺寸大小，图片，攻击范围，塔的攻击伤害值，攻击速度以及相关函数等。
5、敌人行走路线waypoint
路径节点

6、敌人Enemy
目标是多种敌人，生命值各不同，且有些类型敌人可攻击塔。目前只有一种最普通的敌人。
7、子弹bullet
规则：只对第一个发现的目标攻击，直到其离开攻击范围或者被消灭。
二、基本功能可以实现，但仍有很多小bug和需要完善的地方
举例：1、炮塔转动方向问题
2、敌人图片处理不当
3、界面上没有显示实时的具体数据
4、炮塔类型不丰富
5、炮塔升级拆除功能还没有
6、敌人类型不丰富
7、敌人没有实现攻击行为
8、还没有做多关卡
希望之后可以继续完善。

