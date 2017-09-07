#include "dialog.h"
#include "ui_dialog.h"
#include <QtGui>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->pwdLineEdit->setEchoMode(QLineEdit::Password);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_loginBtn_clicked()
{
    if(ui->usrLineEdit->text()==tr("yyj")&&ui->pwdLineEdit->text()==tr("1020"))
        accept();
    else
        if(ui->usrLineEdit->text()==tr("zmy")&&ui->pwdLineEdit->text()==tr("0504"))
            accept();
    else
    {
       QMessageBox::warning(this,tr("撒比"),tr("你的名字和口令都不知道么!"),QMessageBox::Yes);
        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
    }
}
