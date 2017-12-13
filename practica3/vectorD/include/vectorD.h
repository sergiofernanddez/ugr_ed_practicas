/**
*   @file vectorD.h
*   @brief Fichero de cabezera del TDA vectorD
*   
*   Se crea un vector disperso con una lista de parjea de int y template, su tamaño y el valor nulo del array.
**/

#ifndef __VECTORDISPERSO_H
#define __VECTORDISPERSO_H

/**
*   @brief TDA vectorD
*   
*   Una instancia del tipo de dato abstracto
*   vectorD sobre el contenedor de la stl list, 
*   es una lista de parejas donde el primer elemento 
*   es un int con la posicion y el segundo elemento un dato de tipo T con el contenido.
*   El TDA tiene sus respectivos iteradores, un iterator que itera por todos los
*   elementos del vector y un stored_iterator que itera por los elementos 
*   que son distintos del valor nulo.
*   
*   La eficiencia en espacio es O(n).
*
**/

#include <list>     // tipo list STL
#include <utility>  // clase pair
using namespace std;

template <typename  T >
class vectorD
{
public:

  // declaración de las clases de iterador sobre vectorD
  class stored_iterator;        // iterador sobre elementos no nulos
  class iterator;               // iterador sobre todos los elementos del vector

  typedef unsigned int size_type;
  
  //////////// constructores //////////////
    		
  vectorD<T>( const  T  & t=  T () );
  // constructor por defecto. t hace referencia al valor por defecto del vector
        	
  vectorD<T>(  const vectorD< T > & b);    	
  /** constructor primitivo que hace una copia del vector disperso b. */

  vectorD<T>( int numcomp, const  T  & t =  T () );
  /** constructor primitivo que crea un vectorD con numcomp componentes, todas ellas iguales a t. numcomp deve ser mayor que cero.
  t hace referencia al valor por defecto
   */


  ////////////// destructor ////////////  	
  ~vectorD<T>();


  /////////// Consultores ////////////
  size_type size() const;
  // Devuelve el tamaño del vectorD

  T  default_value( ) const;
  // Devuelve el valor por defecto de vectorD

  bool empty();
  // el vectorD esta vacio?

  ////////  MODIFICADORES //////////////////////

  void set(int p, const  T  & t);
  // Asigna el valor t a la posicion p-esima del vector. No modifica el size del vector

  void push_back( const  T  & t);
  // Inserta un elemento al final del vectorD. Aumenta en 1 el tamanio

  void pop_back(  );
  // elimina un elemento del vectorD. Disminuye en 1 el tamanio

  void clear(); 
  // elimina todos los elementos del vectorD. Tamanio es 0

  void resize(int s);
  // cambia el tama~no del vector a "s" elementos. Si s es menor que el tama~no actual, elimina los restantes. Si es mayor,
  // aumenta la capacidad del vector asignando a todos los nuevos elementos el valor nulo. 


  /////////////// operadores ///////////////////

  vectorD<T> & operator= (const vectorD<T> & x);
  // operador de asignacion

  const  T  & operator[](int c) const  ;
  /** devuelve una referencia constante a la componente c-esima del vectorD. Siendo c mayor o igual que 0 y menor que NumComponentes*/

  bool operator==( const vectorD<T> & x);
  /** devuelve verdadero si tienen los mismos elementos y false en caso contrario */

  bool operator!=( const vectorD<T> & x);
  /** devuelve verdadero si no tienen los mismos elementos y false en caso contrario */


  /////////////////iteradores///////////////////////


  iterator begin();
  /** iterador al inicio sobre todos los elementos del vector */

  iterator end();
  /** iterador final (siguiente al ultimo)  sobre todos los elementos del vector */

  stored_iterator sbegin(); 
  /** iterador inicio sobre elementos no nulos */

  stored_iterator send();
  /** iterador final (siguiente al ultimo) sobre elementos no nulos */


private: // parte  privada

