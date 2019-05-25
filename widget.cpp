#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
}

void Widget::Minimum(){
    if (money>=100) ui->pbCoffee->setEnabled(true);
    if (money<100) ui->pbCoffee->setEnabled(false);
    if (money>=150) ui->pbTea->setEnabled(true);
    if (money<150) ui->pbTea->setEnabled(false);
    if (money>=200) ui->pbCola->setEnabled(true);
    if (money<200) ui->pbCola->setEnabled(false);
    if (money>0) ui->pbreset->setEnabled(true);
    if (money==0) ui->pbreset->setEnabled(false);
    }

void Widget::change(int &num, int coin){
    if (money >= coin){
        num = money / coin;
        money = money % coin;
    }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
    Minimum();
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
    Minimum();
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
    Minimum();
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
    Minimum();
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
    Minimum();
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
    Minimum();
}

void Widget::on_pbCola_clicked()
{
    changeMoney(-200);
    Minimum();
}

void Widget::on_pbreset_clicked()
{
    char str[100];
    int num1=0;
    int num2=0;
    int num3=0;
    int num4=0;
    QMessageBox msg;

    change(num1,500);
    change(num2,100);
    change(num3,50);
    change(num4,10);

    sprintf(str,"Change Money \n 500won count : %d \n 100won count : %d \n 50won count : %d \n 10won count : %d",num1,num2,num3,num4);
    msg.information(nullptr,"reset", str);

    changeMoney(-money);
    Minimum();
}
