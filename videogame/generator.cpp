#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <stdlib.h>
using namespace std;

// #define type second
// #define time first


int main(int argc, char** argv){
	srand(time(nullptr));

	freopen("input.txt", "w", stdout);
	// if (argc > 1){
		// freopen(argv[1], "r", stdin);
	// }

	int T, N, M, a, b;
	
	int magic = 10;

	T = rand() % magic;

	cout << T << "\n";

	N = rand() % magic;
	M = rand() % magic;

	int last = 0;
	cout << N << "\n";
	for (int i = 0; i < N; i++){
		a = (rand() % magic) + last;
		last = a + 1;
		b = (rand() % magic) + last;
		last = b + 1;
		cout << a << " " << b << "\n";
	}
	cout << M << "\n";
	last = 0;
	for (int j = 0; j < M; j++){
		a = (rand() % magic) + last;
		last = a + 1;
		b = (rand() % magic) + last;
		last = b + 1;
		cout << a << " " << b << "\n";
	}

	return 0;
}