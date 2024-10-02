#include <vector>
using namespace std;

vector<int> to_cut, md, sz;
vector<vector<int>> adj;

void dfs(int u, int d = 0){
	sz[u] = 1;
	md[u] = d;
	for (int& x : adj[u]){
		dfs(x, d+1);
		md[u] = max(md[u], md[x]);
		sz[u] += sz[x];
	}
	to_cut[d]--;
	to_cut[md[u]+1]++;
}

int pota(int N, vector<int> P) {

	adj.resize(N);
	sz.resize(N);
	md.resize(N);
	to_cut.assign(N+1, 0);

	for (int i = 1; i < N; i++){
		adj[P[i]].push_back(i);
	}

	dfs(0);

	int cut = N, ans = N;
	for (int i = 0; i <= N; i++){
		cut += to_cut[i];
		ans = min(ans, cut);
	}

	return ans;
}
