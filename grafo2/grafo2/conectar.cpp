#include "conectar.h"

conectar::conectar(int nodos, int ancho, int alto)
{
    //this->alcance = alcance;
    this->L = new lugares(nodos);
    this->L->generarPosicionesRandom(ancho,alto);
    //Esto calcula las distancias entre todo par de nodos
   // this->L->calcularDistancias();
    // Sin embargo para efectos de la red inlambrica debemos
    // quitar todas aquellas aristas cuyo peso sea mayor al del alcance.
   // this->removeAristasMayoresAlcance();
}
