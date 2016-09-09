#include "Stack.h"
#include <cassert>

template<typename T>
Stack<T>::Stack()
{
  this->tam=0;
  this->top=NULL;
}

template<typename T>
void Stack<T>::push( const T& n)
{
    Node<T>* nuevo=new Node<T>(n);
    nuevo->setNext(this->top);
    this->top=nuevo;
    ++this->tam;
}

template<typename T>
bool Stack<T>::isEmpty()const
{
  return (this->top==NULL);
}

template<typename T>
T Stack<T>::tope()const
{
  assert(!isEmpty());
    return this->top->getInfo();

}

template<typename T>
void Stack<T>::pop () {
  if (this->top != NULL) {
    Node<T>* old = this->top;
    this->top = this->top->getNext();
    delete old;
    --this->tam;
  }
}

template<typename T>
int Stack<T>::getSize() const
{
  return this->tam;
}

template<typename T>
Stack<T>::~Stack()
{
  while (!isEmpty()) {
    pop();
  }
}
