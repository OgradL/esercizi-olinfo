#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>
using namespace std;

long long k;

long long calc(long long t, long long d){
	return t * k - d * k * (k-1) / 2;
}

struct edge{
	long long a, b, t, d;

	bool operator<(const edge& a) const{
		return calc(t, d) > calc(a.t, a.d);
	}
};

vector<vector<edge>> G;

long long comunica(int N, int M, int K, int S, int E, vector<int> A, vector<int> B, vector<int> T, vector<int> D){
	k = K;

	G.resize(N);
	for (int i = 0; i < M; i++){
		G[A[i]].push_back((edge){A[i], B[i], T[i], D[i]});
		G[B[i]].push_back((edge){B[i], A[i], T[i], D[i]});
	}

	vector<long long> dist(N, 1e15), dist2(N, 0);
	dist[S] = 0;
	dist2[S] = 0;

	priority_queue<edge> pq;
	pq.push((edge){S, 0, 0, 0});

	while (!pq.empty()){
		auto [n, _, t, d] = pq.top();
		pq.pop();

		if (calc(t, d) > calc(dist[n], dist2[n]))
			continue;
		
		if (n == E)
			break;
		
		for (auto [_, x, t, d1] : G[n]){
			if (calc(dist[x], dist2[x]) > calc(dist[n] + t, dist2[n] + d1)){
				dist[x] = dist[n] + t;
				dist2[x] = dist2[n] + d1;
				pq.push((edge){x, 0, dist[x], dist2[x]});
			}
		}
	}
	
	long long ans = calc(dist[E], dist2[E]);

	return ans;
}