#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto w = new MainWindow(); // deletes itself on close
    w->show();
    return a.exec();
}
