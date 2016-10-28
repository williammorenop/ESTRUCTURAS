#ifndef GRAPH
#define GRAPH

#include <list>
#include <vector>
#include "NodeGraph.h"

template <typename R>
class Graph
{
private:
  std::list< NodeGraph<R>* > listN;
public:
  Graph():listN(std::list< NodeGraph<R>* >()){};
  ~Graph();
  std::list< NodeGraph<R>* > getList();
  bool addNode( R date );
  bool addArist( R dateOrigin, R dateToGo, int weight );
  NodeGraph< R >* findNode( R date );
  bool delNode( R date );
  bool delNode( NodeGraph<R>* n );
  bool delArist( R dateOrigin, R dateToGo );
  void BFS( NodeGraph<R>* n , std::vector< R >& v);
  void DFS( NodeGraph<R>* n, std::vector< R >& dfs);
  void DFS_C( NodeGraph<R>* n, std::vector< R >& dfs);
  void plane(  std::vector< R >& vplane);
};

#include "Graph.hxx"

#endif
