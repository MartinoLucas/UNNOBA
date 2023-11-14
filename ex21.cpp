#include <iostream>
#include <string>
using namespace std;

/*Structs*/
struct Players
{
    string name;
    int score;
    int race;
};
struct Nodo
{
    Players player;
    Nodo* next = nullptr;
};

/*Constants*/
const int MAX_PLAYERS = 10;

/*Functions body*/
void insertNodo(Nodo*& end, Nodo*& n){
    if (end == nullptr)
    {
        end = n;
        n->next = n;
    } else {
        n->next=end->next;
        end->next=n;
        end=n;
    }
    
}

void validateRace(int & race){

    while(race <= 0 || race >= 4){
        cout<<"Insert the race: ";
        cin>>race;
    }
           
}

void raceAttributes(int race){
        switch (race)
        {
        case 1:
            {
                cout<<"El mago tiene los siguientes atributos:"<<endl;
                cout<<"1 punto de sanación por cada 5 de daño recibido"<<endl;
                break;
            }
        case 2:
            {
                cout<<"El guerrero tiene los siguientes atributos:"<<endl;
                cout<<"20% más de daño infligido"<<endl;
                break;
            }
        case 3:
            {
                cout<<"El elfo tiene los siguientes atributos:"<<endl;
                cout<<"capacidad de resucitar a un compañero a cambio de 200 puntos"<<endl;
                break;
            }
        default:
            break;
        }
}

void loadPlayers(Nodo*& end){
    Nodo* n;
    string name;
    int score, race, max=0;
    cout<<"Insert player name: ";
    cin>>name;

    while (name != "x" && max<MAX_PLAYERS)
    {
        cout<<"Insert the score: ";
        cin>>score;

        cout<<"Insert the race: ";
        cin>>race;

        n= new Nodo;
        n->player.name=name;
        validateRace(race);
        n->player.race=race;
        n->player.score=score;

        insertNodo(end, n);
        max++;

        cout<<"Insert player name: ";
        cin>>name;
    }
    

}

void playerAttributes(Nodo* end){
    string player;
    cout<<"Ingrese el jugador a informar: ";
    cin>>player;
    
    bool exist = false;

    Nodo* tNodo = end->next;

    if(end != nullptr)
    {
        do
        {
            if (tNodo->player.name == player)
            {
                raceAttributes(tNodo->player.race);
                exist = true;
                break;
            }
            tNodo = tNodo->next;
        } while (tNodo != end->next);

        if (!exist)
        {
            cout<<"El jugador no existe."<<endl;
        }
        
        
           
    } else {
        cout<<"La lista esta vacía."<<endl;
    }
    
}

void minusScore(Nodo* end, int race, int quantScore){
    Nodo* tNodo = end->next;
    do
    {
        if (tNodo->player.race == race)
        {
            tNodo->player.score= tNodo->player.score - quantScore;
        }
        tNodo=tNodo->next;
        
    } while (tNodo != end->next);
    
    
}

void printPlayers(Nodo* end){
    Nodo* tNodo = end->next;
    do
    {
        cout<<endl<<endl<<"Jugador "<<tNodo->player.name<<endl;
        cout<<"     Puntaje: "<< tNodo->player.score<<endl;

        tNodo= tNodo->next;
    } while (tNodo != end->next);
    
}

int main(){

    Nodo* end = nullptr;

    loadPlayers(end);
    cout<<endl<<"Lista de jugadores: "<<endl;
    printPlayers(end);

    playerAttributes(end);
    minusScore(end, 3, 200);
    cout<<endl<<"Lista de jugadores modificada: "<<endl;
    printPlayers(end);

    return 0;
}