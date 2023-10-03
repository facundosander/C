#include "../include/jugada.h"

// Define la estructura Jugada
struct rep_jugada {
    int numero;
    Movimiento movimientos[4];
};

// Crea una jugada con los valores dados
TJugada crearTJugada(int numero, Movimiento mov1, Movimiento mov2, Movimiento mov3, Movimiento mov4){
    TJugada nuevaJugada = NULL;
    nuevaJugada = new rep_jugada;
    nuevaJugada->numero = numero;
    nuevaJugada->movimientos[0] = mov1;
    nuevaJugada->movimientos[1] = mov2;
    nuevaJugada->movimientos[2] = mov3;
    nuevaJugada->movimientos[3] = mov4;

    return nuevaJugada;
}

// Función que retorna el numero de la jugada
int numeroTJugada(TJugada jugada){
    return jugada->numero;
}

// Función que retorna los movimientos de una jugada
Movimiento * movimientoTJugada(TJugada jugada) {
    return jugada->movimientos;
}

// Devuelve true si y solo si la jugada tiene el movimiento mov en la posicion pos
bool tieneMovimientoEnPosTJugada(TJugada jugada, int pos, Movimiento mov){
    if (jugada->movimientos[pos - 1] == mov)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

// Imprime la jugada
const char* movimientoAString(Movimiento movimiento) {
    switch (movimiento) {
        case Derecha:
            return "Derecha";
        case Izquierda:
            return "Izquierda";
        case Arriba:
            return "Arriba";
        case Abajo:
            return "Abajo";
        default:
            return "Movimiento desconocido";
    }
    return "Movimiento desconocido";  // línea añadida
}

void imprimirTJugada(TJugada jugada) {
    printf("Jugada: %d \nMovimientos: %s %s %s %s \n", 
    jugada->numero, 
    movimientoAString(jugada->movimientos[0]), 
    movimientoAString(jugada->movimientos[1]), 
    movimientoAString(jugada->movimientos[2]), 
    movimientoAString(jugada->movimientos[3]));
}

// Libera la memoria asignada para un jugada
void liberarTJugada(TJugada &jugada) {
    delete jugada;
    jugada = NULL;
}

// Retorna una copia de la jugada
TJugada copiarTJugada(TJugada jugada) {
    return crearTJugada(jugada->numero, jugada->movimientos[0], jugada->movimientos[1], jugada->movimientos[2], jugada->movimientos[3]);
}