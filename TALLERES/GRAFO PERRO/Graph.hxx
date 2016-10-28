#include "Graph.h"
#include <list>
#include <vector>

template <typename R>
Graph::  ~Graph()
{
  for(std::list< NodeGraph * >::iterator it = this->listN.begin() ; it != this->listN.end() ; ++it )
    delNode( *it );
}

template <typename R>
Graph::std::list< std::NodeGraph<R>*> getList()
{
  return this->listN;
}

template <typename R>
Graph::bool addNode( R date )
{
  if( findNodeNodete ) == NULL )
    return false;
  this->listN.push_back( new NodeGraph<R>(date) );
  return true;

template <typename R>}
Graph::bool addArist( R dateOrigin, R dateToGo, int weight );{
    NodeGraph< R >* aux,aux2;
    aux = aux2 = NULL;
    aux=findNode(dateOrigin);
    aux2=findNode(dateToGo);
    if( aux == NULL || aux2 == NULL )
      return 0;
    aux->addNode(aux2,weight);
    return 1;
}

template <typename R>
Graph::NodeGraph< R >* findNode( R date )
{
  for(std::list< NodeGraph * >::iterator it = this->listN.begin() ; it != this->listN.end() ; ++it )
      if( *it->getDate() == date )
        return *it;
  return NULL;
}

template <typename R>
Graph::bool delNode( R date )
{
  NodeGraph<R> * aux = findNode( date );
  if( aux == NULL )
    return false;
  return delNode( aux );
}

template <typename R>
Graph::bool delNode( NodeGraph<R>* n )
{
  for(std::list< NodeGraph * >::iterator it = this->listN.begin() ; it != this->listN.end() ; ++it )
  {
    *it->delArist(n);
  }
  return 1;

}
template <typename R>
Graph::bool delArist( R dateOrigin, R dateToGo )
{
  NodeGraph< R >* aux,aux2;
  aux = aux2 = NULL;
  aux=findNode(dateOrigin);
  aux2=findNode(dateToGo);
  if( aux == NULL || aux2 == NULL )
    return 0;
  return aux->delArist( aux2 );
}
template <typename R>
Graph::void BFS( NodeGraph<R>* n , std::vector< R >& v)
{
  this->allNode( false );
  queue< NodeGraph<R>* > q;
  n->setVisited( true );
  q.push( n );
  while( !q.empty() )
  {
      NodeGraph<R>* now = q.front();
      q.pop();
      v.push_back( now->getDate() );
      std::list< std::pair< NodeGraph* , int > > :: iterator it;
      for(  it = now.getList().begin() ; it != now.getList().end() ; ++it )
      {
        if(!((*it).first->getVisited()))
        {
          (*it).first->setVisited( true );
          q.push( *it.first );
        }
      }
  }
}

template <typename R>
Graph::void DFS( NodeGraph<R>* n, std::vector< R >& dfs)
{
  this->allNode( false );
  DFS_C( n, dfs);
}

template <typename R>
Graph::void DFS_C( NodeGraph<R>* n, std::vector< R >& dfs)
{
   dfs.push_back(n->getDate());
   std::list< std::pair< NodeGraph* , int > > :: iterator it;
   for(  it = n.getList().begin() ; it != n.getList().end() ; ++it )
   {
     if(*it.first->getVisited()==false)
     {
       *it.first->setVisited(true);
       DFS_C(*it.first,dfs);
     }
   }
}

template <typename R>
Graph::void plane(  std::vector< R >& vplane)
{
  std::list< std::list< NodeGraph<R>* > :: iterator it;
  for(  it = this->listN.begin() ; it != this->listN.end() ; ++it )
  {
     vplane.push_back(*it->getDate());
  }
}
