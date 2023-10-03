/*
  Módulo principal de la Tarea 3.

Intérprete de comandos para probar los módulos implementados.

Cada comando tiene un nombre y una secuencia (posiblemente vacía) de parámetros.
Se asume que los comandos están bien formados. Esto implica que:
- el nombre es uno de los descritos más abajo;
- la cantidad y tipo de los parámetros cumplen con lo requerido.

El comando 'Fin' termina el programa

El comando '# comentario' imprime comentario.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
*/

#define cmd_es(nom_comando, cmd) (0 == strcmp(nom_comando, cmd))

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "include/partida.h"
#include "include/jugadoresABB.h"
#include "include/conjuntoIds.h"
#include "include/colaJugadoresABB.h"
#include "include/aplicaciones.h"


#define MAX_PALABRA 32
#define MAX_LINEA 256
Movimiento movArr[4] = { Derecha, Izquierda, Arriba, Abajo};

// Lee una fecha de la entrada en formato "dd/mm/aaaa" y la escribe la variable fecha
void leerFecha(TFecha &fecha);

/* La implementación de las funciones de testeo se realiza al final del archivo*/
// Funciones para testear fecha
void main_crearFecha(TFecha &fecha); 
void main_liberarFecha(TFecha &fecha);
void main_imprimirFecha(TFecha fecha);
void main_aumentarDias(TFecha &fecha);
void main_compararFechas(); 
void main_copiarFecha(TFecha fecha);
// Funciones para testear jugada
void main_crearJugada(TJugada &jugada);
void main_liberarJugada(TJugada &jugada);
void main_imprimirNumeroJugada(TJugada jugada);
void main_tieneMovimientoEnPosTJugada(TJugada jugada);
void main_imprimirMovimientoJugada(TJugada jugada);
void main_imprimirJugada(TJugada jugada);
void main_copiarJugada(TJugada jugada);
// Funciones para testear partida
void main_crearPartida(TPartida &partida);
void main_agregarEnPartida(TPartida &partida, TJugada &jugada);
void main_liberarPartida(TPartida &partida);
void main_esVaciaPartida(TPartida partida);
void main_imprimirPartida(TPartida partida);
void main_estaEnPartida(TPartida partida);
void main_obtenerDeTPartida(TPartida partida);
void main_removerDePartida(TPartida &partida);
void main_imprimirJugadasConMovimiento(TPartida partida);
void main_imprimirCopiaPartida(TPartida partida);
// Funciones para testear jugador
void main_crearJugador(TJugador &jugador, TPartida &partida);
void main_imprimirIdJugador(TJugador jugador);
void main_imprimirEdadJugador(TJugador jugador);
void main_imprimirNombreJugador(TJugador jugador);
void main_imprimirPaisJugador(TJugador jugador);
void main_imprimirPartidaJugador(TJugador jugador);
void main_imprimirJugador(TJugador jugador);
void main_liberarJugador(TJugador &jugador);
void main_agregarJugadaJugador(TJugador &jugador, TJugada &jugada);
void main_removerJugadaJugador(TJugador &jugador);
void main_estaEnPartidaJugador(TJugador jugador);
void main_imprimirJugadasFechaJugador(TJugador jugador);
void main_imprimirJugadaJugador(TJugador jugador);
void main_imprimirCopiaJugador(TJugador jugador);
//Funciones para testear jugadoresLDE
void main_crearListaJugadores(TJugadoresLDE &listaJugadores);
void main_liberarListaJugadores(TJugadoresLDE &listaJugadores);
void main_imprimirMayorAMenorTJugadoresLDE(TJugadoresLDE &listaJugadores);
void main_imprimirMenorAMayorTJugadoresLDE(TJugadoresLDE &listaJugadores);
void main_insertarJugadorListaJugadores(TJugadoresLDE &listaJugadores, TJugador &jugador, TFecha &fecha);
void main_imprimirJugadorListaJugadores(TJugadoresLDE &listaJugadores);
void main_imprimirFechaDeJugadorListaJugadores(TJugadoresLDE &listaJugadores);
void main_eliminarInicioListaJugadores(TJugadoresLDE &listaJugadores);
void main_eliminarFinalListaJugadores(TJugadoresLDE &listaJugadores);
void main_imprimirCantidadListaJugadores(TJugadoresLDE &listaJugadores);
void main_estaEnListaJugadores(TJugadoresLDE &listaJugadores);
void main_unirConVacioListaJugadores(TJugadoresLDE &listaJugadores);
void main_crearYUnirListaJugadores(TJugadoresLDE &listaJugadores);
void main_unirListaJugadoresTiempo(TJugadoresLDE &listaJugadores);
void main_imprimirInicioListaJugadores(TJugadoresLDE &listaJugadores);
//Funciones para testear jugadoresABB
void main_crearArbolJugadores(TJugadoresABB &arbolJugadores);
void main_esVacioArbolJugadores(TJugadoresABB arbolJugadores);
void main_liberarArbolJugadores(TJugadoresABB &arbolJugadores);
void main_insertarArbolJugadores(TJugadoresABB &arbolJugadores, TJugador &jugador);
void main_estaEnArbolJugadores(TJugadoresABB arbolJugadores);
void main_removerArbolJugadores(TJugadoresABB &arbolJugadores);
void main_imprimirArbolJugadores(TJugadoresABB arbolJugadores);
void main_imprimirCantidadArbolJugadores(TJugadoresABB arbolJugadores);
void main_imprimirJugadorArbolJugadores(TJugadoresABB arbolJugadores);
void main_alturaArbolJugadores(TJugadoresABB arbolJugadores);
void main_esPerfectoArbolJugadores(TJugadoresABB arbolJugadores);
void main_maxIdJugadorArbolJugadores(TJugadoresABB arbolJugadores);
void main_mayoresEdadArbolJugadores(TJugadoresABB arbolJugadores);
void main_esPerfectoArbolJugadoresTiempo(TJugadoresABB &arbolJugadores);
void main_esPerfectoArbolJugadoresTiempo2(TJugadoresABB &arbolJugadores);
void main_mayoresEdadArbolJugadoresTiempo(TJugadoresABB &arbolJugadores);
void main_amplitudArbolJugadores(TJugadoresABB arbolJugadores);
void main_amplitudArbolJugadoresTiempo(TJugadoresABB &arbolJugadores);
void main_serializarArbolJugadores(TJugadoresABB arbolJugadores);
void main_deserializarArbolJugadores(TPilaJugador pilaJugadores);
void main_deserializarArbolJugadoresTiempo();
//Funciones para testear pilaJugadores
void main_crearPilaJugadores(TPilaJugador &pilaJugadores);
void main_liberarPilaJugadores(TPilaJugador &pilaJugadores);
void main_imprimirCantidadPila(TPilaJugador &pilaJugadores);
void main_apilarJugadorPilaJugadores(TPilaJugador &pilaJugadores, TJugador &jugador);
void main_cima(TPilaJugador &pilaJugadores);
void main_desapilar(TPilaJugador &pilaJugadores);
void main_imprimirPila(TPilaJugador &pilaJugadores);
//Funciones para testear conjuntoIds
void main_crearConjuntoIds(TConjuntoIds &conjuntoIds);
void main_insertarConjuntoIds(TConjuntoIds &conjuntoIds);
void main_imprimirConjuntoIds(TConjuntoIds &conjuntoIds);
void main_liberarConjuntoIds(TConjuntoIds &conjuntoIds);
void main_esVacioConjuntoIds(TConjuntoIds &conjuntoIds);
void main_borrarConjuntoIds(TConjuntoIds &conjuntoIds);
void main_perteneceConjuntoIds(TConjuntoIds &conjuntoIds);
void main_cardinalConjuntoIds(TConjuntoIds &conjuntoIds);
void main_cantMaxConjuntoIds(TConjuntoIds &conjuntoIds);
void main_unionConjuntoIds(TConjuntoIds &conjuntoIds1, TConjuntoIds &conjuntoIds2);
void main_interseccionConjuntoIds(TConjuntoIds &conjuntoIds1, TConjuntoIds &conjuntoIds2);
void main_diferenciaConjuntoIds(TConjuntoIds &conjuntoIds1, TConjuntoIds &conjuntoIds2);
//Funciones para testear colaJugadoresABB
void main_crearCola(TColaJugadoresABB &colaJugadoresABB);
void main_liberarCola(TColaJugadoresABB &colaJugadoresABB);
void main_cantidadEnCola(TColaJugadoresABB &colaJugadoresABB);
void main_encolar(TColaJugadoresABB &colaJugadoresABB, TJugadoresABB &arbolJugadores);
void main_frente(TColaJugadoresABB &colaJugadoresABB, TJugadoresABB &arbolJugadores);
void main_desencolar(TColaJugadoresABB &colaJugadoresABB);
//Funciones para testear las aplicaciones
void main_menoresQueElResto(TJugadoresLDE lista);
void main_menoresQueElRestoTiempo();
void main_sumaPares(TConjuntoIds &conjuntoIds);
void main_sumaParesTiempo();

