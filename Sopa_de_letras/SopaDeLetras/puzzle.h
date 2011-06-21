#ifndef PUZZLE_H
#define PUZZLE_H
#include <QString>
#include "arbol.h"
#include <QStringList>
#include <QMap>
#include <QPair>
#include <QHash>
#include <QTime>
#include <clasehash.h>

class puzzle
{
public:
    ClaseHash *hash;
    QTime  tiempos;
    QString **tablero;
    arbol *arb;
    QStringList list_palabras;
    puzzle(int cantidad_hash, int cantidad_arreglo);
    int espacio_hash;
    arbol *matriz_hash;
    void Resolver_puzzle();
    void llenar_tablero(QList<QString> puzzle);
    void Agregar_palabra(QStringList pal);

private:
    QList<QString> palabras;
    int minimo;
    int maximo;
    int minimo2;
    int tamanio;
    void super_recorrido(QList<QString> palabras, int f, int c, int c2);
    void recorrido_diagonales(QStringList palabras, int f, int f2, int c, int c2);
    QMap<QString,QString> map_palabras;
    //uint32_t SuperFastHash (const char * data, int len);
    int funcion_primera(QString pal);


};

#endif // PUZZLE_H
