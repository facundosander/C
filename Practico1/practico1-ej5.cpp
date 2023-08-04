#include <stdio.h>

// Estructura para representar un punto con coordenadas X e Y
typedef struct rep_punto {
    int coordX, coordY;
} Punto;

// Estructura para representar una colección de puntos con capacidad y cantidad actual
typedef struct rep_colPuntos {
    int capacidad;
    int cantidad;
    Punto *arregloPuntos; // Puntero al arreglo de puntos
} ColPuntos;
// Función para encontrar la posición correcta para un nuevo punto en la colección ordenada
int posicion(ColPuntos &colPtos, Punto &pto) {
    Punto *aux;
    aux = colPtos.arregloPuntos; // Puntero auxiliar al arreglo de puntos
    int posicion = 0;
    // Recorre la colección hasta encontrar la posición correcta o alcanzar la cantidad actual
    while (posicion != colPtos.cantidad) {
        // Compara las coordenadas para encontrar la posición correcta según el orden lexicográfico
        if (pto.coordX < aux->coordX || (pto.coordX == aux->coordX && pto.coordY <= aux->coordY)) {
            return posicion;
        } else {
            aux++;
            posicion++;
        }
    }
    return posicion; // Retorna la posición encontrada
}

// Función para insertar un punto en la colección, manteniendo el orden lexicográfico
void insertarPunto(ColPuntos &colPtos, Punto pto) {
    Punto *aux;
    aux = colPtos.arregloPuntos; // Puntero auxiliar al arreglo de puntos
    int pos;
    // Verifica si hay espacio en la colección
    if (colPtos.cantidad != colPtos.capacidad) {
        // Encuentra la posición correcta para el nuevo punto
        pos = posicion(colPtos, pto);
        // Si la cantidad actual es menor que la posición encontrada, inserta en la posición
        if (colPtos.cantidad < pos) {
            aux[pos] = pto;
            colPtos.cantidad++;
        } else {
            // Desplaza los puntos existentes para hacer espacio para el nuevo punto
            for (size_t i = colPtos.cantidad; i > pos; i--) {
                aux[i] = aux[i - 1];
            }
            // Inserta el nuevo punto en la posición correcta
            aux[pos] = pto;
            colPtos.cantidad++;
        }
    }
}

// Función para encontrar la posición correcta para un nuevo punto en la colección ordenada



int main(){
    // Define una colección de puntos con capacidad para 5 puntos
    ColPuntos colPtos;
    colPtos.capacidad = 5;
    colPtos.cantidad = 0;
    colPtos.arregloPuntos = new Punto[colPtos.capacidad]; // Asegúrate de tener suficiente memoria

    // Define algunos puntos para insertar
    Punto p1 = {3, 4};
    Punto p2 = {1, 2};
    Punto p3 = {3, 2};
    Punto p4 = {7, 2};
    // Inserta los puntos en la colección
    insertarPunto(colPtos, p1);
    insertarPunto(colPtos, p2);
    insertarPunto(colPtos, p3);
    insertarPunto(colPtos, p4);
    // Imprime los puntos en la colección
    printf("Puntos en la coleccion:\n");
    for (int i = 0; i < colPtos.cantidad; i++) {
        printf("Punto %d: (%d, %d)\n", i + 1, colPtos.arregloPuntos[i].coordX, colPtos.arregloPuntos[i].coordY);
    }

    // Libera la memoria asignada para el arreglo de puntos
    delete[] colPtos.arregloPuntos;

    return 0;
}
