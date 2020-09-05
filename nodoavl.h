#ifndef NODOAVL_H
#define NODOAVL_H
#include <iostream>
#include <string>
using namespace std;
#include "matriz.h"
class NodoAvl
{
protected:
 int dato;
 NodoAvl *izdo;
 NodoAvl *dcho;
 int fe;

public:
    NodoAvl(int dato);
    // operaciones de acceso
     int valorNodo();
     /* metodos propios */
     NodoAvl* subarbolIzdo(); // get izq
     NodoAvl* subarbolDcho(); // get derecho
     void ramaIzdo(NodoAvl* n); // set izq
     void ramaDcho(NodoAvl* n); // set derecho
     void Pfe(int vfe); // set
     int Ofe(); // get



};

#endif // NODOAVL_H
