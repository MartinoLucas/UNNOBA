#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

/*Structs*/
struct Productos
{
    int codigo;
    int stock;
    string descripcion;
    float precio;
};

struct Nodo
{
    Productos producto;
    Nodo* siguiente = nullptr;
};

/*Functions*/
void cargarNodo(Nodo*& inicio, Nodo*& nuevo){
    if (inicio == nullptr)
    {
        inicio = nuevo;
    } else 
    {
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
    
}

void cargaProds(Nodo*& inicio){
    int codigo, stock;
    float precio;
    string descripcion;
    Nodo* nuevo;

    cout<<"Ingrese el codigo, stock, precio y descripcion: ";
    cin>> codigo;

    while (codigo != -1)
    {
        cin>> stock;
        cin>> precio;
        getline(cin>>ws, descripcion);

        nuevo = new Nodo;

        nuevo->producto.codigo = codigo;
        nuevo->producto.descripcion = descripcion;
        nuevo->producto.precio= precio;
        nuevo->producto.stock= stock;
        cargarNodo(inicio, nuevo);

        cout<<"Ingrese el codigo, stock, precio y descripcion: ";
        cin>>codigo;
    }
    
}

void imprimirLista(Nodo* inicio){
    while (inicio != nullptr)
    {
        cout<<endl<<"Producto "<<inicio->producto.codigo<<endl<<endl;
        cout<<"Descripcion: "<<inicio->producto.descripcion<<endl;
        cout<<"Precio: "<<inicio->producto.precio<<endl;
        cout<<"Stock: "<<inicio->producto.stock<<endl;
        inicio=inicio->siguiente;
    }
    
}

void incrementarPrecio(Nodo* inicio, float porcentaje){
    while (inicio != nullptr)
    {
        inicio->producto.precio= inicio->producto.precio * (porcentaje + 1.0);
        inicio= inicio->siguiente;
    }
    
}

void incrementarStock(Nodo*& inicio, int codigo, int cantAIncrementar){
    bool existe = false;
    Nodo* tNodo = inicio;

    while (tNodo != nullptr)
    {
        if (tNodo->producto.codigo == codigo){
            tNodo->producto.stock = tNodo->producto.stock + cantAIncrementar;
            existe = true;
        }
        tNodo= tNodo->siguiente;
    }
    
    if (!existe)
    {
        cout<<"El producto con el cogido ingresado no existe.";
    } else {
        cout<<"Se modifico el stock del producto "<< codigo;
    }
    
    
}

void eliminarSinStock(Nodo*& inicio){
    Nodo* tNodo = inicio;
    Nodo* aEliminar = nullptr;

    while (tNodo != nullptr && tNodo->producto.stock == 0)
    {
        aEliminar = tNodo;
        tNodo = tNodo->siguiente;
        inicio = tNodo;
        delete aEliminar;
    }
    tNodo = inicio;
    while (tNodo != nullptr && tNodo->siguiente != nullptr)
    {
        if(tNodo->siguiente->producto.stock == 0){
            aEliminar = tNodo->siguiente;
            tNodo->siguiente = tNodo->siguiente->siguiente;
            delete aEliminar;
        } else {
            tNodo = tNodo->siguiente;
        }
    }
    
    
}

int main(){

    Nodo* inicio = nullptr;

    cargaProds(inicio);
    imprimirLista(inicio);
    incrementarPrecio(inicio, 0.25);
    imprimirLista(inicio);
    incrementarStock(inicio, 44, 50);
    imprimirLista(inicio);
    eliminarSinStock(inicio);
    imprimirLista(inicio);

    return 0;
}