#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int N;
	
	cin >> N;
	
	vector<int> A(N);
	
	vector<int> copy(N);
	
	for (int i = 0; i < N; i++){
		cin >> A[i];
		copy[i] = A[i];
	}
	
	sort(copy.begin(), copy.end());
	
	
	
	
	return 0;
}
