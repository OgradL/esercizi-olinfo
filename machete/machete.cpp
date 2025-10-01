#include <vector>
using namespace std;

int machete(int N, int K, vector<int> P){

	vector<vector<int>> adj(N);
	for (int i = 1; i < N; i++){
		adj[P[i]].push_back(i);
	}

	int ans = 0;

	auto dfs = [&](auto&& dfs, int v) -> int {
		int d = 1;
		int c;
		for (int x : adj[v]){
			c = dfs(dfs, x);
			if (c >= K-1 && v != 0){
				c = 0;
				ans++;
			}
			d = max(d, c + 1);
		}

		return d;
	};

	dfs(dfs, 0);

	return ans;
}
