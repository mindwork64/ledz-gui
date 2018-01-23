#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/qmath.h>
#include <QObject>


float uSrc; // Напряжение источника питания
int iLed; // Ток диода
int vResList[] = {10,11,12,13,15,16,18,20,22,24,27,30,33,36,39,43,47,51,56,62,68,75,82,91,100,110,120,130,150,160,180,200,220,240,270,300,330,360,390,430,470,510,560,620,680,750,820,910,1000,1100,1200,1300,1500,1600,1800,2000,2200,2400,2700,3000,3300,3600,3900,4300,4700,4750,5100,5600,6200,6800,7500,8200,9100,10000,11000,12000,13000,15000,16000,18000,20000,22000,24000,27000,30000,33000,36000,39000,43000,47000,51000,56000,62000,68000,75000,82000,91000,100000,110000,120000,130000,150000,160000,180000,200000,220000,240000,270000,300000,330000,360000,390000,430000,470000,510000,560000,620000,680000,750000,820000,910000,1000000,1100000,1200000,1300000,1500000,1600000,1800000,2000000,2200000,2400000,2700000,3000000,3300000,3600000,3900000,4300000,4700000,4750000,5100000};
float uLed; // Прямое напряжение диода
float iCalcRes;
float iAbsRes;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnCalc_clicked()
{
    uSrc = (ui->uSrcBox->toPlainText()).toFloat();
    uLed = (ui->uLedBox->toPlainText()).toFloat();
    iLed = (ui->iLedBox->toPlainText()).toInt();

    if ((float)uLed > (float)uSrc)
    {
        ui->lStatus->setStyleSheet("QLabel { color : red; }");
        ui->lStatus->setText(tr("Напряжение диода выше напряжения источника!"));
    }

    QString qResLed;
    QString qResWatt;
    QString qAbsRes;
    float fResLed = (uSrc - uLed) / ((float)iLed / 1000);
    float fResWatt = (qPow(iLed, 2) * fResLed) / 1000;

    QString wattMul;
    if (fResWatt >= 1000)
    {
        fResWatt = fResWatt / 1000;
        wattMul = tr(" Вт");
    }

    else if (fResWatt < 1000)
    {
        wattMul = tr(" мВт");
    }

    iCalcRes = qCeil(fResLed);

    int index = 0;
    do
    {
        index++;
    }
    while (iCalcRes >= vResList[index]);
    iAbsRes = vResList[index];
    QString resMul;
    if (iAbsRes >= 1000)
    {
        iAbsRes = iAbsRes / 1000;
        resMul = tr(" кОм");
    }
    else if (iAbsRes < 1000)
    {
        resMul = tr(" Ом");
    }

    ui->fResLedBox->setText(qResLed.setNum(fResLed) + resMul);
    ui->iAbsResBox->setText(qAbsRes.setNum(iAbsRes) + resMul);
    ui->wResWattBox->setText(qResWatt.setNum(fResWatt) + wattMul);

}
