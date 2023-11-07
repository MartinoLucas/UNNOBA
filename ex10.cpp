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
void crearNodo(string word, Nodo*& start, Nodo*& end){
    Nodo* n = new Nodo;
    n->word=word;

    if (start==nullptr)
    {
       start = n;
       end = n;
    } else {
        end->next=n;
        end=n;
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

/*Funcion que almacena palabras*/
void cargarPalabras(Nodo*& start, Nodo*& end){
    string word;
    cout<<"Ingrese una palabra a almacenar(termina con 'fin'): ";
    getline(cin>>ws, word);

    while (aMinuscula(word) != "fin")
    {   
        crearNodo(aMinuscula(word), start, end);
        cout<<"Ingrese una palabra a almacenar(termina con 'fin'): ";
        getline(cin>>ws, word);
    }
        
}

/*Funcion que crea copia de palabras repetidas*/
void copiaRepetidas(Nodo* start, Nodo*& startC, Nodo*& endC) {
    Nodo* current = start;

    while (current != nullptr) {
        Nodo* temp = current->next;
        while (temp != nullptr) {
            if (temp->word == current->word) {
                crearNodo(temp->word, startC, endC);
                // Break the link for the repeated word in the original list
                current->next = temp->next;
            }
            temp = temp->next;
        }
        current = current->next;
    }
}

/*Funcion que imprime listas de palabras*/
void imprimirLista(Nodo* start){
    while (start != nullptr)
    {
        cout<<start->word<<endl;
        start=start->next;
    }
    
}

/*Funcion que libera la memoria*/
void liberarMemoria(Nodo* start) {
    while (start != nullptr) {
        Nodo* temp = start;
        start = start->next;
        delete temp;
    }
}

int main(){

    Nodo* start = nullptr;
    Nodo* end = nullptr;

    Nodo* startC = nullptr;
    Nodo* endC = nullptr;

    cargarPalabras(start, end);
    cout<<"Lista entera:"<<endl;
    imprimirLista(start);
    copiaRepetidas(start, startC, endC);
    cout<<endl<<"Lista repetida:"<<endl;
    imprimirLista(startC);

    liberarMemoria(start);
    liberarMemoria(startC);

    return 0;
}