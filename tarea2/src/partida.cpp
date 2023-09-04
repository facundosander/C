#include "../include/partida.h"

struct rep_partida {
    TJugada jugada;
    rep_partida * sig;
};

TPartida crearTPartida(){
    TPartida nuevaPartida = NULL;
    nuevaPartida = new rep_partida;
    nuevaPartida->sig = NULL;
    nuevaPartida->jugada = NULL;
    return nuevaPartida;
}

void agregarEnTPartida(TPartida& partida, TJugada jugada){
    if (partida->jugada == NULL) {
        partida->jugada = jugada;
    }
    else{
        if (numeroTJugada(partida->jugada) > numeroTJugada(jugada))
        {
            TPartida nuevoNodo = crearTPartida();
            nuevoNodo->jugada = jugada;
            nuevoNodo->sig = partida;
            partida = nuevoNodo;
        }
        else{
        TPartida aux = partida;
        while ( aux->sig != NULL && numeroTJugada(aux->sig->jugada) <= numeroTJugada(jugada))
        {
            aux = aux->sig;
        }
        TPartida nuevoNodo = crearTPartida();
        nuevoNodo->jugada = jugada;
        nuevoNodo->sig = aux->sig;
        aux->sig = nuevoNodo;
        }
    }
}

void imprimirTPartida(TPartida partida){
    TPartida aux = partida;
    while (aux != NULL && aux->jugada != NULL)
    {
        imprimirTJugada(aux->jugada);
        aux = aux->sig;
    }
    
}

void liberarTPartida(TPartida& partida){
    while (partida != NULL)
    {
        TPartida aux = partida;
        partida = partida->sig;
        liberarTJugada(aux->jugada);
        delete aux;
        aux = NULL;
    }
    
}

bool esVaciaTPartida(TPartida partida){
    bool res = false;
    if ( partida->jugada == NULL )
    {
        res = true;
    }
    return res;
}

TPartida copiarTPartida(TPartida partida){
    TPartida copiaTPartida = crearTPartida();
    TPartida aux = partida;
    while (aux!=NULL)
    {
        TJugada copiaTJugada = copiarTJugada(aux->jugada);
        agregarEnTPartida(copiaTPartida, copiaTJugada);
        aux = aux->sig;
    }
    
    return copiaTPartida;
}

bool estaEnTPartida(TPartida partida, int numeroDeJugada){
    TPartida aux = partida;
    while (aux!=NULL){
        
        if (numeroTJugada(aux->jugada)==numeroDeJugada){
            return true;
        }
        aux = aux->sig;
    }
    
    return false;
}

TJugada obtenerDeTPartida(TPartida partida, int numeroDeJugada){
    TPartida aux = partida;
    while (aux!=NULL){
        
        if (numeroTJugada(aux->jugada)==numeroDeJugada){
            return aux->jugada;
        }
        aux = aux->sig;
    }
    return NULL;
}

void imprimirJugadasConMovimiento(TPartida partida, int pos, Movimiento mov){
    TPartida aux = partida;
    while (aux!=NULL)
    {
        if (tieneMovimientoEnPosTJugada(aux->jugada, pos, mov))
        {
            imprimirTJugada(aux->jugada);
        }
        aux = aux->sig;
    }
    
}

void removerDeTPartida(TPartida& partida, int numeroDeJugada){
    if (partida == NULL) return;
    if (numeroTJugada(partida->jugada) == numeroDeJugada) {
        TPartida aux = partida;
        partida = partida->sig;
        liberarTJugada(aux->jugada);
        delete aux;
        return;
    }
    TPartida anterior = partida;
    TPartida actual = partida->sig;
    while (actual != NULL) {
        if (numeroTJugada(actual->jugada) == numeroDeJugada) {
            anterior->sig = actual->sig;
            liberarTJugada(actual->jugada);
            delete actual;
            return;
        }
        anterior = actual;
        actual = actual->sig;
    }
}






