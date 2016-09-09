#ifndef STACK
#define STACK

#include "Node.h"

template<typename T>
class Stack{
  int tam;
  Node<T>* top;
public:
  Stack();
  void push(const T&);
  bool isEmpty()const;
  T tope()const;
  void pop();
  int getSize()const;
  ~Stack();
};

#include "Stack.hpp"
#endif
