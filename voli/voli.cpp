#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct edge{
	long long A, B, L, C;

	bool operator<(const edge& b) const{
		return L > b.L;
	}
};

long long plan(int N, int M, int K, vector<int> A, vector<int> B, vector<int> L, vector<int> C, vector<int> T) {

	vector<vector<edge>> G(N);
	for (int i = 0; i < M; i++){
		G[A[i]].push_back((edge){A[i], B[i], L[i], C[i]});
		G[B[i]].push_back((edge){B[i], A[i], L[i], C[i]});
	}

	priority_queue<edge> pq;
	pq.push((edge){0, 0, 0, -1});

	vector<unordered_map<int, int>> dist(N);
	vector<long long> ans(N, 1e18);
	// vector<int> v(N, 0);
	

	while (!pq.empty()){
		auto [n, z, d, c] = pq.top();
		pq.pop();

		ans[n] = min(ans[n], d);
		if (n == N-1) break;
		if (dist[n][c]) continue;
		dist[n][c] = 1;
		// v[n] = 1;

		for (auto x : G[n]){
			if (!dist[x.B][x.C] /*&& !v[x.B]*/){
				pq.push((edge){x.B, 0, d + x.L + ((c != x.C) ? T[x.C] : 0), x.C});
			}
		}
	}

	return ans[N-1];
}
