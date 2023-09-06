#include "../include/jugadoresLDE.h"

typedef struct rep_jugadoresNodo *TJugadoresNodo;
struct rep_jugadoresNodo {
    TJugador jugador;
    TFecha fecha;
    rep_jugadoresNodo * sig;
    rep_jugadoresNodo * prev;
};

struct rep_jugadoresLDE {
    rep_jugadoresNodo * ini;
    rep_jugadoresNodo * fin;
};

TJugadoresLDE crearTJugadoresLDE(){
    TJugadoresLDE nuevoTJugadoresLDE = NULL;
    nuevoTJugadoresLDE = new rep_jugadoresLDE;
    nuevoTJugadoresLDE->ini = NULL;
    nuevoTJugadoresLDE->fin = NULL;
    return nuevoTJugadoresLDE;
}

TJugadoresNodo crearTJugadorNodo(TJugador jugador, TFecha fecha) {
    TJugadoresNodo nuevoTJugadoresNodo = NULL;
    nuevoTJugadoresNodo = new rep_jugadoresNodo;
    nuevoTJugadoresNodo->jugador = jugador;
    nuevoTJugadoresNodo->fecha = fecha;
    nuevoTJugadoresNodo->sig = NULL;
    nuevoTJugadoresNodo->prev = NULL;
    return nuevoTJugadoresNodo;
}

void insertarTJugadoresLDE(TJugadoresLDE &jugadores, TJugador &jugador, TFecha &fecha){
    TJugadoresNodo nuevoNodo = crearTJugadorNodo(jugador, fecha);
    if (jugadores->ini == NULL)
    {
        jugadores->ini = nuevoNodo;
        jugadores->fin = nuevoNodo;
    }
    else
    {
        if (compararTFechas(jugadores->ini->fecha,fecha) == 1)
        {
            nuevoNodo->sig = jugadores->ini;
            jugadores->ini->prev = nuevoNodo;
            jugadores->ini = nuevoNodo;
        }
        else
        {
            TJugadoresNodo aux = jugadores->ini;
            while (aux->sig != NULL && compararTFechas(aux->sig->fecha, fecha) != 1)
            {
                aux = aux->sig;
            }
            if (aux->sig == NULL && compararTFechas(aux->fecha, fecha) != 1)
            {
                aux->sig = nuevoNodo;
                nuevoNodo->prev = aux;
                jugadores->fin = nuevoNodo;
            }
            else
            {
                nuevoNodo->sig = aux->sig;
                nuevoNodo->prev = aux;
                aux->sig = nuevoNodo;
                aux->sig->prev = nuevoNodo;
            }
        }
    }
    
    
}

void liberarTJugadoresNodo(TJugadoresNodo &JugadoresNodo){
    liberarTFecha(JugadoresNodo->fecha);
    liberarTJugador(JugadoresNodo->jugador);
    delete JugadoresNodo;
    JugadoresNodo == NULL;
}

void liberarTJugadoresLDE(TJugadoresLDE &jugadoresLDE){
    while (jugadoresLDE->ini != NULL)
    {
        TJugadoresNodo aux = jugadoresLDE->ini;
        jugadoresLDE->ini = jugadoresLDE->ini->sig;
        liberarTJugadoresNodo(aux);
    }
    delete jugadoresLDE;
    jugadoresLDE = NULL;
}

void imprimirMayorAMenorTJugadoresLDE(TJugadoresLDE jugadores){
    TJugadoresNodo aux = jugadores->fin;
    while (aux != NULL)
    {
        imprimirTJugador(aux->jugador);
        aux = aux->prev;
    }
    
    
}

void imprimirMenorAMayorTJugadoresLDE(TJugadoresLDE jugadores){
}

nat cantidadTJugadoresLDE(TJugadoresLDE jugadores){
    return 0;
}

void eliminarInicioTJugadoresLDE(TJugadoresLDE &jugadores){
}

void eliminarFinalTJugadoresLDE(TJugadoresLDE &jugadores){
}

bool estaEnTJugadoresLDE(TJugadoresLDE jugadores, nat id){ 
    return false;
}

TJugador obtenerTJugadorDeTJugadoresLDE(TJugadoresLDE jugadores, nat id){
    return NULL;
}

TFecha obtenerTFechaDeTJugadoresLDE(TJugadoresLDE jugadores, nat id){
    return NULL;
}

TJugadoresLDE obtenerSegunTFecha(TJugadoresLDE jugadores, TFecha fecha){
    return NULL;
}

TJugadoresLDE unirTJugadoresLDE(TJugadoresLDE &jugadores1, TJugadoresLDE &jugadores2){
    return NULL;
}