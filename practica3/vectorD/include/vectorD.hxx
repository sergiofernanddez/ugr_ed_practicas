/**
 * Práctica 3 vectorD
 * Grupo B2
 * Sergio Fernández Fernández
 * Bate Yee 
 **/

#include <cassert>
#include <algorithm>

//TO-DO: Completar la implementacion de los metodos de vectorD.h

template <class T>
vectorD<T>::vectorD(const  T  & t){
	n_ele = 0;                  
	v_nulo = t;
}

template <class T>
vectorD<T>::vectorD(const vectorD<T> & b){
	n_ele = b.n_ele;
	v_nulo = b.v_nulo;
	vd = b.vd;
}


template<class T>
vectorD<T>::vectorD(int numcomp, const T& nul){
	if(numcomp > 0){
		v_nulo = nul;
		n_ele = numcomp;
		for(int i = 0; i < numcomp; i++){
			vd.push_back(make_pair(i,v_nulo));
		}
	}
}

template<typename T>
vectorD<T>::~vectorD(){
	vd.clear();
	v_nulo = T();
	n_ele = 0;
}

template <typename T>
typename vectorD<T>::size_type vectorD<T>::size() const{
	return n_ele;
}

template<typename T>
T vectorD<T>::default_value()const{
	return v_nulo;
}

template<typename T>
bool vectorD<T>::empty(){
	return n_ele > 0 && !vd.empty();
}

template<typename T>
void vectorD<T>::set(int p, const T &val){
	if(!vd.empty()){
		typename list< pair<int, T> >::iterator it;
		for(it = vd.begin(); it != vd.end(); ++it){
			if(it->first == p){
				it->second = val;
			}
		}
	}
}

template<typename T>
void vectorD<T>::push_back(const T &t){
	if(t != v_nulo){
		pair<int,T> pareja;
		pareja.first = n_ele;
		pareja.second = t;
		n_ele++;
		vd.push_back(pareja);
	}
}

template<typename T>
void vectorD<T>::pop_back(){
	vd.pop_back();
	n_ele = n_ele-1;
}

template<typename T>
void vectorD<T>::clear(){
	vd.clear();
	n_ele = 0;
}

template<typename T>
void vectorD<T>::resize(int s){
	if(s > n_ele){
		for(int i = n_ele; i < s;i++){
			vd.push_back(make_pair(i,v_nulo));
		}
	}
	else if(s < n_ele){
		for(int j = s; j < n_ele; j++){
			vd.pop_back();
		}
	}
	n_ele = s;
}

template<typename T>
vectorD<T> &vectorD<T>::operator=(const vectorD<T> &otro){
	if(this != &otro){
		typename list<pair<int,T> >::iterator it;
		vd.clear();
		n_ele = otro.n_ele;

		for(it = otro.vd.begin(); it != otro.vd.end();++it){
			vd.push_back(make_pair(it->first,it->second));
		}
	}
	return *this;
}

template<class T>
const T& vectorD<T>::operator[](int c) const{
	typename list<pair<int,T> >::const_iterator it;
	if(c >= 0 && c < n_ele){
		bool paro = false;
		for(it = vd.begin(); it != vd.end() && !paro; ++it){
			if(it->first == c){
				paro = true;
			}
		}
	}
	return it->second;
}

template<typename T>
bool vectorD<T>::operator==(const vectorD<T> &otro){
	bool iguales = true;
	if(n_ele == otro.n_ele){
		typename list<pair<int, T> >::iterator it,itdos;

		for(it = vd.begin(), itdos = otro.vd.begin();it != vd.end() && itdos != otro.vd.end() && iguales; ++it, ++itdos){
			if (it->first != itdos->first || it->second != itdos->second){
				iguales = false;
			}
		}
	}
	else{
		iguales = false;
	}
	return iguales;
}

template<typename T>
bool vectorD<T>::operator!=(const vectorD<T> &otro){
	bool distintos = false;
	if(n_ele == otro.n_ele){
		typename list<pair<int, T> >::iterator it,itdos;
		for(it = vd.begin(), itdos = otro.vd.begin(); it != vd.end() && itdos != otro.vd.end() && !distintos; ++it,++itdos){
			if(it->first != itdos->first){
				distintos = true;
			}
			else if(it->second != itdos->second){
				distintos = true;
			}
		}
	}
	else{
		distintos = true;
	}
	return distintos;
}

template<typename T>
typename vectorD<T>::iterator vectorD<T>::begin(){
	iterator ite;

	ite.ite_rep = vd.begin();
	ite.i_vect = 0;
	ite.el_vect = this;

	return ite;
}
template <typename T>
typename vectorD<T>::iterator vectorD<T>::end(){
	iterator ite;

	ite.ite_rep = vd.end();
	ite.i_vect = n_ele;
	ite.el_vect = this;

	return ite;
}

template<class T>
typename vectorD<T>::stored_iterator vectorD<T>::sbegin(){
	stored_iterator iter;
	iter.ite = vd.begin();
	return iter;
}


template <typename T>
typename vectorD<T>::stored_iterator vectorD<T>::send(){
	stored_iterator s_ite;
	s_ite.ite = vd.end();

	return s_ite;
}

template<class T>
int vectorD<T>::checkRepFails(){

	typename list<pair<int,T> >::iterator it, it2;

	if(vd.size() > n_ele)
		throw "Fallo tipo1";

	for(it = vd.begin(); it != vd.end(); ++it){

		if(it->second == v_nulo)
			throw "Fallo tipo 2";
		if(it->first < 0)
			throw "Fallo tipo 3";

		it2 = ++it;
		if(it->first > it2->first)
			throw "Fallo tipo 4";
	}	

	return 0;
}

template<class T>
vectorD<T>::iterator::iterator(){
	el_vect =0;
	i_vect = 0;
};

template<class T>
vectorD<T>::iterator::iterator(const iterator & d){
	i_vect = d.i_vect;
	ite_rep = d.ite_rep;
	el_vect = d.el_vect;
}

template<class T>
const T &vectorD<T>::iterator::operator*(){
	if(i_vect != ite_rep->first)
		return el_vect->v_nulo;
	else
		return ite_rep->second;
}

template<class T>
typename vectorD<T>::iterator& vectorD<T>::iterator::operator++( ){

	if(i_vect <= el_vect->n_ele){
		++i_vect;
		if(i_vect == ite_rep->first)
			++ite_rep;

	}else
		throw "Ha superado el limite del vector disperso";

	return *this;
}

template<class T>
typename vectorD<T>::iterator vectorD<T>::iterator::operator++(int){
	iterator nuevo(*this);
	this->operator++();
	return nuevo;
}

template<class T>
bool vectorD<T>::iterator::operator==(const iterator &d){
	if((i_vect == d.i_vect) && (ite_rep == d.ite_rep) && (el_vect == d.el_vect))
		return true;
	else
		return false;
}

template<class T>
bool vectorD<T>::iterator::operator!=(const iterator &d){
	if((i_vect != d.i_vect) || (ite_rep != d.ite_rep) || (el_vect != d.el_vect))
		return true;
	else
		return false;
}

template<class T>
typename vectorD<T>::iterator& vectorD<T>::iterator::operator=(const iterator &d){
	//if(d.i_vect>=0 && d.i_vect<=this->el_vect->n_ele)
		i_vect = d.i_vect;
	
	delete [] el_vect;
		
	ite_rep = d.ite_rep;
	el_vect = d.el_vect;

	return *this;
}
