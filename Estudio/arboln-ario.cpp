

int altura( Nodo* n )
{
  if( n == NULL )
  {
    return -1;
  }
  list<Nodo*> temp =n->getHijos();
  list<Nodo*>::iterator it;
  int may=-1;
  for( it = temp.begin() ; it != temp.end() ; ++it )
  {
      may=max(may,altura(*it));
  }
  return may+1;
}


int mayor=altura(raiz);
