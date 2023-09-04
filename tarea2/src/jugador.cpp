#include "../include/jugador.h"

struct rep_jugador {
};

TJugador crearTJugador(nat id, nat edad, const char pais[100], const char nombre[100], TPartida partida) {
    return NULL;
}

void liberarTJugador(TJugador &jugador) {
}

void imprimirTJugador(TJugador jugador) {
}

nat idTJugador(TJugador jugador) {
    return 0;
}

nat edadTJugador(TJugador jugador) {
    return 0;
}

char* nombreTJugador(TJugador jugador) {
    return NULL;
}

char* paisTJugador(TJugador jugador) {
    return NULL;
}

TPartida partidaTJugador(TJugador jugador) {
    return NULL;
}

void agregarJugadaATJugador(TJugador &jugador, TJugada jugada){
}

void removerJugadaDeTJugador(TJugador &jugador, int numeroDeJugada){
}

bool estaEnPartidaDeTJugador(TJugador jugador, int numeroDeJugada){
    return false;
}

TJugada obtenerDePartidaDeTJugador(TJugador jugador, int numeroDeJugada){
    return NULL;
}

TJugador copiarTJugador(TJugador jugador){
    return NULL;
}
