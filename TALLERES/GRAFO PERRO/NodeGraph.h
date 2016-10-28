
template <typename R>
class NodeGraph
{
private:
  R dato;
  bool visited;
  std::list< std::pair< NodeGraph< R >* , int > > listN;
public:
  NodeGraph (){} dato:NULL , listN : vector< std::pair< NodeGraph* , int > >() ;
  NodeGraph (const R dato ){} this->dato:dato , listN : vector< std::pair< NodeGraph* , int > >() ;
  ~NodeGraph();
   bool delArist(NodeGraph<R>* n);
  bool addNode( NodeGraph<R>* n , int weight );
  void setVisited( bool s );
  bool getVisited( );
  R getDate();

};
