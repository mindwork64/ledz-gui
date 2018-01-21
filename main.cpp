#include <iostream>
#include <cmath>
#include <string>
#include "mainwindow.h"
#include <QApplication>
#include <QtCore/QTextCodec>
#include <QtCore/qmath.h>

using namespace std;



int main(int argc, char *argv[])
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("System"));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
