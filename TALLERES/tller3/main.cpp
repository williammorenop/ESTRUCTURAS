#include <iostream>
#include <queue>
#include <cstdio>
#include "ArbolBinarioOrd.h"


int main ()
{
  ArbolBinarioOrd<int> ar;
  int a=1;
  ar.insertar(a);
  a=5;
  ar.insertar(a);
  a=10;
  ar.insertar(a);
  std::queue<int> q;
  ar.inOrden(q);
  while(!q.empty()){
    std::cout<<q.front()<<" ";
    q.pop();
  }
  std::cout<<std::endl;
  std::cout<<"minimo "<<ar.minimo()<<std::endl;
  std::cout<<"maximo "<<ar.maximo()<<std::endl;
  std::cout<<"altura "<<ar.altura()<<std::endl;
  ar.tamano(a);
  std::cout<<"tamano "<<a<<std::endl;
  std::cout<<"esVacio "<<ar.esVacio()<<std::endl;

  a=5;
  ar.eliminar(a);
  ar.inOrden(q);
  while(!q.empty()){
    std::cout<<q.front()<<" ";
    q.pop();
  }
  std::cout<<std::endl;
  std::cout<<"sali"<<std::endl;
  return 0;
}
