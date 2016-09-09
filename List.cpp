
template <typename T>
List<T>::List()
{
    int=0;
    top=NULL;
    ass=NULL;
}
template <typename T>
void List::push(const T& dato)
{
    Nodo Node(dato);
    if(tam==0)
    {
        top=&Nodo;
        ass=&Nodo;
    }
    else
    {
        Node <T>* aux=top;
        top=&Nodo;
        top->setNext(aux);
    }
    ++tam;
}


template <typename T>
bool List::isempty()const
{
   return tam==0;
}

template <typename T>
T List::top() const
{
    return top->getinfo;
}

template <typename T>
T List::dat(int i) const
{
    Node<T>* aux=top;
    for(int a=0;a<i;a++)
    {
        aux=aux->getNext();
    }
    return aux->getinfo;
}

template <typename T>
T List::ass() const
{
    return ass->getinfo;
}

template <typename T>
void List::popf()
{
    Node <T>* aux=top;
    top=top->getNext;

    /////BORRAR NODO DE AUX//////////////////////////////////////
}



template <typename T>
void List::popl()
{
    Node <T>* aux=ass;
    ass=top;
    for(int a=0; a<tam-1;a++)
    {
        ass=ass->getNext();
    }
    ass->setNext(NULL);

    /////BORRAR NODO DE AUX//////////////////////////////////////
}
template <typename T>
int Ass::getsize() const
{
    return tam;
}

///DESTRUCTOR
