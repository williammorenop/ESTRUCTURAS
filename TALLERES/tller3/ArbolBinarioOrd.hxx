#include "ArbolBinarioOrd.h"
#include <queue>
#include <algorithm>
template <class T>
ArbolBinarioOrd<T>::ArbolBinarioOrd() { this->raiz = NULL; }
template <class T> ArbolBinarioOrd<T>::ArbolBinarioOrd(T &val) {
  this->raiz = new NodoBinario<T>(val);
}
template <class T> ArbolBinarioOrd<T>::~ArbolBinarioOrd() {
  if(this->raiz!=NULL){

    delete this->raiz;
  }
}
template <class T> bool ArbolBinarioOrd<T>::esVacio() {
  return this->raiz == NULL;
}
template <class T> T &ArbolBinarioOrd<T>::datoRaiz() {
  return this->raiz->dato;
}

template <class T> void ArbolBinarioOrd<T>::preOrden(std::queue<T> &q) {
  preOrden(this->raiz, q);
}

template <class T>
void ArbolBinarioOrd<T>::preOrden(NodoBinario<T> *n, std::queue<T> &q) {
  if (n != NULL) {
    q.push(n->obtenerDato());
    preOrden(n->obtenerHijoIzq(), q );
    preOrden(n->obtenerHijoDer(), q );
  }
}

template <class T> void ArbolBinarioOrd<T>::inOrden(std::queue<T> &q) {
  inOrden(this->raiz, q);
}

template <class T>
void ArbolBinarioOrd<T>::inOrden(NodoBinario<T> *n, std::queue<T> &q) {

  if (n != NULL) {
    inOrden(n->obtenerHijoIzq(), q);
    q.push(n->obtenerDato());
    inOrden(n->obtenerHijoDer(), q);
  }
}

template <class T> void ArbolBinarioOrd<T>::posOrden(std::queue<T> &q) {
  posOrden(this->raiz, q);
}

template <class T>
void ArbolBinarioOrd<T>::posOrden(NodoBinario<T> *n, std::queue<T> &q) {
  if (n != NULL) {
    posOrden(n->obtenerHijoIzq(), q);
    posOrden(n->obtenerHijoDer(), q);
    q.push(n->obtenerDato());
  }
}

template <class T>
void ArbolBinarioOrd<T>::nivelOrden(std::queue<T>&que)
{
	std::queue<NodoBinario<T>*> q;
	q.insert(this->raiz);
	while( !q.empty() )
	{
		NodoBinario<T>* n=q.front();
		q.pop();
		que.insert(n->obtenerDato());
		if( n->obtenerHijoIzq() != NULL )
			q.insert(n->obtenerHijoIzq());
		if( n->obtenerHijoDer() != NULL)
			q.insert(n->obtenerHijoDer());
	}
}
template <class T>
int ArbolBinarioOrd<T>::altura()
{
	return altura(this->raiz);
}

template <class T>
int ArbolBinarioOrd<T>::altura( NodoBinario<T>* n)
{
	int tam=-1;
	if( n!=NULL )
	{
		int tamIzq,tamDer;
		tamIzq=altura(n->obtenerHijoIzq());
		tamDer=altura(n->obtenerHijoDer());
		tam=std::max(tamIzq,tamDer);
		++tam;
	}
	return tam;
}

template <class T> int ArbolBinarioOrd<T>::tamano(int &cont) {
  cont=0;
  tamano(this->raiz, cont);
}
template <class T>
void ArbolBinarioOrd<T>::tamano(NodoBinario<T> *n, int &cont) {

  if (n != NULL) {
    tamano(n->obtenerHijoIzq(), cont);
    tamano(n->obtenerHijoDer(), cont);
    cont++;
  }
}

/*int ArbolBinarioOrd <T> :: tamano(NodoBinario<T> *n){
      int cont=0;
      if(n->obtenerDato()!=NULL)
      {
      cont+=tamano(n->obtenerHijoIzq());
      cont+=tamano(n->obtenerHijoDer());
      cont++;
      }
      return cont;
}*/

template <class T> bool ArbolBinarioOrd<T>::buscar(T &val) {
  return buscar(this->raiz, val)!=NULL;
}

