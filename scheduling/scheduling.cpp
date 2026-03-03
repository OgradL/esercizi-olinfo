#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Dinic{

	int n;
	int source, sink;
	vector<long long> edges;
	vector<vector<pair<int, int>>> adj;
	vector<int> depth, nxt;
	int scale;

	Dinic(int N, int start, int end){
		n = N;
		adj.resize(n);
		nxt.resize(n);
		depth.resize(n);
		source = start;
		sink = end;
	}

	void add_edge(int a, int b, int c){
		int i = edges.size();

		edges.push_back(c);
		edges.push_back(0);

		adj[a].push_back({b, i});
		adj[b].push_back({a, i+1});
	}

	bool bfs(){
		fill(depth.begin(), depth.end(), -1);
		depth[source] = 0;

		queue<int> q;
		q.push(source);

		while (!q.empty()){
			int n = q.front();
			q.pop();

			for (auto [x, e] : adj[n]){
				if (depth[x] >= 0 || edges[e] < scale)
					continue;
				depth[x] = depth[n] + 1;
				q.push(x);
			}
		}

		return depth[sink] >= 0;
	}

	long long dfs(int v, long long f){
		if (v == sink)
			return f;

		for (; nxt[v] < adj[v].size(); nxt[v]++){
			auto [x, e] = adj[v][nxt[v]];

			if (depth[x] <= depth[v] || edges[e] < scale) continue;
			long long d = dfs(x, min(f, edges[e]));

			if (d == 0)
				continue;

			edges[e] -= d;
			edges[e^1] += d;

			return d;
		}
		return 0;
	}

	long long flow(){
		long long ans = 0;

		for (scale = 1 << 21; scale > 0; scale >>= 1){

			while (bfs()){
				fill(nxt.begin(), nxt.end(), 0);

				while (long long f = dfs(source, 1e18)){
					ans += f;
				}
			}
		}

		return ans;
	}
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> A(N), B(N);
	for (int& x : A)
		cin >> x;
	for (int& x : B)
		cin >> x;

	vector<vector<int>> C(N, vector<int>(N));
	for (auto& x : C){
		for (auto& y : x){
			cin >> y;
		}
	}

	Dinic dinic(N + 2, N, N+1);

	for (int i = 0; i < N; i++){
		dinic.add_edge(dinic.source, i, A[i]);
		dinic.add_edge(i, dinic.sink, B[i]);
		for (int j = 0; j < i; j++){
			dinic.add_edge(i, j, C[i][j]);
			dinic.add_edge(j, i, C[j][i]);
		}
	}

	cout << dinic.flow() << "\n";

	return 0;
}
