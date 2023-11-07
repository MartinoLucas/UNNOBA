#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

/*Structs*/
struct Nodo{
    int numero;
    Nodo* siguiente=nullptr;
};

/*Functions body*/
void crearNodo(int numero, Nodo*& inicio, Nodo*& final){
    Nodo* n = new Nodo;
    n->numero=numero;
    
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
        int numero;
        cout<<"Ingrese un numero: ";
        cin>>numero;
    while (numero >= 0)
    {   
        crearNodo(numero, inicio, final);
        cout<<"Ingrese un numero: ";
        cin>>numero;
    } 
    
}

void imprimirLista(Nodo* inicio){
    while (inicio != nullptr)
    {
        cout<<inicio->numero<<endl;
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

/*Funcion que borra nodos*/
void borrarNodo(Nodo* aEliminar, Nodo* anterior){
    
    if (aEliminar->siguiente == nullptr)
    {
        anterior->siguiente=nullptr;

    } else{

        anterior->siguiente=aEliminar->siguiente;

    }
    delete aEliminar;

}

/*Funcion que borra numero todas las cants de veces*/
void borrarOcurrencias(Nodo*& inicio, int numero){
    int cantBorrado =0;
    Nodo* auxInicio=inicio;

    while (auxInicio->numero==numero)
    {
        auxInicio=auxInicio->siguiente;
        cantBorrado++;
    }

    while (auxInicio != nullptr)
    {
        if (auxInicio->siguiente!=nullptr && numero==auxInicio->siguiente->numero)
        {
            borrarNodo(auxInicio->siguiente, auxInicio);
            cantBorrado++;
        }else{
            auxInicio=auxInicio->siguiente;
        }
        
    }
    cout<<"Se ha borrado "<<cantBorrado<<" veces"<<endl;
    
}

int main(){

    Nodo* inicio =nullptr;
    Nodo* final = nullptr;

    cargarDatos(inicio, final);
    cout<<"Lista entera: "<<endl;
    imprimirLista(inicio);
    borrarOcurrencias(inicio, 4);
    cout<<"Lista borrada: "<<endl;
    imprimirLista(inicio);
    borrarHeap(inicio);

    return 0;
}