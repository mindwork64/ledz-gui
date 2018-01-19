#include "mainwindow.h"
#include "ui_mainwindow.h"


float uSrc; // Напряжение источника питания
int iLed; // Ток диода
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
    QString qOut;
    ui->wResWattBox->setText(qOut.setNum(uSrc));
    if ((float)uLed > (float)uSrc)
    {
        ui->lStatus->setStyleSheet("QLabel { color : red; }");
        ui->lStatus->setText(tr("Напряжение диода выше напряжения источника!"));
    }
}
