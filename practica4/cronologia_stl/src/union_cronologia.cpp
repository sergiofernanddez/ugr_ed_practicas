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
  ifstream fich1, fich2;
  Cronologia crono1, crono2;

  if (argc < 3 || argc >4) {
    cerr << "ERROR en la ejecucion de " << argv[0] << endl;
    cerr << "Debes pasar dos nombres de ficheros con los datos y un tercero opcional para que se guarde la suma" << endl;
    exit(1);
  }

  fich1.open(argv[1]);
  fich2.open(argv[2]);

  fich1 >> crono1;
  fich2 >> crono2;

  Cronologia cronoSuma;
  
  cronoSuma = crono1 + crono2;

  if (argc == 3)
    cout << cronoSuma;
  
  else {
    ofstream fichSalida(argv[3]);
    fichSalida << cronoSuma;
    fichSalida.close();
  }

  fich1.close();
  fich2.close();
  
  return 0;
}