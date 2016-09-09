

#include "Node.h"
template <typename T>
Node<T>::Node(const T& info,Node<T>* n)
{
  this->info=info;
  this->next=n;
}

template<typename T>
Node<T>* Node<T>::getNext()const
{
  return this->next;
}

template<typename T>
void Node<T>::setNext(Node<T>* n )
{
  this->next=n;
}
template<typename T>
T Node<T>::getInfo()const
{
  return this->info;
}
