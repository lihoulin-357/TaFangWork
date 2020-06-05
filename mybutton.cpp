#include "mybutton.h"
#include <QPixmap>

myButton::myButton(QString pix):QPushButton(0)
{
   QPixmap pixmap(pix);
   this->setFixedSize(pixmap.width(),pixmap.height());
   this->setStyleSheet("QPushButton{border:0px;}");
   this->setIcon(pixmap);
   this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}
