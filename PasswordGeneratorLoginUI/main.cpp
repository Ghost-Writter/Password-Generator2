/*

    Цель работы – реализация простейшего генератора паролей,
    обладающего основными требованиями к парольным генераторам.

*/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));

    MainWindow w;
    w.show();

    return a.exec();
}
