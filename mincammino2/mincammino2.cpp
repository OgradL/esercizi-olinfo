#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<long long>& D) {

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({0, 0});
	D[0] = 0;

	for (int i = 1; i < N; i++)
		D[i] = -1;

	vector<vector<pair<int, long long>>> adj(N);
	for (int i = 0; i < M; i++){
		adj[X[i]].emplace_back(Y[i], P[i]);
	}

	while (!pq.empty()){
		auto [d, n] = pq.top();
		pq.pop();

		if (d > D[n])
			continue;

		for (auto [x, w] : adj[n]){
			if (D[x] == -1 || D[x] > d + w){
				pq.push({D[x] = d + w, x});
			}
		}
	}
}
