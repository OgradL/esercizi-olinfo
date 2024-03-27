#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>
using namespace std;

long long k;

long long calc(long long t, long long d){
	return t * k - k * (k-1) / 2 * d;
}

struct edge{
	long long a, b, t;

	bool operator<(const edge& a) const{
		return t > a.t;
	}
};

vector<vector<edge>> G;

long long comunica(int N, int M, int K, int S, int E, vector<int> A, vector<int> B, vector<int> T, vector<int> D){
	k = K;

	G.resize(N);
	for (int i = 0; i < M; i++){
		G[A[i]].push_back((edge){A[i], B[i], calc(T[i], D[i])});
		G[B[i]].push_back((edge){B[i], A[i], calc(T[i], D[i])});
	}

	vector<long long> dist(N, 1e18);
	dist[S] = 0;

	priority_queue<edge> pq;
	pq.push((edge){S, 0, 0});

	while (!pq.empty()){
		auto [n, _, t] = pq.top();
		pq.pop();

		if (n == E)
			break;
		
		for (auto [_, x, t] : G[n]){
			if (dist[x] > dist[n] + t){
				dist[x] = dist[n] + t;
				pq.push((edge){x, 0, dist[x]});
			}
		}
	}
	
	long long ans = dist[E];

	return ans;
}
