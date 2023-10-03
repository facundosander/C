/*
  Módulo de definición de 'jugador'.

  Los elementos de tipo TJugador son elementos que almacenan un id, una edad, un pais, un nombre y una partida.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef JUGADOR_H
#define JUGADOR_H

#include <string.h>
#include "utils.h"
#include "partida.h"

// Definición de tipo TJugador como un puntero a rep_jugador
typedef struct rep_jugador *TJugador;

// Función para crear un jugador
// Devuelve un jugador con el id, edad, pais, nombre y partida pasados por parámetro
// La función es Theta(1) peor caso
TJugador crearTJugador(nat id, nat edad, const char pais[100], const char nombre[100], TPartida partida);

// Función para liberar la memoria asignada a un jugador
// La función es Theta(n) peor caso, donde n es la cantidad de jugadas en la partida del jugador
void liberarTJugador(TJugador &jugador);

// Función para imprimir un jugador con el siguiente formato:
// "Jugador *id*: *nombre*, *pais*, *edad* años\n"
// [partida del jugador]
// Por ejemplo, si tenemos a la jugador "Jugador1" con id 1, edad 20, pais "Uruguay" y dos jugadas en la partida la función imprimirá:
// "Jugador 1: Jugador1, Uruguay, 20 años
// Jugada 1:  
// Movimientos: <mov1_1> <mov1_2> <mov1_3> <mov1_4>
// Jugada 2:  
// Movimientos: <mov2_1> <mov2_2> <mov2_3> <mov2_4>"
//
// La función es Theta(n) peor caso, donde n es la cantidad de jugadas en la partida del jugador
void imprimirTJugador(TJugador jugador);

// Función para obtener el id de un jugador
// La función es Theta(1) peor caso
nat idTJugador(TJugador jugador);

// Función para obtener la edad de un jugador
// La función es Theta(1) peor caso
nat edadTJugador(TJugador jugador);

// Función para obtener el nombre de un jugador
// La función es Theta(1) peor caso
char* nombreTJugador(TJugador jugador);

// Función para obtener el pais de un jugador
// La función es Theta(1) peor caso
char* paisTJugador(TJugador jugador);

// Función para obtener la partida de un jugador
// La función es Theta(1) peor caso
TPartida partidaTJugador(TJugador jugador);

// Función para agregar una jugada a la partida de un jugador
// La función es Theta(n) peor caso, siendo n la cantidad de jugadas en la partida del jugador
void agregarJugadaATJugador(TJugador &jugador, TJugada jugada);

// Función para remover una jugada de la partida de un jugador
// La función es Theta(n) peor caso, siendo n la cantidad de jugadas en la partida del jugador
// PRE: La jugada está en la partida del jugador
void removerJugadaDeTJugador(TJugador &jugador, int numeroDeJugada);

// Función para determinar si una jugada está en la partida de un jugador
// La función es Theta(n) peor caso, siendo n la cantidad de jugadas en la partida del jugador
bool estaEnPartidaDeTJugador(TJugador jugador, int numeroDeJugada);

// Función para obtener una jugada de la partida de un jugador
// La función es Theta(n) peor caso, siendo n la cantidad de jugadas en la partida del jugador
// PRE: La jugada está en la partida del jugador
TJugada obtenerDePartidaDeTJugador(TJugador jugador, int numeroDeJugada);

// Función para copiar un jugador
// La función es Theta(n) peor caso, siendo n la cantidad de jugadas en la partida del jugador
TJugador copiarTJugador(TJugador jugador);

#endif // JUGADOR_H