//Sergio Fernández Fernández
//Bate Ye
//Grupo B2
//Estructura de Datos

#include "../include/quienesquien.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <set>
#include <string>
#include <algorithm>

QuienEsQuien::QuienEsQuien(){
	//TODO :)
}
QuienEsQuien::QuienEsQuien(const QuienEsQuien &quienEsQuien){
	*this = quienEsQuien;
}
QuienEsQuien& QuienEsQuien::operator= (const QuienEsQuien &quienEsQuien){
	if (this != &quienEsQuien) {
		this->limpiar();
		personajes = quienEsQuien.personajes;
		atributos = quienEsQuien.atributos;
		tablero = quienEsQuien.tablero;
		arbol = quienEsQuien.arbol;
		jugada_actual = quienEsQuien.jugada_actual;
  }

  return *this;
}
QuienEsQuien::~QuienEsQuien(){
	this->limpiar();
}

/**
	* @brief Devuelve si el nodo n es nodo hoja o no
**/

bool EsHoja(const bintree<Pregunta>::node &n){
	bool es = true;
	if(!n.left().null() || !n.right().null()){
		es = false;
	}
	return es;
}


void QuienEsQuien::limpiar(){
	personajes.clear();
  	atributos.clear();

  	for (auto iter = tablero.begin(); iter != tablero.end(); ++iter) {
    	iter->clear();
  	}

  	tablero.clear();

  	arbol.clear();
  	jugada_actual = arbol.root();
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

void QuienEsQuien::mostrar_estructuras_leidas(){
	cout << "personajes: "<< (this->personajes) << endl;
	cout << "atributos:  "<< (this->atributos)  << endl;
	cout << "tablero:    "<< endl;


	// Escribe la cabecera del tablero
	for(vector<string>::iterator it_atributos = this->atributos.begin();
		it_atributos != this->atributos.end();
		it_atributos++){
		cout << *it_atributos << "\t";
	}
	cout <<endl;

	int indice_personaje = 0;
	for(vector<vector<bool> >::iterator it_tablero_atributos = tablero.begin();
		it_tablero_atributos!= tablero.end();
		it_tablero_atributos++){

		string personaje = this->personajes[indice_personaje];
		int indice_atributo = 0;
		for(vector<bool>::iterator it_atributos_personaje = (*it_tablero_atributos).begin();
			it_atributos_personaje != (*it_tablero_atributos).end();
			it_atributos_personaje++){

			cout << *it_atributos_personaje<<"\t";

			indice_atributo++;
		}

		cout << personaje << endl;

		indice_personaje++;
	}

}

/**
  * @brief Devuelve una copia de la cadena original sin las subcadenas no deseadas.
  * 
  * @param cadena_original Cadena de la que se eliminan las subcadenas no deseadas.
  * @param cadena_a_eliminar Subcadena que se busca y se elimina.
  *
  * @return Copia de la cadena original sin las subcadenas no deseadas.
  */
string limpiar_string(string cadena_original,string cadena_a_eliminar){
	string linea(cadena_original);

	while(linea.find_first_of(cadena_a_eliminar) != std::string::npos){
		linea.erase(linea.find_first_of(cadena_a_eliminar),cadena_a_eliminar.length());
	}

	return linea;
}

istream& operator >> (istream& is, QuienEsQuien &quienEsQuien) {
	quienEsQuien.limpiar();
	
  	if(is.good()){
  		string linea;
    	getline(is, linea, '\n');

    	linea = limpiar_string(linea,"\r");
    	
    	while(linea.find('\t') != string::npos ){
    		string atributo = linea.substr(0,linea.find('\t'));
			quienEsQuien.atributos.push_back(atributo);
    		linea = linea.erase(0,linea.find('\t')+1);
    	}

		assert(linea ==  "Nombre personaje");
	}
	
    while( is.good() ) {
    	string linea;
    	getline(is, linea, '\n');
    	linea = limpiar_string(linea,"\r");

    	//Si la linea contiene algo extrae el personaje. Si no lo es, la ignora.
    	if(linea != ""){;
	    	vector<bool> atributos_personaje;
	    	
	    	int indice_atributo=0;
	    	while(linea.find('\t') != string::npos){
	    		string valor = linea.substr(0,linea.find('\t'));
	    		
	    		assert(valor == "0" || valor == "1");
	    		
	    		bool valor_atributo = valor == "1";
	    		
	    		atributos_personaje.push_back(valor_atributo);
				
	    		linea = linea.erase(0,linea.find('\t')+1);
	    		indice_atributo++;
			}
			
			string nombre_personaje = linea;
	    	
	    	quienEsQuien.personajes.push_back(nombre_personaje);
	    	quienEsQuien.tablero.push_back(atributos_personaje);
	    }
  	}
  	
	return is;
}

ostream& operator << (ostream& os, const QuienEsQuien &quienEsQuien){

	//Escribimos la cabecera, que contiene los atributos y al final una columna para el nombre
	for(vector<string>::const_iterator it_atributos = quienEsQuien.atributos.begin();
		it_atributos != quienEsQuien.atributos.end();
		it_atributos++){

		os  << *it_atributos << "\t";
	}
	os << "Nombre personaje" << endl;

	//Rellenamos con ceros y unos cada l�nea y al final ponemos el nombre del personaje.
	for(int indice_personaje=0;indice_personaje<quienEsQuien.personajes.size();indice_personaje++){
		for(int indice_atributo=0;indice_atributo<quienEsQuien.personajes.size();indice_atributo++){

			os  << quienEsQuien.tablero[indice_personaje][indice_atributo] << "\t";
		}
		os  << quienEsQuien.personajes[indice_personaje] << endl;
	}

	return os;
}

/**
  * @brief Convierte un n�mero a un vector de bool que corresponde 
  *        con su representaci�n en binario con un numero de digitos
  *        fijo.
  *
  * @param n N�mero a convertir en binario.
  * @param digitos N�mero de d�gitos de la representaci�n binaria.
  *
  * @return Vector de booleanos con la representaci�n en binario de @e n 
  *      con el n�mero de elementos especificado por @e digitos. 

  */
vector<bool> convertir_a_vector_bool(int n, int digitos) {
  vector<bool> ret;
  while(n) {
    if (n&1){
      ret.push_back(true);
    } else{
      ret.push_back(false);
    }
    n>>=1;  
  }

  while(ret.size()<digitos){
  	ret.push_back(false);
  }

  reverse(ret.begin(),ret.end());
  return ret;
}

void QuienEsQuien::personajes_verdaderos_falsos(vector<int> &personajes_true,vector<int> &personajes_false, int indice){
	if(indice == 0){
		for(int i = 0; i < personajes.size(); i++){
			if(tablero[i][0] == true){
				personajes_true.push_back(i);
			}
			else{
				personajes_false.push_back(i);
			}
		}
	}
	else{
		vector<int> aux1, aux2;
		for(int i = 0; i < personajes_true.size(); i++){
			if(tablero[personajes_true[i]][indice] == true){
				aux1.push_back(personajes_true[i]);
			}
		}
		for(int j = 0; j < personajes_false.size(); j++){
			if(tablero[personajes_false[j]][indice] == false){
				aux2.push_back(personajes_false[j]);
			}
		}
		personajes_true.clear();
		personajes_false.clear();
		personajes_true = aux1;
		personajes_false = aux2;
	}
}
void QuienEsQuien::crear_arb_aux(bintree<Pregunta> &arb,bintree<Pregunta>::node n, vector<int> p1,vector<int> p2,int indice){
	//para cada llamada recursiva, esta funcion crea otros dos vectores de true y false.
	if(n == arb.root()){
		if(p1.size() > 1){
			Pregunta aux(atributos[indice+1],p1.size());
			arb.insert_left(n,aux);
		}
		if(p2.size() > 1){
			Pregunta aux2(atributos[indice+1],p2.size());
			arb.insert_right(n,aux2);
		}
		crear_arb_aux(arb,n.left(),p1,p1,indice+1);
		crear_arb_aux(arb,n.right(),p2,p2,indice+1);
	}
	else{
		vector<int> verd;
		vector<int> fals;
		if(n == n.parent().left()){
			verd = p1;
			fals = p1;
		}
		else{
			verd = p2;
			fals = p2;
		}
		personajes_verdaderos_falsos(verd,fals,indice);
		if(verd.size() > 1){
			Pregunta n1(atributos[indice+1],verd.size());
			bintree<Pregunta> nueva1(n1);
			arb.insert_left(n,nueva1);
			crear_arb_aux(arb,n.left(),verd,verd,indice+1);
		}
		if(fals.size() > 1){
		 	Pregunta n2(atributos[indice+1],fals.size());
			bintree<Pregunta> nueva2(n2);
			arb.insert_right(n,nueva2);	
			crear_arb_aux(arb,n.right(),fals,fals,indice+1);
		}
	}
}
void QuienEsQuien::insertar_personajes(const Pregunta &personaje,bintree<Pregunta>::node n,bintree<Pregunta> &arbol,
	const map<string,int> &mapa, int indice_personaje){
	if(!n.null()){
		Pregunta pre = *(n);
		auto it = mapa.find(pre.obtener_pregunta());
		if(it != mapa.end()){
			if(tablero[indice_personaje][it->second] == true){
				if(n.left().null()){
					arbol.insert_left(n,personaje);
				}
				else{
					insertar_personajes(personaje,n.left(),arbol,mapa,indice_personaje);
				}
			}
			else{
				if(!n.right().null()){
					insertar_personajes(personaje,n.right(),arbol,mapa,indice_personaje);
				}
				else{
					arbol.insert_right(n,personaje);
				}
			}
		}
	}
}
bintree<Pregunta> QuienEsQuien::crear_arbol()
{
	vector<int> p1,p2;
	Pregunta root(atributos[0],personajes.size());
	personajes_verdaderos_falsos(p1,p2,0);
	bintree<Pregunta> arbol(root);
	crear_arb_aux(arbol,arbol.root(), p1,p2,0);
	map<string,int> mapa;
	int i = 0;
	for(auto it = atributos.begin(); it != atributos.end(); ++it){
		mapa[atributos[i]] = i;
		i++;
	}
	for(int i = 0; i < personajes.size(); i++){
		Pregunta persona(personajes[i],1);
		bintree<Pregunta>::node n = arbol.root();
		insertar_personajes(persona,n,arbol,mapa,i);
	}
	return arbol;
}

void QuienEsQuien::usar_arbol(bintree<Pregunta> arbol_nuevo){
	arbol = arbol_nuevo;
}

void QuienEsQuien::iniciar_juego(){
	bintree<Pregunta> arb = this->crear_arbol();
	this->usar_arbol(arb);
	this->eliminar_nodos_redundantes();
}

void QuienEsQuien::obtener_personajes_levantados(set<string> & personajes_levantados, const bintree<Pregunta>::node &j){
	if(!j.null()){
		Pregunta p = *(j);
		if(EsHoja(j)){
			personajes_levantados.insert(p.obtener_personaje());
		}
		else{
			obtener_personajes_levantados(personajes_levantados, j.left());
			obtener_personajes_levantados(personajes_levantados, j.right());
		}
	}
}

set<string> QuienEsQuien::informacion_jugada(bintree<Pregunta>::node jugada_actual){
	
	set<string> personajes_levantados;
	obtener_personajes_levantados(personajes_levantados,jugada_actual);
	return personajes_levantados;
}


void escribir_esquema_arbol(ostream& ss,
					  const bintree<Pregunta>& a, 
		    		  bintree<Pregunta>::node n,
					  string& pre){
	if (n.null()){
	    ss << pre << "-- x" << endl;
	} else {
	    ss << pre << "-- " << (*n) << endl;
	    if ( !n.right().null() || !n.left().null()) {// Si no es una hoja
			pre += "   |";
	    	escribir_esquema_arbol(ss,a, n.right(), pre);
	     	pre.replace(pre.size()-4, 4, "    ");
	      	escribir_esquema_arbol (ss,a, n.left(), pre);
	      	pre.erase(pre.size()-4, 4);    
	    }
  	}
}

void QuienEsQuien::escribir_arbol_completo() const{
	string pre = "";
	escribir_esquema_arbol(cout,this->arbol,this->arbol.root(),pre);
}

void QuienEsQuien::eliminar_nodos_redundantes_aux(const bintree<Pregunta>::node &n){
		bintree<Pregunta>::node padre = n.parent();
	if(!padre.null()){
		bintree<Pregunta> subarbol;
		
		if(!EsHoja(n)){
			if(!n.left().null() && !n.right().null()){
				eliminar_nodos_redundantes_aux(n.left());
		        eliminar_nodos_redundantes_aux(n.right());
			}
			else if(!n.left().null() && n.right().null()){
				arbol.prune_left(n,subarbol);
				arbol.insert_left(padre,subarbol);
		        eliminar_nodos_redundantes_aux(n.left());
			}
			else if(n.left().null() && !n.right().null()){
			    arbol.prune_right(n,subarbol);
				arbol.insert_right(padre,subarbol);
		        eliminar_nodos_redundantes_aux(n.right());
		    }
		
	    }
    }
}


void QuienEsQuien::eliminar_nodos_redundantes(){
	eliminar_nodos_redundantes_aux(arbol.root());
}


/**
	* @brief Devuelve la profundidad donde se encuentra el nodo n
**/

int profundidad(bintree<Pregunta>::node n){
	if(!n.parent().null()){
		return profundidad(n.parent()) +1;
	}
	return 0;
}

int QuienEsQuien::profundidad_promedio_hojas_aux(const bintree<Pregunta>::node &n, int &canti){
	int pro = 0;
	if(!n.null()){
		if(EsHoja(n)){
			int pn = profundidad(n);
			canti++;
			pro = pro + pn;
		}
		else{
			pro += profundidad_promedio_hojas_aux(n.left(),canti) + profundidad_promedio_hojas_aux(n.right(),canti);
		}
	}
	return pro;
}
float QuienEsQuien::profundidad_promedio_hojas(){
	int pro;
	float media;
	int cantidad = 0;

	pro = profundidad_promedio_hojas_aux(arbol.root(),cantidad);
	media = (float)(pro/cantidad);
	if(media > 0){
		return media;
	}
	return -1;
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max).
**/

int generaEntero(int min, int max){
    int tam= max -min;
    return ((rand()%tam)+min);
}

void QuienEsQuien::tablero_aleatorio(int numero_de_personajes){
	srand(0);

	this->limpiar();

	float log_2_numero_de_personajes = log(numero_de_personajes)/log(2);

	int numero_de_atributos = ceil(log_2_numero_de_personajes);

	cout << "Petici�n para generar "<< numero_de_personajes<<" personajes ";
	cout << "con "<<numero_de_atributos<< " atributos"<<endl;
	cout << "Paso 1: generar "<< pow(2,numero_de_atributos) << " personajes"<<endl;

	//Fase 1: completar el tablero con todos los personajes posibles
	//Completo el tablero y los nombres de personajes a la vez
	for(int indice_personaje=0;indice_personaje< pow(2,numero_de_atributos);indice_personaje++){
		vector<bool> atributos_personaje = convertir_a_vector_bool(indice_personaje,numero_de_atributos);
		string nombre_personaje = "Personaje_"+to_string(indice_personaje);

		this->personajes.push_back(nombre_personaje);
		this->tablero.push_back(atributos_personaje);
	}

	// Completo los nombres de los atributos.
	for(int indice_atributo=0;indice_atributo<numero_de_atributos;indice_atributo++){
		string nombre_atributo = "Atributo_"+to_string(indice_atributo);
		this->atributos.push_back(nombre_atributo);
	}

	cout << "Paso 2: eliminar "<< (pow(2,numero_de_atributos)-numero_de_personajes) << " personajes"<<endl;
	//Fase 2. Borrar personajes aleatoriamente hasta que quedan solo los que hemos pedido.
	while(personajes.size()>numero_de_personajes){
		int personaje_a_eliminar = generaEntero(0,personajes.size());

		personajes.erase(personajes.begin()+personaje_a_eliminar);
		tablero.erase(tablero.begin()+personaje_a_eliminar);
	}
}
