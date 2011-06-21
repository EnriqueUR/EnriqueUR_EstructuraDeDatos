#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "renderarea.h"
#include "conectar.h"
#include "lugares.h"
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    RenderArea *AreaRender;
    conectar *C;


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
