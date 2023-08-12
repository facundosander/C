#include "../include/agenda.h"

struct rep_agenda {
    /************ Parte 5.1 ************/
    /*Escriba el código a continuación */
    TEvento eventos[MAX_EVENTOS];
    int tope;
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

//Funcion que devuelve la posicion de un evento dentro de una agenda
int posicion (TAgenda &agenda, TEvento &evento){
    TEvento *aux;
    aux = agenda->eventos;
    int posicion = 0;
    while (posicion != agenda->tope)
    {
        if (compararTFechas(fechaTEvento(evento), fechaTEvento(*aux)) == -1 || compararTFechas(fechaTEvento(evento), fechaTEvento(*aux)) == 0)
        {
            return posicion;
        }
        else
        {
            aux++;
            posicion++;
        }
        
        
    }
    return posicion;
}
void agregarEnAgenda(TAgenda &agenda, TEvento evento) {
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    if (agenda->tope < MAX_EVENTOS)
    {
        if (agenda->tope == 0)
        {
            agenda->eventos[0] = evento;
            agenda->tope++;
        }
        else
        {
            int pos = posicion(agenda, evento);

            // Mueve todos los eventos posteriores hacia atrás para hacer espacio
            for (int i = agenda->tope; i > pos; i--) {
                agenda->eventos[i] = agenda->eventos[i - 1];
            }

            // Inserta el nuevo evento en la posición adecuada
            agenda->eventos[pos] = evento;
            agenda->tope++;
        }
    }
    /****** Fin de parte Parte 5.2 *****/
}

void liberarTAgenda(TAgenda &agenda) {
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    TEvento *aux;
    aux = agenda->eventos;
    for (int i = agenda->tope - 1; i >= 0; i--)
    {
        liberarTEvento(aux[i]);
    }
    delete agenda;
    agenda = NULL;
    /****** Fin de parte Parte 5.2 *****/
}

void imprimirTAgenda(TAgenda agenda) {
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    TEvento *aux;
    aux = agenda->eventos;
    for (int i = 0; i < agenda->tope; i++)
    {
        imprimirTEvento(aux[i]);
    }
    
    /****** Fin de parte Parte 5.2 *****/
}

bool estaEnAgenda(TAgenda agenda, int id) {
    bool res = false;
    /************ Parte 5.4 ************/
    /*Escriba el código a continuación */
    TEvento *aux;
    aux = agenda->eventos;
    for (int i = 0; i < agenda->tope; i++)
    {
        if (idTEvento(aux[i]) == id){
            return res = true;
        } 
    }
    
    /****** Fin de parte Parte 5.4 *****/
    return res;
}

TEvento obtenerDeAgenda(TAgenda agenda, int id) {
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */
    TEvento *aux;
    aux = agenda->eventos;
    for (int i = 0; i < agenda->tope; i++)
    {
        if (idTEvento(aux[i]) == id){
            return aux[i];
        } 
    }
    /****** Fin de parte Parte 5.5 *****/
    return NULL;  // Devolver NULL si no se encontró el evento
}

void posponerEnAgenda(TAgenda &agenda, int id, nat n) {
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */
    TEvento nuevaFecha = obtenerDeAgenda(agenda, id);
    posponerTEvento(nuevaFecha, n);
    for (int i = 1; i < agenda->tope; i++) {
        TEvento aux = agenda->eventos[i];
        int j = i - 1;
        
        while (j >= 0 && compararTFechas(fechaTEvento(agenda->eventos[j]), fechaTEvento(aux)) > 0) {
            agenda->eventos[j + 1] = agenda->eventos[j];
            j = j - 1;
        }
        agenda->eventos[j + 1] = aux;
    }
    /****** Fin de pmarte Parte 5.5 *****/
}

void imprimirEventosFecha(TAgenda agenda, TFecha fecha) {
    /************ Parte 5.7 ************/
    /*Escriba el código a continuación */
    for (int i = 0; i < agenda->tope; i ++){
        TEvento aux = agenda->eventos[i];
        TFecha fechaux = fechaTEvento(aux);
        if (compararTFechas(fechaux,fecha) == 0){
            imprimirTEvento(aux);
        }
        
    }
    
    /****** Fin de parte Parte 5.7 *****/
}

bool hayEventosFecha(TAgenda agenda, TFecha fecha) {
    bool res = false;
    /************ Parte 5.7 ************/
    /*Escriba el código a continuación */
    /*La función debe ejecutar una versión */
    /*Iterativa del algoritmo de búsqueda  */
    /*binaria.                              */
    int inicio = 0;                        
    int fin = agenda->tope - 1;            

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2; 
        int comparacion = compararTFechas(fechaTEvento(agenda->eventos[medio]), fecha);
        if (comparacion == 0) {
            return true;
        } else if (comparacion > 0) {
            fin = medio - 1;
        } else {
            inicio = medio + 1;
        }
    }

    /****** Fin de parte Parte 5.7 *****/
    return res;
}

int posicionid (TAgenda &agenda, TEvento &evento){
    TEvento *aux;
    aux = agenda->eventos;
    int posicion = 0;
    while (posicion != agenda->tope)
    {
        if (*aux == evento)
        {
            return posicion;
        }
        else
        {
            aux++;
            posicion++;
        }
        
        
    }
    return posicion;
}
void removerDeAgenda(TAgenda &agenda, int id) {
    /************ Parte 5.8 ************/
    /*Escriba el código a continuación */
    TEvento fechaBorrar = obtenerDeAgenda(agenda, id);
    if (fechaBorrar == NULL) {
        return;
    }
    int pos = posicionid(agenda, fechaBorrar);
    if (pos >= 0 && pos < agenda->tope) {
        liberarTEvento(agenda->eventos[pos]);
        for (int i = pos; i < agenda->tope - 1; i++){
            agenda->eventos[i] = agenda->eventos[i + 1];
        }
        agenda->tope--;
    }
    /****** Fin de parte Parte 5.8 *****/
}





