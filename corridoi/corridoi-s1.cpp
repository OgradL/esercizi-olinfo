#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct node{
	long long A, B, C, K, idx, l;

	bool operator<(const node& a) const{
		return C > a.C;
	}
};

vector<long long> shorten(int N, int M, int Q, vector<long long> K, vector<int> A, vector<int> B, vector<int> C) {
	vector<long long> ansv(Q, 42);

	for (int query = 0; query < Q; query++){
		vector<vector<node>> G(N);
		for (int i = 0; i < M; i++){
			G[A[i]].push_back((node){A[i], B[i], C[i], 0, i, 0});
			G[B[i]].push_back((node){B[i], A[i], C[i], 0, i, 0});
		}

		long long ans = 1e18;

		priority_queue<node> pq;
		pq.push((node){0, -1, 0, K[query], -1, 0});

		vector<vector<long long>> dist(3, vector<long long>(N, 1e18));
		dist[0][0] = 0;

		while (!pq.empty()){
			auto [n, z, c, k, idx, l] = pq.top();
			pq.pop();
			

			if (dist[l][n] < c)
				continue;
			
			if (n == l){
				l++;
			}
			if (l > 2){
				ans = min(ans, c);
				break;
			}

			for (node& x : G[n]){
				if ((x.B <= l || x.B > 2) && dist[l][x.B] > c + x.C){
					dist[l][x.B] = c + x.C;
					pq.push((node){x.B, -1, c + x.C, k, -1, l});
				}
			}
		}

		ansv[query] = ans;
	}
	return ansv;
}
