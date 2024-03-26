#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF (long long)(1e18)

struct nodo{
	long long to = 0;
	long long w = INF;
	long long k = 0;

	bool operator<(nodo a){
		return (w != a.w) ? (w < a.w) : (k < a.k);
	}
};
bool operator<(nodo a, nodo b){
	return (a.w != b.w) ? (a.w < b.w) : (a.k < b.k);
}

long long fuggi(int N, int M, vector<int> A, vector<int> B, vector<int> T, vector<int> R){

	vector<vector<nodo>> G[2];
	G[0].resize(N); G[1].resize(N);
	for (int i = 0; i < M; i++){
		G[R[i]][A[i]].push_back((nodo){B[i], T[i]});
	}

	// nodo {to: nodo, w: distanza, k: kune spese}
	priority_queue<nodo> pq;
	pq.push((nodo){0, 0});

	// nodo {to: nodo, w: distanza, k: kune spese}
	vector<nodo> dist(N, (nodo){0, INF, INF});
	dist[0] = (nodo){0, 0, 0};

	nodo n;
	while (!pq.empty()){
		n = pq.top();
		pq.pop();

		// cout << n.to << " " << n.w << " " << n.k << "\n";
		if (n.w > dist[n.to].w)
			continue;
		if (n.k < dist[n.to].k)
			continue;

		for (nodo x : G[0][n.to]){
			// cout << x.to << " " << x.w << "\n";
			if (n.w + x.w < dist[x.to].w){
				pq.push((nodo){x.to, n.w + x.w, n.k + x.w});
				dist[x.to] = (nodo){x.to, n.w + x.w, n.k + x.w};
				if (G[1][n.to].size()){
					pq.push((nodo){x.to, n.w + x.w, n.k + x.w - 1});
					dist[x.to] = (nodo){x.to, n.w + x.w, n.k + x.w - 1};
				}
			}
		}

	}

	return dist[N-1].k;
}