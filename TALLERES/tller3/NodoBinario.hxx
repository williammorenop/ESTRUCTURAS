#include "NodoBinario.h"

template <class T>
NodoBinario <T>::NodoBinario(){
  this->hijoIzq= NULL;
  this->hijoDer= NULL;
}
template<class T>
NodoBinario <T>::NodoBinario(T& val){
  this->dato=val;
  this->NodoBinario();
}

template<class T>
NodoBinario<T>::NodoBinario(T& val, NodoBinario<T> *izq, NodoBinario<T> *der){
  this->NodoBinario(val);
  this->hijoIzq=izq;
  this->hijoDer=der;
}

template<class T>
NodoBinario <T>::~NodoBinario(){
  delete this->hijoIzq;
  delete this->hijoDer;
  delete this;
}

template<class T>
T& NodoBinario <T>:: obtenerDato(){
  return this->dato;
}

template<class T>
void NodoBinario <T>::fijarDato(T& val){
  this->dato=val;
}

template<class T>
NodoBinario<T>* NodoBinario <T>:: obtenerHijoIzq(){
  return this->hijoIzq;
}

template<class T>
NodoBinario<T>* NodoBinario <T>:: obtenerHijoDer(){
  return this->hijoDer;
}

template<class T>
void NodoBinario <T>:: fijarHijoIzq(NodoBinario<T> *izq){
  this->hijoIzq=izq;
}

template<class T>
void NodoBinario <T>:: fijarHijoDer(NodoBinario<T> *der){
  this->hijoDer=der;
}
