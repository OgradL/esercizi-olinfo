#include <bits/stdc++.h>

using namespace std;

int GreatestHappiness(int N, int K, int *C) {
	
	int i;
	int total = 0;
	for (i = 0; i < N; i++)
		total += C[i];
	return total;
	
}


int main(){
	
	int N, K;
	int* H = (int*)malloc((N) * sizeof(int));
	
	cin >> N >> K;
	for (int i = 0; i < N; i++){
		cin >> H[i];
	}
	
	
	cout << GreatestHappiness(N, K, H);
	
	return 0;
}
