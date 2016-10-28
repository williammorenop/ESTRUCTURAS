#include <list>
#include <vector>

template <typename R>
class Graph
{
private:
  std::list< NodoGraph<R>* > listN;
public:
  Graph():listN(std::list< NodoGraph<R>* >()){};
  ~Graph();
  std::list< std::NodoGraph<R>*> getList();
  bool addNode( R date );
  bool addArist( R dateOrigin, R dateToGo, int weight );
  NodoGraph< R >* findNode( R date );
  bool delNode( R date );
  bool delNode( NodeGraph<R>* n );
  bool delArist( R dateOrigin, R dateToGo );
  void BFS( NodeGraph<R>* n , std::vector< R >& v);
  void DFS( NodeGraph<R>* n, std::vector< R >& dfs);
  void DFS_C( NodeGraph<R>* n, std::vector< R >& dfs);
  void plane(  std::vector< R >& vplane);
};
