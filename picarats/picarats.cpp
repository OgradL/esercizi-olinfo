#include <iostream>
#include <vector>
using namespace std;

int f(int n, int N, int C, vector<vector<pair<int, int>>>& G, vector<int>& P, vector<vector<int>>& dp){
	if (dp[n][C] != -1)
		return dp[n][C];

	if (n == N-1)
		return dp[n][C] = (C < 30)?(P[n] / (1 << C)):0;
	
	int d, td;
	int ans = 1e9;
	for (int c = 0; c <= C; c++){
		d = (c < 30) ? (P[n] / (1 << c)) : 0;
		td = 1e9;
		for (auto x : G[n]){
			td = min(td, f(x.first, N, C - c + x.second, G, P, dp));
		}
		ans = min(ans, max(d, td));
	}


	return dp[n][C] = ans;
}

int main(){

	int N, M, C;
	cin >> N >> M >> C;

	vector<int> P(N);
	for (int &n : P)
		cin >> n;

	vector<vector<pair<int, int>>> G(N);

	int a, b, c;
	for (int i = 0; i < M; i++){
		cin >> a >> b >> c;
		G[a].push_back({b, c});
	}

	vector<vector<int>> dp(N, vector<int>(101, -1));

	f(0, N, C, G, P, dp);

	cout << dp[0][C] << "\n";

	return 0;
}