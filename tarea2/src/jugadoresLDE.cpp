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
    nat cantidad;
};

TJugadoresLDE crearTJugadoresLDE(){
    TJugadoresLDE nuevoTJugadoresLDE = NULL;
    nuevoTJugadoresLDE = new rep_jugadoresLDE;
    nuevoTJugadoresLDE->ini = NULL;
    nuevoTJugadoresLDE->fin = NULL;
    nuevoTJugadoresLDE->cantidad = 0;
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
        if (compararTFechas(jugadores->ini->fecha,fecha) != 1)
        {
            nuevoNodo->sig = jugadores->ini;
            jugadores->ini->prev = nuevoNodo;
            jugadores->ini = nuevoNodo;
        }
        else
        {
            TJugadoresNodo aux = jugadores->ini;
            while (aux->sig != NULL && compararTFechas(aux->sig->fecha, fecha) != -1)
            {
                aux = aux->sig;
            }
            if (aux->sig == NULL && compararTFechas(aux->fecha, fecha) != -1)
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
    
    jugadores->cantidad++;
}

void liberarTJugadoresNodo(TJugadoresNodo &JugadoresNodo){
    liberarTFecha(JugadoresNodo->fecha);
    liberarTJugador(JugadoresNodo->jugador);
    delete JugadoresNodo;
    JugadoresNodo = NULL;
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
    TJugadoresNodo aux = jugadores->ini;
    while (aux != NULL)
    {
        imprimirTJugador(aux->jugador);
        imprimirTFecha(aux->fecha);
        aux = aux->sig;
    }
    
}

void imprimirMenorAMayorTJugadoresLDE(TJugadoresLDE jugadores){
    TJugadoresNodo aux = jugadores->fin;
    while (aux != NULL)
    {
        imprimirTJugador(aux->jugador);
        imprimirTFecha(aux->fecha);
        aux = aux->prev;
    }
    
    
}

nat cantidadTJugadoresLDE(TJugadoresLDE jugadores){
    return jugadores->cantidad;
}

void eliminarInicioTJugadoresLDE(TJugadoresLDE &jugadores){
    if (jugadores != NULL)
    {
        TJugadoresNodo nodoborrar = jugadores->ini;
        jugadores->ini = jugadores->ini->sig;
        liberarTJugadoresNodo(nodoborrar);
        jugadores->cantidad--;
        if (jugadores->ini != NULL)
        {
            jugadores->ini->prev = NULL;
        } else
        {
            jugadores->fin = NULL;
        }
        
        
    }
    
}

void eliminarFinalTJugadoresLDE(TJugadoresLDE &jugadores){
        if (jugadores != NULL)
    {
        TJugadoresNodo nodoborrar = jugadores->fin;
        jugadores->fin = jugadores->fin->prev;
        liberarTJugadoresNodo(nodoborrar);
        jugadores->cantidad--;
        if (jugadores->fin != NULL)
        {
            jugadores->fin->sig = NULL;
        }else
        {
            jugadores->ini = NULL;
        }
        
        
    }
}

bool estaEnTJugadoresLDE(TJugadoresLDE jugadores, nat id){ 
    if (jugadores != NULL)
    {
        TJugadoresNodo aux = jugadores->ini;
        while (aux != NULL)
        {
            if (idTJugador(aux->jugador) == id)
            {
                return true;
            }
            aux = aux->sig;
        }
        
    }
    return false;
}

TJugador obtenerTJugadorDeTJugadoresLDE(TJugadoresLDE jugadores, nat id){
    if (jugadores != NULL)
    {
        TJugadoresNodo aux = jugadores->ini;
        while (aux != NULL)
        {
            if (idTJugador(aux->jugador) == id)
            {
                return aux->jugador;
            }
            aux = aux->sig;
        }
        
    }
    return NULL;
}


TFecha obtenerTFechaDeTJugadoresLDE(TJugadoresLDE jugadores, nat id){
    if (jugadores != NULL)
    {
        TJugadoresNodo aux = jugadores->ini;
        while (aux != NULL)
        {
            if (idTJugador(aux->jugador) == id)
            {
                return aux->fecha;
            }
            aux = aux->sig;
        }
        
    }
    return NULL;
}

TJugadoresLDE obtenerSegunTFecha(TJugadoresLDE jugadores, TFecha fecha){
    TJugadoresLDE nuevaLista = NULL;
    if (jugadores != NULL)
    {
        TJugadoresNodo aux = jugadores->ini;
        while (aux != NULL)
        {
            if (compararTFechas(aux->fecha, fecha) == 0)
            {
                TJugador nuevoJugador = copiarTJugador(aux->jugador);
                TFecha nuevaFecha = copiarTFecha(aux->fecha);
                insertarTJugadoresLDE(nuevaLista, nuevoJugador, nuevaFecha);
            }
            aux = aux->sig;
        }
        
    }
    return nuevaLista;
}

TJugadoresLDE unirTJugadoresLDE(TJugadoresLDE &jugadores1, TJugadoresLDE &jugadores2){
    TJugadoresLDE nuevaLista = crearTJugadoresLDE();
    if (jugadores1 != NULL)
    {
        TJugadoresNodo aux = jugadores1->ini;
        while (aux != NULL)
        {
            TJugador nuevoJugador = copiarTJugador(aux->jugador);
            TFecha nuevaFecha = copiarTFecha(aux->fecha);
            insertarTJugadoresLDE(nuevaLista, nuevoJugador, nuevaFecha);
            aux = aux->sig;
        }
        
    }
    if (jugadores2 != NULL)
    {
        TJugadoresNodo aux = jugadores2->ini;
        while (aux != NULL)
        {
            TJugador nuevoJugador = copiarTJugador(aux->jugador);
            TFecha nuevaFecha = copiarTFecha(aux->fecha);
            insertarTJugadoresLDE(nuevaLista, nuevoJugador, nuevaFecha);
            aux = aux->sig;
        }
        
    }
    liberarTJugadoresLDE(jugadores1);
    liberarTJugadoresLDE(jugadores2);
    return nuevaLista;
}