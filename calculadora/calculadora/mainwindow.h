#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "conversiones.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     conversiones *C;
     void enviar();

private:
    Ui::MainWindow *ui;

private slots:
    void on_btres_6_clicked();
    void on_btres_2_clicked();
    void on_btres_3_clicked();
    void on_btres_5_clicked();
    void on_btres_4_clicked();
    void on_btres_8_clicked();
    void on_btres_7_clicked();
    void on_bcero_clicked();
    void on_bnueve_clicked();
    void on_bocho_clicked();
    void on_bsiete_clicked();
    void on_bseis_clicked();
    void on_bcinco_clicked();
    void on_bcuatro_clicked();
    void on_btres_clicked();
    void on_bdos_clicked();
    void on_buno_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
