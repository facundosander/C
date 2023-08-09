#include "../include/agenda.h"

struct rep_agenda {
    /************ Parte 5.1 ************/
    /*Escriba el código a continuación */
    TEvento eventos[MAX_EVENTOS];
    unsigned int tope;
    /****** Fin de parte Parte 5.1 *****/
};

TAgenda crearTAgenda() {
    TAgenda nuevaAgenda = NULL;
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    nuevaAgenda = new rep_agenda;
    nuevaAgenda->tope=0;
    /****** Fin de parte Parte 5.2 *****/
    return nuevaAgenda;
}

// primero comparar con el primero, si el evento es mas chico que el primer evento en la agenda, agregar el evento el el primer lugar
// sino, si es igual agregar en el segundo lugar y si existe mas eventos a la derecha, moverlos un lugar a la derecha.
// sino, si es mas grande comparar con el siguiente elemento:
// si el siguiente elemento es mas grande agregar en el medio, si es igual, agregar despues, si es mas chico, mover al segundo elemento, repetir secuencia,
// si no entra en ninguana de estas condiciones, agregar al final.
void agregarEnAgenda(TAgenda &agenda, TEvento evento) {
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    if (agenda->tope < MAX_EVENTOS)
    {
        if (agenda->tope==0)
        {
            *agenda->eventos = evento;
            agenda->tope++;
        }else
        {
            for (int i = 0; i < agenda->tope; i++)
            {
                if (compararTFechas(fechaTEvento(*agenda->eventos),fechaTEvento(evento))==1)
                {
                    
                }
                
            }
            
        }
    
    }
    /****** Fin de parte Parte 5.2 *****/
}

void liberarTAgenda(TAgenda &agenda) {
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 5.2 *****/
}

void imprimirTAgenda(TAgenda agenda) {
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 5.2 *****/
}

bool estaEnAgenda(TAgenda agenda, int id) {
    bool res = false;
    /************ Parte 5.4 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 5.4 *****/
    return res;
}

TEvento obtenerDeAgenda(TAgenda agenda, int id) {
    TEvento res = NULL;
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 5.5 *****/
    return res;
}

void posponerEnAgenda(TAgenda &agenda, int id, nat n) {
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 5.5 *****/
}

void imprimirEventosFecha(TAgenda agenda, TFecha fecha) {
    /************ Parte 5.7 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 5.7 *****/
}

bool hayEventosFecha(TAgenda agenda, TFecha fecha) {
    bool res = false;
    /************ Parte 5.7 ************/
    /*Escriba el código a continuación */
    /*La función debe ejecutar una versión */
    /*Iterativa del algoritmo de búsqueda  */
    /*binaria.                              */

    /****** Fin de parte Parte 5.7 *****/
    return res;
}

void removerDeAgenda(TAgenda &agenda, int id) {
    /************ Parte 5.8 ************/
    /*Escriba el código a continuación */

    /****** Fin de parte Parte 5.8 *****/
}





