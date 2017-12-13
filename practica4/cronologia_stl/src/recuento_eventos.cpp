/*
*		Trabajo realizado por:
*		Sergio Fernández Fernández
*		Bate Ye
*		Grupo B2
*		Prácticas Estructura de Datos
*/

#include "FechaHistorica.h"
#include "Cronologia.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char *argv[]) {
  ifstream fichero;
  Cronologia crono;
  double num_acon = 0, max_acon = 0, anios;
  double promedio;
  Cronologia::iterator it;

  if (argc != 2) {
    cerr << "ERROR en la ejecucion de " << argv[0] << endl;
    cerr << "Debes pasar el archivo con la cronologia" << endl;
    exit(1);
  }

  fichero.open(argv[1]);
  fichero >> crono;

  anios = crono.numAnios();

  for (it = crono.begin(); it != crono.end(); it++) {
    int acon = it->second.numAcont();
    num_acon += acon;

    if (acon > max_acon)
      max_acon = acon;
  }

  promedio = num_acon / anios;


  cout << "Numero de acontecimientos en FechaHistorica->      " << num_acon << endl;
  cout << "Numero de años de la cronologia->                  " << anios << endl;
  cout << "Numero maximo de acontecimientos en una año        " << max_acon << endl;
  cout << "Hay " << promedio << " acontecimientos de media por año" << endl;

  fichero.close();
  return 0;
}