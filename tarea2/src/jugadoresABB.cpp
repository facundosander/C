#include "../include/jugadoresABB.h"

struct rep_jugadoresABB {
    TJugador jugador;
    rep_jugadoresABB * izq;
    rep_jugadoresABB * der;
};

TJugadoresABB crearTJugadoresABB() {
    return NULL;
}

bool esVacioTJugadoresABB(TJugadoresABB jugadoresABB) {
    return jugadoresABB == NULL;
}

void insertarTJugadoresABB(TJugadoresABB &jugadoresABB, TJugador jugador) {
    if (esVacioTJugadoresABB(jugadoresABB)) {
        jugadoresABB = new rep_jugadoresABB;
        jugadoresABB->jugador = jugador;
        jugadoresABB->izq = NULL;
        jugadoresABB->der = NULL;
    } else {
        nat id_actual = idTJugador(jugadoresABB->jugador);
        nat id_nuevo = idTJugador(jugador);

        if (id_nuevo < id_actual) {
            insertarTJugadoresABB(jugadoresABB->izq, jugador);
        } else if (id_nuevo > id_actual) {
            insertarTJugadoresABB(jugadoresABB->der, jugador);
        }
    }
}

void liberarNodo(TJugadoresABB &nodo) {
    liberarTJugador(nodo->jugador);
    delete nodo;
    nodo = NULL;
}

void liberarTJugadoresABB(TJugadoresABB &jugadoresABB) {
    if (!esVacioTJugadoresABB(jugadoresABB)) {
        liberarTJugadoresABB(jugadoresABB->izq);
        liberarTJugadoresABB(jugadoresABB->der);
        liberarNodo(jugadoresABB);
    }
}


void imprimirTJugadoresABB(TJugadoresABB jugadoresABB) {
    if (!esVacioTJugadoresABB(jugadoresABB)) {
        imprimirTJugadoresABB(jugadoresABB->izq);
        imprimirTJugador(jugadoresABB->jugador);
        imprimirTJugadoresABB(jugadoresABB->der);
    }
}

nat cantidadTJugadoresABB(TJugadoresABB jugadoresABB) {
    if (esVacioTJugadoresABB(jugadoresABB)) {
        return 0;
    } else {
        return 1 + cantidadTJugadoresABB(jugadoresABB->izq) + cantidadTJugadoresABB(jugadoresABB->der);
    }
}


TJugador maxIdJugador(TJugadoresABB jugadoresABB) {
    while (jugadoresABB->der != NULL) {
        jugadoresABB = jugadoresABB->der;
    }
    return jugadoresABB->jugador;
}

void removerTJugadoresABB(TJugadoresABB &jugadoresABB, nat id) {
    if (jugadoresABB == NULL) return;

    if (id < idTJugador(jugadoresABB->jugador)) {
        removerTJugadoresABB(jugadoresABB->izq, id);
    }

    else if (id > idTJugador(jugadoresABB->jugador)) {
        removerTJugadoresABB(jugadoresABB->der, id);
    }
    else {
        if (jugadoresABB->izq == NULL) {
            TJugadoresABB aBorrar = jugadoresABB;
            jugadoresABB = jugadoresABB->der;
            liberarNodo(aBorrar);
        }
        else if (jugadoresABB->der == NULL) {
            TJugadoresABB aBorrar = jugadoresABB;
            jugadoresABB = jugadoresABB->izq;
            liberarNodo(aBorrar);
        }
        else {
            TJugador tempJugador =copiarTJugador(maxIdJugador(jugadoresABB->izq));
            liberarTJugador(jugadoresABB->jugador);
            jugadoresABB->jugador = tempJugador;
            removerTJugadoresABB(jugadoresABB->izq, idTJugador(tempJugador));
        }
    }
}





bool estaTJugadoresABB(TJugadoresABB jugadoresABB, nat id) {
    if (jugadoresABB == NULL) {
        return false; 
    }
    
    if (idTJugador(jugadoresABB->jugador) == id) {
        return true; 
    } else if (id < idTJugador(jugadoresABB->jugador)) {
        return estaTJugadoresABB(jugadoresABB->izq, id); 
    } else {
        return estaTJugadoresABB(jugadoresABB->der, id);
    }
}

TJugador obtenerDeTJugadoresABB(TJugadoresABB jugadoresABB, nat id) {
    if (jugadoresABB == NULL) {
        return NULL; 
    }
    
    if (idTJugador(jugadoresABB->jugador) == id) {
        return jugadoresABB->jugador;
    } else if (id < idTJugador(jugadoresABB->jugador)) {
        return obtenerDeTJugadoresABB(jugadoresABB->izq, id);
    } else {
        return obtenerDeTJugadoresABB(jugadoresABB->der, id); 
    }
}

nat alturaTJugadoresABB(TJugadoresABB jugadoresABB) {
    if (jugadoresABB == NULL)
        return 0;
    
    nat altIzq = alturaTJugadoresABB(jugadoresABB->izq);
    nat altDer = alturaTJugadoresABB(jugadoresABB->der);

    if (altIzq > altDer)
        return 1 + altIzq;
    else
        return 1 + altDer;
}


bool esPerfectoTJugadoresABB(TJugadoresABB jugadoresABB) {
    if (jugadoresABB == NULL)
        return true;

    nat altIzq = alturaTJugadoresABB(jugadoresABB->izq);
    nat altDer = alturaTJugadoresABB(jugadoresABB->der);

    if (altIzq != altDer)
        return false;
    
    return esPerfectoTJugadoresABB(jugadoresABB->izq) && esPerfectoTJugadoresABB(jugadoresABB->der);
}

TJugadoresABB mayoresTJugadoresABB(TJugadoresABB jugadoresABB, nat edad) {
    TJugadoresABB result;
    if (jugadoresABB == NULL)
        return NULL;

    TJugadoresABB fizq = mayoresTJugadoresABB(jugadoresABB->izq, edad);
    TJugadoresABB fder = mayoresTJugadoresABB(jugadoresABB->der, edad);

    TJugador raiz = jugadoresABB->jugador;

    if (edadTJugador(raiz) > edad) {
        result = new rep_jugadoresABB;
        result->jugador = copiarTJugador(raiz);
        result->izq = fizq;
        result->der = fder;
    } else if (fizq == NULL)
    {
        result = fder;
    } else if (fder == NULL)
    {
        result = fizq;
    }
    else
    {
        TJugador mayor =copiarTJugador(maxIdJugador(jugadoresABB->izq));
        result = new rep_jugadoresABB;
        result->jugador = mayor;
        result->izq = fizq;
        result->der = fder;
        TJugadoresABB aux = fizq;
        while (aux->der != NULL) {
            aux = aux->der;
        }
        TJugadoresABB aBorrar = aux;
        aux = aux->izq;
        liberarNodo(aBorrar);

    }
    
    return result;
    
}
