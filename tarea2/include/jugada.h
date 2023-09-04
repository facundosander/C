/*
  Módulo de definición de 'TJugada'.

  Los elementos de tipo TJugada son elementos que almacenan un numero y una cantidad fija de 4 Movimientos.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef JUGADA_H
#define JUGADA_H

#include <string.h>
#include <stdio.h>

// Define el tipo TJugada como un puntero a rep_jugada
typedef struct rep_jugada *TJugada;

// Enumerado que define los posibles voleres que puede tomar un Movimiento.
enum Movimiento { Derecha = 1, Izquierda = 2, Arriba = 3, Abajo = 4};

// Función que crea un elemento de tipo TJugada con los valores dados
TJugada crearTJugada(int numero, Movimiento mov1, Movimiento mov2, Movimiento mov3, Movimiento mov4);

// Función que retorna el numero de la jugada
int numeroTJugada(TJugada jugada);

// Función que retorna los movimientos de una jugada
Movimiento * movimientoTJugada(TJugada jugada);

// Función que retorna true si y solo si, la jugada tiene el movimiento "mov" en la posicion "pos"
// PRE: 1 <= pos <= 4
bool tieneMovimientoEnPosTJugada(TJugada jugada, int pos, Movimiento mov);

// Función que imprime la información del jugada en el siguiente formato:
// Jugada: <numeroDeJugada>
// Movimientos: <mov1> <mov2> <mov3> <mov4>
void imprimirTJugada(TJugada jugada);

// Función que libera la memoria asignada para un jugada
// Debe liberar también la memoria del movimiento asociado
void liberarTJugada(TJugada &jugada);

// Retorna una copia de la jugada
TJugada copiarTJugada(TJugada jugada);

#endif  // JUGADA_H
