#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   // w.setStyleSheet("background-image: url(/home/ziom/Завантаження/siniy_pyatna_fon_odnotonnyy_2560x1600.jpg)");
    w.show();

    return a.exec();
}
