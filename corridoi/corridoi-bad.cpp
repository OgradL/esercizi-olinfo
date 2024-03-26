#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct node{
	long long A, B, C, K, idx, l;
	unordered_map<int, long long> tape, seen;

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

		while (!pq.empty()){
			auto [n, z, c, k, idx, l, tape, seen] = pq.top();
			pq.pop();

			seen[n] = 1;
			
			if (n == l){
				l++;
				seen = unordered_map<int, long long>();
			}
			if (l > 2){
				ans = min(ans, c);
				break;
			}

			for (node& x : G[n]){
				if ((x.B <= l || x.B > 2) && !seen[x.B])
					pq.push((node){x.B, -1, c + x.C - tape[x.idx], k, -1, l, move(tape), move(seen)});
			}

			if (k){
				for (node& x : G[n]){
					auto copy = move(tape);
					long long v = min(k, x.C);
					copy[x.idx] += v;
					if ((x.B <= l || x.B > 2) && !seen[x.B])
						pq.push((node){x.B, -1, c + x.C - copy[x.idx], k - v, -1, l, move(copy), move(seen)});
				}
			}
		}

		ansv[query] = ans;
	}
	return ansv;
}
