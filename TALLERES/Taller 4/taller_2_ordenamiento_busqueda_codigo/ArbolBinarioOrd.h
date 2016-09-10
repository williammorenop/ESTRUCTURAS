#ifndef ARBOLBINARIOORD
#define ARBOLBINARIOORD

#include <queue>
#include <list>
#include "NodoBinario.h"
template <class T>
class ArbolBinarioOrd {
protected:
  NodoBinario<T>* raiz;

public:
  ArbolBinarioOrd();
  ArbolBinarioOrd(T &val);
  ~ArbolBinarioOrd();
  bool esVacio();
  T &datoRaiz();
  void preOrden(std::queue<T> &q);
  void preOrden(NodoBinario<T> *n, std::queue<T> &q);
  void inOrden(std::queue<T> &q);
  void inOrden(NodoBinario<T> *n, std::queue<T> &q);
  void posOrden(std::queue<T> &q);
  void posOrden(NodoBinario<T> *n, std::queue<T> &q);
  void nivelOrden(std::queue<T> &que);
  int altura();
  int altura(NodoBinario<T> *n);
  int tamano(int &cont);
  void tamano(NodoBinario<T> *n, int &cont);
  bool buscar(T &val);
  NodoBinario<T> *buscar(NodoBinario<T> *n, T &val);
  bool insert(T &val);
  bool insert(NodoBinario<T> *n, T &val);
  NodoBinario<T>* erase(NodoBinario<T> *n,T &val);
  bool erase(T &val);
  NodoBinario<T>* minimoNodo(NodoBinario<T> *);
  void inordenEnLista(std::list< T >&l);
  T &minimo(NodoBinario<T> *);
  T &maximo(NodoBinario<T> *);
  T &minimo();
  T &maximo();
};

#include "ArbolBinarioOrd.hxx"
#endif