

int Triqui::maximasJugadas ()
{
    return maximas(this->raiz);
}

int maximas( Nodo* n)
{
  if( n == NULL )
    return -1;
  list<Nodo*> temp =n->getHijos();
  list<Nodo*>::iterator it;
  int may=temp.size();
  for( it = temp.begin() ; it != temp.end() ; ++it )
  {
      may=max(may,maximas(*it));
  }
  return may;
}

pair<int,int> Triqui::ganador (string tablero)
{
  Nodo* tab=buscarTablero(tablero);
  return minimoGanador( tab );
}

Nodo* buscarTablero(string tablero, Nodo* n){


  if(tablero==n->obtenerTablero())
    return n;

  list<nodo*> lista=n->obtenerHijos();
  list<nodo*>::iterator it=lista.begin();

  for(;it!= lista.end();it++){
    Nodo* nodo= buscarTablero(tablero, *it);
    if(nodo!= NULL)
      return nodo;

  }

  return NULL;
}

pair< int , int > minimoGanador( Nodo* n )
{
  if( n->getHijos().empty() )
  {
    int gg=gano( n->getTablero() );
    if(  gg != -1 )
    {
      return make_pair( 0 , gg );
    }
    else
    {
      return make_pair( INF  , -1 );
    }
  }
  list<Nodo*> temp =n->getHijos();
  list<Nodo*>::iterator it;
  pair< int, int > men=make_pair( INF , -1 );
  for( it = temp.begin() ; it != temp.end() ; ++it )
  {
      men=min(men,minimoGanador(*it));
  }
  ++men.first;
  return men;
}

// Johan no sabe programar
