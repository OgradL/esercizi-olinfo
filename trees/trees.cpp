#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

vector<vector<int>> G;

long long ans = 0;
pair<long long, long long> dfs(int u, int p){
	pair<long long, long long> ret = {1, 0};

	for (int x : G[u]){
		if (x == p) continue;
		auto r = dfs(x, u);
		ret.first = (ret.first * r.first) % MOD;
		ret.second = (ret.second + r.first - 1 + MOD) % MOD;
	}

	ret.first++;

	ans += ret.second;

	return ret;
}

int count_sets(int N, vector<int> U, vector<int> V){

	G.resize(N);
	for (int i = 0; i < N-1; i++){
		G[U[i]].push_back(V[i]);
		G[V[i]].push_back(U[i]);
	}

	auto ret = dfs(0, 0);

	ans = (ans + ret.first - 1 + MOD) % MOD;

	return ans;
}
