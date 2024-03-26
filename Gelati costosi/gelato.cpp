#include <bits/stdc++.h>

using namespace std;


int presta(int N, int C, vector<int> P){
	sort(P.begin(), P.end(), greater<int>());
	long long su = 0;
	for (int i = 0; i < N; i++){
		su += P[i];
		if (su >= C) return i + 1;
	}
}


int main(){
	
	int N, C;
	
	cin >> N >> C;
	
	vector<int> P(N);
	
	for (int &i: P) cin >> i;
	
	cout << presta(N, C, P);
	
	return 0;
}
