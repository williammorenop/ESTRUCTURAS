#ifndef ARBOL
#define ARBOL
#include <queue>
template <typename T>
class Arbol {
protected:
  Nodo<T>* raiz;
public:
  Arbol();
  Arbol(T& val);
  ~Arbol();
  bool esVacio();
  Nodo<T>* obtenerRaiz();
  void fijarRaiz(Nodo<T>* nraiz);
  bool insertarNodo(T& padre, T& n);
  bool eliminarNodo(T& n);
  bool buscar(T& n);
  unsigned int altura(Nodo<T>* inicio);
  unsigned int tamano(Nodo<T>* inicio);
  void preOrden(Nodo<T>* inicio,std::queue<T>&order);
  void posOrden(Nodo<T>* inicio,std::queue<T>&order);
  void nivelOrden(Nodo<T>* inicio,std::queue<T>&order);
};

#include "Arbol.hxx"
#endif
