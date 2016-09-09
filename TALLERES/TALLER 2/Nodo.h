

#ifndef NODO
#define NODO

#include <list>

template<typename T>
class Nodo {
    	protected:
        	T dato;
          std::list<Nodo<T>*> desc;
    	public:
        	~Nodo();
        	T& obtenerDato();
        	void fijarDato(T& val);
          void fijarDesc(std::list<Nodo<T>*>&de);
          void limpiarLista();
        	void adicionarDesc(T& nval);
        	void eliminarDesc(T& val);
          std::list<Nodo<T>*>& getDesc();

};

#include "Nodo.hxx"
#endif
