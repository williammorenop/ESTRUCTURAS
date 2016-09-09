#include "Nodo.h"
#include <list>

//using namespace std;

template <typename T>
T&   Nodo<T>:: obtenerDato()
{
	return dato;
}

template <typename T>
void Nodo<T> ::fijarDato(T& val)
{
	dato=val;
}

template <typename T>
void Nodo<T>::limpiarLista()
{
	desc.clear();
}

template <typename T>
void Nodo<T>::adicionarDesc(T& nval)
{
	Nodo<T>* temp=new Nodo<T>();
	temp->fijarDato(nval);
	desc.push_back(temp);
}

template <typename T>
void Nodo<T>::eliminarDesc(T& val)
{
    //Nodo<T> hola;
      typename  std::list<Nodo<T>* >::iterator it;
	for (it=desc.begin();it != desc.end();++it)
	{
        if(it->dato==val)
        {
    	break;
        }
	}
	desc.erase(it);
}

template <typename T>
Nodo<T>::~Nodo()
{
		typename  std::list<Nodo<T>* >::iterator it=desc.begin();
		typename  std::list<Nodo<T>* >::iterator it2;

		while (it!=desc.end())
		{
						it2=it++;
					  delete *it2;

		}

}
template <typename T>
std::list<Nodo<T>*>& Nodo<T>::getDesc()
{
		return this->desc;
}

template <typename T>
void Nodo<T>::fijarDesc(std::list<Nodo<T>*>&de)
{
	this->desc=de;
}
