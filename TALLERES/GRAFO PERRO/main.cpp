#include <iostream>
#include <cstdio>
#include "Graph.h"

using namespace std;

int main()
{
  Graph<int> a;
  for( int i  = 0 ; i < 4 ; ++i )
    a.addNode( i );
  a.addArist( 0 , 1 , 0 );
  a.addArist( 1 , 2 , 0 );
  a.addArist( 2 , 3 , 0 );
  a.addArist( 3 , 0 , 0 );
  std::vector< int > v;
  a.BFS( a.findNode(1) , v );
  for( int i = 0 ; i < v.size() ; ++i )
    printf("%d ",v[i] );
  printf("\n");
  return 0;
}
