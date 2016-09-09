#ifndef ARBOLBINARIOORD
#define ARBOLBINARIOORD

template <class T> class ArbolBinarioOrd {
protected:
  NodoBinario<T> *raiz;

public:
  ArbolBinarioOrd() ArbolBinarioOrd(T &val);
  ~ArbolBinarioOrd();
  bool esVacio();
  T &datoRaiz();
  void preOrden(queue<T> &q);
  void preOrden(NodoBinario<T> *n, queue<T> &q);
  void inOrden(queue<T> &q);
  void inOrden(NodoBinario<T> *n, queue<T> &q);
  void posOrden(queue<T> &q);
  void posOrden(NodoBinario<T> *n, queue<T> &q);
  void nivelOrden(queue<T> &que);
  int altura();
  int altura(NodoBinario<T> *n);
  int tamano(int &cont);
  void tamano(NodoBinario<T> *n, int &cont);
  bool buscar(T &val);
  NodoBinario<T> *buscar(NodoBinario<T> *n, T &val);
  bool insertar(T &val);
  bool insertar(NodoBinario<T> *n, T &val);
  bool eliminar(T &val);
  NodoBinario<T> eliminar(NodoBinario<T> *n, T &val);
  T &minimo(NodoBinario<T> *n);
  T &maximuswell(NodoBinario<T> *n);
};

#include "ArbolBinarioOrd.hxx"
#endif
