#include <iostream>
using namespace std;

int main(){

	long long N, D;
	cin >> N >> D;

	long long a = 2, b = 1;

	a = a * D;
	b = b * D;

	long long potenza = 1;
	for (int i = 0; i < N-1; i++){
		potenza *= 10;
	}

	while (a < potenza){
		a *= 2;
	}

	while (b < potenza){
		b *= 3;
	}

	if (D >= 5 * potenza){
		a = 0;
		b = 0;
	}


	cout << a << " " << b << "\n";

	return 0;
}