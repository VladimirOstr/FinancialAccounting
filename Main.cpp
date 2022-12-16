#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataStorage *data = new DataStorage();
    MainWindow w(data);
    w.show();
    return a.exec();
}
