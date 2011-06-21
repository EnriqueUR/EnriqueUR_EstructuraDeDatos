#ifndef ARBOL_H
#define ARBOL_H
#include <QString>
class nodo{
public:
    nodo(QString pal){this->Palabra = pal; this->hijo_dere =0;this->hijo_izq=0;}
    QString Palabra;
    nodo *hijo_izq;
    nodo *hijo_dere;
};

class arbol
{
public:
    arbol();
    void add_Palabra(QString pal);
    bool buscar_Palabra(QString pal);
    void remover_Palabra(nodo *n, QString pal);//talvez lo pongo

private:
     nodo *raiz;
     void aux_add(nodo *n, QString pal);
     bool aux_buscar(nodo *n, QString pal);
};

#endif // ARBOL_H
