#include "arbol.h"
#include <QDebug>
arbol::arbol()
{
   this->raiz = 0;
}
void arbol::add_Palabra(QString pal){
  if(this->raiz == 0){
      this->raiz = new nodo(pal);

  }else{
      aux_add(this->raiz,pal);
  }
}
void arbol::aux_add(nodo *n, QString pal){
    if(n==0){
      n = new nodo(pal);
  }else{
      if(pal < n->Palabra){
        aux_add(n->hijo_izq,pal);
      }else if(pal > n->Palabra){
        aux_add(n->hijo_dere,pal);
      }
  }
}

bool arbol::buscar_Palabra(QString pal){
    return aux_buscar(this->raiz,pal);
}

bool arbol::aux_buscar(nodo *n, QString pal){
    if(n == 0)
        return false;
    else if(pal < n->Palabra)
        return aux_buscar(n->hijo_izq,pal);
    else if(pal > n->Palabra)
        return aux_buscar(n->hijo_dere,pal);
    else
        return true;
}