// programa principal que lee comandos de la entrada estándar e invoca a la función de test correspondiente
int main() {
    TFecha fecha = NULL;
    TJugada jugada = NULL;
    TPartida partida = NULL;
    TJugador jugador = NULL;
    TJugadoresLDE listaJugadores = NULL;
    TJugadoresABB arbolJugadores = NULL;
    TPilaJugador pilaJugadores = NULL;
    TConjuntoIds conjuntoIds[2] = {NULL, NULL};
    TColaJugadoresABB colaJugadoresABB = NULL;

    char restoLinea[MAX_LINEA + 1];
    char cmd[MAX_PALABRA];

    int cont_comandos = 0;
    bool seguir = true;
    while (seguir) {
        // mostrar el prompt
        cont_comandos++;
        printf("%u>", cont_comandos);

        // leer el comando en la variable cmd
        leerChars(cmd);

        // procesar el comando
        if (cmd_es("Fin", cmd)) {  // Termina el programa
            seguir = false;
            printf("Fin.\n");

        } else if (cmd_es("#", cmd)) {  // Imprime el comentario luego del #
            leerRestoLinea(restoLinea);
            printf("# %s.\n", restoLinea);

            ///////////////////////////////////
            /* Funciones para testear fecha */
            ///////////////////////////////////

        } else if (cmd_es("crearFecha", cmd)) {  // Crea una fecha y la almacena en la variable fecha
            main_crearFecha(fecha);

        } else if (cmd_es("imprimirFecha", cmd)) {  // Imprime la fecha almacenada en la variable fecha
            main_imprimirFecha(fecha);

        } else if (cmd_es("liberarFecha", cmd)) {  // Libera la memoria de la variable fecha
            main_liberarFecha(fecha);

        } else if (cmd_es("aumentarDias", cmd)) {  // Aumenta la fecha almacenada en la variable fecha en la cantidad de días indicada
            main_aumentarDias(fecha);

        } else if (cmd_es("compararFechas", cmd)) {  // Compara dos fechas leidas de la entrada
            main_compararFechas();

        } else if (cmd_es("copiarFecha", cmd)) {  // Copia la fecha almacenada en la variable fecha en otra variable fecha
            main_copiarFecha(fecha);

        }

            ///////////////////////////////////
            /* Funciones para testear jugada */
            ///////////////////////////////////

          else if (cmd_es("crearJugada", cmd)) {  // Crea un jugada y lo almacena en la variable jugada
            main_crearJugada(jugada);

        } else if (cmd_es("imprimirNumeroJugada", cmd)) {  // Imprime el numero de la jugada almacenada en la variable jugada
            main_imprimirNumeroJugada(jugada);

        } else if (cmd_es("imprimirMovimientoJugada", cmd)) {  // Imprime la fecha de la jugada almacenada en la variable jugada
            main_imprimirMovimientoJugada(jugada);

        } else if (cmd_es("tieneMovimientoEnPosTJugada", cmd)) {  // Chequea si la jugada tiene cierto movimiento en una posicion dada
            main_tieneMovimientoEnPosTJugada(jugada);

        } else if (cmd_es("imprimirJugada", cmd)) {  // Imprime toda la información de la jugada almacenado en la variable jugada
            main_imprimirJugada(jugada);

        } else if (cmd_es("liberarJugada", cmd)) {  // Libera la memoria de la jugada almacenado en la variable jugada
            main_liberarJugada(jugada);

        } else if (cmd_es("copiarJugada", cmd)) {  // Copia el jugada almacenada en la variable jugada en otra variable de tipo jugada
            main_copiarJugada(jugada);

        }

            ///////////////////////////////////
            /* Funciones para testear partida */
            ///////////////////////////////////

          else if (cmd_es("crearPartida", cmd)) {  // Crea una partida y la almacena en la variable "partida"
            main_crearPartida(partida);

        } else if (cmd_es("agregarEnPartida", cmd)) {  // Agrega el jugada almacenada en la variable jugada a la partida almacenada en la variable "partida"
            main_agregarEnPartida(partida, jugada);

        } else if (cmd_es("imprimirPartida", cmd)) {  // Imprime toda la información de la partida almacenada en la variable "partida"
            main_imprimirPartida(partida);

        } else if (cmd_es("liberarPartida", cmd)) {  // Libera la memoria de la partida almacenada en la variable "partida"
            main_liberarPartida(partida);

        } else if (cmd_es("esVaciaPartida", cmd)) {  // Evalua si una partida es vacia
            main_esVaciaPartida(partida);

        } else if (cmd_es("estaEnPartida", cmd)) {  // Indica si la jugada almacenada en la variable jugada está en la partida almacenada en la variable "partida"
            main_estaEnPartida(partida);

        } else if (cmd_es("obtenerDePartida", cmd)) {  // Indica si la jugada almacenada en la variable jugada está en la partida almacenada en la variable "partida"
            main_obtenerDeTPartida(partida);

        } else if (cmd_es("removerDePartida", cmd)) {  // Remueve la jugada almacenada en la variable jugada de la partida almacenada en la variable "partida"
            main_removerDePartida(partida);

        } else if (cmd_es("imprimirJugadasConMovimiento", cmd)) {  // Imprime todas las jugadas de la partida que contienen el movimiento "mov" en la posicion "pos"
            main_imprimirJugadasConMovimiento(partida);

        } else if (cmd_es("imprimirCopiaPartida", cmd)) {  // Imprime una copia de la partida almacenada en la variable "partida"
            main_imprimirCopiaPartida(partida);
        }

            ///////////////////////////////////
            /* Funciones para testear jugador */
            ///////////////////////////////////

        else if (cmd_es("crearJugador", cmd)) {  
            main_crearJugador(jugador, partida);
        
        } else if (cmd_es("liberarJugador", cmd)){ // Libera la memoria de un jugador almacenado en la variable "jugador"
            main_liberarJugador(jugador);

        }else if (cmd_es("imprimirIdJugador", cmd)) {  // Imprime el id de un jugador almacenado en la variable "jugador"
            main_imprimirIdJugador(jugador);

        } else if (cmd_es("imprimirEdadJugador", cmd)) {  // Imprime la edad del jugador almacenado en la variable "jugador"
            main_imprimirEdadJugador(jugador);
                
        } else if (cmd_es("imprimirPaisJugador", cmd)) {  // Imprime el nombre del jugador almacenado en la variable "jugador"
            main_imprimirPaisJugador(jugador);

        } else if (cmd_es("imprimirNombreJugador", cmd)) {  // Imprime el nombre del jugador almacenado en la variable "jugador"
            main_imprimirNombreJugador(jugador);

        } else if (cmd_es("imprimirPartidaJugador", cmd)) {  // Imprime la partida del jugador almacenado en la variable "jugador"
            main_imprimirPartidaJugador(jugador);

        } else if (cmd_es("imprimirJugador", cmd)) {  // Imprime todos los datos del jugador almacenado en la variable "jugador"
            main_imprimirJugador(jugador);

        } else if (cmd_es("agregarJugadaJugador", cmd)){ // Agrega la jugada almacenada en la variable "jugada" a la partida del jugador almacenado en la variable "jugador"
            main_agregarJugadaJugador(jugador, jugada);

        } else if (cmd_es("removerJugadaJugador", cmd)){ // Remueve la jugada con el Id pasado por parametro de la partida del jugador almacenado en la variable "jugador"
            main_removerJugadaJugador(jugador);

        } else if (cmd_es("estaEnPartidaJugador", cmd)){  // Determina si una jugada está en la partida de un jugador
            main_estaEnPartidaJugador(jugador);

        } else if (cmd_es("imprimirJugadaJugador", cmd)){ // Imprime la jugada con Id pasado por parametro de la partida de un jugador almacenado en la variable "jugador"
            main_imprimirJugadaJugador(jugador);

        } else if (cmd_es("imprimirCopiaJugador", cmd)){ // Imprime una copia de un jugador almacenado en la variable "jugador"
            main_imprimirCopiaJugador(jugador);

        }

            ///////////////////////////////////
            /* Funciones para testear pila de jugadores */
            ///////////////////////////////////

        else if (cmd_es("crearPilaJugadores", cmd)) {  // Crea una pila de jugadores y la almacena en la variable pilaJugadores
            main_crearPilaJugadores(pilaJugadores);


        } else if (cmd_es("liberarPilaJugadores", cmd)) {  // Libera la memoria de la pila de jugadores almacenada en la variable pilaJugadores
            main_liberarPilaJugadores(pilaJugadores);

        } else if (cmd_es("imprimirCantidadPila", cmd)) {  // Imprime la cantidad de elementos de la pila
            main_imprimirCantidadPila(pilaJugadores);

        } else if (cmd_es("apilarPilaJugadores", cmd)) {  // Agrega el jugador almacenado en la variable jugador a la pila de jugadores almacenada en la variable pilaJugadores
            main_apilarJugadorPilaJugadores(pilaJugadores, jugador);

        } else if (cmd_es("obtenerCimaPila", cmd)) {
            main_cima(pilaJugadores);

        } else if (cmd_es("desapilar", cmd)) {
            main_desapilar(pilaJugadores);
        } 

            ///////////////////////////////////
            /* Funciones para testear lista de jugadores */
            ///////////////////////////////////

        else if (cmd_es("crearListaJugadores", cmd)) {  // Crea una lista de jugadores y la almacena en la variable listaJugadores
            main_crearListaJugadores(listaJugadores);

        } else if (cmd_es("liberarListaJugadores", cmd)) {  // Libera la memoria de la lista de jugadores almacenada en la variable listaJugadores
            main_liberarListaJugadores(listaJugadores);

        } else if (cmd_es("imprimirMayorAMenorTJugadoresLDE", cmd)) {  // Imprime toda la información de la lista de jugadores almacenada en la variable listaJugadores de mayor a menor segun sus fechas
            main_imprimirMayorAMenorTJugadoresLDE(listaJugadores);

        } else if (cmd_es("imprimirMenorAMayorTJugadoresLDE", cmd)) {  // Imprime toda la información de la lista de jugadores almacenada en la variable listaJugadores de menor a mayor segun sus fechas
            main_imprimirMenorAMayorTJugadoresLDE(listaJugadores);

        } else if (cmd_es("insertarJugadorListaJugadores", cmd)) {  // Agrega la jugador almacenada en la variable jugador a la lista de jugadores almacenada en la variable listaJugadores
            main_insertarJugadorListaJugadores(listaJugadores, jugador, fecha);

        } else if (cmd_es("imprimirJugadorListaJugadores", cmd)) {  // Imprime la jugador con Id pasado por parametro de la lista de jugadores almacenada en la variable listaJugadores
            main_imprimirJugadorListaJugadores(listaJugadores);

        } else if (cmd_es("imprimirFechaDeJugadorListaJugadores", cmd)) {  // Imprime la fecha del jugador con Id pasado por parametro de la lista de jugadores almacenada en la variable listaJugadores
            main_imprimirFechaDeJugadorListaJugadores(listaJugadores);

        } else if (cmd_es("imprimirCantidadListaJugadores", cmd)) {
            main_imprimirCantidadListaJugadores(listaJugadores);

        } else if (cmd_es("eliminarInicioListaJugadores", cmd)) {
            main_eliminarInicioListaJugadores(listaJugadores);

        } else if (cmd_es("eliminarFinalListaJugadores", cmd)) {
            main_eliminarFinalListaJugadores(listaJugadores);

        } else if (cmd_es("estaEnListaJugadores", cmd)) {
            main_estaEnListaJugadores(listaJugadores);
            
        } else if (cmd_es("unirConVacioListaJugadores", cmd)) {
            main_unirConVacioListaJugadores(listaJugadores);
            
        } else if (cmd_es("crearYUnirListaJugadores", cmd)) {
            main_crearYUnirListaJugadores(listaJugadores);
            
        } else if (cmd_es("unirListaJugadoresTiempo", cmd)) {
            main_unirListaJugadoresTiempo(listaJugadores);
            
        } else if (cmd_es("imprimirInicioListaJugadores", cmd)) {
            main_imprimirInicioListaJugadores(listaJugadores);
        }
            ///////////////////////////////////
            /* Funciones para testear arbol de jugadores */
            ///////////////////////////////////

        else if (cmd_es("crearArbolJugadores", cmd)) {
            main_crearArbolJugadores(arbolJugadores);

        } else if (cmd_es("esVacioArbolJugadores", cmd)) {
            main_esVacioArbolJugadores(arbolJugadores);

        } else if (cmd_es("liberarArbolJugadores", cmd)) {
            main_liberarArbolJugadores(arbolJugadores);

        } else if (cmd_es("insertarJugadorArbolJugadores", cmd)) {
            main_insertarArbolJugadores(arbolJugadores, jugador);

        } else if (cmd_es("imprimirCantidadArbolJugadores", cmd)) {
            main_imprimirCantidadArbolJugadores(arbolJugadores);

        } else if (cmd_es("imprimirArbolJugadores", cmd)) {
            main_imprimirArbolJugadores(arbolJugadores);

        } else if (cmd_es("estaEnArbolJugadores", cmd)) {
            main_estaEnArbolJugadores(arbolJugadores);

        } else if (cmd_es("removerArbolJugadores", cmd)) {
            main_removerArbolJugadores(arbolJugadores);

        } else if (cmd_es("imprimirJugadorArbolJugadores", cmd)) {
            main_imprimirJugadorArbolJugadores(arbolJugadores);

        } else if (cmd_es("alturaArbolJugadores", cmd)) {
            main_alturaArbolJugadores(arbolJugadores);

        } else if (cmd_es("esPerfectoArbolJugadores", cmd)) {
            main_esPerfectoArbolJugadores(arbolJugadores);

        } else if (cmd_es("maxIdJugadorArbolJugadores", cmd)) {
            main_maxIdJugadorArbolJugadores(arbolJugadores);

        } else if (cmd_es("mayoresEdadArbolJugadores", cmd)) {
            main_mayoresEdadArbolJugadores(arbolJugadores);

        } else if (cmd_es("esPerfectoArbolJugadoresTiempo", cmd)) {
            main_esPerfectoArbolJugadoresTiempo(arbolJugadores);

        } else if (cmd_es("esPerfectoArbolJugadoresTiempo2", cmd)) {
            main_esPerfectoArbolJugadoresTiempo2(arbolJugadores);

        } else if (cmd_es("mayoresEdadArbolJugadoresTiempo", cmd)) {
            main_mayoresEdadArbolJugadoresTiempo(arbolJugadores);

        } else if (cmd_es("amplitudArbolJugadores", cmd)) {
            main_amplitudArbolJugadores(arbolJugadores);

        } else if (cmd_es("amplitudArbolJugadoresTiempo", cmd)) {
            main_amplitudArbolJugadoresTiempo(arbolJugadores);

        } else if (cmd_es("serializarArbolJugadores", cmd)) {
            main_serializarArbolJugadores(arbolJugadores);

        } else if (cmd_es("deserializarArbolJugadores", cmd)) {
            main_deserializarArbolJugadores(pilaJugadores);

        } else if (cmd_es("deserializarArbolJugadoresTiempo", cmd)) {
            main_deserializarArbolJugadoresTiempo();    

            //////////////////////////////////////////////////
            /* Funciones para testear conjunto de jugadores */
            //////////////////////////////////////////////////
        }else if (cmd_es("crearConjunto", cmd)) {
            main_crearConjuntoIds(conjuntoIds[0]);

        } else if (cmd_es("insertarConjunto", cmd)) {
            main_insertarConjuntoIds(conjuntoIds[0]);

        } else if (cmd_es("imprimirConjunto", cmd)) {
            main_imprimirConjuntoIds(conjuntoIds[0]);

        } else if (cmd_es("liberarConjunto", cmd)) {
            main_liberarConjuntoIds(conjuntoIds[0]);

        } else if (cmd_es("esVacioConjunto", cmd)) {
            main_esVacioConjuntoIds(conjuntoIds[0]);

        } else if (cmd_es("borrarConjunto", cmd)) {
            main_borrarConjuntoIds(conjuntoIds[0]);

        } else if (cmd_es("perteneceConjunto", cmd)) {
            main_perteneceConjuntoIds(conjuntoIds[0]);

        } else if (cmd_es("cardinalConjunto", cmd)) {
            main_cardinalConjuntoIds(conjuntoIds[0]);

        } else if (cmd_es("cantMaxConjunto", cmd)) {
            main_cantMaxConjuntoIds(conjuntoIds[0]);

        } else if (cmd_es("unionConjunto", cmd)) {
            main_unionConjuntoIds(conjuntoIds[0], conjuntoIds[1]);

        } else if (cmd_es("interseccionConjunto", cmd)) {
            main_interseccionConjuntoIds(conjuntoIds[0], conjuntoIds[1]);

        } else if (cmd_es("diferenciaConjunto", cmd)) {
            main_diferenciaConjuntoIds(conjuntoIds[0], conjuntoIds[1]);

        } else if (cmd_es("crearConjuntoAux", cmd)) {
            main_crearConjuntoIds(conjuntoIds[1]);

        } else if (cmd_es("liberarConjuntoAux", cmd)) {
            main_liberarConjuntoIds(conjuntoIds[1]);

        } else if (cmd_es("imprimirConjuntoAux", cmd)) {
            main_imprimirConjuntoIds(conjuntoIds[1]);

        } else if (cmd_es("insertarConjuntoAux", cmd)) {
            main_insertarConjuntoIds(conjuntoIds[1]);

            /////////////////////////////////////////////
            /* Funciones para testear colaJugadoresABB */
            /////////////////////////////////////////////
        
        }else if (cmd_es("crearCola", cmd)) {
            main_crearCola(colaJugadoresABB);

        } else if (cmd_es("liberarCola", cmd)) {
            main_liberarCola(colaJugadoresABB);

        } else if (cmd_es("imprimirCantidadCola", cmd)) {
            main_cantidadEnCola(colaJugadoresABB);

        } else if (cmd_es("encolar", cmd)) {
            main_encolar(colaJugadoresABB, arbolJugadores);

        } else if (cmd_es("obtenerFrenteCola", cmd)) {
            main_frente(colaJugadoresABB, arbolJugadores);

        } else if (cmd_es("desencolar", cmd)) {
            main_desencolar(colaJugadoresABB);

           ///////////////////////////////////
           /* Funciones para testear las aplicaciones */
           ///////////////////////////////////

        } else if (cmd_es("menoresQueElResto", cmd)) {
            main_menoresQueElResto(listaJugadores);

        } else if (cmd_es("menoresQueElRestoTiempo", cmd)) {
            main_menoresQueElRestoTiempo();

        } else if (cmd_es("sumaPares", cmd)) {
            main_sumaPares(conjuntoIds[0]);

        } else if (cmd_es("sumaParesTiempo", cmd)) {
            main_sumaParesTiempo();

        } else {
            printf("Comando no reconocido.\n");  // Comando no reconocido

        }  // if
        fgets(restoLinea, MAX_LINEA + 1, stdin);
    }  // while

    return 0;
}  // main

