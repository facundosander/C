/*
  Módulo de definición de 'aplicaciones'.

  El módulo de acplicaciones es para practicar el USO de TADs.
  Durante la implementación sólo se deben utilizar los TADs.
  Nunca se puede acceder a la representación de los datos.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef APLICACIONES_H
#define APLICACIONES_H

#include "jugadoresLDE.h"
#include "pilaJugador.h"
#include "conjuntoIds.h"

// Función que devuelve una TPilaJugador con las jugadores de 'lista' cuyas edades son menores estrictas que las de cada una de las siguientes.
// Es decir, en el resto de la lista no hay ningún jugador cuya edad es menor o igual.
// En la TPilaJugador resultado los elementos deben estar en orden reverso al que estaban en 'lista'. 
// Que la TPilaJugador resultado esté en orden reverso implica que la edad del jugador de la cima es mayor que todas las demás.
// La TPilaJugador resultado no comparte memoria con los elementos de 'lista' y al final de la ejecución de la función 'lista' debe quedar vacía.
// No se deben usar estructuras auxiliares ni definir funciones auxiliares.
// El tiempo de ejecución debe ser O(n*m) pero caso, siendo 'n' la cantidad de elementos de 'lista' y 'm' la cantidad máxima de partidas de los jugadores de 'lista'.
TPilaJugador menoresQueElResto(TJugadoresLDE lista);

// Función que determina si hay un par de ids pertenecientes a "c" tales que su suma es igual a "k"
// La función es Theta(n) peor caso, siendo "n" la cantidad máxima de elementos de "c"
bool sumaPares(nat k, TConjuntoIds c);


#endif  // APLICACIONES_H
