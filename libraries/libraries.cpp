#include <iostream>
#include <vector>
#include <array>
using namespace std;


template<typename T, unsigned long S>
array<T, S> addarr(const array<T, S>& a, const array<T, S>& b){
	array<T, S> res;
	for (int i = 0; i < S; i++){
		res[i] = a[i] + b[i];
	}
	return res;
}

template<typename T, unsigned long S>
array<T, S> subarr(const array<T, S>& a, const array<T, S>& b){
	array<T, S> res;
	for (int i = 0; i < S; i++){
		res[i] = a[i] - b[i];
	}
	return res;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<vector<int>> adj(4*N);
	int node_idx = 0;
	int a, b, w;
	for (int i = 1; i < N; i++){
		cin >> a >> b >> w;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < N; i++){
		for (int j = 1; j <= 3; j++){
			adj[i].push_back(j*N + i);
			adj[j*N+i].push_back(i);
		}
	}

	vector<array<long long, 3>> count(4*N, {0, 0, 0});
	
	int K, idx;
	for (int i = 0; i < 3; i++){
		cin >> K;
		while (K--){
			cin >> idx;
			count[(i+1)*N+idx][i]++;
		}
	}

	vector<long long> ans(N);
	vector<array<long long, 3>> subtree(4*N);

	auto dfs = [&](auto&& dfs, int v, int p) -> void {
		subtree[v] = count[v];

		for (int x : adj[v]){
			if (x == p) continue;
			dfs(dfs, x, v);
			subtree[v] = addarr(subtree[v], subtree[x]);
		}
	};

	auto solve = [&](auto&& solve, int v, int p) -> void {
		if (v >= N)
			return;

		array<long long, 3>& S = subtree[v];

		long long T = S[0] * S[1];
		for (int x : adj[v]){
			array<long long, 3>& E = subtree[x];
			T -= E[0] * E[1];
		}

		for (int x : adj[v]){
			array<long long, 3>& E = subtree[x];
			ans[v] += E[2] * (T - (E[0]*S[1] - 2*E[0]*E[1] + E[1]*S[0]));
		}

		for (int x : adj[v]){
			if (x == p) continue;
			array<long long, 3> E = subtree[x];
			S = subarr(S, E);
			subtree[x] = addarr(subtree[x], S);
			solve(solve, x, v);
			subtree[x] = subarr(subtree[x], S);
			S = addarr(S, E);
		}
	};


	dfs(dfs, 0, 0);

	solve(solve, 0, 0);


	for (long long x : ans)
		cout << x << ' ';
	cout << "\n";

	return 0;
}
