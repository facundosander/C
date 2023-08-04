/*
  Módulo principal de la Tarea 1.

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

#include "include/agenda.h"

#define MAX_PALABRA 32
#define MAX_LINEA 256

// Lee una fecha de la entrada en formato "dd/mm/aaaa" y la escribe la variable fecha
void leerFecha(TFecha &fecha);

/* La implementación de las funciones de testeo se realiza al final del archivo*/
// Funciones para testear fecha
void main_crearFecha(TFecha &fecha); 
void main_liberarFecha(TFecha &fecha);
void main_imprimirFecha(TFecha fecha);
void main_aumentarDias(TFecha &fecha);
void main_compararFechas(); 
// Funciones para testear evento
void main_crearEvento(TEvento &evento, TFecha &fecha);
void main_liberarEvento(TEvento &evento);
void main_imprimirIdEvento(TEvento evento);
void main_imprimirFechaEvento(TEvento evento);
void main_imprimirEvento(TEvento evento);
void main_posponerEvento(TEvento &evento);
// Funciones para testear agenda
void main_crearAgenda(TAgenda &agenda);
void main_agregarEnAgenda(TAgenda &agenda, TEvento &evento);
void main_liberarAgenda(TAgenda &agenda);
void main_imprimirAgenda(TAgenda agenda);
void main_estaEnAgenda(TAgenda agenda);
void main_removerDeAgenda(TAgenda &agenda);
void main_posponerEnAgenda(TAgenda &agenda);
void main_hayEventosFechaAgenda(TAgenda agenda);
void main_imprimirEventosFechaAgenda(TAgenda agenda);