  /**
        *   
        *   @page repvectorD Rep del TDA vectorD
        *   @section favectorD Funcion de Abstraccion
        *
        *   Un objeto @e f del TDA vectorD debe cumplir:
        *   
        *   -@c f.n_ele es el número de elementos del vectorD
        * 
        *   -@c f.vd es una lista de pair<int, T>, 
        *   donde int es la posicion del vector y T es el contenido de dicha posición.
        *
        *   -@c f.v_nulo es el valor del vectorD que es nulo
        *
        *   @section irvectorD Invariante de Representación
        *   
        *   Un objeto válido @e rep del TDA vectorD
        *   representa una lista solo con valores distintos de v_nulo y n_ele>=0
        *
        *   f.n_ele debe ser mayor o igual a 0.
        *
        *   f.vd no puede tener elementos que sean distintos de valor nulo.
        *   vd->second != v_nulo
        *   Se accede mediante:
        *       {f.vd->first, f.vd->second}
        *   
        **/

  list< pair<int, T > > vd;     // lista que aloja el vector disperso (solo los != valor nulo)
  size_type n_ele;              // numero de elementos totals
  T   v_nulo;                   // valor nulo del vector

  /* FA e IR*/
  /* FA(rep): rep -- > vector
    (vd,n_ele,v_nulo):
       vd=[ (a,v1), (b,v2), ..., (n,vn) ]
       n_ele = M
       v_nulo = t
    --------->
    pos: 0 1 2 ... a-1 a ... x .... b....  ... n-1 n  n+1 ..... M-1
    val: t t t ....t  v1 ... t .... v2 ..  ... t   vn  t  ...... t
    */
   
  int checkRepFails();
  /* Comprueba el IR y devuelve el tipo de fallo segun indica el IR. En caso de cumplir el IR se devuelve 0 */

  /* IR :
    IR(rep): rep ---> bool
   (vd,n_ele,v_nulo) :
    0 <= vd.size() < n_ele;  //Fallo tipo 1 
    vd[i].second != v_nulo, para todo i = 0, ..., vd.size()-1; // Fallo tipo 2 
    vd[i].first >=0, para todo i = 0, ..., vd.size()-1; // Fallo tipo 3
    vd[i].first < vd[j].first si i<j // Fallo tipo 4
   */
  
/* ITERADORES SOBRE VECTOR DISPERSO */
    
public:
  class stored_iterator{      //stored_iterator está implementada
    public:
      friend class vectorD<T>;
      
      stored_iterator() {} 
      stored_iterator(const stored_iterator & d) : ite(d.ite) {}
      const pair<int, T > & operator *(  ) { return (*ite);}  
      stored_iterator & operator++( ) {++ite; return *this;}    // operador ++ prefijo (invocado con ++it)
      stored_iterator operator++(int ) {stored_iterator tmp(*this); ++ite; return tmp;}  // operador ++ posfijo (invocado con it++)
      bool operator == (const stored_iterator & d) {return ite == d.ite;}
      bool operator != (const stored_iterator & d) {return ite != d.ite; }
      
    private:
      typename list<pair<int, T > >::iterator ite;
  };

  class iterator{             //iterator no está implementada 
    public:
      friend class vectorD<T>;
      iterator();
      iterator(const iterator & d);
      int getIvec();
      iterator getIteRep();
      vectorD<T> &getVector();
      const  T  & operator *(  );
      iterator & operator++( );     // operador ++ prefijo (invocado con ++it)
      iterator operator++(int );    // operador ++ posfijo (invocado con it++)
      bool operator == (const iterator & d);
      bool operator != (const iterator & d);
      iterator & operator=(const iterator & d);

    private:
      int i_vect; // indice sobre el vector abstracto
      typename list<pair<int, T > >::iterator ite_rep; //iterador a la representacion
      vectorD<T> *el_vect; // ptro al vector para obtener el valor nulo del vector
      /* FA e IR*/
      /* FA(rep): rep -- > iterador sobre vector abstracto
        (i_vect, ite_rep, el_vec):
        i_vect = k
        ite_rep = p 
        el_vect = v
         --------->
        iterador a la posicion k-esima del vector abstracto con valor nulo (*v).v_nulo
         */
     
        /* IR :
         IR(rep): rep ---> bool
        (i_vect, ite_rep): 
         --------->
         0 <= i_vect <=n_ele
         i_vect <= (*ite_rep).first
         */   
       
  };


};

#include "vectorD.hxx"

#endif
 
 
