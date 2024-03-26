#include <iostream>
#include <vector>
using namespace std;

int calc(int n, long long v, int N, vector<int>& P, vector<vector<int>>& dp){
	if (v <= 0) return -v;
	if (n == N) return 1e9 + 1042069;
	if (dp[n][v] != -1) return dp[n][v];

	return dp[n][v] = min(
		calc(n + 1, v - P[n], N, P, dp),
		calc(n + 1, v, N, P, dp)
		);
}

int mangia(int N, int K, vector<int>& P){
	vector<vector<int>> dp(N + 1, vector<int>(K + 1, -1));

	return calc(0, K, N, P, dp) + K;
}

int main(){
	
	#ifdef EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int N, K;
	cin >> N >> K;
	
	vector<int> P(N);
	
	for (int i = 0; i < N; i++)
		cin >> P[i];
	
	cout << mangia(N, K, P) << "\n";
	
	return 0;
}