///////////////////////////////
/* Funciones main para Fecha */
///////////////////////////////

void leerFecha(TFecha &fecha) {
    nat *componentes = new nat[3];
    scanf("%u/%u/%u", &componentes[0], &componentes[1], &componentes[2]);
    fecha = crearTFecha(componentes[0], componentes[1], componentes[2]);
    delete[] componentes;
}

void main_crearFecha(TFecha &fecha) {
    assert(fecha == NULL);
    leerFecha(fecha);
}

void main_liberarFecha(TFecha &fecha) {
    assert(fecha != NULL);
    liberarTFecha(fecha);
}

void main_imprimirFecha(TFecha fecha) {
    assert(fecha != NULL);
    imprimirTFecha(fecha);
}

void main_aumentarDias(TFecha &fecha) {
    assert(fecha != NULL);
    nat cantDias = leerNat();
    aumentarTFecha(fecha, cantDias);
    printf("La nueva fecha aplazada %d dias es: ", cantDias);
    imprimirTFecha(fecha);
}

void main_compararFechas() {
    TFecha fecha1 = NULL, fecha2 = NULL;
    leerFecha(fecha1);
    leerFecha(fecha2);
    int comp = compararTFechas(fecha1, fecha2);
    if (comp == 0) {
        printf("Las fechas son iguales. \n");
    } else if (comp == 1) {
        printf("La primera fecha es posterior a la segunda. \n");
    } else
        printf("La primera fecha es anterior a la segunda. \n");
    liberarTFecha(fecha1);
    liberarTFecha(fecha2);
}

