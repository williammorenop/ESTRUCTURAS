#ifndef NODEGRAPH
#define NODEGRAPH

#include <vector>
#include <list>


template <typename R>
class NodeGraph
{
private:
  R date;
  bool visited;
  std::list< std::pair< NodeGraph< R >* , int > > listN;
public:
  NodeGraph ():  listN ( std::list< std::pair< NodeGraph<R>* , int > >() ){};
  NodeGraph (const R dateL ): date(dateL) , listN ( std::list< std::pair< NodeGraph<R>* , int > >() ){};
  ~NodeGraph();
  std::list< std::pair< NodeGraph< R >* , int > > getList();
  bool delArist(NodeGraph<R>* n);
  bool addNode( NodeGraph<R>* n , int weight );
  void setVisited( bool s );
  bool getVisited( );
  R getDate();

};
#include "NodeGraph.hxx"

#endif
