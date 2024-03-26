#include <iostream>
#include <stdlib.h>
using namespace std;

int GreatestHappiness(int N, int K, int *C);

int main(){

	int N, K;
	cin >> N >> K;
	
	int *C = (int *)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++){
		cin >> C[i];
	}

	cout << GreatestHappiness(N, K, C) << "\n";

	return 0;
}