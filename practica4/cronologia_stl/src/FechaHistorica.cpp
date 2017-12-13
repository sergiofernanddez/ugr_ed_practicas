/*
*		Trabajo realizado por:
*		Sergio Fernández Fernández
*		Bate Ye
*		Grupo B2
*		Prácticas Estructura de Datos
*/

#include"FechaHistorica.h"

FechaHistorica::FechaHistorica(){
	acontecimientos.first = 0;

}

FechaHistorica::FechaHistorica(istringstream &datos)
{
  datos >> *this;
}

FechaHistorica::FechaHistorica(int anio){
	acontecimientos.first = anio;
}

FechaHistorica::FechaHistorica(const FechaHistorica &fecha){
	if(fecha.acontecimientos.first > 0){
		acontecimientos.first = fecha.acontecimientos.first;
		acontecimientos.second.insert(fecha.acontecimientos.second.begin(), fecha.acontecimientos.second.end());
	}
}

int FechaHistorica::getAnio() const{
	return acontecimientos.first;
}

void FechaHistorica::setAnio(int anio){
	acontecimientos.first = anio;
}

int FechaHistorica::numAcont() 
{
	return acontecimientos.second.size();
}

void FechaHistorica::aniadeAcontecimiento(const string &acon)
{
  acontecimientos.second.insert(acon);
}

void FechaHistorica::push_back(const string &acon){
	acontecimientos.second.insert(acon);
}

void FechaHistorica::pop_back(){
	set<string>::iterator it = --(acontecimientos.second.end());
	acontecimientos.second.erase(it);
}

FechaHistorica FechaHistorica::buscarPalabra(string palabra) {
	set<string>::iterator it = acontecimientos.second.begin();
	string auxiliar;
	FechaHistorica nueva;
	for(; it != acontecimientos.second.end(); ++it){
		auxiliar = *(it);
		if(auxiliar.find(palabra) != string::npos){
			nueva.acontecimientos.first = acontecimientos.first;
			nueva.acontecimientos.second.insert(auxiliar);
		}
	}
	return nueva;
}
FechaHistorica& FechaHistorica::operator=(const FechaHistorica &fecha){
	if(this != &fecha){
		acontecimientos.first = fecha.acontecimientos.first;
		acontecimientos.second.clear();
		acontecimientos.second.insert(fecha.acontecimientos.second.begin(), fecha.acontecimientos.second.end());
	}
	return *this;
}
FechaHistorica FechaHistorica::operator+(const FechaHistorica &fecha) {
	FechaHistorica nueva;
	if(acontecimientos.first == fecha.acontecimientos.first){
		nueva.acontecimientos.first = acontecimientos.first;
		nueva.acontecimientos.second.insert(acontecimientos.second.begin(), acontecimientos.second.end());
		nueva.acontecimientos.second.insert(fecha.acontecimientos.second.begin(), fecha.acontecimientos.second.end());
	}
	else{
		nueva.acontecimientos.first = 0;
	}
	return nueva;
}

ostream &operator<<(ostream &os, const FechaHistorica &f)
{
  os << f.getAnio();

  for (auto it = f.cbegin(); it != f.cend(); it++)
  {
    os << '#' << *it;
  }

  return os;
}

istream &operator>>(istream &is, FechaHistorica &f)
{
  string aux;
  bool esAnio = true;

  while (getline(is, aux, '#'))
  {
    if (esAnio)
    {
      istringstream anioInput(aux);
      anioInput >> f.acontecimientos.first;
      esAnio = false;
    }
    else
      f.aniadeAcontecimiento(aux);
  }

  return is;
}

FechaHistorica::iter FechaHistorica::begin() {
	return acontecimientos.second.begin();
}
FechaHistorica::iter FechaHistorica::end() {
	return acontecimientos.second.end();
}
FechaHistorica::const_iter FechaHistorica::cbegin() const{
	return acontecimientos.second.cbegin();
}
FechaHistorica::const_iter FechaHistorica::cend() const{
	return acontecimientos.second.cend();
}
