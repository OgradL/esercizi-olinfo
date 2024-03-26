#include <iostream>
using namespace std;

int main(){
	srand(time(NULL));

	int N = 10;
	int Q = 200000;

	cout << N << "\n";
	for (int i = 0; i < N; i++){
		cout << rand() % (1<<20) << " " << rand() % (1<<20) << " " << rand() % (1<<20) << "\n";
	}

	cout << Q << "\n";
	for (int i = 0; i < Q; i++){
		cout << rand() % N + 1 << " " << rand() % (1<<20) << "\n";
	}

	return 0;
}