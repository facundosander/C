/*
  Módulo de definición de 'conjuntoPersonas'.

  Los estructura de tipo conjuntoIds es un conjunto acotado que almacena ids.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef CONJUNTOIDS_H
#define CONJUNTOIDS_H

#include "utils.h"

// Definición de tipo TConjuntoIds como un puntero a rep_conjuntoIds
// El conjunto es acotado, y la cantidad máxima de elementos define el rango de identificadores que almacena
// Los identificadores que almacena el conjunto cumplen 0<id<=cantMax
typedef struct rep_conjuntoIds* TConjuntoIds;



//------------------------ FUNCIONES TÍPICAS ------------------------

// Función para crear un nuevo conjunto de ids
// Devuelve un conjunto vacío
// La funcion es Theta(n) peor caso, siendo n la cantidad máxima de elementos del conjunto
TConjuntoIds crearTConjuntoIds(nat cantMax);

// Función para determinar si un conjunto de ids es vacío
// Devuelve true si el conjunto es vacío, false en otro caso
// La funcion es Theta(1) peor caso
bool esVacioTConjuntoIds(TConjuntoIds c);

// Procedimiento para insertar el identificador "id" en el conjunto de ids "c"
// Si "id" no pertenece al rango válido de ids del conjunto "c" la función no hace nada   
// La función es Theta(1) peor caso
void insertarTConjuntoIds(nat id, TConjuntoIds &c); 

// Procedimiento para borrar al "id" del conjunto de ids "c"
// Si "id" no pertenece al conjunto "c" la función no hace nada
// La función es Theta(1) peor caso
void borrarTConjuntoIds(nat id, TConjuntoIds &c);

// Función para determinar si el identificador "id" pertenece al conjunto "c"
// Devuelve true si pertenece, false en otro caso
// La funcion es Theta(1) peor caso
bool perteneceTConjuntoIds(nat id, TConjuntoIds c);

// Función que retorna la cantidad de elementos del conjunto de ids "c"
// La función es Theta(1) peor caso
nat cardinalTConjuntoIds(TConjuntoIds c);

// Función que retorna la cantidad máxima de elementos del conjunto de ids "c"
// La función es Theta(1) peor caso
nat cantMaxTConjuntoIds(TConjuntoIds c);

// Procedimiento para imprimir el conjunto de ids
// Imprime los ids del conjunto ordenado de menor a mayor
// Deben imprimirse solamente los elementos, separados por un espacio, con un salto de línea al final
// Ejemplo: si el conjunto "c" tiene los elementos 7, 29, 42 y 75 la impresión debe ser "7 29 42 75 "
// La función es Theta(n) peor caso, siendo "n" la cantidad máxima de elementos de "c"
void imprimirTConjuntoIds(TConjuntoIds c);

// Procedimiento para liberar la memoria asignada a un conjunto de ids
// La funcion es Theta(1) peor caso
void liberarTConjuntoIds(TConjuntoIds &c);



//------------------------ OPERACIONES ENTRE CONJUNTOS ------------------------

// Función que retorna la unión entre los conjuntos de ids "c1" y "c2"
// Ambos conjuntos tienen la misma cantidad máxima de elementos, "n"
// La función es Theta(n) peor caso
TConjuntoIds unionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2);

// Función que retorna la intersección entre los conjuntos de ids "c1" y "c2"
// Ambos conjuntos tienen la misma cantidad máxima de elementos, "n"
// La función es Theta(n) peor caso
TConjuntoIds interseccionTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2);

// Función que retorna la diferencia entre los conjuntos de ids "c1" y "c2"
// Ambos conjuntos tienen la misma cantidad máxima de elementos, "n"
// La función es Theta(n) peor caso
TConjuntoIds diferenciaTConjuntoIds(TConjuntoIds c1, TConjuntoIds c2);

#endif  // CONJUNTOIDS_H
