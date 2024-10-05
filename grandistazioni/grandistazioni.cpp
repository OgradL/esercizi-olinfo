#include <vector>
#include <queue>
using namespace std;

struct node{
	int n;
	long long d;

	bool operator<(const node& a) const {
		return d > a.d;
	}
};

long long viaggia(int N, int M, vector<int> A, vector<int> B, vector<int> T, vector<int> V, vector<int> W) {
	
	vector<vector<node>> G(N), Gr(N);
	for (int i = 0; i < M; i++){
		G[A[i]].push_back({B[i], T[i]});
		Gr[B[i]].push_back({A[i], T[i]});
	}

	priority_queue<node> pq;
	vector<long long> dist(N, 1e18);
	vector<node> prev(N);
	pq.push({N-1, 0});
	dist[N-1] = 0;

	while (!pq.empty()){
		node n = pq.top();
		pq.pop();

		if (n.d > dist[n.n])
			continue;

		for (auto [x, t] : Gr[n.n]){
			if (dist[x] > dist[n.n] + t){
				dist[x] = dist[n.n] + t;
				pq.push({x, dist[x]});
				prev[x] = {n.n, t};
			}
		}
	}
	
	vector<long long> jump(N, -1), lenght(N, -1);
	for (int i = 0; i < N-1; i++){
		jump[i] = prev[i].n;
		lenght[i] = prev[i].d;
	}

	vector<int> history;
	vector<int> seen(N, 0);
	int x = 0;
	long long ans = 0;
	while (x != N-1){
		if (seen[x] || W[x] == -1){
			seen[x] = 1;
			history.push_back(x);
			ans += lenght[x];
			x = jump[x];
		} else {
			seen[x] = 1;
			long long d = 0;
			for (int i = history.size()-1; i >= 0; i--){
				d += lenght[history[i]];
				jump[history[i]] = x;
				lenght[history[i]] = d;
			}
			history.clear();
			ans += W[x];
			x = V[x];
		}
	}
	
    return ans;
}
