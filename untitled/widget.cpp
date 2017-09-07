/*#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}*/


#include "widget.h"
#include "ui_widget.h"
#include <time.h>


Widget::Widget(QWidget *parent)
    : QWidget(parent),
   ui(new Ui::Widget)
{   f=0;
     ui->setupUi(this);
   // resize(600, 600);
    this->setFixedSize(600,600);

     //Background
    background=new QLabel(this);
    background->setFixedSize(600, 600);



    picLabel = new QLabel(this);
    picLabel->setFixedSize(50, 50);



}
//将图片画在label
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
     srand((unsigned) time(NULL));
     if(f==0)
    {pix.load("E:/QT/mycode/untitled/cat1.jpg");//图片的位置
     f=1;}
     else
     { pix.load("E:/QT/mycode/untitled/cat2.jpg");
        f=0;
     }

     QPainter painter2(this);
     QPixmap pix2;
     pix2.load("E:/QT/mycode/untitled/room.jpg");
     painter2.drawPixmap(0,0,600,600,pix2);

    painter.drawPixmap(picLabel->x(),picLabel->y(),picLabel->width(),picLabel->height(),pix);
}

void Widget::keyPressEvent(QKeyEvent *event)
{

    int x = 0;
    int y = 0;
    switch (event->key()) {
    case Qt::Key_Up:
        y = picLabel->y() - 10;
        if(y > -10)
            picLabel->move(picLabel->x(), y);//向上移动就是x不变y减小
        break;
    case Qt::Key_Down:
        y = picLabel->y() + 10;
        if(y < this->height() - 40)
        {
            picLabel->move(picLabel->x(), y);//向下移动是x不变y 变大
        }
        break;
    case Qt::Key_Right:
        x = picLabel->x() + 10;
        if(x < this->width() - 40)
        {
            picLabel->move(x, picLabel->y());
        }
        break;
    case Qt::Key_Left:
        x = picLabel->x() - 10;
        if(x > -10)
            picLabel->move(x, picLabel->y());
        break;
    default:
        break;
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
}

Widget::~Widget()
{

}
