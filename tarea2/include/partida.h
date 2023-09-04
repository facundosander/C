/*
  Módulo de definición de 'TPartida'.

  Los elementos de tipo TPartida almacenan una serie de TJugada con una estructura de lista simple ordenada por numero de jugada.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef PARTIDA_H
#define PARTIDA_H

#include "jugada.h"

// Definición de tipo TPartida como un puntero a rep_partida
typedef struct rep_partida* TPartida;

// Función para crear un elemento de tipo TPartida
// Devuelve una partida vacía
// La función es Theta(1) peor caso
TPartida crearTPartida();

// Función para agregar una jugada a una partida
// Recibe un elemento de tipo TPartida y un elemento de tipo TJugada y lo agrega a la partida en orden por numero de jugada (de menor a mayor)
// La función es Theta(n) peor caso, siendo n la cantidad de jugadas en la partida
void agregarEnTPartida(TPartida& partida, TJugada jugada);

// Función para imprimir todas las jugadas de una partida
// Recibe un elemento de tipo TPartida e imprime sus jugadas en orden
// El formato en el que se debe imprimir la partida es utilizando de forma secuencial la función ImprimirTJugada
// Si la partida está vacía no imprime nada
// La función es Theta(n) peor caso, siendo n la cantidad de jugadas en la partida
void imprimirTPartida(TPartida partida);

// Función para liberar una partida
// Recibe una referencia a un elemento de tipo TPartida y libera su memoria
// Libera además la memoria de cada una de las jugadas en la partida
// La función es Theta(n) peor caso, siendo n la cantidad de jugadas en la partida
void liberarTPartida(TPartida& partida);

// Funcion para verificar si una partida es vacia, retorna True si y solo si la partida es vacia
// La función es Theta(1) peor caso
bool esVaciaTPartida(TPartida partida);

// Retorna una copia de la partida pasada por parámetro, donde los jugadas de la copia son copias de los jugadas de la partida original
// La función es Theta(n) peor caso, siendo n la cantidad de jugadas en la partida
TPartida copiarTPartida(TPartida partida);

// Función para verificar si un elemento de tipo TJugada existe en una partida
// Recibe una partida y un numero de jugada de la jugada y regresa un booleano indicando su existencia
// La función es Theta(n) peor caso, siendo n la cantidad de jugadas en la partida
bool estaEnTPartida(TPartida partida, int numeroDeJugada);

// Función para obtener un jugada de una partida
// Recibe una partida y un numero de jugada de la partida y regresa la jugada con ese id
// La función es Theta(n) peor caso, siendo n la cantidad de jugadas en la partida
// PRE: La jugada debe estar en la partida
TJugada obtenerDeTPartida(TPartida partida, int numeroDeJugada);

// Función para imprimir todas las jugadas de una partida que contienen el movimiento "mov" en la posicion "pos"
// Si no hay jugadas con mov en la posicion pos, no imprime nada
// PRE: 1 <= pos <= 4
// La función es Theta(n) peor caso, siendo n la cantidad de jugadas en la partida
void imprimirJugadasConMovimiento(TPartida partida, int pos, Movimiento mov);

// Función para remover una jugada de una partida
// Recibe una partida y el numero de jugada de la jugada y elimina la jugada con ese numero de jugada de la partida
// La función es Theta(n) peor caso, siendo n la cantidad de jugadas en la partida
// PRE: La jugada debe estar en la partida
void removerDeTPartida(TPartida& partida, int numeroDeJugada);

#endif  // PARTIDA_H