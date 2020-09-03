#include "matriz.h"

matriz::matriz()
{
this->origen = new nodomatriz(NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, "Origen", NULL);

}
// metodo verificar las cabeceras horinzontales

bool matriz::verificarCabecerasHorizontales(string depa){
    nodomatriz* aux = this->origen;

        if(aux->derecha == NULL){
            return false;
        }else{
            while(aux != NULL){
                if(aux->nombre == depa){
                    return true;
                }
                aux = aux->derecha;
            }
            return false;
        }
}
 // insertar cabecera horizontal

void matriz::crearCabeceraHorizontal(string depa){
    if(verificarCabecerasHorizontales(depa) == false){
            nodomatriz* aux = this->origen;
            int x = 1;
            while(aux->derecha != NULL){
                aux = aux->derecha;
                x++;
            }
            aux->derecha = new nodomatriz(NULL, NULL, NULL, aux, NULL, NULL, x, 0, depa, NULL);
        }
}


// verificar cabecera vertical
bool matriz::verificarCabecerasVerticales(string empresa){
    nodomatriz* aux = this->origen;

    if(aux->abajo == NULL){
        return false;
    }else{
        while(aux != NULL){
            if(aux->nombre == empresa){
                return true;
            }
            aux = aux->abajo;
        }
        return false;
    }
}

// insertar cabecera vertical

void matriz::crearCabeceraVertical(string empresa){
    if(verificarCabecerasVerticales(empresa) == false){

        nodomatriz* aux = this->origen;
        int y = 1;
        while(aux->abajo != NULL){
            aux = aux->abajo;
            y++;
        }
        aux->abajo = new nodomatriz(aux, NULL, NULL, NULL, NULL, NULL, 0, y, empresa, NULL);
    }
}

 // recorrer columnas
string matriz::recorrerDepartamentos(){
    string retorno = "Departamentos disponibles:\n";
    nodomatriz* aux = this->origen;
    while(aux != NULL){
        if(aux->nombre != "Origen"){
            retorno += aux->nombre + "\n";
        }
        aux = aux->derecha;
    }
    return retorno;
}

// recorrer filas

string matriz::recorrerEmpresas(){
    string retorno = "Empresas disponibles:\n";
    nodomatriz* aux = this->origen;
    while(aux != NULL){
        if(aux->nombre != "Origen"){
            retorno += aux->nombre + "\n";
        }
        aux = aux->abajo;
    }
    return retorno;
}


// buscar departamento (columnas)
nodomatriz* matriz::buscarDepartamento(string depa){
    nodomatriz* aux = this->origen;
    while(aux != NULL){

        if(aux->nombre == depa){
            break;
        }
        aux = aux->derecha;
    }
    return aux;
}

// buscar empresa (filas)
nodomatriz* matriz::buscarEmpresa(string empresa){
    nodomatriz* aux = this->origen;
    while(aux != NULL){
        if(aux->nombre == empresa){
            break;
        }
        aux = aux->abajo;
    }
    return aux;
}


// verificar existencia en la matriz



bool matriz::verificarExistencia(string usu, string depa, string empresa){

    nodomatriz* columna = buscarDepartamento(depa);

    nodomatriz* fila = buscarEmpresa(empresa);

    int x = columna->posX, y = fila->posY;
    if(columna->abajo == NULL || fila->derecha == NULL ){
        return true;
    }else{
        bool band = false;
        while(columna != NULL){
            if(columna->posX == x && columna->posY == y){
                band = true;
                break;
            }
            columna = columna->abajo;
        }
        if(band){
            while(columna != NULL){
                if(columna->infoestu->getnombre() == usu){
                    return false;
                }
                columna = columna->adentro;
            }
        }
        return true;
    }
}


