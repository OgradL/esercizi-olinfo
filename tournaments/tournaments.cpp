#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#include <map>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> adj(N);
	int a, b;
	for (int i = 0; i < N-1; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}


	vector<vector<pair<int, int>>> ancestors(N);
	vector<map<int, int>> closest(N);
	vector<int> deleted(N, 0), subtree(N);

	function<int(int, int, int, int)> dfs = [&](int v, int p, int d, int root) -> int {
		if (root != -1){
			ancestors[v].push_back({root, d});
		}
		subtree[v] = 1;
		for (int x : adj[v]){
			if (x == p) continue;
			if (deleted[x]) continue;
			subtree[v] += dfs(x, v, d+1, root);
		}
		return subtree[v];
	};

	function<int(int, int, int)> get_centroid = [&](int v, int p, int sz) -> int {
		for (int x : adj[v]){
			if (x == p) continue;
			if (deleted[x]) continue;
			if (subtree[x] * 2 >= sz)
				return get_centroid(x, v, sz);
		}
		return v;
	};

	function<void(int)> build_centroid = [&](int v) -> void {
		dfs(v, v, 0, -1);
		int root = get_centroid(v, v, subtree[v]);
		dfs(root, root, 0, root);


		deleted[root] = 1;
		for (int x : adj[root]){
			if (!deleted[x])
				build_centroid(x);
		}
	};

	build_centroid(0);

	vector<int> X(M), T(M);
	for (int i = 0; i < M; i++){
		cin >> X[i] >> T[i];
	}

	vector<int> order(M);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int a, int b){
		return T[a] < T[b];
	});

	for (auto [p, d] : ancestors[0]){
		closest[p][-d] = 0;
	}

	int ans = 0;
	for (int u : order){
		int n = X[u];
		int t = T[u];

		int best = -1;
		for (auto [p, d] : ancestors[n]){
			auto it = closest[p].lower_bound(-(t - d));
			if (it == closest[p].end())
				continue;

			best = max(best, it->second);
		}

		if (best == -1)
			continue;

		best++;
		ans = max(ans, best);

		for (auto [p, d] : ancestors[n]){
			auto it = closest[p].lower_bound(-(t + d));
			if (it == closest[p].end()){
				closest[p][-(t+d)] = best;
				continue;
			}

			if (it->second >= best)
				continue;

			if (it != closest[p].begin() && prev(it)->second <= best){
				closest[p].erase(prev(it));
			}

			closest[p][-(t+d)] = best;
		}
	}

	cout << ans << "\n";

	return 0;
}
