#include "widget.h"
#include "ui_widget.h"
#include "QMessageBox"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeEnabled();
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

void Widget::calculation(QString &str)
{
    int change[4];
    int value[4]={500,100,50,10};
    str = QString("Change Money \n500won count : %1 \n100won count : %2 \n50won count : %3 \n10won count : %4");

    for(int i=0; i<4; i++){
        change[i] = money / value[i];
        money = money % value[i];

        str = str.arg(change[i]);
    }
}

void Widget::on_pbReset_clicked()
{
    QMessageBox m;
    QString str;

    Widget::calculation(str);
    m.information(nullptr,"Reset", str);

    Widget::changeMoney(-money);
}
