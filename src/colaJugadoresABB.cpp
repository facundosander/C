#include "../include/colaJugadoresABB.h"
#include "../include/jugadoresLDE.h"

typedef struct rep_colaNodoJugadoresABB * TcolaNodo;

struct rep_colaJugadoresABB {
  nat cantidad;
  rep_colaNodoJugadoresABB * ini;
  rep_colaNodoJugadoresABB * fin;
};

struct rep_colaNodoJugadoresABB {
  TJugadoresABB jugadoresABB;
  rep_colaNodoJugadoresABB * sig;
};

TColaJugadoresABB crearTColaJugadoresABB() {
  TColaJugadoresABB ColaJugadoresABB = new rep_colaJugadoresABB;
  ColaJugadoresABB->ini = NULL;
  ColaJugadoresABB->fin = NULL;
  ColaJugadoresABB->cantidad = 0;
  return ColaJugadoresABB;
}

TcolaNodo crearTColaNodoJugadoresABB(TJugadoresABB jugadoresABB){
  TcolaNodo ColaNodo = new rep_colaNodoJugadoresABB;
  ColaNodo->jugadoresABB = jugadoresABB;
  ColaNodo->sig = NULL;
  return ColaNodo;
}

void liberarTColaJugadoresABB(TColaJugadoresABB &c) {
  while (c->ini != NULL)
  {
    TcolaNodo aux = c->ini;
    c->ini = c->ini->sig;
    delete aux;
  }
  delete c;
  c = NULL;
}

nat cantidadEnTColaJugadoresABB(TColaJugadoresABB c) { 
  return c->cantidad;
}

void encolarEnTColaJugadoresABB(TJugadoresABB t, TColaJugadoresABB &c) {
  TcolaNodo nuevoNodo = crearTColaNodoJugadoresABB(t);
  if (c->ini == NULL)
  {
    c->ini = nuevoNodo;
    c->fin = nuevoNodo;
    c->cantidad++;
  }
  else
  {
    c->fin->sig = nuevoNodo;
    c->fin = nuevoNodo;
    c->cantidad++;
  }
  
}

TJugadoresABB frenteDeTColaJugadoresABB(TColaJugadoresABB c) { 
  return c->ini->jugadoresABB;
}

void desencolarDeTColaJugadoresABB(TColaJugadoresABB &c) {
  TcolaNodo aux = c->ini;
  c->ini = c->ini->sig;
  delete aux;
  c->cantidad--;
}
