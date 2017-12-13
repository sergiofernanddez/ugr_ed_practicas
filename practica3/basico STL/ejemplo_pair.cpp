#include <iostream>
#include <utility>
using namespace std;
 
int main()
{
    pair <int, char> grupo ;

    grupo.first = 2;
    grupo.second = 'B' ;

    pair <string, double> alumno1 ("Pedro Martínez Contreras", 7.3) ;
    pair <string, double> alumno2 ;

    alumno2 = make_pair ("Jesús González Vázquez", 4.5);
 
    cout << grupo.first << " " ;
    cout << grupo.second << endl ;
 
    cout << alumno1.first << " " ;
    cout << alumno1.second << endl ;
 
    cout << alumno2.first << " " ;
    cout << alumno2.second << endl ;
 
    return 0;
}