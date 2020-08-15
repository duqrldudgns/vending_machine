#include "widget.h"
#include "ui_widget.h"
#include "QMessageBox"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbReset->setEnabled(false);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    this->ui->lcdNumber->display(money);
    Widget::changeEnabled();
}

void Widget::changeEnabled(){
    if (money > 0) ui->pbReset->setEnabled(true);
    else ui->pbReset->setEnabled(false);
    if (money >= 100) ui->pbCoffee->setEnabled(true);
    else ui->pbCoffee->setEnabled(false);
    if (money >= 150) ui->pbTea->setEnabled(true);
    else ui->pbTea->setEnabled(false);
    if (money >= 200) ui->pbMilk->setEnabled(true);
    else ui->pbMilk->setEnabled(false);
}

void Widget::on_pb10_clicked()
{
    Widget::changeMoney(10);
}

void Widget::on_pb100_clicked()
{
    Widget::changeMoney(100);
}

void Widget::on_pb50_clicked()
{
    Widget::changeMoney(50);
}

void Widget::on_pb500_clicked()
{
    Widget::changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    Widget::changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    Widget::changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    Widget::changeMoney(-200);
}

void Widget::calculation(int *change_money)
{
    int value[4]={500,100,50,10};

    for(int i=0; i<4; i++){
        change_money[i] = money / value[i];
        money = money % value[i];
    }
}

void Widget::on_pbReset_clicked()
{
    QMessageBox m;
    char str[100];
    int change[4];

    Widget::calculation(change);

    sprintf(str,"Change Money \n500won count : %d \n100won count : %d \n50won count : %d \n10won count : %d ", change[0], change[1], change[2], change[3]);
    m.information(nullptr,"Reset", str);

    Widget::changeMoney(-money);
}
