#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

using pl = pair<long long, pair<int, int>>;

int avoid_volunteers(int subtask, int N, int M, int K, int S, int E, int T, int A[], int B[], int W[], int P[], int V[]) {

	vector<vector<pair<int, int>>> G(N);
	for (int i = 0; i < M; i++){
		G[A[i]].push_back({i, B[i]});
		G[B[i]].push_back({i, A[i]});
	}

	auto dijkstra = [&](long long maxV){
		priority_queue<pl, vector<pl>, greater<pl>> pq;
		vector<vector<long long>> dist(N, vector<long long>(K+1, 1e18));
		vector<vector<int>>	visited(N, vector<int>(K+1, 0));

		pq.push({0, {S, 0}});
		dist[S][0] = 0;

		while (!pq.empty()){
			auto [d, pi] = pq.top();
			auto [n, k] = pi;
			pq.pop();

			if (n == E)
				break;

			if (visited[n][k])
				continue;
			visited[n][k] = 1;

			for (auto [idx, to] : G[n]) {
				if (V[idx] <= maxV){
					if (dist[to][k] > d + W[idx]){
						dist[to][k] = d + W[idx];
						pq.push({d + W[idx], {to, k}});
					}
				}
				if (k < K){
					if (dist[to][k+1] > d + P[idx]){
						dist[to][k+1] = d + P[idx];
						pq.push({d + P[idx], {to, k+1}});
					}
				}
			}
		}
		return *min_element(dist[E].begin(), dist[E].end());
	};

	int lo = 0, hi = *max_element(V, V + M) + 1, mid;
	long long total_time = 1e18, ans = 1e18;
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;

		total_time = dijkstra(mid);
		if (total_time > T)
			lo = mid;
		else
			hi = mid, ans = total_time;
	}
	
	return ans > T ? -1 : hi;
}