void main_copiarFecha(TFecha fecha) {
    assert(fecha != NULL);
    TFecha fechaCopia = copiarTFecha(fecha);
    printf("La fecha copiada es: ");
    imprimirTFecha(fechaCopia);
    liberarTFecha(fechaCopia);
}

/////////////////////////////////
/* Funciones main para Jugadas */
/////////////////////////////////

void main_crearJugada(TJugada &jugada) {
    assert(jugada == NULL);
    int id = leerNat();
    int mov1 = leerNat();
    int mov2 = leerNat();
    int mov3 = leerNat();
    int mov4 = leerNat();
    jugada = crearTJugada(id, movArr[mov1 -1], movArr[mov2 -1], movArr[mov3 -1], movArr[mov4 -1]); 
}

void main_imprimirNumeroJugada(TJugada jugada) {
    assert(jugada != NULL);
    printf("El numero de la jugada es: %d\n", numeroTJugada(jugada));
}

void main_imprimirMovimientoJugada(TJugada jugada) {
    assert(jugada != NULL);
    Movimiento * movsJugada = movimientoTJugada(jugada);
    assert(movsJugada != NULL);
    printf("Los movimientos son: ");
    for(int i = 0; i < 4; i++){
        switch (movsJugada[i])
        {
            case Derecha: 
                printf("Derecha ");
            break;
            case Izquierda: 
                printf("Izquierda ");
            break;
            case Arriba: 
                printf("Arriba ");
            break;
            default:
                printf("Abajo ");
        }
    }
    printf("\n");
}

void main_tieneMovimientoEnPosTJugada(TJugada jugada){
    assert(jugada != NULL);
    int pos = leerNat();
    int indiceMov = leerNat();
    Movimiento mov;
    switch (indiceMov)
        {
            case 1: 
                mov = Derecha;
            break;
            case 2: 
                    mov = Izquierda;
            break;
            case 3: 
                mov = Arriba ;
            break;
            case 4: 
                mov = Abajo ;
            default:;
        }
    if (tieneMovimientoEnPosTJugada(jugada, pos, mov))
        printf("La jugada contiene el movimiento en dicha posicion.\n");
    else
        printf("La jugada NO contiene el movimiento en dicha posicion.\n");

}

