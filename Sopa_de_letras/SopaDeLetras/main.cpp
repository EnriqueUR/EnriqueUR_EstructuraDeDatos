#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QString>
#include <QStringList>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
      MainWindow w;
      w.show();

    return a.exec();
}
