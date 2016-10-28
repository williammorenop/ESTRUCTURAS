#include "NodeGraph.h"
#include <list>
#include <vector>

template <typename R>
NodeGraph< R >::~NodeGraph(){};


template <typename R>
bool  NodeGraph< R >::delArist(NodeGraph< R >* n)
{
  typename std::list< std::pair< NodeGraph< R >* , int > >::iterator it;
  for( it = this->listN.begin() ; it != this->listN.end() ; ++it )
    if( (*it).first == n )
    {
      this->listN.erase(it);
      return true;
    }
  return false;
}

template <typename R>
bool  NodeGraph< R >::addNode( NodeGraph<R>* n , int weight )
{
  typename std::list< std::pair< NodeGraph< R >* , int > >::iterator it;
  for( it = this->listN.begin() ; it != this->listN.end() ; ++it )
    if( n == *it.first)
      return false;
  this->listN.push_back( make_pair(n,weight) );
  return true;
}

template <typename R>
void  NodeGraph< R >::setVisited( bool s )
{
    this->visited = s;
}

template <typename R>
bool  NodeGraph< R >::getVisited( )
{
  return this->visited;
}

template <typename R>
R NodeGraph< R >::getDate()
{
  return this->date;
}
