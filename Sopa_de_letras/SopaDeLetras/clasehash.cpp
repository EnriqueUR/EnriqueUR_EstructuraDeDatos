#include "clasehash.h"
#include <QDebug>

ClaseHash::ClaseHash(int tam)
{
    cantidad = tam;
    elementos = new QList<QString>[tam];
}
void ClaseHash::addmember(QString palabra){
    int num = funcion1(palabra);
    if(isMember(palabra)== -1){
        elementos[num].push_back(palabra);
    }
}

void ClaseHash::addmember2(QString palabra){
    int num = funcion3(palabra);
    elementos[num].push_back(palabra);
}

void ClaseHash::delete_member(QString palabra)
{
    int num = funcion1(palabra);
    elementos[num].removeAt(isMember(palabra));
}
bool ClaseHash::buscar_pal(QString palabra){
    int num = funcion3(palabra);
    for(int i =0;i < elementos[num].count();i++){
        if(elementos[num].at(i)==palabra){
        return true;
        }
    }
}

int ClaseHash::isMember(QString palabra){
    int num = funcion1(palabra);
    for(int i=0; i < elementos[num].count(); i++){
        if(elementos[num].at(i)==palabra){
            return i;
        }
    }
    return -1;
}

int ClaseHash::funcion1(QString palabra){
    int suma =0;
    for(int i=0;i < palabra.count();i++){
        suma += palabra.at(i).toAscii();
    }
    return suma%(cantidad);
}

int ClaseHash::funcion2(QString palabra){
    int suma=0;
    for(int i=0; i < palabra.count();i++){
        suma += (palabra.at(i).toAscii() + (palabra.at(i).toAscii()<<2))+(palabra.at(i).toAscii()<<4);

    }
     return suma%cantidad;
}

unsigned long hash(char *str)
   {
       unsigned long hash = 5381;
       int c;

       while(c = *str++)
           hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

       return hash;
   }

int ClaseHash::bucket(){
    int temp=0;
    for(int i=0; i < cantidad;i++){
        if(elementos[i].count()!=0)
            if(elementos[i].count()>temp){
                temp=elementos[i].count();
            }
    }
    return temp;

}
int ClaseHash::funcion3(QString pal){
    unsigned int hash=0;
    int i;
      for (i=0; i<pal.length(); ++i)
      {
        hash += pal.at(i).toAscii();
        hash += (hash << 2);
        hash ^= (hash >> 6);
      }
      hash += (hash << 1);
      hash ^= (hash >> 2);
      hash += (hash << 4);
      return (hash%cantidad);
}

int ClaseHash::buckets(){
    int suma=0;
    for(int i=0; i < cantidad;i++){
        if(elementos[i].count()==0)
            suma++;
    }
    return suma;
}

double ClaseHash::average(){
    double suma=0.0;
    double disp=0.0;
    double promedio=0.0;
    for(int i=0; i < cantidad;i++){
        if(elementos[i].count()!=0){
            suma = suma + elementos[i].count();
            disp++;
        }
    }
    promedio = suma/disp;
    qDebug()<<promedio;
    return promedio;

}

