#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void sposta(int chi, int dove);

int pianifica(int N, int M, int P1, int D1, int P2, int D2, int A[], int B[]) {

	vector<vector<int>> adj(N);
	for (int i = 0; i < M; i++){
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
	}

	vector<vector<int>> dist(N, vector<int>(N, -1));
	
	auto bfs = [&](int source, vector<int>& d){
		queue<int> q;
		q.push(source);
		d[source] = 0;

		while (!q.empty()){
			auto n = q.front();
			q.pop();

			for (int x : adj[n]){
				if (d[x] == -1){
					d[x] = d[n] + 1;
					q.push(x);
				}
			}
		}
	};

	for (int i = 0; i < N; i++){
		bfs(i, dist[i]);
	}


	vector<vector<int>> seen(N, vector<int>(N, 0));
	vector<vector<pair<int, int>>> prev(N, vector<pair<int, int>>(N, {-1, -1}));
	
	auto bfs2 = [&](int cutoff){
		seen.assign(N, vector<int>(N, 0));
		queue<pair<int, int>> q;
		q.push({P1, P2});

		while (!q.empty()){
			auto [n0, n1] = q.front();
			q.pop();
			
			if (n0 == D1 && n1 == D2){
				return true;
			}

			for (int x : adj[n0]){
				if (!seen[x][n1] && dist[x][n1] >= cutoff){
					prev[x][n1] = {n0, n1};
					seen[x][n1] = 1;
					q.push({x, n1});
				}
			}

			for (int x : adj[n1]){
				if (!seen[n0][x] && dist[n0][x] >= cutoff){
					prev[n0][x] = {n0, n1};
					seen[n0][x] = 1;
					q.push({n0, x});
				}
			}
		}

		return false;
	};

	int lo = 0, hi = dist[P1][P2]+1, mid;
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;

		if (bfs2(mid)){
			lo = mid;
		} else {
			hi = mid;
		}
	}

	bfs2(lo);

	pair<int, int> curr = {D1, D2};
	pair<int, int> end = {P1, P2};
	
	vector<pair<int, int>> args;
	while (curr != end){
		auto pre = prev[curr.first][curr.second];
		if (pre.first == curr.first){
			args.push_back({2, curr.second});
		} else {
			args.push_back({1, curr.first});
		}
		curr = pre;
	}

	reverse(args.begin(), args.end());

	for (auto [chi, dove] : args){
		sposta(chi, dove);
	}

	return lo;
}
