
#ifndef NODO
#define NODO

#include <list>

template< class T >
    	class Nodo {
    	protected:
        	T dato;
        	std::list< Nodo<T>* > desc;
    	public:
        	Nodo();
        	~Nodo();
        	T& obtenerDato();
        	void fijarDato(T& val);
        	void limpiarLista();
        	void adicionarDesc(T& nval);
        	void eliminarDesc(T& val);
};

#include "Nodo.hxx"
#endif

