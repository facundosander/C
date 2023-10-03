/*
  Módulo de definición de 'jugadoresLDE'.

  La estructura de tipo jugadoresLDE es un lista doblemente encadenada de jugadores (y fechas) con puntero al inicio y al final de la lista.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef JUGADORESLDE_H
#define JUGADORESLDE_H

#include "jugador.h"
#include "fecha.h"
#include "utils.h"

// Definición de tipo TJugadoresLDE como un puntero a rep_jugadoresLDE
typedef struct rep_jugadoresLDE *TJugadoresLDE;

// Función para crear una nueva lista vacía de jugadores
TJugadoresLDE crearTJugadoresLDE();

// Función para insertar ordenadamente un jugador en la lista de jugadores según la fecha dada
// Si ya existe un jugador con la misma fecha asociada, el mas reciente se considerara mayor.
// La función es Theta(n) peor caso, siendo n la cantidad de jugadores en la lista
void insertarTJugadoresLDE(TJugadoresLDE &jugadores, TJugador &jugador, TFecha &fecha);

// Función para liberar la memoria asignada a una lista de jugadores
// La función es O(n*m) peor caso, donde n es la cantidad de jugadores en la lista y m es la cantidad de jugadas de la partida con mas jugadas entre todas las jugadores de la lista.
void liberarTJugadoresLDE(TJugadoresLDE &jugadores);

// Función para imprimir secuencialmente los jugadores con su fecha asociada de la lista de jugadores (de mayor a menor segun sus fechas).
// La función es O(n*m) peor caso, donde n es la cantidad de jugadores en la lista y m es la cantidad de jugadas de la partida con mas jugadas entre todas las jugadores de la lista.
void imprimirMayorAMenorTJugadoresLDE(TJugadoresLDE jugadores);

// Función para imprimir los jugadores con su fecha ascciada de la lista de jugadores de menor a mayor según sus fechas.
// La función es O(n*m) peor caso, donde n es la cantidad de jugadores en la lista y m es la cantidad de jugadas de la partida con mas jugadas entre todas las jugadores de la lista.
void imprimirMenorAMayorTJugadoresLDE(TJugadoresLDE jugadores);

// Función para obtener la cantidad de jugadores en la lista de jugadores
// La función es Theta(1) peor caso
nat cantidadTJugadoresLDE(TJugadoresLDE jugadores);

// Función para eliminar una jugador del inicio de la lista de jugadores
// La función es Theta(m) peor caso, donde m es la cantidad de jugadas de la partida de jugador que se elimina de la lista.
// Si no hay jugadores en la lista la función no hace nada
void eliminarInicioTJugadoresLDE(TJugadoresLDE &jugadores);

// Función para eliminar una jugador del final de la lista de jugadores
// La función es Theta(m) peor caso, donde m es la cantidad de jugadas de la partida de la jugador que se elimina de la lista.
// Si no hay jugadores en la lista la función no hace nada
void eliminarFinalTJugadoresLDE(TJugadoresLDE &jugadores);

// Función para verificar si un elemento de tipo TJugador existe en una lista de jugadores
// Devuelve true si existe, false en caso contrario
// La función es Theta(n) peor caso, siendo n la cantidad de jugadores en la lista
bool estaEnTJugadoresLDE(TJugadoresLDE jugadores, nat id);

// Función para obtener una jugador en la lista de jugadores
// La función es Theta(n) peor caso, siendo n la cantidad de jugadores en la lista
// PRE: El jugador existe en la lista
TJugador obtenerTJugadorDeTJugadoresLDE(TJugadoresLDE jugadores, nat id);


// Función para obtener la mayor fecha asociada al jugador que tiene "id" como id en la lista de jugadores
// La función es Theta(n) peor caso, siendo n la cantidad de jugadores en la lista
// PRE: El jugador existe en la lista
TFecha obtenerTFechaDeTJugadoresLDE(TJugadoresLDE jugadores, nat id);

// Función para obtener los jugadores en la lista de jugadores que tienen fecha igual al parametro "fecha"
// La lista resultado debe de respetar el orden de la lista original
// La lista resultado NO comparte memoria con la lista parametro
// Si no hay ningun jugador con esa fecha, se devuelve la lista vacia.
// La función es O(n*m) peor caso, donde n es la cantidad de jugadores en la lista y m es la cantidad de jugadas de la partida con mas jugadas entre todas las jugadores de la lista.
TJugadoresLDE obtenerSegunTFecha(TJugadoresLDE jugadores, TFecha fecha);

// Función que recibe dos listas de jugadores y las une en una NUEVA lista.
// Al final de la función se libera la memoria de las listas originales.
// La función es Theta(n1 + n2) peor caso, donde n1 es la cantidad de jugadores en la lista jugadores1 y n2 es la cantidad de jugadores en la lista jugadores2.
TJugadoresLDE unirTJugadoresLDE(TJugadoresLDE &jugadores1, TJugadoresLDE &jugadores2);

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

// Funcion que recibe una lista de jugadores y devuelve el jugador que tiene en primer lugar.
// PRE: cantidadTJugadoresLDE(personas) > 0
// La función es Theta(1) peor caso.
TJugador obtenerInicioDeTJugadoresLDE(TJugadoresLDE jugadores);

///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

#endif  // JUGADORESLDE_H
