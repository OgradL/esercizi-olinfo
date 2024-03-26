#include <iostream>
#include <vector>
using namespace std;

int dp(int p, int e, int N, int K, vector<int>& V, vector<int>& C, vector<vector<int>>& memo){
	if (p >= N) return 0;
	if (memo[p][e] != -1) return memo[p][e];
	
	int a = 1e9, b = 1e9;
	a = dp(p+1, min(e+C[p], K), N, K, V, C, memo) + V[p];
	if (e == K)
		b = dp(p+1, 0, N, K, V, C, memo);
	
	memo[p][e] = min(a, b);
	return memo[p][e];
}


int main() {
	
	int N, K;
	cin >> N >> K;
	
	vector<int> V(N), C(N);
	for (int &n : V) cin >> n;
	for (int &n : C) cin >> n;
	
	// dp[pos][energy] = time;
	vector<vector<int>> memo(N, vector<int>(K+1, -1));
	
	
	cout << dp(0, 0, N, K, V, C, memo) << "\n";
	
	
	return 0;
}