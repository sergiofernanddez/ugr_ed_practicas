#include<iostream>	
#include<ctime>
#include<cstdlib>			
using namespace std;

//Programa principal
int main(int argc, char * argv[]){
   
   int util_filas = atoi(argv[1]);
   int util_columnas = atoi(argv[2]);

   int *matriz_1;
   int *matriz_2;
   int *matriz_resultado;
   matriz_1 = new int[util_filas*util_columnas];
   matriz_2 = new int[util_filas*util_columnas];
   matriz_resultado = new int[util_filas*util_columnas];
   
   //Insertar valores dentro de la primera matriz
   srand(time(0));
   for (int i=0; i<util_filas; i++){
    	for (int j=0; j<util_columnas; j++){
    		matriz_1[i*util_columnas+j] = rand() % 50000;
    	}		 
   }

   //Insertar valores dentro de la segunda matriz
   srand(time(0));
   for (int i=0; i<util_filas; i++){
    	for (int j=0; j<util_columnas; j++){
			matriz_2[i*util_columnas+j] = rand() % 50000;
		}
   }
  
   
	clock_t tini;
	tini=clock();

   //Calcula la multiplicacion entre las dos matrices 
   for(int i=0; i<util_filas; i++){
   	for(int j=0; j<util_columnas; j++){
   		for(int k=0; k<util_columnas; k++)
   			matriz_resultado[i*util_columnas+j] += matriz_1[i*util_columnas+k] * matriz_2[k*util_columnas+j] ;
   			
		}
	}

	clock_t tfin;
	tfin=clock();
	
	cout << util_filas << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;
	
	delete [] matriz_1;
	delete [] matriz_2;
	delete [] matriz_resultado;
}
