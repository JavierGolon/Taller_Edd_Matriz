#include "arbolavl.h"

ArbolAvl::ArbolAvl()
{
    this->raiz = NULL;

}


NodoAvl* ArbolAvl::Oraiz(){
    return this->raiz;
}

void ArbolAvl::Praiz(NodoAvl *r){
    this->raiz = r;
}

NodoAvl* ArbolAvl::rotacionII(NodoAvl* n, NodoAvl* n1){
    n->ramaIzdo(n1->subarbolDcho());
    n1->ramaDcho(n);
    // actualización de los factores de equilibrio
    if (n1->Ofe() == -1) // la condición es true en la inserción
    {
        n->Pfe(0);
        n1->Pfe(0);
    }else{
        n->Pfe(-1);
        n1->Pfe(1);
    }
    return n1;
}


NodoAvl* ArbolAvl::rotacionDD(NodoAvl* n, NodoAvl* n1){
    n->ramaDcho(n1->subarbolIzdo());
    n1->ramaIzdo(n);
    // actualización de los factores de equilibrio
    if (n1->Ofe() == +1) // la condición es true en la inserción
    {
        n->Pfe(0);
        n1->Pfe(0);
    }
    else
    {
        n->Pfe(+1);
        n1->Pfe(-1);
    }
    return n1;
}

NodoAvl* ArbolAvl::rotacionDI(NodoAvl* n, NodoAvl* n1){
    NodoAvl* n2;
    n2 = n1->subarbolIzdo();
    n->ramaDcho(n2->subarbolIzdo());
    n2->ramaIzdo(n);
    n1->ramaIzdo(n2->subarbolDcho());
    n2->ramaDcho(n1);
    // actualización de los factores de equilibrio
    if (n2->Ofe() == +1)
        n->Pfe(-1);
    else
        n->Pfe(0);
    if (n2->Ofe() == -1)
        n1->Pfe(+1);
    else
        n1->Pfe(0);
    n2->Pfe(0);
    return n2;
}

NodoAvl* ArbolAvl::rotacionID(NodoAvl* n, NodoAvl* n1){
    NodoAvl* n2;
    n2 = n1->subarbolDcho();
    n->ramaIzdo(n2->subarbolDcho());
    n2->ramaDcho(n);
    n1->ramaDcho(n2->subarbolIzdo());
    n2->ramaIzdo(n1);
    // actualización de los factores de equilibrio
    if (n2->Ofe() == +1)
        n1->Pfe(-1);
    else
        n1->Pfe(0);
    if (n2->Ofe() == -1)
        n->Pfe(1);
    else
        n->Pfe(0);
    n2->Pfe(0);
    return n2;
}

NodoAvl* ArbolAvl::insertarAvl(NodoAvl* raiz, int dt, bool &hc){
    NodoAvl *n1;
    if (raiz == NULL)
    {
        raiz = new NodoAvl(dt);
        hc = true;
    }
    else if (dt < raiz->valorNodo())
    {
        NodoAvl *iz;
        iz = insertarAvl(raiz->subarbolIzdo(), dt, hc);
        raiz->ramaIzdo(iz);
        // regreso por los nodos del camino de búsqueda
        if (hc) // siempre se comprueba si creció en altura
        {
            // decrementa el fe por aumentar la altura de rama izquierda
            switch (raiz->Ofe())
            {
            case 1: // tenía +1 y creció su izquierda
                raiz->Pfe(0);
                hc = false; // árbol deja de crecer
                break;
            case 0: // tenía 0 y creció su izquierda
                raiz->Pfe(-1); // árbol sigue creciendo
                break;
            case -1: // aplicar rotación a la izquierda
                n1 = raiz->subarbolIzdo();
                if (n1->Ofe() == -1)
                    raiz = rotacionII(raiz, n1);
                else
                    raiz = rotacionID(raiz, n1);
                hc = false; // árbol deja de crecer en ambas rotaciones
            }
        }
    }
    else if (dt > raiz->valorNodo())
    {
        NodoAvl *dr;
        dr = insertarAvl(raiz->subarbolDcho(), dt, hc);
        raiz->ramaDcho(dr);
        // regreso por los nodos del camino de búsqueda
        if (hc) // siempre se comprueba si creció en altura
        {
            // incrementa el fe por aumentar la altura de rama izquierda
            switch (raiz->Ofe())
            {
            case 1: // aplicar rotación a la derecha
                n1 = raiz->subarbolDcho();
                if (n1->Ofe() == +1)
                    raiz = rotacionDD(raiz, n1);
                else
                    raiz = rotacionDI(raiz,n1);
                hc = false; // árbol deja de crecer en ambas rotaciones
                break;
            case 0: // tenía 0 y creció su derecha
                raiz->Pfe(+1); // árbol sigue creciendo
                break;
            case -1: // tenía -1 y creció su derecha
                raiz->Pfe(0);
                hc = false; // árbol deja de crecer
            }
        }
    }
    else
        throw "No puede haber claves repetidas " ;
    return raiz;
}



