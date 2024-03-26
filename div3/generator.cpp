#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(int argc, char** argv){
	srand(time(NULL));

	cout.tie(0);
	cout.sync_with_stdio(false);

	int T = 1000, digits = 1000;
	if (argc >= 3){
		T = stoi(argv[1]);
		digits = stoi(argv[2]);
	}
	cout << T << "\n";

	for (int i = 0; i < T; i++){
		for (int i = 0; i < digits; i++){
			cout << rand() % 10;
		}
		cout << "\n";
	}

	return 0;
}