void main_imprimirJugada(TJugada jugada) {
    assert(jugada != NULL);
    imprimirTJugada(jugada);
}

void main_liberarJugada(TJugada &jugada) {
    assert(jugada != NULL);
    liberarTJugada(jugada);
}

void main_copiarJugada(TJugada jugada) {
    assert(jugada != NULL);
    TJugada jugadaCopia = copiarTJugada(jugada);
    printf("La jugada copiado es: ");
    imprimirTJugada(jugadaCopia);
    liberarTJugada(jugadaCopia);
}

////////////////////////////////
/* Funciones main para Partida */
////////////////////////////////

void main_crearPartida(TPartida &partida) {
    assert(partida == NULL);
    partida = crearTPartida();
}

void main_liberarPartida(TPartida &partida) {
    liberarTPartida(partida);
}

void main_esVaciaPartida(TPartida partida){
    if (esVaciaTPartida(partida))
        printf("La partida esta vacia.\n");
    else
        printf("La partida NO esta vacia.\n");
}

void main_estaEnPartida(TPartida partida) {
    nat numero = leerNat();
    if (estaEnTPartida(partida, numero))
        printf("La jugada con numero %d está en la partida.\n", numero);
    else
        printf("La jugada con numero %d NO está en la partida.\n", numero);
}

void main_obtenerDeTPartida(TPartida partida){
    assert(partida != NULL);
    nat numero = leerNat();
    if (estaEnTPartida(partida, numero)){
        TJugada jugada = obtenerDeTPartida(partida, numero);
        imprimirTJugada(jugada);
    }else{
        printf("La jugada con numero %d NO está en la partida.\n", numero);
    }
}

void main_removerDePartida(TPartida &partida) {
    nat numero = leerNat();
    if (estaEnTPartida(partida, numero)) {
        removerDeTPartida(partida, numero);
        printf("La jugada con numero %d se removió de la partida.\n", numero);
    } else
        printf("La jugada con numero %d NO está en la partida.\n", numero);
}

void main_agregarEnPartida(TPartida &partida, TJugada &jugada) {
    assert(jugada != NULL);
    agregarEnTPartida(partida, jugada);
    jugada = NULL;
}

void main_imprimirPartida(TPartida partida) {
    imprimirTPartida(partida);
}

void main_imprimirJugadasConMovimiento(TPartida partida) {
    nat pos = leerNat();
    nat mov = leerNat();
    imprimirJugadasConMovimiento(partida, pos, movArr[mov-1]);
}

void main_imprimirCopiaPartida (TPartida partida) {
    if (esVaciaTPartida(partida)) {
        printf("La partida está vacía.\n");
    }
    TPartida copia = copiarTPartida(partida);
    if (esVaciaTPartida(copia))
        printf("La copia está vacía.\n");
    else
        imprimirTPartida(copia);

    liberarTPartida(copia);
}

////////////////////////////////
/* Funciones main para Jugador */
////////////////////////////////

void main_crearJugador(TJugador &jugador, TPartida &partida){
    assert (jugador == NULL);
    nat id = leerNat();
    nat edad = leerNat();
    char pais[100];
    leerChars(pais);
    char nombre[100];
    leerRestoLinea(nombre);
    jugador = crearTJugador(id, edad, pais, nombre, partida);
    partida = NULL;
}

void main_liberarJugador(TJugador &jugador){
    assert (jugador != NULL);
    liberarTJugador(jugador);
    jugador=NULL;
}

void main_imprimirIdJugador(TJugador jugador){
    assert (jugador != NULL);
    printf("El id del jugador es: %d\n", idTJugador(jugador));
}

void main_imprimirEdadJugador(TJugador jugador){
    assert (jugador != NULL);
    printf("La edad del jugador es: %d\n", edadTJugador(jugador));
}   

void main_imprimirPaisJugador(TJugador jugador){
    assert (jugador != NULL);
    printf("El pais del jugador es: %s\n", paisTJugador(jugador));
}

void main_imprimirNombreJugador(TJugador jugador){
    assert (jugador != NULL);
    printf("El nombre del jugador es: %s\n", nombreTJugador(jugador));
}

void main_imprimirPartidaJugador(TJugador jugador){
    assert (jugador != NULL);
    imprimirTPartida(partidaTJugador(jugador));
}

void main_imprimirJugador(TJugador jugador){
    assert (jugador != NULL);
    imprimirTJugador(jugador);   
}

void main_agregarJugadaJugador(TJugador &jugador, TJugada &jugada){
    assert (jugador != NULL && jugada != NULL);
    agregarJugadaATJugador(jugador, jugada);
    jugada = NULL;
}

void main_removerJugadaJugador(TJugador &jugador){
    assert (jugador != NULL);
    nat id = leerNat();
    removerJugadaDeTJugador(jugador, id);
}

void main_estaEnPartidaJugador(TJugador jugador){
    assert (jugador != NULL);
    nat id = leerNat();
    if (estaEnPartidaDeTJugador(jugador, id))
        printf("La jugada con id %d está en la partida de la jugador.\n", id);
    else
        printf("La jugada con id %d NO está en la partida de la jugador.\n", id);
}

void main_imprimirJugadaJugador(TJugador jugador){
    assert (jugador != NULL);
    nat id = leerNat();
    TJugada jugada = obtenerDePartidaDeTJugador(jugador, id);
    imprimirTJugada(jugada);
}

void main_imprimirCopiaJugador(TJugador jugador){
    assert (jugador != NULL);
    TJugador copia = copiarTJugador(jugador);
    imprimirTJugador(copia);
    liberarTJugador(copia);
}


//////////////////////////////////////
/* Funciones main para JugadoresLDE */
//////////////////////////////////////

void main_crearListaJugadores(TJugadoresLDE &listaJugadores){
    assert (listaJugadores == NULL);
    listaJugadores = crearTJugadoresLDE();
}

void main_liberarListaJugadores(TJugadoresLDE &listaJugadores){
    assert (listaJugadores != NULL);
    liberarTJugadoresLDE(listaJugadores);
}

void main_insertarJugadorListaJugadores(TJugadoresLDE &listaJugadores, TJugador &jugador, TFecha &fecha){
    assert (listaJugadores != NULL && jugador != NULL && fecha != NULL);
    insertarTJugadoresLDE(listaJugadores, jugador, fecha);
    jugador = NULL;
    fecha = NULL;
}

void main_eliminarInicioListaJugadores(TJugadoresLDE &listaJugadores){
    assert (listaJugadores != NULL);
    eliminarInicioTJugadoresLDE(listaJugadores);
}

void main_eliminarFinalListaJugadores(TJugadoresLDE &listaJugadores){
    assert (listaJugadores != NULL);
    eliminarFinalTJugadoresLDE(listaJugadores);
}

void main_imprimirMayorAMenorTJugadoresLDE(TJugadoresLDE &listaJugadores){
    assert (listaJugadores != NULL);
    imprimirMayorAMenorTJugadoresLDE(listaJugadores);
}

void main_imprimirMenorAMayorTJugadoresLDE(TJugadoresLDE &listaJugadores){
    assert (listaJugadores != NULL);
    imprimirMenorAMayorTJugadoresLDE(listaJugadores);
}

void main_imprimirCantidadListaJugadores(TJugadoresLDE &listaJugadores){
    assert (listaJugadores != NULL);
    printf("La cantidad de jugadores en la lista es: %d.\n", cantidadTJugadoresLDE(listaJugadores));
}

void main_estaEnListaJugadores(TJugadoresLDE &listaJugadores){
    assert (listaJugadores != NULL);
    nat id = leerNat();
    if (estaEnTJugadoresLDE(listaJugadores, id))
        printf("La jugador con id %d está en la lista.\n", id);
    else
        printf("La jugador con id %d NO está en la lista.\n", id);
}

