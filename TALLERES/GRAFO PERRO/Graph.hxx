
#include <list>
#include <vector>
#include <queue>

template <typename R>
bool  Graph< R >::delNode( NodeGraph<R>* n )
{
  typename std::list< NodeGraph< R > * >::iterator it;
  for( it  = this->listN.begin() ; it != this->listN.end() ; ++it )
  {
    (*it)->delArist(n);
  }
  return 1;
}

template <typename R>
Graph< R >::~Graph()
{
  typename std::list< NodeGraph< R > * >::iterator it;
  for( it = this->listN.begin() ; it != this->listN.end() ; ++it )
    delNode( *it );
}

template <typename R>
std::list< NodeGraph<R>*> Graph< R >:: getList()
{
  return this->listN;
}

template <typename R>
bool  Graph< R >::addNode( R date )
{
  if( findNode( date )  != NULL )
    return false;
  this->listN.push_back( new NodeGraph<R>(date) );
  return true;
}

template <typename R>
bool  Graph< R >::addArist( R dateOrigin, R dateToGo, int weight ){
    NodeGraph< R > *aux,*aux2;
    aux = aux2 = NULL;
    aux=findNode(dateOrigin);
    aux2=findNode(dateToGo);
    if( aux == NULL || aux2 == NULL )
      return 0;
    aux->addNode(aux2,weight);
    return 1;
}

template <typename R>
NodeGraph < R >* Graph< R >::findNode( R date )
{
  typename std::list< NodeGraph< R > * >::iterator it;
  for( it = this->listN.begin() ; it != this->listN.end() ; ++it )
      if( (*it)->getDate() == date )
        return *it;
  return NULL;
}


template <typename R>
bool  Graph< R >::delNode( R date )
{
  NodeGraph<R> * aux = findNode( date );
  if( aux == NULL )
    return false;
  return delNode( aux );
}

template <typename R>
void Graph< R >::allNode( bool  s )
{
  typename std::list< NodeGraph< R > * >::iterator it;
  for( it = this->listN.begin() ; it != this->listN.end() ; ++it )
      (*it)->setVisited( s );
}

template <typename R>
void  Graph< R >::BFS( NodeGraph<R>* n , std::vector< R >& v)
{
  if( n == NULL )
    return ;
  this->allNode( false );
  std::queue< NodeGraph<R>* > q;
  n->setVisited( true );
  q.push( n );
  while( !q.empty() )
  {
      NodeGraph<R>* now = q.front();
      q.pop();
      v.push_back( now->getDate() );
      typename std::list< std::pair< NodeGraph< R >* , int > > :: iterator it;
      for(  it = now->getList().begin() ; it != now->getList().end() ; ++it )
      {
        if(!((*it).first->getVisited()))
        {
          (*it).first->setVisited( true );
          q.push( (*it).first );
        }
      }
  }
}

template <typename R>
bool  Graph< R >::delArist( R dateOrigin, R dateToGo )
{
  NodeGraph< R > *aux,*aux2;
  aux = aux2 = NULL;
  aux=findNode(dateOrigin);
  aux2=findNode(dateToGo);
  if( aux == NULL || aux2 == NULL )
    return 0;
  return aux->delArist( aux2 );
}
template <typename R>
void  Graph< R >::DFS( NodeGraph<R>* n, std::vector< R >& dfs)
{
  this->allNode( false );
  n->setVisited(true);
  DFS_C( n, dfs);
}

template <typename R>
void  Graph< R >::DFS_C( NodeGraph<R>* n, std::vector< R >& dfs)
{
   dfs.push_back(n->getDate());
   std::cout << "pase por " << n->getDate() << std::endl;
   typename std::list< std::pair< NodeGraph< R >* , int > > :: iterator it;
   std::cout << "el tamano  es " << n->getList().size() << std::endl;
   int cont = 0 ;
   for(  it = n->getList().begin() ; it != n->getList().end() ; ++it )
   {
     std::cout << "entre " << n->getList().size() << " and " << ++cont << std::endl;
     std::cout << (it!=n->getList().end()) << " " << std::endl;
     std::cout << "llegue aca con " << (*it).first->getDate() << " en " << n->getDate() << std::endl;
     std::cout << " y " << (it!=n->getList().end()) << " and " << (!(*it).first->getVisited()) << std::endl;
     if(!(*it).first->getVisited())
     {
       std::cout << "pase" << std::endl;
       (*it).first->setVisited(true);
       DFS_C((*it).first,dfs);
     }
     std::cout << "llegue al final del for " << std::endl;
   }
   std::cout << "sali "<< std::endl;
}

template <typename R>
void  Graph< R >::plane(  std::vector< R >& vplane)
{
  typename  std::list< NodeGraph<R>* > :: iterator it;
  for(  it = this->listN.begin() ; it != this->listN.end() ; ++it )
  {
     vplane.push_back(*it->getDate());
  }
}
