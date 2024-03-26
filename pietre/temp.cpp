#include <iostream>
#include <vector>
using namespace std;

struct casa{
	int size;
	int x, y;
	string color;
};
struct albero{
	int size;
	int x, y;
};
struct paese{
	casa casas[10];
	albero alberi[3];
};

template<class T>
void leggi_vettore(T vettore[], int size){
	for (int i = 0; i < size; i++){
		cin >> vettore[i];
	}
}

template<class T>
void operator>>(istream& cin, T v[]){
	for (int i = 0; i < 3; i++){
		cin >> v[i];
	}
}

struct tmp{
	int v;
	int operator[](tmp a){
		return v + a.v;
	}
};

int main(){

	// paese sorisole;

	// for (int i = 0; i < 10; i++){
	// 	cin >> sorisole.casas[i].size >> sorisole.casas[i].x >> sorisole.casas[i].y >> sorisole.casas[i].color;
	// }

	// for (int i = 0; i < 3; i++){
	// 	cin >> sorisole.alberi[i].size >> sorisole.alberi[i].x >> sorisole.alberi[i].y;
	// }

	int (vettore_5dimensioni[3])[3];

	cin >> vettore_5dimensioni;

	// for (int i = 0; i < 5; i++){
	// 	leggi_vettore(vettore_5dimensioni[i], 3);
	// 	// for (int j = 0; j < 10; j++){
	// 	// 	cin >> vettore_5dimensioni[i][j];
	// 	// }
	// }

	tmp a, b;
	a.v = 4;
	b.v = 26;

	cout << a[b] << "\n";

	return 0;
}