template <class T> NodoBinario<T>*  ArbolBinarioOrd<T>::buscar(NodoBinario<T> *n, T &val) {

  NodoBinario<T>* temp=NULL;
  if (n != NULL)
  {
    if (n->obtenerDato() == val) {
      return n;
    }
    if( n->obtenerDato() > val ){
    	temp=buscar(n->obtenerHijoIzq(),val);
        if (temp!=NULL) {
          return temp;
        }
    }
    else if( n->obtenerDato() < val){
    	temp=buscar(n->obtenerHijoDer(),val);
        if (temp!=NULL) {
          return temp;
        }
    }
  }
  return NULL;
}

/*
template <class T> bool  ArbolBinarioOrd<T>::buscar(NodoBinario<T> *n, T &val) {

  if (n != NULL) {
    if (n->dato == val) {
      return true;
    }
    if (buscar(n->obtenerHijoIzq())) {
      return true;
    }
    if (buscar(n->obtenerHijoDer())) {
      return true;
    }
  }
  return 0;
}
*/

template <class T> bool ArbolBinarioOrd<T>::insertar(T &val) {

  if (this->raiz == NULL) {
    this->raiz = new NodoBinario<T>(val);
  } else {
    insertar(this->raiz, val);
  }
}

template <class T>
bool ArbolBinarioOrd<T>::insertar(NodoBinario<T> *n, T &val) {

  if (val < (n->obtenerDato())) {
    if (n->obtenerHijoIzq() != NULL) {

      return insertar(n->obtenerHijoIzq(), val);

    } else {
      n->fijarHijoIzq ( new NodoBinario<T>(val));
      return 1;
    }
  } else if (val > (n->obtenerDato())) {
    if (n->obtenerHijoDer() != NULL) {
      return insertar(n->obtenerHijoDer(), val);
    } else {

      n->fijarHijoDer (new NodoBinario<T>(val));
      return 1;
    }
  }
  return 0;
}

template <class T>
bool ArbolBinarioOrd<T>::eliminar(T &val)
{
	if(buscar(val)){
	 this->raiz=eliminar(this->raiz,val);
		return true;
	}
	return false;
}
template <class T>
NodoBinario<T>* ArbolBinarioOrd<T>::eliminar(NodoBinario<T>* n,T&val)
{
  NodoBinario<T>* temp=NULL;
	if(n->obtenerDato()==val)
	{
		if( n->obtenerHijoDer() == NULL && n->obtenerHijoIzq() == NULL )
		{
			delete n;
      return NULL;
		}
    else if( n->obtenerHijoIzq() == NULL && n->obtenerHijoDer()!= NULL )
    {
      temp = n->obtenerHijoDer();
      n->fijarHijoDer(NULL);
      delete n;
      return temp;
    }
    else if( n->obtenerHijoIzq() != NULL && n->obtenerHijoDer()== NULL )
    {
      temp = n->obtenerHijoIzq();
      n->fijarHijoIzq(NULL);
      delete n;
      return temp;
    }
    else
    {
      temp = minimoNodo(n);
      if(temp != NULL){
        n->fijarDato(temp->obtenerDato());
        delete temp;
        return n;
      }
    }
	}
  else if( n->obtenerDato() < val )
  {
     n->fijarHijoDer(eliminar(n->obtenerHijoDer(),val));
     return n;
  }
  else if( n->obtenerHijoIzq()->obtenerDato() > val )
  {
    n->fijarHijoIzq(eliminar(n->obtenerHijoIzq(),val));
    return n;

  }
  return NULL;
}
template <class T>
NodoBinario<T>* ArbolBinarioOrd<T>::minimoNodo(NodoBinario<T> *n) {
  if (n->obtenerHijoIzq() == NULL) {
    return n;
  } else {
    return minimoNodo(n);
  }
}
template <class T> T &ArbolBinarioOrd<T>::minimo() {
  if( this->raiz!=NULL)
  return minimo(this->raiz);
}
template <class T> T &ArbolBinarioOrd<T>::minimo(NodoBinario<T> *n) {
  if (n->obtenerHijoIzq() == NULL) {
    return n->obtenerDato();
  } else {
    return minimo(n->obtenerHijoIzq());
  }
}
template <class T> T &ArbolBinarioOrd<T>::maximo() {
  if( this->raiz!=NULL)
  return maximo(this->raiz);
}
template <class T> T &ArbolBinarioOrd<T>::maximo(NodoBinario<T> *n) {
  if (n->obtenerHijoDer() == NULL) {
    return n->obtenerDato();
  } else {
    return maximo(n->obtenerHijoDer());
  }
}
