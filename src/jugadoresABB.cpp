#include "../include/jugadoresABB.h"
#include "../include/colaJugadoresABB.h"
#include "../include/pilaJugador.h"

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
    if (jugadoresABB == NULL)
        return NULL;

    TJugadoresABB fizq = mayoresTJugadoresABB(jugadoresABB->izq, edad);
    TJugadoresABB fder = mayoresTJugadoresABB(jugadoresABB->der, edad);

    if (edadTJugador(jugadoresABB->jugador) > edad) {
        TJugadoresABB result = new rep_jugadoresABB;
        result->jugador = copiarTJugador(jugadoresABB->jugador);
        result->izq = fizq;
        result->der = fder;
        return result;
    } 
    else if (fizq == NULL) {
        return fder;
    } 
    else if (fder == NULL) {
        return fizq;
    } 
    else {
        TJugadoresABB result = new rep_jugadoresABB;
        TJugador tempJugador = copiarTJugador(maxIdJugador(fizq));
        result->jugador = tempJugador;
        result->izq = fizq;
        result->der = fder;
        removerTJugadoresABB(result->izq, idTJugador(tempJugador));
        return result;
    }
}

///////////////////////////////////
////// FIN CÓDIGO TAREA 2 //////
///////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/////////////  NUEVAS FUNCIONES  //////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

nat amplitudTJugadoresABB(TJugadoresABB t) {
    if (t == NULL)
    {
        return 0;
    }
    TColaJugadoresABB cola = crearTColaJugadoresABB();
    encolarEnTColaJugadoresABB(t, cola);
    nat amplitud = 0;
    while (cantidadEnTColaJugadoresABB(cola) != 0)
    {
        nat nivel = cantidadEnTColaJugadoresABB(cola);
        if (amplitud < nivel)
        {
            amplitud = nivel;
        }
            for (nat i = 0; i < nivel; i++) {
            TJugadoresABB nodoAcutal = frenteDeTColaJugadoresABB(cola);
            desencolarDeTColaJugadoresABB(cola);

            if (nodoAcutal->izq != NULL) encolarEnTColaJugadoresABB(nodoAcutal->izq, cola);
            if (nodoAcutal->der != NULL) encolarEnTColaJugadoresABB(nodoAcutal->der, cola);
        }
    }

    liberarTColaJugadoresABB(cola);

    return amplitud;
}
    
    


TPilaJugador serializarTJugadoresABB(TJugadoresABB t) {
    if (t == NULL)
    {
        return crearTPilaJugador();
    }
    TColaJugadoresABB cola = crearTColaJugadoresABB();
    encolarEnTColaJugadoresABB(t, cola);
    TPilaJugador pila = crearTPilaJugador();

    while (cantidadEnTColaJugadoresABB(cola) != 0){
        TJugadoresABB actualABB = frenteDeTColaJugadoresABB(cola);
        desencolarDeTColaJugadoresABB(cola);
        TJugador copiaJugador = actualABB->jugador;
        apilarEnTPilaJugador(pila, copiaJugador);
        
        if (actualABB->izq != NULL) encolarEnTColaJugadoresABB(actualABB->izq, cola);
        if (actualABB->der != NULL) encolarEnTColaJugadoresABB(actualABB->der, cola);

    }
    TPilaJugador pilaFinal = crearTPilaJugador();
    while (cantidadEnTPilaJugador(pila)!=0)
    {
        TJugador nodo = cimaDeTPilaJugador(pila);
        apilarEnTPilaJugador(pilaFinal, nodo);
        desapilarDeTPilaJugador(pila);
    }
    liberarTPilaJugador(pila);
    liberarTColaJugadoresABB(cola);
    
    return pilaFinal;
}

TJugadoresABB deserializarTJugadoresABB(TPilaJugador &p) {
    TJugadoresABB arbol = crearTJugadoresABB();

    while (cantidadEnTPilaJugador(p) != 0)
    {
        TJugador jugadorCima = copiarTJugador(cimaDeTPilaJugador(p));
        desapilarDeTPilaJugador(p);
        insertarTJugadoresABB(arbol, jugadorCima);
    }
    liberarTPilaJugador(p);
    return arbol;
}


///////////////////////////////////////////////////////////////////////////
/////////////  FIN NUEVAS FUNCIONES  //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
