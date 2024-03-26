#include <bits/stdc++.h>

using namespace std;

int scarta(int M, vector<bool> L, vector<bool> D, vector<bool> N){
	
	int count = M;
	for (int i = 0; i < M; i++){
		if (int(L[i]) + int(D[i]) + int(N[i]) == 1) count--;
	}
	return count;
	
}

int main(){
	
	int M;
	
	cin >> M;
	
	vector<bool> L(M), D(M), N(M);
	
	int i0, i1, i2;
	for (int i = 0; i < M; i++){
		cin >> i0 >> i1 >> i2;
		L[i] = i0;
		D[i] = i1;
		N[i] = i2;
	}
	
	cout << scarta(M, L, D, N);
	
	return 0;
}
