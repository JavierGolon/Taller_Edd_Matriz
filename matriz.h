#ifndef MATRIZ_H
#define MATRIZ_H
#include "nodomatriz.h"
#include <iostream>
#include <fstream>
using namespace std;

class matriz
{
public:
    matriz();
    bool agregarUsuario(string, int, int, string, string); // insertar
    bool verificarExistencia(string, string, string);
    estudiante* validarSesion(string, string, string, string);
    string recorrerMatriz();
    string catalogoDeActivos();
    estudiante* cambiarEstadoActivo(string, string, string);
    estudiante* devolverUsuario(string, string, string);
    estudiante activosDeEmpresa(string);
    string activosDeDepartamento(string);
    //Activo* buscarActivo(string);
    string recorrerDepartamentos();
    string recorrerEmpresas();
    string usuariosMatriz();
    void reporteMatriz();

private:
    nodomatriz* origen;
    bool verificarCabecerasHorizontales(string);
    bool verificarCabecerasVerticales(string);
    void crearCabeceraHorizontal(string);
    void crearCabeceraVertical(string);
    nodomatriz* buscarDepartamento(string); //  obtener columna
    nodomatriz* buscarEmpresa(string); // obtener fila





};

#endif // MATRIZ_H
