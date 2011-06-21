#ifndef LUGARES_H
#define LUGARES_H

#include <QList>
#include <QVector>
#include <QString>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct hora{
    int x,y;
    int peso;
    QString lugar;
};

struct dia{
    hora horas[24];
};

struct lugar{
    dia dias[7];
};

class lugares
{
public:
    lugares(int cantidad_nodos);
    float **matriz;
    //lugar *destinos;
    int _tamano;


    hora getNodo(int i);
    int getSize() { return _tamano; }
    void set_dia_hora(int dia, int hora);
    float getPesoArista(int nodo1, int nodo2);

    QList<lugar> destinos;
    //estas funciones agragan los datos a la estructura
    void generarPosicionesRandom(int ancho,int alto);
    bool agregar_destino(int peso, QString l1);
    bool borrar_destino(QString l1);
    bool modificar_destino(int peso, QString l1);
    int existe_destino(QString l1);

    //estas funciones agragan a la matriz
    void addArista(int nodo1, int nodo2, float peso);
    void removeArista(int nodo1, int nodo2);
    void setPesoArista(int nodo1, int nodo2,float peso);
    void addtodo();

    static const float INFINITO = 99999.00;

private:
    int _dia;
    int _hora;



};

#endif // LUGARES_H
