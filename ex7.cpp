#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

/*Structs body*/
struct Nodo{
    int numero;
    Nodo* siguiente = nullptr;
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

/*Funcion que lee e informa*/
void enLista(Nodo* inicio){
    int numero;
    cout<<"Inserte el numero a verificar: ";
    cin>>numero;
    bool noEstaEnLista = 1;
    while (inicio != nullptr)
    {
        if (numero == inicio->numero)
        {
            cout<<numero<<" esta en la lista."<<endl;
            noEstaEnLista=0;
            break;
        }
        inicio=inicio->siguiente;
        
    }
    if (noEstaEnLista)
    {
        cout<<"El numero ingresado no esta en la lista."<<endl;
    }
    
    
}

/*Funcion que lee e informa cantidad de ocurrencias*/
void enListaCantidad(Nodo* inicio){
    int numero;
    cout<<"Inserte el numero a verificar: ";
    cin>>numero;
    bool noEstaEnLista = 1;
    int ocurrencias = 0;
    while (inicio != nullptr)
    {
        if (numero == inicio->numero)
        {
            ocurrencias++;
            noEstaEnLista=0;
        
        }
        inicio=inicio->siguiente;
        
    }
    if (noEstaEnLista)
    {
        cout<<"El numero ingresado no esta en la lista."<<endl;
    } else {
        cout<<"El numero ingresado aparece "<<ocurrencias<<" veces."<<endl;
    }
    
    
}

/*Funcion que recibe lista y genera dos listas con pares e impares*/
void listasParEImpar(Nodo*& inicio, Nodo* final){
    Nodo* inicioP=nullptr;
    Nodo* finalP=nullptr;

    Nodo* inicioI=nullptr;
    Nodo* finalI=nullptr;

    Nodo* auxInicio = inicio;

    while (auxInicio != nullptr)
    {
        if ((auxInicio->numero % 2) == 0)
        {
            crearNodo(auxInicio->numero,inicioP,finalP);
        } else if((auxInicio->numero % 2) == 1){
            crearNodo(auxInicio->numero,inicioI,finalI);
        }
        auxInicio=auxInicio->siguiente;
    }
    cout<<"Lista Impar: "<<endl;
    imprimirLista(inicioI);
    cout<<"Lista Par: "<<endl;
    imprimirLista(inicioP);
    borrarHeap(inicio);
    
}

int main(){

    Nodo* inicio = nullptr;
    Nodo* final = nullptr;

    cargarDatos(inicio, final);
    cout<<"Lista completa: "<<endl;
    imprimirLista(inicio);
    // enLista(inicio);
    // enListaCantidad(inicio);
    // borrarHeap(inicio);
    listasParEImpar(inicio,final);
    

    return 0;
}