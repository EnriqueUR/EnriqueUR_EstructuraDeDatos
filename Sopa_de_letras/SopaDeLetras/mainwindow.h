#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QList>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <QMap>
#include <QTime>
#include <QMessageBox>
#include <QFileDialog>
#include <QtGui>
#include"puzzle.h"
#include <QApplication>

using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    puzzle *tab;


private:
    int cantidad;
    QTime tiempo;
    QMap<QString,QString> map_palabras;
    QStringList list_palabras;
    QList<QString> arr_palabras;
    void llenar_tabla(int cant);
    void llenar_array();
    void llenar_listaPalabras();
    Ui::MainWindow *ui;

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
