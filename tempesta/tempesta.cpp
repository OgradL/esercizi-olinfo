#include <cstdlib>
#include <vector>
using namespace std;

long long atterra(int N, vector<int> U, vector<int> V) {

	vector<vector<int>> adj(N);
	for (int i = 0; i < N - 1; i++){
		adj[U[i]].push_back(V[i]);
		adj[V[i]].push_back(U[i]);
	}

	vector<int> par(N), path;
	auto find_path = [&](auto&& find_path, int v, int p) -> void {
		par[v] = p;
		for (int x : adj[v]){
			if (x == p) continue;
			find_path(find_path, x, v);
		}
	};
	find_path(find_path, 0, 0);

	path.push_back(N-1);
	int x = N-1;
	while (x != 0){
		x = par[x];
		path.push_back(x);
	}

	if (path.size() == N){
		return -1;
	}

	vector<int> pots;

	for (int i = 0; i < path.size(); i++){
		int c = (i != 0) + (i != path.size()-1);

		if (adj[path[i]].size() > c){
			pots.push_back(i);
		}
	}

	long long ans = 0;
	int idx = 0;
	
	for (int i = 0; i < path.size(); i++){
		if (idx == pots.size() - 1){
			// nothing yay
		} else if (i - pots[idx] > pots[idx+1] - i){
			idx++;
		}

		ans += 1 + abs(i - pots[idx]);
	}

	return ans;
}
