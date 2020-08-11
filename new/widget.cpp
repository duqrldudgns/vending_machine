#include "widget.h"
#include "ui_widget.h"
#include "QMessageBox"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pb10_clicked()
{
    //changeMoney(10);
}

void Widget::on_pb100_clicked()
{
    money += 100;
    this->ui->lcdNumber->display(money);
}

void Widget::on_pb50_clicked()
{
    money += 50;
    this->ui->lcdNumber->display(money);
}

void Widget::on_pb500_clicked()
{
    money += 500;
    this->ui->lcdNumber->display(money);
}

void Widget::on_pbCoffee_clicked()
{
    money -= 100;
    this->ui->lcdNumber->display(money);
}

void Widget::on_pbTea_clicked()
{
    money -= 150;
    this->ui->lcdNumber->display(money);
}

void Widget::on_pbMilk_clicked()
{
    money -= 200;
    this->ui->lcdNumber->display(money);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox m;
    m.information(nullptr,"Reset", "10 : 100 : 50 : 500 :");
}
