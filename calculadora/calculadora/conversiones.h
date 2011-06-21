#ifndef CONVERSIONES_H
#define CONVERSIONES_H
#include <QString>
#include <QList>
#include <QStringList>
#include <math.h>

struct priori{
    char n1;
    char n2;
};

class conversiones
{
public:
    conversiones();
    QList<QString> numeros;
    QList<QString> operadores;
    QList<QString> posfija;

    QList<QString> tabla_prioridad;
    void convertir_pos_fija(QStringList simb);
    double resolver_pos_fija(QList<QString> numeros);
    double evaluar(int n1, int n2, QString operador);

    void guardar_numero_simbolo(char simb);
    void identificar_operador(QString simb,int indice, int fin);
    int verificar_prioridad(char operador);
    void mezclar();
private:
    int cuantos;
    int final_cadena;
};

#endif // CONVERSIONES_H
