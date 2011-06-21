#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QString>
//#include "grafo.h"
#include "lugares.h"
#include "mainwindow.h"

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = 0);
    void setGrafo(lugares *G ) { this->G = G; }

private:
    lugares *G;
    //Grafo *G;
    void dibujarNodo(hora n,QPainter &P);
    void dibujarArista(hora n1,hora n2, float peso, QPainter &P);
protected:
   void paintEvent(QPaintEvent *event);

public slots:

signals:

};

#endif // RENDERAREA_H
