#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent)
{
}

void RenderArea::dibujarNodo(hora n,QPainter &P)
{
    P.setPen(Qt::black);
    P.setBrush(Qt::yellow);
    P.drawEllipse(QPointF(n.x,n.y),12,12);
    P.drawText(n.x-9,n.y+5,n.lugar);
}

void RenderArea::dibujarArista(hora n1,hora n2, float peso, QPainter &P)
{
    P.setPen(Qt::black);
    P.drawLine(n1.x,n1.y,n2.x,n2.y);
    int midX, midY;
    midX = (n1.x+n2.x)/2;
    midY = (n1.y+n2.y)/2;
    QString temp;
    temp.setNum(peso,'f',1);
    P.drawText(midX,midY,temp);
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter( this ); // Inicializar el Painter
    painter.setPen( Qt::black ); // La pluma en como vamos a dibujar es negra
    painter.setBrush(Qt::white);
    painter.drawRect(0,0,this->width()-1,this->height()-1);
    qDebug() << this->height();
    //TODO : Logica para pintar el grafo
   for (int i=0;i<G->getSize();i++)
    {
       hora n = G->getNodo(i);
       //Primero dibujar todas las aristas que salen de el
       //
           for (int j=i+1;j<G->getSize();j++)
            {
               if (G->getPesoArista(i,j)!=lugares::INFINITO)
                   this->dibujarArista(n,G->getNodo(j),G->getPesoArista(i,j),painter);
            }
            this->dibujarNodo(n,painter);

    }
}
