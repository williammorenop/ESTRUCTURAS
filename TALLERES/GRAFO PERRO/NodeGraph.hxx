#include "NodeGraph.h"
#include <list>

template <typename R>
NodeGraph::~NodeGraph();


template <typename R>
NodeGraph::bool delArist(NodeGraph< R >* n)
{
  std::list< std::pair< NodeGraph< R >* , int > >::iterator it;
  for( it = this->listN.begin() ; it != this->listN.end() ; ++it )
    if( *it.first == n )
    {
      this->listN.erase(it);
      return true;
    }
  return false;
}

template <typename R>
NodeGraph::bool addNode( NodeGraph<R>* n , int weight )
{
  std::list< std::pair< NodeGraph< R >* , int > >::iterator it;
  for( it = this->listN.begin() ; it != this->listN.end() ; ++it )
    if( n == *it.first)
      return false;
  this->listN.push_back( make_pair(n,weight) );
  return true;
}

template <typename R>
NodeGraph::void setVisited( bool s )
{
    this->visited = s;
}

template <typename R>
NodeGraph::bool getVisited( )
{
  return this->visited;
}

R getDate()
{
  return this->date;
}
