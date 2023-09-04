/*
  Módulo de definición de 'jugadoresABB'.

  La estructura de tipo jugadoresABB es un arbol binario de búsqueda que almacena a los jugadores por id. 

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef JUGADORESABB_H
#define JUGADORESABB_H

#include "jugadoresLDE.h"

// Definición de tipo TJugadoresABB como un puntero a rep_jugadorABB
typedef struct rep_jugadoresABB* TJugadoresABB;

// Función para crear un nuevo árbol binario
// Devuelve un nuevo árbol binario vacío
// La funcion es Theta(1) peor caso
TJugadoresABB crearTJugadoresABB();

// Función para determinar si un árbol binario es vacío
// Devuelve true si el árbol binario es vacío, false en caso contrario
// La funcion es Theta(1) pero caso
bool esVacioTJugadoresABB(TJugadoresABB jugadoresABB);

// Función para insertar un jugador en el árbol binario ordenado por id
// La funcion es Theta(n) peor caso, siendo n la cantidad de jugadores en el árbol binario
// PRE: El jugador no está en el árbol binario
void insertarTJugadoresABB(TJugadoresABB &jugadoresABB, TJugador p);

// Función para liberar la memoria asignada a un árbol binario
// La función es O(n*m) peor caso, donde n es la cantidad de jugadores en el árbol y m es la cantidad de jugadas de la partidas con mas jugadas entre todas los jugadores del árbol.
void liberarTJugadoresABB(TJugadoresABB &jugadoresABB);

// Función para imprimir los jugadores del árbol binario en orden de id
// La función es O(n*m) peor caso, donde n es la cantidad de jugadores en el árbol y m es la cantidad de jugadas de la partidas con mas jugadas entre todas los jugadores del árbol.
void imprimirTJugadoresABB(TJugadoresABB jugadoresABB);

// Función para obtener la cantidad de jugadores en el árbol binario
// La funcion es Theta(n) peor caso, siendo n la cantidad de jugadores en el árbol binario
nat cantidadTJugadoresABB(TJugadoresABB jugadoresABB);

// Función para obtener el jugador con el id más grande del árbol binario
// La funcion es Theta(n) peor caso, siendo n la cantidad de jugadores en el árbol binario
// PRE: el árbol binario no es vacío
TJugador maxIdJugador(TJugadoresABB jugadoresABB);

// Función para eliminar un jugador del árbol binario
// En caso de que el nodo a remover tenga ambos subárboles no vacíos,
// se reemplaza por el Jugador con el id más grande del subárbol izquierdo. 
// La función es Theta(n+m) peor caso, donde n es la cantidad de jugadores en el árbol y m es la cantidad de jugadas de la partidas de la perosna a remover.
// PRE: El jugador está en el árbol binario
void removerTJugadoresABB(TJugadoresABB &jugadoresABB, nat id);

// Función que determina si un jugador está en el árbol binario
// Devuelve true si el jugador está en el árbol binario, false en caso contrario
// La funcion es Theta(n) peor caso, siendo n la cantidad de jugadores en el árbol binario
bool estaTJugadoresABB(TJugadoresABB jugadoresABB, nat id);

// Función para obtener un jugador del árbol binario
// La funcion es Theta(n) peor caso, siendo n la cantidad de jugadores en el árbol binario
// PRE: el jugador está en el árbol binario
TJugador obtenerDeTJugadoresABB(TJugadoresABB jugadoresABB, nat id);

// Funcion para obtener la altura del árbol binario
// La funcion es Theta(n) peor caso, siendo n la cantidad de jugadores en el árbol binario
nat alturaTJugadoresABB(TJugadoresABB jugadoresABB);

// Función para determinar si el árbol binario es perfecto
// Devuelve true si el árbol binario es perfecto, false en caso contrario
// La funcion es Theta(n) peor caso, siendo n la cantidad de jugadores en el árbol binario
bool esPerfectoTJugadoresABB(TJugadoresABB jugadoresABB);

// Función que retorna un nuevo TJugadoresABB con los jugadores de jugadoresABB que son mayores a cierta edad
// El árbol retornado NO comparte memoria con el árbol pasado por parámetro.
// En caso de que deba elegir un nuevo nodo como raíz seleccione el nodo con el id más grande del 
// subárbol izquierdo.
// La funcion es O(n*m) peor caso, donde n es la cantidad de jugadores en el árbol y m es la cantidad de jugadas de la partidas con mas jugadas entre todas los jugadores del árbol.
TJugadoresABB mayoresTJugadoresABB(TJugadoresABB jugadoresABB, nat edad);

#endif  // JUGADORESABB_H