void main_imprimirJugadorListaJugadores(TJugadoresLDE &listaJugadores){
    assert (listaJugadores != NULL);
    nat id = leerNat();
    TJugador jugador = obtenerTJugadorDeTJugadoresLDE(listaJugadores, id);
    imprimirTJugador(jugador);
}

void main_imprimirFechaDeJugadorListaJugadores(TJugadoresLDE &listaJugadores){
    assert (listaJugadores != NULL);
    nat id = leerNat();
    TFecha fecha = obtenerTFechaDeTJugadoresLDE(listaJugadores, id);
    imprimirTFecha(fecha);
}

void main_unirConVacioListaJugadores(TJugadoresLDE &listaJugadores){
    assert (listaJugadores != NULL);
    TJugadoresLDE listaJugadores2 = crearTJugadoresLDE();
    TJugadoresLDE jugadoresUnidos = unirTJugadoresLDE(listaJugadores, listaJugadores2);
    listaJugadores = jugadoresUnidos;
}
void main_crearYUnirListaJugadores(TJugadoresLDE &listaJugadores){
    assert (listaJugadores != NULL);
    TPartida partida = crearTPartida();
    TJugador jugador = crearTJugador(1, 20, "Uruguay","Juan", partida);
    TPartida partida2 = crearTPartida();
    TJugador jugador2 = crearTJugador(2, 21, "China", "Pedro", partida2);
    TPartida partida3 = crearTPartida();
    TJugador jugador3 = crearTJugador(3, 22, "Australia", "Maria", partida3);
    TFecha fecha1 = crearTFecha(26,1,1999);
    TFecha fecha2 = crearTFecha(2,5,2002);
    TFecha fecha3 = crearTFecha(7,5,2002);
    TJugadoresLDE listaJugadores2 = crearTJugadoresLDE();
    insertarTJugadoresLDE(listaJugadores2, jugador, fecha1);
    insertarTJugadoresLDE(listaJugadores2, jugador2, fecha2);
    insertarTJugadoresLDE(listaJugadores2, jugador3, fecha3);
    TJugadoresLDE jugadoresUnidos = unirTJugadoresLDE(listaJugadores, listaJugadores2);
    listaJugadores = jugadoresUnidos;
}

void main_unirListaJugadoresTiempo(TJugadoresLDE &listaJugadores){
    assert (listaJugadores != NULL);
    nat tamanio = leerNat();
    nat timeout = leerNat();
    clock_t tm = clock();
    for (nat i = 0; i < tamanio; i++){
        TPartida partida = crearTPartida();
        TFecha fecha1 = crearTFecha(26,1,1999);
        TJugador jugador = crearTJugador(1, 20, "Uruguay","Juan", partida);
        insertarTJugadoresLDE(listaJugadores, jugador, fecha1);
    }
    TJugadoresLDE listaJugadores2 = crearTJugadoresLDE();
    for (nat i = 0; i < tamanio; i++){
        TPartida partida = crearTPartida();
        TFecha fecha1 = crearTFecha(26,1,1999);
        TJugador jugador = crearTJugador(1, 20, "Uruguay","Juan", partida);
        insertarTJugadoresLDE(listaJugadores2, jugador, fecha1);
    }
    
    TJugadoresLDE jugadoresUnidos = unirTJugadoresLDE(listaJugadores, listaJugadores2);
    listaJugadores = jugadoresUnidos;
    
    tm = clock() - tm;
    float tiempo = ((float)tm) / CLOCKS_PER_SEC;
    //printf("%f \n", tiempo);
    if (tiempo > timeout)
    printf("ERROR, tiempo excedido; %.1f > %d \n", tiempo, timeout);
    else
    printf("Bien.\n");
}

void main_imprimirInicioListaJugadores(TJugadoresLDE &listaJugadores){
    assert (listaJugadores!= NULL);
    TJugador jugador = obtenerInicioDeTJugadoresLDE(listaJugadores);
    imprimirTJugador(jugador);
}

//ACAA

void main_crearArbolJugadores(TJugadoresABB &arbolJugadores){
    assert (arbolJugadores == NULL);
    arbolJugadores = crearTJugadoresABB();
}

void main_esVacioArbolJugadores(TJugadoresABB arbolJugadores){
    if (esVacioTJugadoresABB(arbolJugadores))
        printf("El árbol de jugadores está vacío.\n");
    else
        printf("El árbol de jugadores NO está vacío.\n");
}

void main_liberarArbolJugadores(TJugadoresABB &arbolJugadores){
    liberarTJugadoresABB(arbolJugadores);
}

void main_insertarArbolJugadores(TJugadoresABB &arbolJugadores, TJugador &jugador){
    assert (jugador != NULL);
    insertarTJugadoresABB(arbolJugadores, jugador);
    jugador = NULL;
}

void main_estaEnArbolJugadores(TJugadoresABB arbolJugadores){
    nat id = leerNat();
    if (estaTJugadoresABB(arbolJugadores, id))
        printf("La jugador con id %d está en el árbol de jugadores.\n", id);
    else
        printf("La jugador con id %d NO está en el árbol de jugadores.\n", id);
}

void main_removerArbolJugadores(TJugadoresABB &arbolJugadores){
    nat id = leerNat();
    removerTJugadoresABB(arbolJugadores, id);
}

void main_imprimirArbolJugadores(TJugadoresABB arbolJugadores){
    imprimirTJugadoresABB(arbolJugadores);
}

void main_imprimirCantidadArbolJugadores(TJugadoresABB arbolJugadores){
    printf("La cantidad de jugadores en el árbol es: %d.\n", cantidadTJugadoresABB(arbolJugadores));
}

void main_imprimirJugadorArbolJugadores(TJugadoresABB arbolJugadores){
    assert(!esVacioTJugadoresABB(arbolJugadores));
    nat id = leerNat();
    if (!estaTJugadoresABB(arbolJugadores, id))
        printf("La jugador con id %d NO está en el árbol de jugadores.\n", id);
    else{
        TJugador jugador = obtenerDeTJugadoresABB(arbolJugadores, id);
        imprimirTJugador(jugador);
    }
}

void main_alturaArbolJugadores(TJugadoresABB arbolJugadores){
    printf("La altura del árbol de jugadores es: %d.\n", alturaTJugadoresABB(arbolJugadores));
}

void main_esPerfectoArbolJugadores(TJugadoresABB arbolJugadores){
    if (esPerfectoTJugadoresABB(arbolJugadores))
        printf("El árbol de jugadores es perfecto.\n");
    else
        printf("El árbol de jugadores NO es perfecto.\n");
}

void main_esPerfectoArbolJugadoresTiempo(TJugadoresABB &arbolJugadores){
    nat tamanio = leerNat();
    nat timeout = leerNat();

    for (nat i = 0; i < tamanio; i++){
        TJugador jugador = crearTJugador(i, 20, "Uruguay", "Juan", NULL);
        insertarTJugadoresABB(arbolJugadores, jugador);
    }
    
    clock_t tm = clock();
    bool result = esPerfectoTJugadoresABB(arbolJugadores);
    tm = clock() - tm;
    if (result)
        printf("El árbol de jugadores es perfecto.\n");
    else
        printf("El árbol de jugadores NO es perfecto.\n");
    float tiempo = ((float)tm) / CLOCKS_PER_SEC;
    //printf("%f \n", tiempo);
    if (tiempo > timeout)
        printf("ERROR, tiempo excedido; %.1f > %d \n", tiempo, timeout);
    else
        printf("Bien.\n");
}

void insertarEnArbolDeArreglo(TJugadoresABB &arbolJugadores, TJugador *arreglo, int inicio, int final){
    if (inicio <= final){
        int mid = (inicio + final) / 2;
        insertarTJugadoresABB(arbolJugadores, arreglo[mid]);
        insertarEnArbolDeArreglo(arbolJugadores, arreglo, inicio, mid - 1);
        insertarEnArbolDeArreglo(arbolJugadores, arreglo, mid + 1, final);
    }
}

