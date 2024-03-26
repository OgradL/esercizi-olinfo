#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <algorithm>
using namespace std;

#define INF 1e9+10
#define all(x) x.begin(), x.end()

int main(){
	srand(time(nullptr));

	freopen("input.txt", "w", stdout);

	int N, R, T, L;
	N = rand() % 64;
	R = rand() % N;
	T = rand() % 32;
	L = rand() % 1000;

	cout << N << " " << R << " " << T << " " << L << "\n";

	vector<int> X(N);
	int n = 0;
	for (int i = 0; i < N; i++){
		X[i] = rand() % L;
	}
	
	sort(all(X));
	
	for (int i : X) cout << i << " ";

	cout << "\n";

	return 0;
}