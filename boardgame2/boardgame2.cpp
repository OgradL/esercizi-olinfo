#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, long long>>> adj;
vector<long long> winning, cost[2];

void dfs(int v){
	if (winning[v] != -1)
		return;
	long long best = 0;
	for (auto& [x, d] : adj[v]){
		dfs(x);
		best = max(best, 1 - winning[x]);
	}
	winning[v] = best;
};

long long dfs2(int v, int turn = 0){
	if (cost[turn][v] != -1){
		return cost[turn][v];
	}
	long long res = 0;
	if (turn){
		for (auto& [x, d] : adj[v]){
			res = max(res, dfs2(x, 1-turn));
		}
	} else {
		res = 1e18;
		for (auto& [x, d] : adj[v]){
			if (winning[x]) continue;
			res = min(res, d + dfs2(x, 1-turn));
		}
	}
	return cost[turn][v] = res;
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	adj.resize(N);

	long long a, b, w;
	for (int i = 0; i < M; i++){
		cin >> a >> b >> w;
		--a, --b;
		adj[a].push_back({b, w});
	}

	winning.assign(N, -1);
	cost[0].assign(N, -1);
	cost[1].assign(N, -1);

	dfs(0);

	if (winning[0]){
		cout << "Alice\n";
		cout << dfs2(0, 0) << "\n";
	} else {
		cout << "Bob\n";
		cout << dfs2(0, 1) << "\n";
	}

	return 0;
}
