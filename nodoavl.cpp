#include "nodoavl.h"

NodoAvl::NodoAvl(int valor)
{
     this->dato = valor;
     this->izdo =this->dcho= NULL;
     this->fe = 0;
}
//-------------------------------------

int NodoAvl::valorNodo(){
    return dato;
}

NodoAvl* NodoAvl::subarbolIzdo(){
    return this->izdo;
}


NodoAvl* NodoAvl::subarbolDcho(){
    return this->dcho;
}


void NodoAvl::ramaIzdo(NodoAvl *n){
    this->izdo = n;
}

void NodoAvl::ramaDcho(NodoAvl *n){
    this->dcho =n;
}



void NodoAvl::Pfe(int vfe){
    this->fe = vfe;
}

int NodoAvl::Ofe(){
    return this->fe;
}



