/*
  Módulo de definición de 'TEvento'.

  Los elementos de tipo TEvento son elementos que almacenan un id, una descripción y una fecha.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef EVENTO_H
#define EVENTO_H

#include <string.h>

#include "fecha.h"

// Constante para definir el largo máximo de la descripción de un evento
const int MAX_DESCRIPCION = 100;

// Define el tipo TEvento como un puntero a rep_evento
typedef struct rep_evento *TEvento;

// Función que crea un elemento de tipo TEvento con los valores dados
TEvento crearTEvento(int id, const char descripcion[100], TFecha fecha);

// Función que retorna el id del evento
int idTEvento(TEvento evento);

// Función que retorna la fecha del evento
TFecha fechaTEvento(TEvento evento);

// Función que imprime la información del evento en el siguiente formato:
// Evento <id>: <descripcion>
// Fecha: <fecha>
void imprimirTEvento(TEvento evento);

// Función que libera la memoria asignada para un evento
// Debe liberar también la memoria de la fecha asociada
void liberarTEvento(TEvento &evento);

// Función que aumenta la cantidad de días en la fecha del evento
void posponerTEvento(TEvento &evento, int dias);

#endif  // EVENTO_H