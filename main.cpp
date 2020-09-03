#include <QCoreApplication>
#include "lista.h"
#include "estudiante.h"
#include "matriz.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    lista * listastudent = new lista();
    estudiante * val1 = new estudiante(1,"javier",18);
    estudiante * val2 = new estudiante(2,"luis",22);
    estudiante * val3 = new estudiante(3,"maria",19);
    estudiante * val4 = new estudiante(4,"carlos",21);
    estudiante * val5 = new estudiante(5,"pedro",45);
    estudiante * val6 = new estudiante(6,"juan",22);
    estudiante * val7 = new estudiante(7,"camila",98);
    estudiante * val8 = new estudiante(8,"sofia",22);
    estudiante * val9 = new estudiante(9,"jose",21);
  /*  listastudent->insertar(val1);
    listastudent->insertar(val9);
    listastudent->insertar(val3);
    listastudent->insertar(val4);
    listastudent->insertar(val5);
    listastudent->insertar(val6);
    listastudent->insertar(val7);
    listastudent->insertar(val8);
    listastudent->insertar(val2);
    listastudent->recorrer();
    //listastudent->eliminar(6);
    //cout<<""<<endl;
    //listastudent->recorrer();
    listastudent->ordenarDESC();
    cout<<"after"<<endl;
    listastudent->recorrer();
    //listastudent->reporte();
    listastudent->reporte();
    listastudent->ordenarASC();
    cout<<""<<endl;
    listastudent->reporte();*/

    // crear grado
     // matriz

    matriz * nuevamatriz = new matriz();



    nuevamatriz->agregarUsuario("javier",1,20,"1ero","1");
    nuevamatriz->agregarUsuario("juan",2,21,"2ndo","2");
    nuevamatriz->agregarUsuario("carlos",3,22,"3er","3");
    nuevamatriz->agregarUsuario("pedro",4,23,"3er","4");
    nuevamatriz->agregarUsuario("taller",5,22,"3er","1");
    nuevamatriz->agregarUsuario("luis",6,8,"1ero","2");
    nuevamatriz->agregarUsuario("pedro2",6,8,"1ero","4");
    cout<<"ingreso exitoso"<<endl;
    cout<<nuevamatriz->recorrerMatriz()<<endl;
    cout<<nuevamatriz->recorrerMatriz()<<endl;
    nuevamatriz->reporteMatriz();



    return a.exec();
}


