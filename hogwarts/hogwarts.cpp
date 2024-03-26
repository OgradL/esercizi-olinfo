#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct edge{
	int a, b, s, e;
};

int raggiungi(int N, int M, int A[], int B[], int inizio[], int fine[]){

	vector<vector<edge>> G(N);

	for (int i = 0; i < M; i++){
		G[A[i]].push_back((edge){A[i], B[i], inizio[i], fine[i]});
		G[B[i]].push_back((edge){B[i], A[i], inizio[i], fine[i]});
	}

	vector<int> d(N, 1e9);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	d[0] = 0;
	pq.push({0, 0});

	while (!pq.empty()){
		auto [t, n] = pq.top();
		pq.pop();

		if (n == N-1) break;
		if (t > d[n]) continue;

		for (edge x : G[n]){
			if (x.e <= t) continue;
			if (max(x.s, t) + 1 < d[x.b]){
				d[x.b] = max(x.s, t) + 1;
				pq.push({d[x.b], x.b});
			}
		}
	}

	return d[N-1] == 1e9 ? -1 : d[N-1];
}