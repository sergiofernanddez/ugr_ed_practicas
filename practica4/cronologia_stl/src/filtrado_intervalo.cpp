/*
*		Trabajo realizado por:
*		Sergio Fernández Fernández
*		Bate Ye
*		Grupo B2
*		Prácticas Estructura de Datos
*/

#include "Cronologia.h"
#include "FechaHistorica.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  Cronologia crono;
  ifstream fich;

  if (argc < 4 || argc > 5) {
    cerr << "ERROR en la ejecucion de " << argv[0] << endl;
    cerr << "Debe dar el nombre del fichero cronologia, año inferior y superior. "
         << "Opcional un tercer fichero resultado" << endl;
    exit(1);
  }

  fich.open(argv[1]);
  fich >> crono;
  Cronologia sub_crono = crono.intervalo(atoi(argv[2]), atoi(argv[3]));

  if (argc == 4)
    cout << sub_crono;

  else {
    ofstream fichSalida(argv[4]);
    fichSalida << sub_crono;
    fichSalida.close();
  }

  fich.close();

  return 0;
}