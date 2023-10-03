/*
  Módulo de definición de 'TPilaJugador
'.

  Los elementos de tipo TPilaJugador son pilas de elementos de tipo TJugador.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef _PILA_H
#define _PILA_H

#include "jugador.h"

// Representación de 'TPilaJugador'.
// Se debe definir en pila.cpp.
// struct rep_pilaJugador;
// Declaración del tipo 'TPilaJugador'
typedef struct rep_pilaJugador *TPilaJugador;

// Devuelve una TPilaJugador vacía (sin elementos).
// La funcion es Theta(1) peor caso.
TPilaJugador crearTPilaJugador();

// Libera la memoria asignada a 'p' y la de todos sus elementos.
// La funcion es O(n*m) peor caso, siendo n la cantidad de elementos en 'p' y m la cantidad de jugadas de la partida con mas jugadas entre todos los jugadores de 'p'.
void liberarTPilaJugador(TPilaJugador &p);

// Devuelve la cantidad de elementos de 'p'.
// La funcion es Theta(1) peor caso.
nat cantidadEnTPilaJugador(TPilaJugador p);

// Apila 'jugador' en 'p'-
// La TPilaJugador resultado no comparte memoria con 'jugador'.
// La funcion es Theta(m) peor caso, donde m es la cantidad de jugadas de la partida del 'jugador'.
void apilarEnTPilaJugador(TPilaJugador &p, TJugador jugador);

// Devuelve el elemento más nuevo en 'p'.
// Precondición: cantidadEnPila(p) > 0.
// La funcion es Theta(1) peor caso.
TJugador cimaDeTPilaJugador(TPilaJugador p);

// Remueve de 'p' su elemento más nuevo.
// Se libera la memoria asignada al mismo.
// La funcion es Theta(m) peor caso, donde m es la cantidad de jugadas de la partida del 'jugador' que se desapila.
void desapilarDeTPilaJugador(TPilaJugador &p);

#endif
