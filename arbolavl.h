#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "nodoavl.h"

class ArbolAvl
{
public:
    NodoAvl* raiz;
    ArbolAvl();
    NodoAvl* Oraiz (); // get raiz
    void Praiz( NodoAvl *r); // set raiz
    NodoAvl* rotacionII(NodoAvl* n, NodoAvl* n1);
    NodoAvl* rotacionDD(NodoAvl* n, NodoAvl* n1);
    NodoAvl* rotacionDI(NodoAvl* n, NodoAvl* n1);
    NodoAvl* rotacionID(NodoAvl* n, NodoAvl* n1);

    NodoAvl* insertarAvl(NodoAvl* raiz, int dt, bool &hc);


    void dibujarArbol(NodoAvl *r, int h); // impresion en consola
    void insertar(int dato);
    void ObtenerGrafo(NodoAvl * raiz);
    string obtenerDot(NodoAvl*root); // reporte en graphviz
    // recorridos
    void preorden(NodoAvl* raiz);
    void postorden(NodoAvl * raiz);
    void inorden(NodoAvl* raiz);



};

#endif // ARBOLAVL_H
