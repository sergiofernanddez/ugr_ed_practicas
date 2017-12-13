/**
*   @file FechaHistorica.h
*   @brief Fichero de cabezera del TDA FechaHistorica
*   
*   Se crea una FechaHistorica con un pair de conjunto de acontecimientos y el año al que pertenecen
**/

#ifndef FECHAHISTORICA_H
#define FECHAHISTORICA_H

/**
*   @brief TDA FechaHistorica
*   
*   Una instancia del tipo de dato abstracto
*   FechaHistorica sobre el contenedor de la STL pair<int, set<string>>, 
*   es un TDA mediante el cual podemos representar una serie de acontecimientos
*   ordenados por año mediante el campo first del pair
*   
*   
*   La eficiencia en espacio es O(n).
*
**/

#include<iostream>
#include<string>
#include<set>
#include <sstream>

using namespace std;

class FechaHistorica{

    //Ámbito privado
    private:
     /**
        *   
        *   @page repFechaHistorica Rep del TDA FechaHistorica
        *   @section invFechaHistorica Invariante de Representacion
        *
        *   Un objeto @e f del TDA FechaHistorica debe cumplir:
        *   
        *   -@c f.first>=0 (La fecha comienza a partir del año 0 inclusive)
        * 
        *   -@c f.second es un conjunto de acontecimientos que alberga 
        *   valores de tipo @c string
        *
        *
        *   @section faFechaHistorica Función de Abstracción
        *   
        *   Un objeto válido @e rep del TDA FechaHistorica
        *   representa una pareja de enteros y un conjunto de string, 
        *   el campo first representa el año de los acontecimientos y el
        *   campo second representa los acontecimientos en si.
        *
        *   f.first para acceder al campo fecha
        *
        *   f.second es el conjunto donde se almacenan los acontecimientos de tipo string.
        *   
        **/

        pair<int, set<string> > acontecimientos;

    public: 
        
        /*
        *   @brief Constructor por defecto
        *   @return crea una instancia de FechaHistorica vacia
        */
        FechaHistorica();

        /*
        *   @brief Constructor con parámetros
        *   @param anio es el año con el que se crea la instancia de FechaHistorica
        *   @return crea una instancia de FechaHistorica con un año 
        */
        FechaHistorica(int anio);

        /*
        *   @brief Constructor mediente istringstream
        *   @param datos es el istringstream que crea la instancia
        *   @return crea una instancia de FechaHistorica con un istringstream
        */
        FechaHistorica(istringstream &datos);

        /*
        *   @brief Constructor de copia
        *   @param fecha es la FechaHistorica que se va a copiar
        *   @return crea una instancia de FechaHistorica a partir de otra
        */
        FechaHistorica(const FechaHistorica &fecha);

        /*
        *   @brief Consultor del año
        *   @return Devuelve el año de la FechaHistorica
        */
        int getAnio() const;

        /*
        *   @brief Modificador del año
        *   @param anio es el año que se modifica
        */
        void setAnio(int anio);

        /*
        *   @brief Añade un acontecimiento
        *   @param acon es el acontecimiento a añadir
        */
        void aniadeAcontecimiento(const string &acon);

        /*
        *   @brief numero acontecimientos
        *   @return devuelve el numero de acontecimientos
        */
        int numAcont() ;

        /*
        *   @brief Método push_back
        *   @param acon es el acontecimiento que se inserta al final del conjunto de string
        */
        void push_back(const string &acon);

        /*
        *   @brief Método pop_back
        *   Borra el ultimo acontecimiento del conjunto de string
        */
        void pop_back();

        /*
        *   @brief Método buscarPalabra
        *   @param palabra es la palabra a buscar 
        *   @return devuelve los acontecimientos en los que aparece dicha palabra 
        */
        FechaHistorica buscarPalabra(string palabra);

        /*
         *  @brief Sobrecarga operador = 
         *  @param fecha es la FechaHistorica que se va a copiar
         *  @return devuelve una referencia al objeto 
         */
        FechaHistorica& operator=(const FechaHistorica& fecha);

        /*
         *  @brief Sobrecarca operador +
         *  @pre El campo fecha.first debe ser el mismo
         *  @param fecha es la FechaHistorica que se va a sumar 
         *  @return devuelve una FechaHistorica resultado de la suma
         */
        FechaHistorica operator+(const FechaHistorica &fecha);

        /*
        *   @brief Sobrecarga operador >>
        *   @param entrada es el flujo de entrada
        *   @param fecha es la FechaHistorica en la que se introducen los datos
        */
        friend ostream &operator<<(ostream &os, const FechaHistorica &f);

        /*
        *   @brief Sobrecarga operador <<
        *   @param salida es el flujo de salida
        *   @param fecha es la FechaHistorica que se imprime 
        */
        friend istream &operator>>(istream &is, FechaHistorica &f);

        //////////////////////////////////////////////////////////////////////////////////////////////////

        /*
        *   @brief iterador sobre el conjunto 
        */
        typedef set<string>::iterator iter;

        /*
        *   @brief iterador constante sobre el conjunto 
        */
        typedef set<string>::const_iterator const_iter;

        /*
        *   @brief begin
        *   @return Iterador al primer acontecimiento
        */
        iter begin(); 

        /*
        *   @brief end
        *   @return Iterador al último acontecimiento
        */
        iter end();

        /*
        *   @brief cbegin
        *   @return Iterador constante al primer acontecimieto
        */
        const_iter cbegin() const;

        /*
        *   @brief cend
        *   @return Iterador constante al último acontecimiento
        */
        const_iter cend() const ;
};

#endif



