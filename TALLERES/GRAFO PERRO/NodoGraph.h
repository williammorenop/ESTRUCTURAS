
template <typename R>
class NodeGraph
{
private:
  R dato;
  std::vector< std::pair< NodeGraph* , int > > listN;
public:
  NodeGraph (){} dato:NULL , listN : vector< std::pair< NodeGraph* , int > >() ;
  NodeGraph (const R dato ){} this->dato:dato , listN : vector< std::pair< NodeGraph* , int > >() ;
  ~NodeGraph();







};
