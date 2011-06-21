#include "lugares.h"

lugares::lugares(int cantidad_nodos)
{
    int fila;
    _tamano = cantidad_nodos;

    matriz = new float*[cantidad_nodos]; // Esto crea todas las filas
    for (fila=0; fila<cantidad_nodos; fila++)
    {
        matriz[fila] = new float[cantidad_nodos]; // Esto crea todas las columnas
    }

    for(int i=0; i<cantidad_nodos; i++) // Inicializar el la matriz con ceros en diagonal e infinito el resto
      for(int j=0; j<cantidad_nodos; j++)
        if(i==j)
          matriz[i][j]=0.0;
        else
          matriz[i][j]=INFINITO;

    // Inicializar el indice de nodos
    //lugares = new lugar[cantidad_nodos];

    // Semilla de numeros aleatorios
    srand(time(0));



}

void lugares::addArista(int nodo1, int nodo2, float peso)
{
    // Si la  arista ya existe, entonces no hacer nada
    if(nodo1!=nodo2)
    {
       this->matriz[nodo1][nodo2] = peso;
       this->matriz[nodo2][nodo1] = peso;
    }
}

void lugares::removeArista(int nodo1, int nodo2)
{
    if(nodo1!=nodo2 )
    {
        this->matriz[nodo1][nodo2] = INFINITO;
        this->matriz[nodo2][nodo1] = INFINITO;
    }
}

void lugares::setPesoArista(int nodo1, int nodo2,float peso)
{
    if(nodo1!=nodo2 && this->matriz[nodo1][nodo2]!= INFINITO)
    {
       this->matriz[nodo1][nodo2] = peso;
       this->matriz[nodo2][nodo1] = peso;
    }
}

void lugares::addtodo(){
    int dia = this->_dia;
    int hora = this->_hora;
    for(int i = 0 ; i < this->destinos.count(); i++){
        int num1 = 0;
        int num2 = 0;
        int peso =0;
        num1 = destinos.at(i).dias[dia].horas[hora].x;
        num2 = destinos.at(i).dias[dia].horas[hora].y;
        peso = destinos.at(i).dias[dia].horas[hora].peso;

        if(num1 !=0 && num2 != 0 && peso !=0)
            addArista(num1,num2,peso);
    }
}



int lugares::existe_destino(QString l1){
    for(int i = 0; i < this->destinos.count(); i++){
        if(this->destinos.at(i).dias[this->_dia].horas[this->_hora].lugar == l1){
            return i;
        }
    }
    return -1;
}

bool lugares::modificar_destino(int peso, QString l1){
    int num = existe_destino(l1);
    if(num != -1){
       // this->destinos[num].dias[this->_dia].horas[this->_hora].peso = peso;
        return true;
    }else{
        return false;
    }

}

bool lugares::agregar_destino(int peso, QString l1){
    int num = existe_destino(l1);
    if(num == -1){
        lugar l ;
        l.dias[this->_dia].horas[this->_hora].lugar = l1;
        this->destinos.push_back(l);
        return true;
    }else{
        return false;
    }
}

bool lugares::borrar_destino(QString l1){
    int num = existe_destino(l1);
    if(num != -1){
       // this->destinos[num].dias[this->_dia].horas[this->_hora].peso = INFINITO;
        return true;
    }else{
        return false;
    }
}

void lugares::generarPosicionesRandom(int ancho,int alto)
{
     for(int i=0; i < this->_tamano; i++)
     {
       bool colision=true;
       int cont=0;
       int candidato_x, candidato_y;
       while(colision&&cont<=2) // intentos
       {
           candidato_x = rand()% ancho;
           candidato_y = rand()% alto;
           // Este metodo chequea contra el resto sino colisiona
           // Hasta el nodo i
           /*if (!checkColision(i,candidato_x,candidato_y))
                colision=false;
           else
               cont++;*/
       }
       this->destinos[i].dias[_dia].horas[_hora].x = candidato_x;
       this->destinos[i].dias[_dia].horas[_hora].y = candidato_y;

     }

}

void lugares::set_dia_hora(int dia, int hora){
    this->_dia = dia;
    this->_hora = hora;
}

hora lugares::getNodo(int i){
   hora n;
   n=this->destinos.at(i).dias[this->_dia].horas[this->_hora];
   return n;
}
float lugares::getPesoArista(int nodo1, int nodo2){
    return this->matriz[nodo1][nodo2];
}
