#include <iostream>
#include <queue>
#include <cstdio>
#include "Nodo.h"
#include "Arbol.h"

using namespace std;

void imprimirDes(list<Nodo<int>*> desc)
{
    std::list<Nodo<int>* >::iterator it;
for (it=desc.begin();it != desc.end();++it)
{
    cout<<((*it)->obtenerDato())<<" ";
}
cout<<endl;
}

int main()
{


//    NODO<int> nodoone;
//    NODO<int> nodotwo;
//    NODO<int> nodothree;
//    NODO<int> nodofour;

  Arbol<int> ai;
  Nodo<int> n;
  int num=9;
   n.fijarDato(num);
   ai.fijarRaiz(&n);
   int x,y;
   x=9;y=0;
   cout<<"jjjjjj"<<endl;
   cout<<ai.insertarNodo(x,y)<<" "<<ai.obtenerRaiz()->getDesc().size()<<endl;
imprimirDes(ai.obtenerRaiz()->getDesc());
   y=1;
   cout<<"jjjjjj"<<endl;
   cout<<ai.insertarNodo(x,y)<<" "<<ai.obtenerRaiz()->getDesc().size()<<endl;
imprimirDes(ai.obtenerRaiz()->getDesc());
   y=2;
   cout<<"jjjjjj"<<endl;
   cout<<ai.insertarNodo(x,y)<<" "<<ai.obtenerRaiz()->getDesc().size()<<endl;
imprimirDes(ai.obtenerRaiz()->getDesc());
   x=0;y=5;
   cout<<"jjjjjj"<<endl;
   cout<<ai.insertarNodo(x,y)<<" "<<ai.obtenerRaiz()->getDesc().size()<<endl;
imprimirDes(ai.obtenerRaiz()->getDesc());
   x=5;y=15;
   cout<<"jjjjjj"<<endl;
   cout<<ai.insertarNodo(x,y)<<" "<<ai.obtenerRaiz()->getDesc().size()<<endl;
imprimirDes(ai.obtenerRaiz()->getDesc());
   x=0;y=51;
   cout<<"jjjjjj"<<endl;
   cout<<ai.insertarNodo(x,y)<<" "<<ai.obtenerRaiz()->getDesc().size()<<endl;
imprimirDes(ai.obtenerRaiz()->getDesc());
   x=2;y=555;
   cout<<"jjjjjj"<<endl;
   cout<<ai.insertarNodo(x,y)<<" "<<ai.obtenerRaiz()->getDesc().size()<<endl;
imprimirDes(ai.obtenerRaiz()->getDesc());
   x=9;y=7;
   cout<<"jjjjjj"<<endl;
   cout<<ai.insertarNodo(x,y)<<" "<<ai.obtenerRaiz()->getDesc().size()<<endl;
imprimirDes(ai.obtenerRaiz()->getDesc());
   x=7;y=-1;
   cout<<"jjjjjj"<<endl;
   cout<<ai.insertarNodo(x,y)<<" "<<ai.obtenerRaiz()->getDesc().size()<<endl;
imprimirDes(ai.obtenerRaiz()->getDesc());
   x=0;y=1225;
   cout<<"jjjjjj"<<endl;
   cout<<ai.insertarNodo(x,y)<<" "<<ai.obtenerRaiz()->getDesc().size()<<endl;
imprimirDes(ai.obtenerRaiz()->getDesc());

   cout<<"sali de insertar"<<endl;
  queue<int> q;
  ai.nivelOrden(ai.obtenerRaiz(),q);

  while(!q.empty())
  {
    printf("%d\n",q.front() );
    q.pop();
  }
    return 0;
}
