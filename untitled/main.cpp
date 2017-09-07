#include <qapplication.h>
#include <qpushbutton.h>
#include <qwidget.h>
#include <qfont.h>
#include <qlabel.h>

#include <qlcdnumber.h>
#include <qslider.h>

#include <QMovie>
#include <QGridLayout>
#include <qlineedit.h>
#include <qstring.h>

#include "widget.h"
#include "dialog.h"

class MyMainWindow:public QWidget
{
public:
    MyMainWindow();
private:
    QPushButton *b1;
    QPushButton *exit;
    QLCDNumber *lcd;
    QSlider *slider;
    QLineEdit *ledit;


};
MyMainWindow::MyMainWindow()
{
   setGeometry(200,200,1000,700);

   ledit=new QLineEdit("this will show you!",this);
   ledit->setGeometry(400,500,280,30);


   b1=new QPushButton("进入游戏",this);
   b1->setGeometry(200,200,160,80);
   b1->setFont(QFont("Times",18,QFont::Bold));
   connect(b1,SIGNAL(clicked(bool)),ledit,SLOT(clear()));


   exit=new QPushButton("退出游戏",this);
   exit->setGeometry(200,300,160,80);
   exit->setFont(QFont("Times",18,QFont::Bold));
   connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));

   lcd=new QLCDNumber(2,this);
   lcd->setGeometry(200,390,190,180);

   slider=new QSlider(Qt::Horizontal,this);
   slider->setGeometry(5,5,80,130);
   connect(slider,SIGNAL(valueChanged(int)),lcd,SLOT(display(int)));

       QLabel *gif_label = new QLabel();
       QLabel *prompt_label = new QLabel();
       QGridLayout *grid_layout = new QGridLayout;
       grid_layout->addWidget(gif_label, 1, 1, Qt::AlignCenter);
       grid_layout->addWidget(prompt_label, 2, 1, Qt::AlignCenter);
       QMovie *movie = new QMovie("E:/QT/mycode/untitled/cat.gif");
       gif_label->setMovie(movie);
       gif_label->setGeometry(100,0,190,190);
       movie->start();
       setLayout(grid_layout);

}

class MyMainWindow2:public QWidget
{
public:
    MyMainWindow2();
private:
    QPushButton *b1;
};

MyMainWindow2::MyMainWindow2()
{
    setGeometry(100,100,200,100);
    b1=new QPushButton("this is big \n big man \n big big\n",this);
    b1->setGeometry(10,10,180,80);
    b1->setFont(QFont("Times",18,QFont::Bold));
}

int main(int argc,char **argv)
{
       QApplication a(argc,argv);
       MyMainWindow w;
       a.setActiveWindow(&w);
       w.show();
       MyMainWindow2 w2;
       w2.show();
         Widget w3;
        // w3.show();
       Dialog w4;
       if(w4.exec()==QDialog::Accepted)
       {
           w3.show();
            return a.exec();
       }
        else return 0;

      //return a.exec();




}
