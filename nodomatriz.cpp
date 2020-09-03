#include "nodomatriz.h"

nodomatriz::nodomatriz(nodomatriz* arr, nodomatriz* ab, nodomatriz* der, nodomatriz* izq, nodomatriz* af, nodomatriz* ade, int px, int py, string name, estudiante* estu)
{
    this->arriba = arr;
    this->abajo = ab;
    this->izquierda = izq;
    this->derecha = der;
    this->afuera = af;
    this->adentro = ade;
    this->posX = px;
    this->posY = py;
    this->nombre = name;
    this->infoestu = estu;
}



