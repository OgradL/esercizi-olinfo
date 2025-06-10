#include <functional>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

using pll = pair<long long, long long>;

long long plan(int N, int M, int K, vector<int> A, vector<int> B, vector<int> L, vector<int> C, vector<int> T) {

	++K;

	unordered_map<long long, int> seen;

	unordered_map<long long, vector<pair<long long, long long>>> G;
	for (int i = 0; i < M; i++){
		long long n0 = A[i] * 1LL * K + C[i] + 1;
		long long n1 = B[i] * 1LL * K + C[i] + 1;

		if (!seen[n0]){
			seen[n0] = 1;
			long long par = A[i] * 1LL * K;
			G[par].push_back({n0, T[C[i]]});
			G[n0].push_back({par, 0});
		}
		if (!seen[n1]){
			seen[n1] = 1;
			long long par = B[i] * 1LL * K;
			G[par].push_back({n1, T[C[i]]});
			G[n1].push_back({par, 0});
		}

		G[n0].push_back({n1, L[i]});
		G[n1].push_back({n0, L[i]});
	}

	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({0, 0});

	unordered_map<long long, long long> dist;
	unordered_map<long long, int> visited;
	dist[0] = 0;

	while (!pq.empty()){
		auto [d, n] = pq.top();
		pq.pop();

		if (n == K*1LL*(N-1)) break;
		if (visited[n]) continue;
		visited[n] = 1;

		for (auto [x, w] : G[n]){
			if (!dist.count(x) || (dist[x] > d + w)){
				dist[x] = d + w;
				pq.push({d + w, x});
			}
		}
	}

	return dist[(N-1)*1LL*K];
}
