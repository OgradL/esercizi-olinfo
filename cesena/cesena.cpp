#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int visita(int N, int M, int K, vector<int> S, vector<int> A, vector<int> B, vector<int> T){

	priority_queue<pair<int, int>> pq;

	vector<int> is_chiosco(N, 0);
	for (int i = 0; i < K; i++)
		is_chiosco[S[i]] = 1;
 
	vector<vector<pair<int, int>>> G(N);
	for (int i = 0; i < M; i++){
		G[A[i]].push_back({B[i], T[i]});
		G[B[i]].push_back({A[i], T[i]});
	}

	vector<int> vals(N+1, 0);
	vector<int> dist(N, 0);
	dist[0] = N;
	pq.push({N, 0});


	while (!pq.empty()){
		auto [d, n] = pq.top();
		pq.pop();

		if (d < dist[n])
			continue;

		if (is_chiosco[n])
			++vals[d];

		for (auto [x, t] : G[n]){
			if (min(t, d) > dist[x]){
				dist[x] = min(t, d);
				pq.push({min(t, d), x});
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++){
		ans = min(ans + vals[i], i);
	}

	return ans;
}