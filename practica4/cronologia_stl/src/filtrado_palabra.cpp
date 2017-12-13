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
  string palabra;

  if (argc < 2 || argc > 4) {
    cerr << "ERROR en la ejecucion de " << argv[0] << endl;
    cerr << "Debe dar el nombre del fichero cronologia, "
         << "Opcional la palabra a buscar y un fichero de salida" << endl;
    exit(1);
  }

  if(argc == 2){
      cout << "Introduzca la palabra a buscar: ";
      cin >> palabra;
  }
  else 
    palabra = argv[2];

  fich.open(argv[1]);
  fich >> crono;
  Cronologia sub_crono = crono.buscarPalabra(palabra);

  if (argc == 3)
    cout << sub_crono;

  else {
    ofstream fichSalida(argv[3]);
    fichSalida << sub_crono;
    fichSalida.close();
  }

  fich.close();

  return 0;
}