#include <iostream>

struct Nodo {
    int numero;
    Nodo* next = nullptr;
};

void imprimirLista(Nodo* inicio) {
    while(inicio != nullptr) {
        std::cout << inicio->numero << std::endl;
        inicio = inicio->next;
    }
}

void ingresarAlFinal(Nodo*& inicio, Nodo*& final, int numero) {
    Nodo* nodo = new Nodo;
    nodo->numero = numero;

    if(inicio == nullptr) {
        inicio = nodo;
        final = nodo;
    } else {
        final->next = nodo;
        final = nodo;
    }
}

void ingresarAlPrincipio(Nodo*& inicio, Nodo*& final, int numero) {
    Nodo* nodo = new Nodo;
    nodo->numero = numero;

    if(inicio == nullptr) {
        inicio = nodo;
        final = nodo;
    } else {
        nodo->next = inicio;
        inicio = nodo;
    }
}

void ingresarOrdenado(Nodo*& inicio, int numero) {
    Nodo* nodo = new Nodo;
    nodo->numero = numero;

    if(inicio == nullptr || numero < inicio->numero) {
        nodo->next = inicio;
        inicio = nodo;
    } else {
        Nodo* tNodo = inicio;

        while(tNodo->next != nullptr && tNodo->next->numero < numero) {
            tNodo = tNodo->next;
        }
        nodo->next = tNodo->next;
        tNodo->next = nodo;
    }
}

int main() {
    Nodo* inicio = nullptr;
    Nodo* final = nullptr;

    int numero = 0;
    do
    {
        std::cout << "Ingrese un numero: ";
        std::cin >> numero;

        if(numero == 0) break;

        ingresarOrdenado(inicio, numero);

    } while (numero != 0);
    
    imprimirLista(inicio);

}