/*
  Módulo de definición de 'TColaJugadoresABB'.

  Los elementos de tipo TColaJugadoresABB son colas de elementos de tipo TJugadoresABB.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef _COLA_H
#define _COLA_H

#include "jugadoresABB.h"

// Representación de 'TColaJugadoresABB'.
// Se debe definir en colaJugadoresABB.cpp.
// struct rep_colaJugadoresABB;
// Declaración del tipo 'TColaJugadoresABB'
typedef struct rep_colaJugadoresABB *TColaJugadoresABB;

// Devuelve una TColaJugadoresABB vacía (sin elementos).
// La función es Theta(1) peor caso.
TColaJugadoresABB crearTColaJugadoresABB();

// Libera la memoria asignada a 'c' y la de todos sus elementos pero sin liberar la memoria de los elementos de tipo TJugadoresABB incluidos.
// La función es Theta(n) peor caso, donde n es la cantidad de jugadores en la cola.
void liberarTColaJugadoresABB(TColaJugadoresABB &c);

// Devuelve la cantidad de elementos en 'c'.
// La función es Theta(1) peor caso.
nat cantidadEnTColaJugadoresABB(TColaJugadoresABB c);

// Encola 'persona' en 'c'.
// La función es Theta(1) peor caso.
void encolarEnTColaJugadoresABB(TJugadoresABB t, TColaJugadoresABB &c);

// Devuelve el elemento más antiguo en 'c'.
// Precondición: cantidadEnCola(c) > 0.
// La función es Theta(1) peor caso.
TJugadoresABB frenteDeTColaJugadoresABB(TColaJugadoresABB c);

// Remueve de 'c' su elemento más antiguo.
// Se libera la memoria asignada al elemento de la cola pero sin liberar la memoria del elemento de tipo TJugadoresABB incluido.
// Precondición: cantidadEnCola(c) > 0.
// La función es Theta(1) peor caso.
void desencolarDeTColaJugadoresABB(TColaJugadoresABB &c);

#endif
