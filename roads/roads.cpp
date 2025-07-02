#include <map>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

using pll = pair<long long, int>;

vector<pair<int, int>> orient_roads(int N, int M, vector<int> A, vector<int> B, vector<int> W) { 

	vector<vector<pair<int, int>>> adj(N);
	for (int i = 0; i < M; i++){
		adj[A[i]].push_back({B[i], W[i]});
		adj[B[i]].push_back({A[i], W[i]});
	}

	vector<map<int, int>> used_edge(N);
	vector<pair<int, int>> ans;
	bool impossible = false;

	auto dijkstra = [&](int start, int end){

		vector<long long> dist(N, 1e18), prev(N, -1);
		vector<bool> seen(N, 0);
		priority_queue<pll, vector<pll>, greater<pll>> pq;
		
		pq.push({0, start});
		dist[start] = 0;

		while (!pq.empty()){
			auto [d, n] = pq.top();
			pq.pop();

			if (seen[n])
				continue;
			seen[n] = 1;

			for (auto [x, w] : adj[n]){
				if (used_edge[n][x] >= 0 && dist[x] > d + w){
					dist[x] = d + w;
					prev[x] = n;
					pq.push({d + w, x});
				}
			}
		}

		int curr = end;

		while (curr != start){
			if (prev[curr] == -1){
				impossible = 1;
				return;
			}
			if (used_edge[prev[curr]][curr] == 0){
				ans.push_back({prev[curr], curr});
				used_edge[prev[curr]][curr] = 1;
				used_edge[curr][prev[curr]] = -1;
			}
			curr = prev[curr];
		}
	};

	dijkstra(0, N-1);
	dijkstra(N-1, 0);

	if (impossible)
		return {};

	for (int i = 0; i < M; i++){
		if (used_edge[A[i]][B[i]] == 0){
			ans.push_back({A[i], B[i]});
		}
	}

	return ans;
}
