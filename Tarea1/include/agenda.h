/*
  Módulo de definición de 'TAgenda'.

  Los elementos de tipo TAgenda almacenan una serie de TEventos.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#ifndef AGENDA_H
#define AGENDA_H

#include "evento.h"

// Constante para definir el número máximo de eventos en una agenda
const int MAX_EVENTOS = 100;

// Definición de tipo TAgenda como un puntero a rep_agenda
typedef struct rep_agenda* TAgenda;

// Función para crear un elemento de tipo TAgenda
TAgenda crearTAgenda();

// Función para agregar un evento a una agenda
// Recibe un elemento de tipo TAgenda y un elemento de tipo TEvento y lo agrega a la agenda en orden por fecha (de menor a mayor)
// Si dos eventos tienen la misma fecha, deben ordenarse por orden de creación, de más nuevo a más antiguo
// Si la cantidad de eventos en la agenda es igual a MAX_EVENTOS, la función no tiene efecto
void agregarEnAgenda(TAgenda& agenda, TEvento evento);

// Función para imprimir todos los eventos de una agenda
// Recibe un elemento de tipo TAgenda e imprime sus eventos en orden cronológico
// El formato en el que se debe imprimir la agenda es utilizando de forma secuencial la función ImprimirTEvento
// Si la agenda está vacía no imprime nada
void imprimirTAgenda(TAgenda agenda);

// Función para liberar una agenda
// Recibe una referencia a un elemento de tipo TAgenda y libera su memoria
// Libera además la memoria de cada uno de los eventos en la agenda
void liberarTAgenda(TAgenda& agenda);

// Función para verificar si un elemento de tipo TEvento existe en una agenda
// Recibe una agenda y un identificador del evento y regresa un booleano indicando su existencia
bool estaEnAgenda(TAgenda agenda, int id);

// Función para obtener un evento de una agenda
// Recibe una agenda y un identificador del evento y regresa el evento con ese id
// PRE: El evento debe estar en la agenda
TEvento obtenerDeAgenda(TAgenda agenda, int id);

// Función para posponer un evento en una agenda
// Recibe una agenda, el identificador del evento y un número de días y pospone el evento con ese identificador en la agenda
// El evento pospuesto debe reubicarse en la agenda según el criterio de orden establecido
// En caso de que la nueva fecha del evento pospuesto coincida con la de otro evento en la agenda, el evento con la fecha 
// modificada debe quedar inmediatamente antes en la agenda que todos los de fecha igual o posterior.
// PRE: El evento debe estar en la agenda
void posponerEnAgenda(TAgenda& agenda, int id, nat n);

// Función para imprimir todos los eventos de una agenda que ocurren en una fecha determinada
// Recibe una agenda y una fecha e imprime los eventos que ocurren en esa fecha por orden de creación (más nuevo a más antiguo)
// Si no hay eventos con esa fecha no imprime nada
void imprimirEventosFecha(TAgenda agenda, TFecha fecha);

// Función que determina si existe algún evento en la agenda con la fecha pasada por parámetro.
// La función debe ejecutar un algoritmo de búsqueda binaria
bool hayEventosFecha(TAgenda agenda, TFecha fecha);

// Función para remover un evento de una agenda
// Recibe una agenda y el identificador del evento y elimina el evento con ese identificador de la agenda
// PRE: El evento debe estar en la agenda
void removerDeAgenda(TAgenda& agenda, int id);

#endif  // AGENDA_H