void main_esPerfectoArbolJugadoresTiempo2(TJugadoresABB &arbolJugadores){
    nat tamanio = leerNat();
    nat timeout = leerNat();

    TJugador *arreglo = new TJugador[tamanio];

    for (nat i = 0; i < tamanio; i++){
        TPartida partida = crearTPartida();
        arreglo[i] = crearTJugador(i, 20, "Uruguay","Juan", partida);
    }

    int inicio = 0;
    int final = tamanio - 1;
    insertarEnArbolDeArreglo(arbolJugadores, arreglo, inicio, final);
    clock_t tm = clock();
    bool result = esPerfectoTJugadoresABB(arbolJugadores);
    tm = clock() - tm;
    if (result)
        printf("El árbol de jugadores es perfecto.\n");
    else
        printf("El árbol de jugadores NO es perfecto.\n");
    float tiempo = ((float)tm) / CLOCKS_PER_SEC;
    //printf("%f \n", tiempo);
    if (tiempo > timeout)
        printf("ERROR, tiempo excedido; %.1f > %d \n", tiempo, timeout);
    else
        printf("Bien.\n");

    delete[] arreglo;
}

void main_maxIdJugadorArbolJugadores(TJugadoresABB arbolJugadores){
    assert (!esVacioTJugadoresABB(arbolJugadores));
    TJugador jugador = maxIdJugador(arbolJugadores);
    printf("El jugador con mayor id en el árbol es: \n");
    imprimirTJugador(jugador);
}

void main_mayoresEdadArbolJugadores(TJugadoresABB arbolJugadores){
    nat edad = leerNat();
    TJugadoresABB arbolMayores = mayoresTJugadoresABB(arbolJugadores, edad);
    imprimirTJugadoresABB(arbolMayores);
    liberarTJugadoresABB(arbolMayores);
}

void main_mayoresEdadArbolJugadoresTiempo(TJugadoresABB &arbolJugadores){
    nat tamanio = leerNat();
    nat timeout = leerNat();
    nat edad = leerNat();

    TJugador *arreglo = new TJugador[tamanio];
    for (nat i = 0; i < tamanio; i++) {
        arreglo[i] = crearTJugador(i, i*2, "Uruguay", "Juan", NULL);
    }

    nat inicio = 0;
    nat final = tamanio - 1;
    insertarEnArbolDeArreglo(arbolJugadores, arreglo, inicio, final);
    clock_t tm = clock();
    TJugadoresABB arbolMayores = mayoresTJugadoresABB(arbolJugadores, edad);
    tm = clock() - tm;
    imprimirTJugadoresABB(arbolMayores);
    float tiempo = ((float)tm) / CLOCKS_PER_SEC;
    //printf("%f \n", tiempo);
    if (tiempo > timeout)
        printf("ERROR, tiempo excedido; %.1f > %d \n", tiempo, timeout);
    else
        printf("Bien.\n");
    
    liberarTJugadoresABB(arbolMayores);
    delete[] arreglo;
}


void main_amplitudArbolJugadores(TJugadoresABB arbolJugadores){
    nat amp = amplitudTJugadoresABB(arbolJugadores);
    printf ("La amplitud del árbol es: %d.\n", amp);
}

void main_amplitudArbolJugadoresTiempo(TJugadoresABB &arbolJugadores){
    nat tamanio = leerNat();
    nat timeout = leerNat();

    TJugador *arreglo = new TJugador[tamanio];
    for (nat i = 0; i < tamanio; i++) {
        TPartida partida = crearTPartida();
        arreglo[i] = crearTJugador(i, i*2, "Uruguay", "Juan", partida);
    }

    nat inicio = 0;
    nat final = tamanio - 1;
    insertarEnArbolDeArreglo(arbolJugadores, arreglo, inicio, final);
    clock_t tm = clock();
    nat amp = amplitudTJugadoresABB(arbolJugadores);
    tm = clock() - tm;
    printf ("La amplitud del árbol es: %d.\n", amp);
    float tiempo = ((float)tm) / CLOCKS_PER_SEC;
    //printf("%f \n", tiempo);
    if (tiempo > timeout)
        printf("ERROR, tiempo excedido; %.1f > %d \n", tiempo, timeout);
    else
        printf("Bien.\n");
    
    delete[] arreglo;
}

void main_serializarArbolJugadores(TJugadoresABB arbolJugadores){
    TPilaJugador pilaJugadores = serializarTJugadoresABB(arbolJugadores);
    main_imprimirPila(pilaJugadores);
    liberarTPilaJugador(pilaJugadores);
}

void main_deserializarArbolJugadores(TPilaJugador pilaJugadores){
    TJugadoresABB arbolJugadores = deserializarTJugadoresABB(pilaJugadores);
    imprimirTJugadoresABB(arbolJugadores);
    liberarTJugadoresABB(arbolJugadores);
}

void main_deserializarArbolJugadoresTiempo(){
    nat tamanio = leerNat();
    nat timeout = leerNat();

    TPilaJugador pila = crearTPilaJugador();
    for (nat i = 0; i < tamanio; i++) {
        TJugador jugador = crearTJugador(i, i*2, "Uruguay", "Juan", NULL);
        apilarEnTPilaJugador(pila, jugador);
        liberarTJugador(jugador);
    }

    clock_t tm = clock();
    TJugadoresABB arbol = deserializarTJugadoresABB(pila);
    tm = clock() - tm;
    nat amp = amplitudTJugadoresABB(arbol);
    nat cant = cantidadTJugadoresABB(arbol);
    printf ("La amplitud del árbol es: %d.\n", amp);
    printf ("La cantidad de jugadores en el árbol es: %d.\n", cant);
    liberarTJugadoresABB(arbol);
    float tiempo = ((float)tm) / CLOCKS_PER_SEC;
    //printf("%f \n", tiempo);
    if (tiempo > timeout)
        printf("ERROR, tiempo excedido; %.1f > %d \n", tiempo, timeout);
    else
        printf("Bien.\n");
}


//////////////////////////////////////
/* Funciones main para pilaJugadores */
//////////////////////////////////////


void main_crearPilaJugadores(TPilaJugador &pilaJugadores){
    assert (pilaJugadores == NULL);
    pilaJugadores = crearTPilaJugador();
}

void main_liberarPilaJugadores(TPilaJugador &pilaJugadores){
    assert (pilaJugadores != NULL);
    liberarTPilaJugador(pilaJugadores);
}

void main_apilarJugadorPilaJugadores(TPilaJugador &pilaJugadores, TJugador &jugador){
    assert (pilaJugadores != NULL && jugador != NULL);
    apilarEnTPilaJugador(pilaJugadores, jugador);
}

void main_imprimirCantidadPila(TPilaJugador &pilaJugadores){
	printf("La cantidad de jugadores en la pila es: %d.\n", cantidadEnTPilaJugador(pilaJugadores));
}

void main_cima(TPilaJugador &pilaJugadores){
    assert (pilaJugadores != NULL);
    TJugador jugador = cimaDeTPilaJugador(pilaJugadores);
    imprimirTJugador(jugador);
    jugador = NULL;
}

void main_desapilar(TPilaJugador &pilaJugadores){
    assert (pilaJugadores != NULL);
    desapilarDeTPilaJugador(pilaJugadores);
}

void main_imprimirPila(TPilaJugador &pilaJugadores){
    assert (pilaJugadores != NULL);
    while (cantidadEnTPilaJugador(pilaJugadores) > 0){
        TJugador jugador = cimaDeTPilaJugador(pilaJugadores);
        imprimirTJugador(jugador);
        desapilarDeTPilaJugador(pilaJugadores);
    }
}

///////////////////////////////////////////
/* Funciones main para ConjuntoJugadores */
///////////////////////////////////////////

