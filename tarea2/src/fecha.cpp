#include "../include/fecha.h"

// Estructura para almacenar una fecha con día, mes y año
struct rep_fecha {
    nat dia, mes, anio;
};

// Función para crear un nuevo objeto de tipo TFecha con una fecha dada
TFecha crearTFecha(nat dia, nat mes, nat anio) {
    TFecha nuevaFecha = NULL;
    /************ Parte 3.1 ************/
    /*Escriba el código a continuación */
    nuevaFecha = new rep_fecha;
    nuevaFecha->dia = dia;
    nuevaFecha->mes = mes;
    nuevaFecha->anio = anio;
    /****** Fin de parte Parte 3.1 *****/
    return nuevaFecha;
}

// Función para liberar un objeto de tipo TFecha previamente creado
void liberarTFecha(TFecha &fecha) {
    delete fecha;
    fecha = NULL;
}

// Función para imprimir una fecha representada por un objeto de tipo TFecha
void imprimirTFecha(TFecha fecha) {
    printf("%d/%d/%d\n", fecha->dia , fecha->mes , fecha->anio);
}

// Función para aumentar una fecha en una cantidad dada de días
bool esBisiesto(nat anio) {
    if (anio % 400 == 0) {
        return true;
    } else if (anio % 100 == 0) {
        return false;
    } else if (anio % 4 == 0) {
        return true;
    } else {
        return false;
    }
}
// Función para obtener la cantidad de días de un mes en un año dado
nat diasMes(nat mes, nat anio){
switch (mes)
{
case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
    return 31;
    break;
case 4: case 6: case 9: case 11:
    return 30;
    break;
case 2:
    if (esBisiesto(anio))
    {
        return 29;
    }else
    {
        return 28;
    } 
    break;
default:
    printf("valor incorrecto");
    return 0;
    break;
}
    
}

/*Recuerde que las funciones auxiliares
deben declararse antes de ser utilizadas*/


void aumentarTFecha(TFecha &fecha, nat dias) {
    fecha->dia += dias;
    while (fecha->dia > diasMes(fecha->mes, fecha->anio)) {
        fecha->dia -= diasMes(fecha->mes, fecha->anio);
        fecha->mes++;
        if (fecha->mes > 12) {
            fecha->mes = 1;
            fecha->anio++;
        }
    }
}

// Función para comparar dos fechas representadas por objetos de tipo TFecha
int compararTFechas(TFecha fecha1, TFecha fecha2) {
    int res = 0;
    if (fecha1->anio > fecha2->anio)
    {
        return res = 1;
    }else if (fecha1->anio == fecha2->anio && fecha1->mes > fecha2->mes)
    {
        return res = 1;
    }else if (fecha1->anio == fecha2->anio && fecha1->mes == fecha2->mes && fecha1->dia > fecha2->dia)
    {
        return res = 1;
    }else if (fecha1->anio == fecha2->anio && fecha1->mes == fecha2->mes && fecha1->dia == fecha2->dia)
    {
        return res = 0;
    }else
    {
        return res = -1;
    }
    /****** Fin de parte Parte 3.10 *****/
    return res;

}

// Retorna una copia de la fecha
TFecha copiarTFecha(TFecha fecha) {
    return crearTFecha(fecha->dia, fecha->mes, fecha->anio);
}