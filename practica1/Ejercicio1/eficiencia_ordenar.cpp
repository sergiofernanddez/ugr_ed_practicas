#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void ordenar(int *v, int n) {
    bool cambio=true;
    for (int i=0; i<n-1 && cambio; i++) {
        cambio=false;
    for (int j=0; j<n-i-1; j++)
        if (v[j]>v[j+1]) {
            cambio=true;
            int aux = v[j];
            v[j] = v[j+1];
            v[j+1] = aux;
        }
    }
}

int main(int argc, char * argv[]) {

    int tam=atoi(argv[1]);      // Tamaño del vector
    int vmax=atoi(argv[2]);     // Valor máximo

    int *v= new int[tam];
    srand(time(0));
    for(int i=0; i<tam; i++)
        v[i]= rand() % vmax;

    clock_t tini;
    tini=clock();

    ordenar(v,tam);

    clock_t tfin;
    tfin=clock();

    cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;
    delete [] v;
    

}