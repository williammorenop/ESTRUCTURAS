#ifndef ARBOLBINARIOORD
#define ARBOLBINARIOORD

template< class T >
class ArbolBinarioOrd {
      protected:
          NodoBinario<T> *raiz;
      public:
          ArbolBinarioOrd();
          ArbolBinarioOrd(T& val);
          ~ArbolBinarioOrd();
          bool esVacio();
          T& datoRaiz();
          void preOrden(queue <T>& q);
          void preOrden(NodoBinario<T>*n,queue <T>& q);
          void inOrden(queue <T>& q);
          void inOrden(NodoBinario<T>*n,queue <T>& q);
          void posOrden(queue <T>& q);
          void posOrden(NodoBinario<T>*n,queue <T>& q);
          void nivelOrden(queue <T>& q);
          void nivelOrden(NodoBinario<T>*n,queue <T>& q);
          int altura();
          int tamano();
          bool buscar(T& val);
          bool insertar(T& val);
          bool eliminar(T& val);
          T& minimo();
          T& maximo();
};

#include "ArbolBinarioOrd.hxx"
#endif
