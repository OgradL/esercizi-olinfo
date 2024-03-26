#include <iostream>
#include <vector>
#include <random>
using namespace std;

int main() {

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<long long> random(0, 1e18);
	

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, K;
	N = 100000;
	M = 250000;
	K = random(gen) % M;

	cout << N << " " << M << " " << K << "\n";

	
	for (int i = 0; i < M; i++){
		cout << random(gen) % N << " \n"[i==N-1];
	}
	for (int i = 0; i < M; i++){
		cout << random(gen) % N << " \n"[i==N-1];
	}
	for (int i = 0; i < M; i++){
		cout << random(gen) % (long long)(1e9) << " \n"[i==N-1];
	}
	for (int i = 0; i < M; i++){
		cout << random(gen) % K << " \n"[i==N-1];
	}
	for (int i = 0; i < N; i++){
		cout << random(gen) % (long long)(1e9) << " \n"[i==N-1];
	}

	return 0;
}
