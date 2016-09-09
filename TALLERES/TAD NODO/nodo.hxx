#include "Nodo.h"
#include <list>

//using namespace std;

template <typename T>
T&   nodo<T>:: obtenerDato()
{
	return dato;
}

template <typename T>
void nodo<T> ::fijarDato(T& val)
{
	dato=val;
}

template <typename T>
void nodo<T>::limpiarLista()
{
	desc.clear();
}

template <typename T>
void nodo<T>::adicionarDesc(T& nval)
{
	desc.push_back(nval);
}

template <typename T>
void nodo<T>::eliminarDesc(T& val)
{
    //nodo<T> hola;
      typename  std::list<nodo<T>* >::iterator it;
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
nodo<T>::~nodo();
{
		typename  std::list<nodo<T>* >::iterator it=desc.begin;
		typename  std::list<nodo<T>* >::iterator it2;

		while (it!=desc.end)
		{
						it2=it++;
					  delete *it;
						it=it2;
		}

}
