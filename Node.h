#ifndef NODE
#define NODE

#include <iostream>

template<typename T>
class Node
{
  T info;
  Node<T>* next;
public:
  Node(const T& info, Node<T>* n=NULL);
  Node<T>* getNext()const;
  void setNext(Node<T>*n);
  T getInfo()const;
  void setInfo(const T&);
};

#include "Node.hpp"
#endif