bool matriz::agregarUsuario(string nombre, int id, int edad, string depa, string empresa){
    crearCabeceraHorizontal(depa);

    crearCabeceraVertical(empresa);

    if(verificarExistencia(nombre, depa, empresa)){

        nodomatriz* columna = buscarDepartamento(depa);

        nodomatriz* fila = buscarEmpresa(empresa);
        nodomatriz* listado;

        int x = columna->posX, y = fila->posY;
        estudiante* usuario = new estudiante(id, nombre, edad);
        nodomatriz* nuevo = new nodomatriz(NULL, NULL, NULL, NULL, NULL, NULL, x, y, "Listado", usuario);
        if(columna->abajo == NULL && fila->derecha == NULL){
            nuevo->arriba = columna;
            nuevo->izquierda = fila;
            columna->abajo = nuevo;
            fila->derecha = nuevo;
            return true;
        }else{
            bool band = false;
            if(columna->abajo == NULL){
                while(fila->derecha != NULL){
                    fila = fila->derecha;
                }
                fila->derecha = nuevo;
                columna->abajo = nuevo;
                nuevo->izquierda = fila;
                nuevo->arriba = columna;
                return true;
            }else if(fila->derecha == NULL){
                while (columna->abajo != NULL) {
                    columna = columna->abajo;
                }
                columna->abajo = nuevo;
                fila->derecha = nuevo;
                nuevo->arriba = columna;
                nuevo->izquierda = fila;
                return true;
            }else{
                while(columna != NULL){
                    if(columna->posX == x && columna->posY == y){
                        listado = columna;
                        band = true;
                        break;
                    }
                    columna = columna->abajo;
                }
                if(band){
                    while(listado->adentro != NULL){
                        listado = listado->adentro;
                    }
                    listado->adentro = nuevo;
                    nuevo->afuera = listado;
                    return true;
                }else{
                    columna = buscarDepartamento(depa);
                    fila = buscarEmpresa(empresa);

                    while(columna->abajo !=NULL){
                        if(y > columna->posY && y < columna->abajo->posY){

                            break;
                        }

                        columna = columna->abajo;
                    }

                    while(fila->derecha!=NULL){
                        if(x > fila->posX && x <  fila->derecha->posX){
                            break;
                        }
                        fila = fila->derecha;
                    }

                    // cambios de punteros
                    if(columna->abajo ==NULL){
                        columna->abajo = nuevo;
                        nuevo->arriba = columna;
                    }else{
                     nuevo->abajo = columna->abajo;
                     nuevo->abajo->arriba = nuevo;
                     nuevo->arriba = columna;
                     columna->abajo = nuevo;
                    }

                    // filas
                    if(fila->derecha==NULL){
                     fila->derecha = nuevo;
                     nuevo->izquierda = fila;
                    }else{
                    nuevo->derecha = fila->derecha;
                    nuevo->derecha->izquierda = nuevo;
                    nuevo->izquierda = fila;
                    fila->derecha = nuevo;
                    }


                }
            }
        }
    }else{
        cout<<"false"<<endl;
        return false;
    }
    return false;
    cout<<"false2"<<endl;
}


// metodo para imprimir

string matriz::recorrerMatriz(){
    string dot = "digraph G{\nnode[shape = box]\n";

        nodomatriz* fila = this->origen;

        nodomatriz* columna = this->origen;

        while(fila != NULL){
            //string rank = "{rank = same; ";
            while(columna != NULL){
                string actual = to_string(columna->posX) + to_string(columna->posY);
                if(columna->nombre == "Listado"){
                    nodomatriz* aux = columna;
                    string x = to_string(columna->posX);
                    string y = to_string(-columna->posY);
                    dot += actual + " [label = <<table border = \"0\">";
                    while(aux != NULL){
                        dot += "<tr><td> " + aux->infoestu->getnombre() + "</td></tr> \n";
                        aux = aux->adentro;
                    }
                    dot += "</table>>,pos=\""+x+","+y+"!\" "+" ]\n";

                }else{
                    string x = to_string(columna->posX);
                    string y = to_string(-columna->posY);
                    dot +=  actual+" [label = \"" + columna->nombre + "\""+"pos =\""+x+","+y+"!\""+"]\n";
                }

                if(columna->arriba != NULL){
                    string arriba = to_string(columna->arriba->posX) + to_string(columna->arriba->posY);
                    dot += actual + " -> " + arriba + "\n" ;
                }
                if(columna->abajo != NULL){
                    string abajo = to_string(columna->abajo->posX) + to_string(columna->abajo->posY);
                    dot += actual + " -> " + abajo + "\n" ;
                }
                if(columna->derecha != NULL){
                    string derecha = to_string(columna->derecha->posX) + to_string(columna->derecha->posY);
                    dot += actual + " -> " + derecha + "\n" ;
                }
                if(columna->izquierda != NULL){
                    string izquierda = to_string(columna->izquierda->posX) + to_string(columna->izquierda->posY);
                    dot += actual + " -> " + izquierda + "\n";
                }

                columna = columna->derecha;
            }

            fila = fila->abajo;
            columna = fila;
        }
        dot += "}";
        return dot;
}

void matriz::reporteMatriz(){
    string dot = recorrerMatriz();
    ofstream archivo;
    archivo.open("matriz.txt",ios::out);
    archivo <<dot;
    archivo.close();
    system("neato matriz.txt -Tpng -o matrizrepo.png");
}

