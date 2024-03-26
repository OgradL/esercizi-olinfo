#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1LL<<30;

struct node{
	int A, B, L1, L2;

	bool operator<(const node& a) const{
		return L2 > a.L2;
	}
};

void new_min(int& m1, int& m2, int v){
	if (v < m1){
		m2 = m1;
		m1 = v;
	} else if (v < m2){
		m2 = v;
	}
}

int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]){

	vector<vector<node>> G(N);
	for (int i = 0; i < M; i++){
		G[R[i][0]].push_back((node){R[i][0], R[i][1], L[i], 0});
		G[R[i][1]].push_back((node){R[i][1], R[i][0], L[i], 0});
	}

	vector<int> dist1(N, INF), dist2(N, INF);
	vector<int> v(N, 0);
	priority_queue<node> pq;
	for (int i = 0; i < K; i++){
		pq.push((node){P[i], 0, 0, 0});
		dist1[P[i]] = dist2[P[i]] = v[P[i]] = 0;
	}

	while (!pq.empty()){
		auto [n, _, d1, d2] = pq.top();
		pq.pop();

		if (v[n]) continue;
		v[n] = 1;
		if (n == 0) break;

		for (node x : G[n]){
			if (dist1[x.B] == INF)
				new_min(dist1[x.B], dist2[x.B], d2 + x.L1);
			else if (d2 + x.L1 < dist2[x.B]){
				new_min(dist1[x.B], dist2[x.B], d2 + x.L1);
				pq.push((node){x.B, 0, 0, dist2[x.B]});
			}
		}
	}

	return dist2[0];
}