void main_crearConjuntoIds(TConjuntoIds &conjuntoIds) {
    assert (conjuntoIds == NULL);
    nat cantMax = leerNat();
    conjuntoIds = crearTConjuntoIds(cantMax);
}

void main_insertarConjuntoIds(TConjuntoIds &conjuntoIds) {
    assert (conjuntoIds != NULL);
    nat id = leerNat();
    insertarTConjuntoIds(id, conjuntoIds);
}

void main_imprimirConjuntoIds(TConjuntoIds &conjuntoIds) {
    imprimirTConjuntoIds(conjuntoIds);
}

void main_liberarConjuntoIds(TConjuntoIds &conjuntoIds) {
    liberarTConjuntoIds(conjuntoIds);
}

void main_esVacioConjuntoIds(TConjuntoIds &conjuntoIds){
    if (esVacioTConjuntoIds(conjuntoIds))
       	printf("El conjunto de ids está vacío.\n");
    else
        printf("El conjunto de ids NO está vacío.\n");
}

void main_borrarConjuntoIds(TConjuntoIds &conjuntoIds) {
    assert (conjuntoIds != NULL);
    nat id = leerNat();
    borrarTConjuntoIds(id, conjuntoIds);
}

void main_perteneceConjuntoIds(TConjuntoIds &conjuntoIds) {
    assert (conjuntoIds != NULL);
    nat id = leerNat();
    if (perteneceTConjuntoIds(id, conjuntoIds)) {
        printf("El elemento %d pertenece al conjunto.\n", id);
    } else {
        printf("El elemento %d no pertenece al conjunto.\n", id);
    }
}

void main_cardinalConjuntoIds(TConjuntoIds &conjuntoIds) {
    assert (conjuntoIds != NULL);
    printf("El cardinal del conjunto es: %d.\n", cardinalTConjuntoIds(conjuntoIds));
}

void main_cantMaxConjuntoIds(TConjuntoIds &conjuntoIds) {
    assert (conjuntoIds != NULL);
    printf("La cantidad máxima del conjunto es: %d.\n", cantMaxTConjuntoIds(conjuntoIds));
}

void main_unionConjuntoIds(TConjuntoIds &conjuntoIds1, TConjuntoIds &conjuntoIds2) {
    assert (conjuntoIds1 != NULL && conjuntoIds2 != NULL);
    TConjuntoIds conjuntoIds = unionTConjuntoIds(conjuntoIds1, conjuntoIds2);
    imprimirTConjuntoIds(conjuntoIds);
    liberarTConjuntoIds(conjuntoIds);
}

void main_interseccionConjuntoIds(TConjuntoIds &conjuntoIds1, TConjuntoIds &conjuntoIds2) {
    assert (conjuntoIds1 != NULL && conjuntoIds2 != NULL);
    TConjuntoIds conjuntoIds = interseccionTConjuntoIds(conjuntoIds1, conjuntoIds2);
    imprimirTConjuntoIds(conjuntoIds);
    liberarTConjuntoIds(conjuntoIds);
}

void main_diferenciaConjuntoIds(TConjuntoIds &conjuntoIds1, TConjuntoIds &conjuntoIds2) {
    assert (conjuntoIds1 != NULL && conjuntoIds2 != NULL);
    TConjuntoIds conjuntoIds = diferenciaTConjuntoIds(conjuntoIds1, conjuntoIds2);
    imprimirTConjuntoIds(conjuntoIds);
    liberarTConjuntoIds(conjuntoIds);
}

//////////////////////////////////////////
/* Funciones main para ColaJugadoresABB */
//////////////////////////////////////////

void main_crearCola(TColaJugadoresABB &colaJugadoresABB){
    assert (colaJugadoresABB == NULL);
    colaJugadoresABB = crearTColaJugadoresABB();
}

void main_liberarCola(TColaJugadoresABB &colaJugadoresABB){
    liberarTColaJugadoresABB(colaJugadoresABB);
}

void main_cantidadEnCola(TColaJugadoresABB &colaJugadoresABB){
    printf("La cantidad de arboles de jugadores en la cola es: %d.\n", cantidadEnTColaJugadoresABB(colaJugadoresABB));
}

void main_encolar(TColaJugadoresABB &colaJugadoresABB, TJugadoresABB &arbolJugadores){
    assert (colaJugadoresABB != NULL);
    encolarEnTColaJugadoresABB(arbolJugadores, colaJugadoresABB);
    arbolJugadores = NULL; // se pierde la referencia al árbol, pero queda almacenado en la cola
}

void main_frente(TColaJugadoresABB &colaJugadoresABB, TJugadoresABB &arbolJugadores){
    assert (colaJugadoresABB != NULL);
    arbolJugadores = frenteDeTColaJugadoresABB(colaJugadoresABB); // recupero la referencia al arbol. debo encargarme de liberarlo
    if(!esVacioTJugadoresABB(arbolJugadores)){
        imprimirTJugadoresABB(arbolJugadores);
    }else{
        printf("Arbol vacio\n");
    }
}

void main_desencolar(TColaJugadoresABB &colaJugadoresABB){
    assert (colaJugadoresABB != NULL);
    desencolarDeTColaJugadoresABB(colaJugadoresABB);
}

////////////////////////////////
/* Funciones main para Aplicaciones */
////////////////////////////////

void main_sumaPares(TConjuntoIds &conjuntoIds) {
    assert (conjuntoIds != NULL);
    nat k = leerNat();
    if (sumaPares(k, conjuntoIds)) {
        printf("Existe un par de elementos en el conjunto cuya suma es %d.\n", k);
    } else {
        printf("No existe un par de elementos en el conjunto cuya suma es %d.\n", k);
    }
}

void main_sumaParesTiempo() {
    nat k = leerNat();
    nat tamanio = leerNat();
    nat timeout = leerNat();
    
    TConjuntoIds conjuntoIds = crearTConjuntoIds(tamanio);
    for (nat i = 0; i < tamanio; i++) {  
        insertarTConjuntoIds(i, conjuntoIds);
    }

    clock_t tm = clock();
    bool pares = sumaPares(k, conjuntoIds);
    tm = clock() - tm;
    float tiempo = ((float)tm) / CLOCKS_PER_SEC;
    //printf("%f \n", tiempo);
    if (pares) {
        printf("Existe un par de elementos en el conjunto cuya suma es %d.\n", k);
    } else {
        printf("No existe un par de elementos en el conjunto cuya suma es %d.\n", k);
    }
    liberarTConjuntoIds(conjuntoIds);
    
    if (tiempo > timeout)
        printf("ERROR, tiempo excedido; %.1f > %d \n", tiempo, timeout);
    else
        printf("Bien.\n");    
}

void main_menoresQueElResto(TJugadoresLDE lista) {
    assert (lista != NULL);
    TPilaJugador menores = menoresQueElResto(lista);
    main_imprimirPila(menores);
    liberarTPilaJugador(menores);    
}

void main_menoresQueElRestoTiempo(){
    nat tamanio = leerNat();
    nat timeout = leerNat();

    TJugadoresLDE listaJugadores = crearTJugadoresLDE();
   
    for (nat i = 0; i < tamanio; i++){
        TPartida partida = crearTPartida();
        TFecha fecha1 = crearTFecha(26,1,1999);
        TJugador jugador = crearTJugador(1, 20, "Uruguay","Juan", partida);
        insertarTJugadoresLDE(listaJugadores, jugador, fecha1);
    }

    clock_t tm = clock();
    TPilaJugador res = menoresQueElResto(listaJugadores);
    imprimirTJugador(cimaDeTPilaJugador(res));
    liberarTPilaJugador(res);   
    tm = clock() - tm;
    float tiempo = ((float)tm) / CLOCKS_PER_SEC;
    //printf("%f \n", tiempo);
    if (tiempo > timeout)
        printf("ERROR, tiempo excedido; %.1f > %d \n", tiempo, timeout);
    else
        printf("Bien.\n");

    liberarTJugadoresLDE(listaJugadores);
}
