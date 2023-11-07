#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

/*Structs*/
struct Nodo{
    int numero;
    Nodo* next;
};


/*Functions body*/
void crearNodo(Nodo*&inicio, int numero){
    Nodo * nuevo= new Nodo;
    nuevo->numero=numero;
    Nodo* aux=inicio;
    
    if (inicio==nullptr){
        inicio=nuevo;
    }
    else
    {
        while (aux != nullptr) {
            if (nuevo->numero > aux->numero) {
                nuevo->next = aux;
                inicio = nuevo; 
                break;
            }    
            else if (aux->next == nullptr || nuevo->numero > aux->next->numero) {
                nuevo->next = aux->next;
                aux->next = nuevo;
                break;
            }
            aux = aux->next;
        }

    }
}

/*functions*/

int main(){

    Nodo* inicio = nullptr;

    do
    {
        cin>>
    } while (numero!=0);
    

    return 0;
}