#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

/*Structs*/
struct Nodo{
    string word;
    Nodo* next=nullptr;
};


/*Functions body*/
void crearNodo(string word, Nodo*& inicio, Nodo*& final){
    Nodo* n = new Nodo;
    n->word=word;

    if (inicio==nullptr)
    {
       inicio = n;
       final = n;
    } else {
        final->next=n;
        final=n;
    }

}

/*Funcion de convertir en minuscula una palabra*/
string aMinuscula(string word){
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = tolower(word[i]);
    }
    return word;
}

/*Funcion que inserta ordenado*/
void insertarOrdenado(Nodo*& start, Nodo*& end){
    string word;
    cout<<"Ingrese una palabra(termina en 'fin'): ";
    getline(cin>>ws, word);

    while (aMinuscula(word) != "fin")
    {
        Nodo* tNodo = start;
        Nodo * n = new Nodo;
        n->word = word;
        if (start == nullptr)
        {
            start = n;
            end = n;
        } else {
            while (tNodo!=nullptr)
            {
                if (tNodo->word < n->word)
                {
                    n->next=tNodo;
                    start=n;
                    break;
                } else if (tNodo->next == nullptr ||  n->word > tNodo->next->word)
                {
                    n->next=tNodo->next;
                    tNodo->next=n;
                    break;
                }
                tNodo=tNodo->next;    
            }
        }
        cout<<"Ingrese una palabra(termina en 'fin'): ";
        getline(cin>>ws, word);

        
    }
    
}

/*Funcion que mergea listas y las ordena*/
void mergeOrdenado(){
    
}

void imprimirLista(Nodo* start){
    while (start != nullptr)
    {
        cout<<start->word<<endl;
        start=start->next;
    }
    
}

int main(){

    Nodo* startA = nullptr;
    Nodo* endA = nullptr;

    Nodo* startB = nullptr;
    Nodo* endB = nullptr;

    Nodo* startM = nullptr;
    Nodo* endM = nullptr;

    insertarOrdenado(startA, endA);
    imprimirLista(startA);

    return 0;
}