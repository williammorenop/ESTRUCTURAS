

#ifndef NODO
#define NODO

#include <list>

template<typename T>
    	class nodo {
    	protected:
        	T dato;
        	std::list<nodo<T>*> desc;
    	public:
        	nodo();
        	~nodo();
        	T& obtenerDato();
        	void fijarDato(T& val);
        	void limpiarLista();
        	void adicionarDesc(T& nval);
        	void eliminarDesc(T& val);
};

#include "nodo.hxx"
#endif

