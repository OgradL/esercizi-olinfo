#include <bits/stdc++.h>

using namespace std;

int main(){
	
	
	int N;
	cin >> N;
	
	vector<int> P;
	P.resize(N);
	
	for (int i = 0; i < N; i++){
		cin >> P[i];
	}
	
	vector<int> A;
	A.resize(N);
	
	A[0] = 0;
	for (int i = 1; i < N; i++){
		A[i] = A[i - 1] - 10 + P[i - 1];
	}
	
	vector<int> B;
	B.resize(N);
	
	B[N - 1] = 0;
	for (int i = N - 2; i >= 0; i--){
		B[i] = B[i + 1] - 10 + P[i];
	}
	
	
	for (int i = 0; i < N; i++){
		cout << A[i] << " ";
	}
	cout << "\n";
	
	for (int i = 0; i < N; i++){
		cout << B[i] << " ";
	}
	cout << "\n";
	
	
	for (int i = 0; i < N; i++){
		
		if (P[i] + B[i] - A[i] >= 0){
			cout << i + 1 << "\n";
			break;
		}
		
	}
	
	
	
}


