//Scrivi qui il tuo codice
#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

#define MAXN 5000
#define MAXK 5000
#define MAXP 1000000

int f(int n, int v, int N, int B, int K, vector<int>& P, vector<vector<int> >& memo){
	
	if (v < 0){
		return -1;
	}
	if (n < 0){
		return -1;
	}
	
//	cout << n << " " << v << "\n";
	
	if (memo[n][v] >= -1) return memo[n][v];
	
	if (n == 0){
		return 0;
	}
	if (v == 0){
		return 0;
	}
	
	int idx = n - 1;
	
	int pp = f(n - 1, v - P[idx], N, B, K, P, memo);
	int pn = f(n - 1, v, N, B, K, P, memo);
	
	if (pp >= 0 && pn >= 0){
		memo[n][v] = max(pp + P[idx], pn);
		/*
		if (pp >= K && pn >= K){
			memo[n][v] = min(pp + P[idx], pn);
		} else if (pp + P[idx] >= K){
			memo[n][v] = pp + P[idx];
		} else if (pn >= K){
			memo[n][v] = pn;
		} else {
			memo[n][v] = min(pp + P[idx], pn);
		}
		*/
	} else if (pp >= 0 && pn < 0){
		memo[n][v] = pp + P[idx];
	} else if (pp < 0 && pn >= 0){
		memo[n][v] = pn;
	} else {
		memo[n][v] = -1;
	}
	
	return memo[n][v];
}

int mangia(int N, int K, vector<int>& P){
	
	int sum = 0;
	for (int i = 0; i < N; i++) sum += P[i];
	
	int B = sum - K;
	
	if (B <= 0) return sum;
	
	vector<vector<int> > memo(N + 1, vector<int>(B + 1, -2));
	
	int ans = f(N, B, N, B, K, P, memo);
	
	/*
	cout << "memo: ";
	for (int i = 0; i < N; i++) cout << i << "  |  ";
	cout << "\n";
	for (int i = 0; i < B; i++){
		cout << "      ";
		for (int j = 0; j < N; j++){
			cout << memo[j][i] << " | ";
		}
		cout << "\n";
	}
	*/
	
	ans = sum - ans;
	
	return ans;
}

int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N, K;
	
	cin >> N >> K;
	
	vector<int> P(N);
	
	for (int i = 0; i < N; i++){
		cin >> P[i];
	}
	
	cout << mangia(N, K, P);
	
	return 0;
}