#ifndef CLASEHASH_H
#define CLASEHASH_H
#include <QString>
#include <QList>
#include <stdlib.h>

using namespace std;
class ClaseHash
{
public:

    ClaseHash(int size);
    void addmember(QString palabra);
    void addmember2(QString palabra);
    bool buscar_pal(QString pal);
    void delete_member(QString palabra);
    int isMember(QString palabra);
    int bucket();
    double average();
    int buckets();

private:
    int count;
    int cantidad;
    int funcion3(QString pal);
    unsigned long hash(char *str);
    int funcion1(QString palabra);
    int funcion2(QString palabra);
    QList<QString> *elementos;

};

#endif // CLASEHASH_H
