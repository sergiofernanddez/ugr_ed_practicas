/**
*   @file Cronologia.h
*   @brief Fichero de cabezera del TDA Cronologia
*   
*   Se crea una cronologia ordenada según el año con sus respectivos acontecimientos históricos
**/

#ifndef CRONOLOGIA_H
#define CRONOLOGIA_H

/**
*   @brief TDA Cronologia
*   
*   Una instancia del tipo de dato abstracto
*   Cronologia sobre el tipo de dato abstracto FechaHistorica, 
*   es un map<int, FechaHistorica> donde el primer campo es el año de los acontecimientos
*   y el segundo es una FechaHistorica.
*   Podemos representarlo como:
*       cronologia->first para el año y cronologia->second para la FechaHistorica
*   
*   La eficiencia en espacio es O(n).
*   
*   Un ejemplo de uso puede verse en:
*   @include pruebacronologia.cpp
*
**/

//Bibliotecas 
#include<iostream>
#include<string>
#include<map>
#include"FechaHistorica.h"
#include<sstream>

using namespace std;

class Cronologia{
    //Ámbito privado 
    private:
        /**
        *   
        *   @page repCronologia Rep del TDA Cronologia
        *   @section invCronologia Invariante de Representacion
        *
        *   Un objeto @e c del TDA Cronología debe cumplir:
        *   
        *   -@c c->first>=0 
        * 
        *   -@c c->second.second != ""
        *
        *   @section faCronologia Función de Abstracción
        *   
        *   Un objeto válido @e rep del TDA Cronologia
        *   representa al contenedor de la STL map<int, FechaHistorica>
        *
        *   c->first representa el año de los acontecimientos
        *
        *   c->secondes representa los acontecimientos
        *   
        **/

        map<int, FechaHistorica> cronologia;

    public: 
        
        /*
        *   @brief Constructor por defecto
        *   @return crea una instancia de Cronologia vacia
        */
        Cronologia();

        /*
        *   @brief Constructor con parámetros
        *   @param anio es el año con el que se crea la instancia de Cronologia
        *   @return crea una instancia de Cronologia con un año 
        */
        Cronologia(int anio);

        /*
        *   @brief Constructor de copia
        *   @param crono es la Cronologia que se va a copiar
        *   @return crea una instancia de Cronologiaa partir de otra
        */
        Cronologia(const Cronologia &crono);

        /*
        *   @brief Consultor de los eventos
        *   @param anio es el año de los eventos
        *   @return Devuelve la FechaHistorica con los eventos
        */
        FechaHistorica getEventos(int anio);

        /*
        *   @brief Consultor del numero de años
        *   @return Devuelve el numero de años de la cronologia
        */
        int numAnios() ;

        /*
        *   @brief insertar fecha
        *   @param f es una FechaHistorica a insertar
        */
        void insertarFecha(const FechaHistorica &f);

        /*
        *   @brief Método insertar
        *   @param crono es la Cronologia que se inserta en su sitio correspondiente en el map
        */
        void insertar(const FechaHistorica &f);

        /*
        *   @brief Método eliminar
        *   @param anio es el anio que se quiere borrar 
        *   Borra la Cronologia de un año en concreto
        */
        void eliminar(int anio);

        /*
        *   @brief Método buscarPalabra
        *   @param palabra es la palabra a buscar 
        *   @return devuelve la Cronologia en la que aparece dicha palabra
        */
        Cronologia buscarPalabra(string palabra);

        /*
        *   @brief Cronologia en un intervalo
        *   @param anio_ini es el año desde el que empezar
        *   @param anio_fin es el año en el que terminar 
        *   @return Devuelve una cronología dentro del intervalo     
        */
        Cronologia intervalo(int anio_ini, int anio_fin);

        /*
         *  @brief Sobrecarga operador = 
         *  @param crono es la Cronologia que se va a copiar
         *  @return devuelve una referencia al objeto 
         */
        Cronologia& operator=(const Cronologia& crono);

        /*
         *  @brief Sobrecarca operador +
         *  @param crono es la Cronologia que se va a sumar 
         *  @return devuelve una Cronologia resultado de la suma
         */
        Cronologia operator+(const Cronologia &crono);

        /*
        *   @brief Sobrecarga operador >>
        *   @param entrada es el flujo de entrada
        *   @param crono es la Cronologia en la que se introducen los datos
        */
        //friend istream& operator>> (istream& entrada, Cronologia& crono);

        /*
        *   @brief Sobrecarga operador <<
        *   @param salida es el flujo de salida
        *   @param crono es la Cronologia que se imprime 
        */
        friend ostream& operator<< (ostream& salida, const Cronologia& crono);

        /*
        *   @brief Sobrecarga operador >>
        *   @param is es el flujo de entrada
        *   @param c es la Cronologia de entrada
        */
        friend istream &operator>>(istream& is, Cronologia& c);

        //////////////////////////////////////////////////////////////////////////////////////////////////

        /*
        *   @brief iterador sobre el conjunto 
        */
        typedef typename map<int, FechaHistorica>::iterator iterator;

        /*
        *   @brief iterador constante sobre el conjunto 
        */
        typedef typename map<int, FechaHistorica>::const_iterator const_iterator;

        typedef pair<int, FechaHistorica> fecha;

        /*
        *   @brief begin
        *   @return Iterador al primer año de la Cronologia
        */
        iterator begin() ; 

        /*
        *   @brief end
        *   @return Iterador al último año de la Cronologia
        */
        iterator end() ;

        /*
        *   @brief cbegin
        *   @return Iterador constante al primer año de la Cronologia
        */
        const_iterator cbegin() const;

        /*
        *   @brief cend
        *   @return Iterador constante al último año de la Cronologia
        */
         const_iterator cend() const ;

};

#endif
