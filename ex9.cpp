#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

/*Structs*/
struct Nodo{
    int numero;
    Nodo* siguiente = nullptr;
};


/*Functions body*/
void cargaNodo(Nodo*& inicio, int numero){
    Nodo* tNodo = inicio;
    Nodo* n = new Nodo;
    n->numero=numero;
        if (inicio == nullptr)
        {
            inicio=n;

        }else {
            while (tNodo!=nullptr)
            {
                if (tNodo->numero < n->numero)
                {
                    n->siguiente=tNodo;
                    inicio=n;
                    break;
                } else if (tNodo->siguiente == nullptr ||  n->numero > tNodo->siguiente->numero)
                {
                    n->siguiente=tNodo->siguiente;
                    tNodo->siguiente=n;
                    break;
                }
                tNodo=tNodo->siguiente;    
            }
            
        }
}


/*Funcion que inserta ordenado de forma descendente*/
void insertarOrdenadoDescendente(Nodo*& inicio){
    int numero;
    
    do
    {
        cout<<"Ingrese un numero a insertar: ";
        cin>>numero;
        cargaNodo(inicio, numero);
        
    } while (numero != 0);
    
}

void imprimirLista(Nodo* inicio){
    while (inicio != nullptr)
    {
        cout<<inicio->numero<<endl;
        inicio = inicio->siguiente;
    }
    
}

int main(){

    Nodo* inicio = nullptr;

    insertarOrdenadoDescendente(inicio);
    imprimirLista(inicio);

    return 0;
}