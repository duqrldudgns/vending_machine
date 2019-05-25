#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbCola->setEnabled(false);
    ui->pbreset->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    changeEnabled();
}

void Widget::changeEnabled(){
    if (money>=100) ui->pbCoffee->setEnabled(true);
    else ui->pbCoffee->setEnabled(false);
    if (money>=150) ui->pbTea->setEnabled(true);
    else ui->pbTea->setEnabled(false);
    if (money>=200) ui->pbCola->setEnabled(true);
    else ui->pbCola->setEnabled(false);
    if (money>0) ui->pbreset->setEnabled(true);
    else ui->pbreset->setEnabled(false);
    }

void Widget::calculation(int &num, int coin){
    if (money >= coin){
        num = money / coin;
        money = money % coin;
    }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbCola_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbreset_clicked()
{
    char str[100];
    int num1=0;
    int num2=0;
    int num3=0;
    int num4=0;
    QMessageBox msg;

    calculation(num1,500);
    calculation(num2,100);
    calculation(num3,50);
    calculation(num4,10);

    sprintf(str,"Change Money \n 500won count : %d \n 100won count : %d \n 50won count : %d \n 10won count : %d",num1,num2,num3,num4);
    msg.information(nullptr,"reset", str);

    changeMoney(-money);
}
