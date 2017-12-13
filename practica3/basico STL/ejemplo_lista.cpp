#include <iostream>
#include <list>
using namespace std;
 
int main() {


	list<int> int_list;

	int_list.push_back(1);
	int_list.push_back(1);
	int_list.push_back(8);
	int_list.push_back(9);
	int_list.push_back(7);
	int_list.push_back(8);
	int_list.push_back(2);
	int_list.push_back(3);
	int_list.push_back(3);

	cout << "Tamaño de lista: "<< int_list.size()<<endl;

	int_list.sort();		//ordenar
	int_list.unique();		//eliminar repetidos

	cout << "Tamaño de lista: "<< int_list.size()<<endl;

	int_list.reverse();		//invertir lista



	for(list<int>::iterator list_iter = int_list.begin(); list_iter != int_list.end(); list_iter++)
	{
	    cout<<*list_iter<<endl;
	}

	cout << "Primero en la lista: "<< int_list.front() << endl; 
	int_list.pop_front() ;
	cout << "Primero en la lista: "<< int_list.front() << endl; 
	int_list.push_front(10);
	cout << "Primero en la lista: "<< int_list.front() << endl; 

	// Igual con back(), pop_back() y push_back()


	return 0; 

}
