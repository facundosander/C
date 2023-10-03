#include "../include/pilaJugador.h"

typedef struct rep_pilaNodo *TPilaNodo;
struct rep_pilaNodo {
    TJugador jugador;
    rep_pilaNodo * sig;
};

struct rep_pilaJugador {
    rep_pilaNodo * tope;
    nat cantidad;
};

TPilaJugador crearTPilaJugador() {
  TPilaJugador nuevaPilaJugador = NULL;
  nuevaPilaJugador = new rep_pilaJugador;
  nuevaPilaJugador->tope = NULL;
  nuevaPilaJugador->cantidad = 0;
  return nuevaPilaJugador;
}

TPilaNodo crearTPilaNodo(TJugador jugador){
  TPilaNodo nuevaPilaNodo = NULL;
  nuevaPilaNodo = new rep_pilaNodo;
  nuevaPilaNodo->jugador = jugador;
  nuevaPilaNodo->sig = NULL;
  return nuevaPilaNodo;
}


void liberarTPilaJugador(TPilaJugador &p) {
  while (p->tope != NULL)
  {
    TPilaNodo aux = p->tope;
    p->tope = p->tope->sig;
    liberarTJugador(aux->jugador);
    delete aux;
  }
  delete p;
  p = NULL;
}


nat cantidadEnTPilaJugador(TPilaJugador p) { 
  return p->cantidad;
}

void apilarEnTPilaJugador(TPilaJugador &p, TJugador jugador) {
  TPilaNodo nuevoNodo = crearTPilaNodo(copiarTJugador(jugador));
  nuevoNodo->sig = p->tope;
  p->tope = nuevoNodo;
  p->cantidad++;
}

TJugador cimaDeTPilaJugador(TPilaJugador p) { 
  return p->tope->jugador;
}

void desapilarDeTPilaJugador(TPilaJugador &p) {
  if (p->tope != NULL)
  {
    TPilaNodo aux = p->tope;
    p->tope = p->tope->sig;
    liberarTJugador(aux->jugador);
    delete aux;
    p->cantidad--;
  }
  
}

