/*
*		Trabajo realizado por:
*		Sergio Fernández Fernández
*		Bate Ye
*		Grupo B2
*		Prácticas Estructura de Datos
*/

#include"Cronologia.h"

Cronologia::Cronologia(){
	FechaHistorica aux(0);
	cronologia.insert(make_pair(0, FechaHistorica()));
}
Cronologia::Cronologia(int anio){
	FechaHistorica aux(anio);
	cronologia.insert(make_pair(anio, aux));
}
Cronologia::Cronologia(const Cronologia &crono){
	cronologia.insert(crono.cronologia.begin(), crono.cronologia.end());
}

FechaHistorica Cronologia::getEventos(int anio){
	return cronologia[anio];
}

int Cronologia::numAnios() 
{ 
	return cronologia.size(); 
}

void Cronologia::insertarFecha(const FechaHistorica &f) {
  this->cronologia.insert(fecha(f.getAnio(), f));
}

void Cronologia::insertar(const FechaHistorica &f) {
  auto it = cronologia.find(f.getAnio());

  if (it != cronologia.end()) {
    FechaHistorica nueva_f = it->second + f;
    cronologia.erase(it);
    insertarFecha(nueva_f);
  } else
    insertarFecha(f);
}

void Cronologia::eliminar(int anio){
	if(cronologia.find(anio) != cronologia.end()){
		cronologia.erase(anio);
	}
}
Cronologia Cronologia::buscarPalabra(string palabra){
	Cronologia nueva;
	map<int, FechaHistorica>::iterator it = cronologia.begin();
	for(; it != cronologia.end(); ++it){
		FechaHistorica fnew;
		fnew = it->second.buscarPalabra(palabra);
		if(fnew.getAnio() != 0){
			nueva.cronologia.insert(make_pair(fnew.getAnio(),fnew));
		}
	}
	return nueva;
}
Cronologia Cronologia::intervalo(int anio_ini, int anio_fin){
	map<int,FechaHistorica>::iterator it = cronologia.begin();
	Cronologia nueva;
	for(; it != cronologia.end(); ++it){
		if(it->first >= anio_ini && it->first <= anio_fin){
			nueva.cronologia[it->first] = it->second;
		}
	}
	return nueva;
}
Cronologia &Cronologia::operator=(const Cronologia &crono){
	if(this != &crono){
		cronologia.clear();
		cronologia.insert(crono.cronologia.begin(),crono.cronologia.end());
	}
	return *this;
}
Cronologia Cronologia::operator+(const Cronologia &crono){
	Cronologia resultado(*this);

  for (auto it = crono.cronologia.begin(); it != crono.cronologia.end(); it++) {
    resultado.insertar(it->second);
  }

  return resultado;
}

ostream& operator<< (ostream& salida, const Cronologia& crono)
{
	Cronologia::const_iterator it;
	for (it = crono.cbegin(); it != crono.cend(); it++) {
    salida << it->second << endl;
  }

  return salida;
}


istream &operator>>(istream &is, Cronologia &c) {
  string aux;

  while (getline(is, aux)) {
    istringstream iss(aux);
    c.insertarFecha(FechaHistorica(iss));
  }

  return is;
}

Cronologia::iterator Cronologia::begin() {
	return cronologia.begin();
}

Cronologia::iterator Cronologia::end() {
	return cronologia.end();
}

Cronologia::const_iterator Cronologia::cbegin() const{
	return cronologia.begin();
}

Cronologia::const_iterator Cronologia::cend() const{
	return cronologia.end();
}