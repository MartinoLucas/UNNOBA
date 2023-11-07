#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

/*Structs*/
struct Nodo{
    int numero;
    Nodo* next=nullptr;
};

/*Functions body*/
/*
void crearNodo(int numero, Nodo*& inicio, Nodo*& final){
    Nodo* n = new Nodo;
    n->numero=numero;

    if (inicio==nullptr)
    {
       inicio = n;
       final = n;
    } else {
        final->next=n;
        final=n;
    }

}
*/

/*Funcion de carga de Lista Circular | Innicio*/
void cargarInicio(Nodo*& fin, Nodo*& nuevo){
    if (fin == nullptr)
    {
        fin = nuevo;
        nuevo->next = nuevo;
    } else {
        nuevo->next = fin->next;
        fin->next = nuevo;
    }
    
}

/*Funcion de carga de Lista Circular | Final*/
void cargarFinal(Nodo*& fin, Nodo*& nuevo){
    if (fin == nullptr)
    {
        nuevo->next = nuevo;
    } else {
        nuevo->next = fin->next;
        fin->next = nuevo;
    }
    fin = nuevo;
}

/*Imprimir Lista Circular*/
void imprimirLista(Nodo* fin){
    if (fin != nullptr)
    {
        Nodo* tNodo = fin->next;
        do
        {
            cout<< tNodo->numero << endl;
            tNodo = tNodo->next;
        } while (tNodo != fin->next);
        
    }
    
}

int main(){

    /*main body*/

    return 0;
}