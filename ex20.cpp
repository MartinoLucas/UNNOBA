#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

/*Structs*/
struct Proceso{
    int PID;
    string usuario;
    int segundosEjecucion;
    int fecha;
};

struct Nodo{
    Proceso proceso;
    Nodo* next;
};


/*Functions body*/
/**/

/*Funcion para informar PID con mas segundos de ejecucion*/
void informarPIDMasSegundos(Nodo* fin){
    if (fin != nullptr)
    {
        Nodo* tNodo = fin->next;
        Proceso procMayor = fin->next->proceso;
        do
        {
            if (tNodo->proceso.segundosEjecucion > procMayor.segundosEjecucion)
            {
                procMayor = tNodo->proceso;
            }
            tNodo = tNodo->next;
        } while (tNodo != fin->next);
        cout<< "El ID del proceso con mas duracion fue el " << procMayor.PID << endl;
        
    } else {
        cout<<"La lista esta vacia." << endl;
    }
    
}

/*si existe pid 61 aumentar en 2 los segundos*/
void aumentarPID(Nodo*& fin, int PID, int cantAumento){
    bool exist = false;
    if (fin != nullptr)
    {
        Nodo* tNodo = fin->next;
        do
        {
            if (tNodo->proceso.PID == PID)
            {
                tNodo->proceso.PID += cantAumento;
                exist = true;
            }
            tNodo = tNodo->next;
        } while (tNodo != fin->next);
        if (exist)
        {
            cout<<"No existe el id " << PID << endl;
        }
    } else {
        cout<<"La lista se encuentra vacia :("<<endl;
    }
    
    
}

int main(){

    /*main body*/

    return 0;
}