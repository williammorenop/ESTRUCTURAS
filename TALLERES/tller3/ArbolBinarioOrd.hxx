#include "ArbolBinarioOrd.hxx"
#include <queue>
#include <algorithm>
template <class T> ArbolBinarioOrd<T>::ArbolBinarioOrd() { this->raiz = NULL; }
template <class T> ArbolBinarioOrd<T>::ArbolBinarioOrd(T &val) {
  this->raiz = new NodoBinario<T>(val);
}
template <class T> ArbolBinarioOrd<T>::~ArbolBinarioOrd() {
  delete this->obtenerHijoIzq;
  delete this->obtenerHijoDer;
  delete this;
}
template <class T> bool ArbolBinarioOrd<T>::esVacio() {
  return this->raiz == NULL;
}
template <class T> T &ArbolBinarioOrd<T>::datoRaiz() {
  return this->raiz->dato;
}

template <class T> void ArbolBinarioOrd<T>::preOrden(queue<T> &q) {
  preOrden(this->raiz, q);
}

template <class T>
void ArbolBinarioOrd<T>::preOrden(NodoBinario<T> *n, queue<T> &q) {
  if (n->obtenerDato() != NULL) {
    q.push(n->obtenerDato());
    preOrden(n->obtenerHijoIzq, q, );
    preOrden(n->obtenerHijoDer, q, );
  }
}

template <class T> void ArbolBinarioOrd<T>::inOrden(queue<T> &q) {
  inOrden(this->raiz, q);
}

template <class T>
void ArbolBinarioOrd<T>::inOrden(NodoBinario<T> *n, queue<T> &q) {

  if (n->obtenerDato() != NULL) {
    inOrden(n->obtenerHijoIzq(), q);
    q.push(n->obtenerDato());
    inOrden(n->obtenerHijoDer(), q);
  }
}

template <class T> void ArbolBinarioOrd<T>::posOrden(queue<T> &q) {
  posOrden(this->raiz, q);
}

template <class T>
void ArbolBinarioOrd<T>::posOrden(NodoBinario<T> *n, queue<T> &q) {
  if (n->obtenerDato() != NULL) {
    posOrden(n->obtenerHijoIzq, q);
    posOrden(n->obtenerHijoDer, q);
    q.push(n->obtenerDato());
  }
}

template <class T> 
void ArbolBinarioOrd<T>::nivelOrden(queue<T>&que)
{
	queue<NodoBinario<T>*> q;
	q.insert(this->raiz);
	while( !q.empty() )
	{
		NodoBinario<T>* n=q.front();
		q.pop();
		que.insert(n->obtenerDato);
		if( n->obtenerHijoIzq != NULL )
			q.insert(n->obtenerHijoIzq);
		if( n->obtenerHijoDer != NULL)
			q.insert(n->obtenerHijoDer);
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
		tamIzq=altura(n->obtenerHijoIzq);
		tamDer=altura(n->obtenerHijoDer);
		tam=max(tamIzq,tamDer);
		++tam;
	}
	return tam;
}

template <class T> int ArbolBinarioOrd<T>::tamano(int &cont) {
  tamano(this->raiz, cont);
}
template <class T>
void ArbolBinarioOrd<T>::tamano(NodoBinario<T> *n, int &cont) {

  if (n->obtenerDato() != NULL) {
    tamano(n->obtenerHijoIzq, cont);
    tamano(n->obtenerHijoDer, cont);
    cont++;
  }
}

/*int ArbolBinarioOrd <T> :: tamano(NodoBinario<T> *n){
      int cont=0;
      if(n->obtenerDato()!=NULL)
      {
      cont+=tamano(n->obtenerHijoIzq);
      cont+=tamano(n->obtenerHijoDer);
      cont++;
      }
      return cont;
}*/

template <class T> bool ArbolBinarioOrd<T>::buscar(T &val) {
  return buscar(this->raiz, val)!=NULL;
}

template <class T> NodoBinario<T>*  ArbolBinarioOrd<T>::buscar(NodoBinario<T> *n, T &val) {

  if (n->obtenerDato() != NULL) {
    if (n->dato == val) {
      return n;
    }
	NodoBinario<T>* temp=buscar(n->obtenerHijoIzq);
    if (temp!=NULL) {
      return temp;
    }
	temp=buscar(n->obtenerHijoDer);
    if (temp!=NULL) {
      return temp;
    }
  }
  return NULL;
}

/*
template <class T> bool  ArbolBinarioOrd<T>::buscar(NodoBinario<T> *n, T &val) {

  if (n->obtenerDato() != NULL) {
    if (n->dato == val) {
      return true;
    }
    if (buscar(n->obtenerHijoIzq)) {
      return true;
    }
    if (buscar(n->obtenerHijoDer)) {
      return true;
    }
  }
  return 0;
}
*/

template <class T> bool ArbolBinarioOrd<T>::insertar(T &val) {

  if (this->raiz == null) {
    this->raiz = new NodoBinario(val);
  } else {
    insertar(this->raiz, val);
  }
}

template <class T>
bool ArbolBinarioOrd<T>::insertar(NodoBinario<T> *n, T &val) {

  if (val < (n->obtenerDato)) {
    if (n->obtenerHijoIzq != null) {

      return insertar(n->obtenerHijoIzq, val);

    } else {
      n->fijarHijoIzq = NodoBinario(val);
      return 1;
    }
  } else if (val > (n->obtenerDato)) {
    if (n->obtenerHijoDer != null) {
      return insertar(n->obtenerHijoDer, val);
    } else {

      n->fijarHijoDer = NodoBinario(val);
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
NodoBinario<T>* ArbolBinario<T>::eliminar(NodoBinario<T>* n,T&val)
{
	if(n->obtenerDato==val)
	{
		if( n->obtenerHijoDer != NULL )
		{
			
		}	
	}
}
template <class T> T &ArbolBinarioOrd<T>::minimo(NodoBinario<T> *n) {
  if (n->obtenerHijoIzq == null) {
    return n->obtenerDato;
  } else {
    return minimo(n->obtenerHijoIzq);
  }
}
template <class T> T &ArbolBinarioOrd<T>::maximuswell(NodoBinario<T> *n) {
  if (n->obtenerHijoDer == null) {
    return n->obtenerDato;
  } else {
    return maximuswell(n->obtenerHijoDer);
  }
}