void ArbolAvl::dibujarArbol(NodoAvl *r, int h)
 {
 // escribe las claves del árbol estableciendo separación entre nodos
 int i;
 if (r != NULL)
 {
 dibujarArbol(r->subarbolIzdo(), h + 1);
 for (i = 1; i <= h; i++)
 cout << " ";
 cout << r->valorNodo() << endl;
 dibujarArbol(r->subarbolDcho(), h + 1);
    }
 }

void ArbolAvl::insertar(int dato){
    bool f = false;
    this->raiz = insertarAvl(this->Oraiz(),dato,f);
}


// graphviz

void ArbolAvl::ObtenerGrafo(NodoAvl *raiz){
    string dotocompleto = "digraph grafica{\n"
            "rankdir=TB;\n"
            "node [shape = record, style=filled, fillcolor=seashell2];\n"+
             obtenerDot(raiz)+
             "}\n";

    ofstream archivo;
    archivo.open("arbol.dot",ios::out);
    archivo <<dotocompleto;
    archivo.close();
    system("dot arbol.dot -Tpng -o arbol.png");
}

string ArbolAvl::obtenerDot(NodoAvl *root){
    string dot;
    if(root->subarbolIzdo() == NULL && root->subarbolDcho() == NULL){
        dot="nodo"+to_string(root->valorNodo())+" [ label =\""+to_string( root->valorNodo())+"\"];\n";
    }else{
        dot="nodo"+to_string(root->valorNodo())+" [ label =\"<C0>|"+to_string( root->valorNodo())+"|<C1>\"];\n";
    }

    if(root->subarbolIzdo()!=NULL){
        dot=dot +obtenerDot(root->subarbolIzdo()) +
                       "nodo"+to_string(root->valorNodo())+":C0->nodo"+to_string(root->subarbolIzdo()->valorNodo())+"\n";
    }

    if (root->subarbolDcho()!=NULL){
        dot=dot + obtenerDot(root->subarbolDcho()) +
                       "nodo"+to_string(root->valorNodo())+":C1->nodo"+to_string(root->subarbolDcho()->valorNodo())+"\n";
    }
    return dot;
}


void ArbolAvl::postorden(NodoAvl *raiz){
    if(raiz!=NULL){
        postorden(raiz->subarbolIzdo());
        postorden(raiz->subarbolDcho());
        cout<<"dato"<<raiz->valorNodo()<<endl;
    }
}

void ArbolAvl::preorden(NodoAvl *raiz){
    if(raiz!=NULL){

        cout<<"dato"<<raiz->valorNodo()<<endl;
        postorden(raiz->subarbolIzdo());
        postorden(raiz->subarbolDcho());
    }
}

void ArbolAvl::inorden(NodoAvl *raiz){
    if(raiz!=NULL){
        postorden(raiz->subarbolIzdo());
        cout<<"dato"<<raiz->valorNodo()<<endl;
        postorden(raiz->subarbolDcho());
    }
}
