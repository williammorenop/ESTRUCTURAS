#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

#include <list>
#include <set>
#include <stack>
#include <queue>
#include <vector>

// TODO #1: incluir cabecera arbol binario ordenado o AVL
// #include "arbolAVL.h"
#include "ArbolBinarioOrd.h"


// -------------------------------------------------------------------------
// Clase para que el heap funcione de mayor a menor
//  tomado de http://www.cplusplus.com/reference/queue/priority_queue/priority_queue/
class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=true)
    {reverse=revparam;}
  bool operator() (const std::string& lhs, const std::string&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};
// -------------------------------------------------------------------------
typedef std::list< std::string > TList;
typedef std::set< std::string >  TSet;
// TODO #2: definir arbol binario ordenado o AVL de tipo std::string
// typedef arbolAVL< std::string > TAVL;
typedef ArbolBinarioOrd< std::string > ABOS;
typedef std::priority_queue< std::string , std::vector<std::string>, mycomparison > Heap;

// -------------------------------------------------------------------------
template< class TArbol >
bool LeerArbol( TArbol& arbol, const std::string& nomArch );
bool leerHeap ( Heap& heap, const std::string& nomArch );
void recorridoHeap( TList&, Heap );
// -------------------------------------------------------------------------

int main( int argc, char* argv[] )
{
  if( argc < 2 )
  {
    std::cerr << "Uso: " << argv[ 0 ] << " archivo_entrada" << std::endl;
    return( -1 );

  } // fi

  // Declarar arboles a usar
  TSet miArbolRN; // arbol rojinegro
  // TODO #3: arbol AVL
  // TAVL miArbolORD;
  ABOS miArbolORD;

  // heap
  Heap heap;

  // Llenar arbol rojinegro y calcular el tiempo empleado
  std::clock_t inicioLecturaRN = std::clock( );
  bool lecturaRN = LeerArbol( miArbolRN, argv[ 1 ] );
  std::clock_t finLecturaRN = std::clock( );
  double tiempoLecturaRN = ( finLecturaRN - inicioLecturaRN ) / double( CLOCKS_PER_SEC );
  if( lecturaRN )
    std::cout
      << "Tiempo de llenado arbol RN = "
      << tiempoLecturaRN << "segs."
      << std::endl;
  else
    std::cout
      << "Error al leer \"" << argv[ 1 ]
      << "\" para llenar el arbol RN."
      << std::endl;

  // Llenar arbol AVL y calcular el tiempo empleado
  std::clock_t inicioLecturaORD = std::clock( );
  // TODO #4: usar el archivo para llenar el arbol ORD
   bool lecturaORD = LeerArbol( miArbolORD, argv[ 1 ] );
  std::clock_t finLecturaORD = std::clock( );
  double tiempoLecturaORD = ( finLecturaORD - inicioLecturaORD ) / double( CLOCKS_PER_SEC );
   //TODO #5: informar tiempo de llenado del arbol ORD
     if( lecturaORD )
     std::cout
     << "Tiempo de llenado arbol ORD = "
     << tiempoLecturaORD << "segs."
     << std::endl;
     else
     std::cout
     << "Error al leer \"" << argv[ 1 ]
     << "\" para llenar el arbol ORD."
     << std::endl;

  // Llenar Heap y calcular el tiempo empleado
  std::clock_t inicioLecturaHEAP = std::clock( );
  // TODO #4: usar el archivo para llenar el arbol AVL
   bool lecturaHEAP = leerHeap( heap, argv[ 1 ] );
  std::clock_t finLecturaHEAP = std::clock( );
  double tiempoLecturaHEAP = ( finLecturaHEAP - inicioLecturaHEAP ) / double( CLOCKS_PER_SEC );
   //TODO #5: informar tiempo de llenado del arbol AVL
     if( lecturaHEAP )
     std::cout
     << "Tiempo de llenado HEAP = "
     << tiempoLecturaHEAP << "segs."
     << std::endl;
     else
     std::cout
     << "Error al leer \"" << argv[ 1 ]
     << "\" para llenar el HEAP."
     << std::endl;


  // Obtener el recorrido en inorden del arbol AVL
  TList inordenORD;
  // TODO #6: llamar funcion que genera el recorrido en inorden
   miArbolORD.inordenEnLista( inordenORD );

  TList listaHeap;

  recorridoHeap( listaHeap , heap );

  if( inordenORD.size( ) != miArbolRN.size( ) )
  {
    std::cout << "Cantidad de elementos en los arboles no coinciden." << std::endl;
    return( -1 );

  } // fi

  // Comparar los arboles
  TSet::const_iterator rnIt = miArbolRN.begin( );
  TList::const_iterator avlIt = inordenORD.begin( );
  bool iguales = true;
  for( ; rnIt != miArbolRN.end( ); rnIt++, avlIt++ )
    iguales &= ( *rnIt == *avlIt );

  // Informar si los arboles coinciden o no
  std::cout << "Los arboles ";
  if( !iguales )
    std::cout << "no ";
  std::cout << "coinciden." << std::endl;

  //// verificar si el heap coincide con el rojinegro
  if( listaHeap.size( ) != miArbolRN.size( ) )
  {
    std::cout << "Cantidad de elementos en el heap y el arbol  no coinciden." << std::endl;
    return( -1 );

  } // fi

  // Comparar los arboles
  rnIt = miArbolRN.begin( );
  TList::const_iterator heapIt = listaHeap.begin( );
  iguales = true;
  for( ; rnIt != miArbolRN.end( ); rnIt++, heapIt++ ){
    iguales &= ( *rnIt == *heapIt );
  }
  // Informar si los arboles coinciden o no
  std::cout << "El heap y el arbol ";
  if( !iguales )
    std::cout << "no ";
  std::cout << "coinciden." << std::endl;


  /// Punto 5 la funcion se llama buscar que retorna un bool si el dato esta
  //  la funcion es correcta si los datos estan almacenados de una manera correcta y el archivo no tiene caracteres especiales
  printf("Dijite la placa\n" );
  std::string placa;
  std::cin>>placa;
  if(miArbolORD.buscar(placa))
    printf("La placa existe\n" );
  else
    printf("La placa no existe\n");

    return 0;
}

