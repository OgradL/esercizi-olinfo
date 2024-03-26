#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(int argc, char** argv){
	srand(time(NULL));

	int N = 1000, Q = 1000;
	if (argc >= 3){
		N = stoi(argv[1]);
		Q = stoi(argv[2]);
	}
	cout << N << " " << Q << "\n";


	for (int i = 0; i < N; i++){
		cout << rand() % 10 << " ";
	}
	cout << "\n";

	int v = 0, l, r;
	for (int i = 0; i < Q; i++){
		int op = rand() % 3;
		l = rand() % (N-1);
		r = rand() % (N-l-1) + l + 1;
		if (op == 0){
			// cerr << "ye1\n";
			cout << "0 " << l << " " << r << " " << rand() % 10 << "\n";
			v++;
		}
		if (op == 1){
			// cerr << "ye2\n";
			cout << "1 " << l << " " << r << " " << (rand() % (v+1)) << "\n";
			v++;
		}
		if (op == 2){
			// cerr << "ye3\n";
			cout << "2 " << l << " " << r << "\n";
		}
	}

	return 0;
}