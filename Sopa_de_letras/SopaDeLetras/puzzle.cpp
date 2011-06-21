#include "puzzle.h"
#include <QDebug>


puzzle::puzzle(int cantidad_hash, int cantidad_arreglo)
{
    tablero = new QString*[cantidad_arreglo];
    for(int i=0;i < cantidad_arreglo; i++){
        tablero[i]= new QString[cantidad_arreglo];
    }
    this->hash = new ClaseHash(cantidad_hash);
    this->espacio_hash = cantidad_hash;
    this->tamanio = cantidad_arreglo;
    this->minimo = 1;//este es el minimo para las horizontales y verticales
    this->minimo2 = 1;//este es el minimo para las diagonales
    this->maximo = 15;//y este es el maximo para todaslas direcciones

    for(int i=0; i < 8;i++){
        palabras.push_back("");
    }
}

void puzzle::llenar_tablero(QList<QString> puzzle){
    for(int f=0;f<puzzle.count();f++){
        for(int c=0;c<puzzle.at(f).count();c++){
            this->tablero[f][c]=puzzle.at(f).at(c).toLower();
        }
    }
}

void puzzle::Resolver_puzzle(){
    for(int f =0,f2=this->tamanio-1; f < this->tamanio; f++, f2--){
       for(int c=0, c2 = this->tamanio -1; c < this->tamanio; c++, c2--){
           super_recorrido(palabras,f,c,c2);
           for(int i=0; i < 4;i++){
               palabras[i]="";
           }
           palabras[4] = tablero[f][c];
           palabras[5] = tablero[f][c2];
           palabras[6] = tablero[f2][c2];
           palabras[7] = tablero[f2][c];
           recorrido_diagonales(palabras,f,f2,c,c2);
          for(int i=4; i < 8;i++){
              palabras[i]="";
          }
       }
   }
}

void puzzle::super_recorrido(QList<QString> palabras, int f,int c, int c2){
    for(int i=c, i2 = c2; i <this->tamanio;i++,i2--){
        if(palabras.at(1).count()<=this->minimo){
            palabras[0]+= tablero[f][i];
            palabras[1]+= tablero[f][i2];
            palabras[2]+= tablero[i][f];
            palabras[3]+= tablero[i2][f];
        }else if(palabras.at(1).count()>=this->maximo){
            break;
        }else{
            palabras[0]+= tablero[f][i];
            palabras[1]+= tablero[f][i2];
            palabras[2]+= tablero[i][f];
            palabras[3]+= tablero[i2][f];
            for(int i =0; i < 4; i++){
                if(hash->buscar_pal(palabras.at(i))){
                    list_palabras.push_back(palabras.at(i));
                }
            }
       }
    }
}

void puzzle::recorrido_diagonales(QStringList palabras, int f,int f2, int c, int c2){
    int temp = this->tamanio-1;
    for(int i=c,i2 = c2;i<temp;i++,i2--){
        if(f >= 0 && f < temp){

        if(palabras.at(4).count()<=this->minimo2){
            palabras[4]+=tablero[f+1][i+1];
            palabras[5]+=tablero[f+1][i2-1];
            palabras[6]+=tablero[f2-1][i2-1];
            palabras[7]+=tablero[i2-1][f+1];
            f = f+1;
            f2 = f2 -1;

        }else if(palabras.at(4).count()>=this->maximo)
            break;
        else{
            palabras[4]+=tablero[f+1][i+1];
            palabras[5]+=tablero[f+1][i2-1];
            palabras[6]+=tablero[f2-1][i2-1];
            palabras[7]+=tablero[i2-1][f+1];
            for(int i =4; i < 8; i++){
                if(hash->buscar_pal(palabras.at(i))){
                    list_palabras.push_back(palabras.at(i));
                }
            }
            f = f+1;
            f2 = f2 -1;
        }
    }else{
        break;
    }
    }
}
void puzzle::Agregar_palabra(QStringList pal)
{
   for(int i=0 ; i < pal.count(); i++){
       this->hash->addmember2(pal.at(i));
   }
}

int puzzle::funcion_primera(QString pal){
    int sum =0;
       for(int i=0 ; i < pal.length(); i++){
           sum += pal.at(i).toAscii();
       }

       return sum%(this->espacio_hash);
}