// -------------------------------------------------------------------------
template< class TArbol >
bool LeerArbol( TArbol& arbol, const std::string& nomArch )
{
  std::ifstream entrada( nomArch.c_str( ) );
  if( !entrada )
    return( false );
  while( !entrada.eof( ) )
  {
    std::string codigo, valor;
    entrada >> codigo >> valor;
    if( codigo == "add" )
      arbol.insert( valor );  // El arbol debe proveer el metodo "insert"
    else if( codigo == "del" )
      arbol.erase( valor );   // El arbol debo proveer el metodo "erase"

  } // elihw
  entrada.close( );



  return( true );
}
void eraseHeap(Heap& heap,const std::string &valor)
{
  std::stack<std::string> ss;
  while(heap.top()!=valor && !heap.empty())
  {
    ss.push(heap.top());
    heap.pop();
  }
  if(!heap.empty())
    heap.pop();
  while(!ss.empty())
  {
      heap.push(ss.top());
      ss.pop();
  }
}

bool leerHeap ( Heap& heap, const std::string& nomArch )
{
  std::ifstream entrada( nomArch.c_str( ) );
  if( !entrada )
    return false ;
  while( !entrada.eof( ) )
  {
    std::string codigo, valor;
    entrada >> codigo >> valor;
    if( codigo == "add" )
      heap.push( valor );
    else if( codigo == "del" )
      eraseHeap( heap,valor );

  } // elihw
  entrada.close( );



  return  true ;
}

void recorridoHeap( TList& l ,Heap heap )
{
  while(!heap.empty())
  {
    l.push_back(heap.top());
    heap.pop();
  }
}
