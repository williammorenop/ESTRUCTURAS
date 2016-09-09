#include "Arbol.h"
#include <iostream>
#include <queue>
template<typename T>

bool Arbol<T> :: esVacio(){
    if(this->raiz==NULL){
        return true;
    }
    return false;
}

template <typename T>
Nodo<T>* Arbol<T>::obtenerRaiz(){
    return this->raiz;
}
template <typename T>

void Arbol<T>::fijarRaiz(Nodo<T>* nraiz){

        raiz->fijarDesc(nraiz->getDesc());
        raiz->fijarDato(nraiz->obtenerDato());

}

template <typename T>
bool Arbol<T>::insertarNodo(T& padre, T& n){

    Nodo<T>* papa=buscaR(raiz,padre);
    if(!papa)
      return false;
    std::cout<<"yo soy papa "<<papa->obtenerDato()<<std::endl;
    papa->adicionarDesc(n);
    return true;
}

template<typename T>
bool Arbol<T>::eliminarNodo(T& n)
{
    Nodo<T>* papa=buscaR(raiz,n);
  //  papa->~();//destruccion del papa
  delete papa;
}

template<typename T>
bool Arbol<T>::buscar(T& n)
{
  if(!buscaR(raiz,n))
    return false;
  return true;
}

template <typename T>
Nodo<T>* buscaR(Nodo<T>* actual, T& padre){
  std::cout<<"juancho pere< "<<actual->obtenerDato()<<std::endl;
    if(actual->obtenerDato()==padre){
        return actual;
    }
    typename std::list<Nodo<T>*>::iterator it;
    for (it=actual->getDesc().begin();it != actual->getDesc().end();++it)
    {
      std::cout<<"voy a enviar con "<<actual->obtenerDato()<<" al "<<(*it)->obtenerDato()<<std::endl;
          Nodo<T>* res= buscaR(*it,padre);
          if(res!=NULL)
            return res;
    }
    std::cout<<"jojojo"<<std::endl;
    return NULL;

}
template<typename T>
unsigned int Arbol<T>::altura(Nodo<T>* inicio)
{
  unsigned int n=0;
  typename std::list<Nodo<T>*>::iterator it;
  for (it=inicio->getDesc().begin();it !=inicio->getDesc().end() ; ++it )
  {
        n=max(n,altura(it));
  }
  return n+1;
}
template<typename T>
unsigned int Arbol<T>::tamano(Nodo<T>* inicio)
{
  unsigned int n=1;
  typename std::list<Nodo<T>*>::iterator it;
  for (it=inicio->getDesc().begin();it !=inicio->getDesc().end() ; ++it )
  {
        n+=tamano(it);
  }
  return n;
}
template<typename T>
void Arbol<T>::preOrden(Nodo<T>* inicio,std::queue<T>&order)
{
  order.push(inicio->obtenerDato());
  typename std::list<Nodo<T>*>::iterator it;
  for (it=inicio->getDesc().begin();it !=inicio->getDesc().end() ; ++it )
  {
        preOrden(*it,order);
  }
}
template<typename T>
void Arbol<T>::posOrden(Nodo<T>* inicio,std::queue<T>&order)
{
  typename std::list<Nodo<T>*>::iterator it;
  for (it=inicio->getDesc().begin();it !=inicio->getDesc().end() ; ++it )
  {
        posOrden(*it,order);
  }
  order.push(inicio->obtenerDato());
}
template<typename T>
void Arbol<T>::nivelOrden(Nodo<T>* inicio,std::queue<T>&order)
{
  typename std::queue<Nodo<T>*> q;
  q.push(inicio);
  while(!q.empty())
  {
    Nodo<T>* now=q.front();
    q.pop();
    order.push(now->obtenerDato());
    typename std::list<Nodo<T>*>::iterator it;
    for (it=now->getDesc().begin();it !=now->getDesc().end() ; ++it )
    {
          q.push(*it);
    }
  }
}
template<typename T>
Arbol<T>::~Arbol()
{
  delete raiz;
}
template<typename T>
Arbol<T>::Arbol()
{
  raiz=new Nodo<T>();
}
