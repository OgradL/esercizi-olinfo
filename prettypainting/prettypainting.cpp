#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<vector<int>> adj(N);
	vector<long long> K(N), P(N-1), W(N-1);
	for (auto& x : K)
		cin >> x;
	for (auto& x : P)
		cin >> x;
	for (auto& x : W)
		cin >> x;

	for (int i = 0; i < N-1; i++){
		adj[P[i]].push_back(i+1);
	}

	vector<array<long long, 2>> dp(N, {0, 0});

	auto dfs = [&](auto&& dfs, int v) -> void {
		priority_queue<long long> pq;
		long long res = 0;

		for (auto x : adj[v]){
			dfs(dfs, x);
			res += dp[x][0];
			if (dp[x][1] - dp[x][0] >= 0)
				pq.push(dp[x][1] - dp[x][0]);
		}

		long long last = res - W[v-1];
		while (K[v] > 0 && !pq.empty()){
			K[v]--;
			last = res;
			res += pq.top();
			pq.pop();
		}
		if (K[v] > 0)
			last = res;

		if (v == 0){
			dp[v] = {res, last};
		} else {
			dp[v] = {res, last + W[v-1]};
		}
	};

	dfs(dfs, 0);

	cout << dp[0][0] << "\n";

	return 0;
}
