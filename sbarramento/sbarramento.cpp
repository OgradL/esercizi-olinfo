#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1LL<<60;

struct node{
	int A, B;
	long long D1, D2;
	int R;

	bool operator<(const node& a) const{
		return D2 > a.D2;
	}
};

long long fuggi(int N, int M, vector <int> A, vector <int> B, vector <int> T, vector <int> R){

	vector<vector<node>> G(N);
	for (int i = 0; i < M; i++){
		G[B[i]].push_back((node){B[i], A[i], T[i], 0, R[i]});
	}

	vector<long long> dist1(N, INF), dist2(N, INF);
	vector<int> v(N, 0);
	priority_queue<node> pq;
	pq.push((node){N-1, 0, 0, 0, 0});
	dist1[N-1] = dist2[N-1] = 0;

	long long ans;
	while (!pq.empty()){
		auto [n, _, d1, d2, r] = pq.top();
		pq.pop();
		
		if (v[n]) continue;
		v[n] = 1;

		if (dist1[n] > dist2[n])
			d2--, dist1[n]--;
		
		if (n == 0) {
			ans = d2;
			break;
		}

		for (node& x : G[n]){
			if (x.R){
				dist2[x.B] = min(dist2[x.B], d2 + x.D1);
			} else {
				dist1[x.B] = min(dist1[x.B], d2 + x.D1);
				pq.push((node){x.B, 0, 0, dist1[x.B], 0});
			}
		}
	}

	return ans;
}