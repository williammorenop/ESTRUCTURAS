 #include "ass.h"

template <typename T>
Ass<T>::Ass()
{
    tam=0;
    top=NULL;
    ass=NULL;
}
template <typename T>
void Ass<T>::push(const T& dato)
{
    if(tam==0)
    {
        ass=top= new Node<T>(dato);

    }
    else
    {
        Node <T>* aux=top;
        top= new Node<T> (dato);
        top->setNext(aux);
    }
    ++tam;
}

template <typename T>
bool Ass<T>::isempty()const
{
   return tam==0;
}

template <typename T>
T Ass<T>::topete() const
{

    return this->top->getInfo;
}

template <typename T>
T Ass<T>::asses() const
{
    return this->ass->getinfo;
}

template <typename T>
void Ass<T>::pop()
{
    Node <T>* aux=ass;
    ass=top;
    for(int a=0; a<tam-1;a++)
    {
        ass=ass->getNext();
    }
    ass->setNext(NULL);
    delete aux;
    /////BORRAR NODO DE AUX//////////////////////////////////////
}
template <typename T>
int Ass<T>::getsize() const
{
    return tam;
}

template <typename T>
Ass<T>::~Ass()
{
  while (!isempty()) {
    pop();
  }
}
///DESTRUCTOR


