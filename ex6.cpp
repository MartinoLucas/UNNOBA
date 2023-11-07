#include <iostream>
#include <string>
using namespace std;

struct Nodo{
    string nombreYApellido;
    Nodo* siguiente = nullptr;
};

void crearNodo(string nombre, Nodo*& inicio, Nodo*& final){
    Nodo* n = new Nodo;
    n->nombreYApellido=nombre;
    
    if (inicio==nullptr)
    {
       inicio = n;
       final = n; 
    } else {
        final->siguiente=n;
        final=n;
    }
    
}

void cargarDatos(Nodo*& inicio, Nodo*& final){
        string nombre;
        cout<<"Ingrese nombre y apellido del alumno: ";
        getline(cin>>ws, nombre);
    while (nombre != "x" && nombre != "X")
    {   
        crearNodo(nombre, inicio, final);
        cout<<"Ingrese nombre y apellido del alumno: ";
        getline(cin>>ws, nombre);
    } 
    
}

void imprimirLista(Nodo* inicio){
    while (inicio != nullptr)
    {
        cout<<inicio->nombreYApellido<<endl;
        inicio = inicio->siguiente;
    }
    
}

void borrarHeap(Nodo*& inicio){
    Nodo* tnodo = inicio;
    while (inicio != nullptr && inicio->siguiente != nullptr)
    {
        inicio = inicio->siguiente;
        delete tnodo;
        tnodo = inicio;
    }
    delete inicio;
    
}

/*Permitir al usuario guardar en una lista enlazada simple los nombres de los alumnos de un curso, insertando al
final de la lista y cortando la carga cuando se inserte como nombre "x", ya sea en mayúscula o en minúscula (el
cual no debe insertarse en la lista).

A continuación, solicitar al usuario el nombre de un alumno e informar si se encuentra en la lista o no.
Por último, eliminar a la alumna "Josefina Ortega" de la lista (se asume que no se han almacenado nombres
repetidos).*/

int main(){

    Nodo* inicio = nullptr;
    Nodo* final = nullptr;

    cargarDatos(inicio, final);
    imprimirLista(inicio);
    borrarHeap(inicio);

    return 0;
}