// programa principal que lee comandos de la entrada estándar e invoca a la función de test correspondiente
int main() {
    TFecha fecha = NULL;
    TEvento evento = NULL;
    TAgenda agenda = NULL;

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

            ///////////////////////////////////
            /* Funciones para testear evento */
            ///////////////////////////////////

        } else if (cmd_es("crearEvento", cmd)) {  // Crea un evento y lo almacena en la variable evento
            main_crearEvento(evento, fecha);

        } else if (cmd_es("imprimirIdEvento", cmd)) {  // Imprime el id del evento almacenado en la variable evento
            main_imprimirIdEvento(evento);

        } else if (cmd_es("imprimirFechaEvento", cmd)) {  // Imprime la fecha del evento almacenado en la variable evento
            main_imprimirFechaEvento(evento);

        } else if (cmd_es("imprimirEvento", cmd)) {  // Imprime toda la infromación del evento almacenado en la variable evento
            main_imprimirEvento(evento);

        } else if (cmd_es("liberarEvento", cmd)) {  // Libera la memoria del evento almacenado en la variable evento
            main_liberarEvento(evento);

        } else if (cmd_es("posponerEvento", cmd)) {  // Pospone el evento almacenado en la variable evento una cantidad de días indicada
            main_posponerEvento(evento);

            ///////////////////////////////////
            /* Funciones para testear agenda */
            ///////////////////////////////////

        } else if (cmd_es("crearAgenda", cmd)) {  // Crea una agenda y la almacena en la variable agenda
            main_crearAgenda(agenda);

        } else if (cmd_es("agregarEnAgenda", cmd)) {  // Agrega el evento almacenado en la variable evento a la agenda almacenada en la variable agenda
            main_agregarEnAgenda(agenda, evento);

        } else if (cmd_es("imprimirAgenda", cmd)) {  // Imprime toda la información de la agenda almacenada en la variable agenda
            main_imprimirAgenda(agenda);

        } else if (cmd_es("liberarAgenda", cmd)) {  // Libera la memoria de la agenda almacenada en la variable agenda
            main_liberarAgenda(agenda);

        } else if (cmd_es("estaEnAgenda", cmd)) {  // Indica si el evento almacenado en la variable evento está en la agenda almacenada en la variable agenda
            main_estaEnAgenda(agenda);

        } else if (cmd_es("posponerEnAgenda", cmd)) {  // Pospone el evento almacenado en la variable evento una cantidad de días indicada en la agenda almacenada en la variable agenda
            main_posponerEnAgenda(agenda);

        } else if (cmd_es("removerDeAgenda", cmd)) {  // Remueve el evento almacenado en la variable evento de la agenda almacenada en la variable agenda
            main_removerDeAgenda(agenda);

        } else if (cmd_es("hayEventosFechaAgenda", cmd)) {  // Indica si hay eventos en la agenda en una fecha indicada
            main_hayEventosFechaAgenda(agenda);

        } else if (cmd_es("imprimirEventosFechaAgenda", cmd)) {  // Imprime todos los eventos de la agenda con fecha igual a la indicada
            main_imprimirEventosFechaAgenda(agenda);

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

/////////////////////////////////
/* Funciones main para Eventos */
/////////////////////////////////

void main_crearEvento(TEvento &evento, TFecha &fecha) {
    assert(evento == NULL && fecha != NULL);
    int id = leerNat();
    char desc[100];
    leerRestoLinea(desc);
    evento = crearTEvento(id, desc, fecha);
    fecha = NULL;    
}

void main_imprimirIdEvento(TEvento evento) {
    assert(evento != NULL);
    printf("El id del evento es: %d\n", idTEvento(evento));
}

void main_imprimirFechaEvento(TEvento evento) {
    assert(evento != NULL);
    TFecha fechaEvento = fechaTEvento(evento);
    assert(fechaEvento != NULL);
    printf("La fecha del evento es: ");
    imprimirTFecha(fechaEvento);
}

void main_imprimirEvento(TEvento evento) {
    assert(evento != NULL);
    imprimirTEvento(evento);
}

void main_posponerEvento(TEvento &evento) {
    assert(evento != NULL);
    nat cantDias = leerNat();
    posponerTEvento(evento, cantDias);
}

void main_liberarEvento(TEvento &evento) {
    assert(evento != NULL);
    liberarTEvento(evento);
}

////////////////////////////////
/* Funciones main para Agenda */
////////////////////////////////

void main_crearAgenda(TAgenda &agenda) {
    assert(agenda == NULL);
    agenda = crearTAgenda();
}

void main_liberarAgenda(TAgenda &agenda) {
    assert(agenda != NULL);
    liberarTAgenda(agenda);
}

void main_estaEnAgenda(TAgenda agenda) {
    assert(agenda != NULL);
    nat id = leerNat();
    if (estaEnAgenda(agenda, id))
        printf("El evento con id %d está en la agenda.\n", id);
    else
        printf("El evento con id %d NO está en la agenda.\n", id);
}

void main_removerDeAgenda(TAgenda &agenda) {
    assert(agenda != NULL);
    nat id = leerNat();
    if (estaEnAgenda(agenda, id)) {
        removerDeAgenda(agenda, id);
        printf("El evento con id %d se removió de la agenda.\n", id);
    } else
        printf("El evento con id %d NO está en la agenda.\n", id);
}

void main_agregarEnAgenda(TAgenda &agenda, TEvento &evento) {
    assert(agenda != NULL && evento != NULL);
    agregarEnAgenda(agenda, evento);
    evento = NULL;
}

void main_posponerEnAgenda(TAgenda &agenda) {
    assert(agenda != NULL);
    nat id = leerNat();
    nat cantDias = leerNat();
    if (estaEnAgenda(agenda, id)) {
        posponerEnAgenda(agenda, id, cantDias);
        TEvento eventoPos = obtenerDeAgenda(agenda, id);
        TFecha fechaEvento = fechaTEvento(eventoPos);
        printf("La nueva fecha del evento %d pospuesto %d dias es: ", idTEvento(eventoPos), cantDias);
        imprimirTFecha(fechaEvento);
    } else
        printf("El evento con id %d no existe en la agenda y no puede ser pospuesto.\n", id);
}

void main_hayEventosFechaAgenda(TAgenda agenda) {
    assert(agenda != NULL);
    TFecha fecha = NULL;
    leerFecha(fecha);

    if (hayEventosFecha(agenda, fecha))
        imprimirEventosFecha(agenda, fecha);
    else
        printf("No se encontraron eventos en la fecha determinada.\n");

    liberarTFecha(fecha);
}

void main_imprimirAgenda(TAgenda agenda) {
    assert(agenda != NULL);
    imprimirTAgenda(agenda);
}

void main_imprimirEventosFechaAgenda(TAgenda agenda) {
    assert(agenda != NULL);
    TFecha fecha = NULL;
    leerFecha(fecha);

    imprimirEventosFecha(agenda, fecha);

    liberarTFecha(fecha);
}
