#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include <iostream>
#include <estudiante.h>
using namespace  std;

class nodomatriz
{
public:
       nodomatriz* arriba;
       nodomatriz* abajo;
       nodomatriz* derecha;
       nodomatriz* izquierda;
       nodomatriz* afuera;
       nodomatriz* adentro;
       int posX;
       int posY;
       string nombre;
       estudiante * infoestu;
       nodomatriz(nodomatriz*, nodomatriz*, nodomatriz*, nodomatriz*, nodomatriz*, nodomatriz*, int, int, string, estudiante*);

};

#endif // NODOMATRIZ_H
