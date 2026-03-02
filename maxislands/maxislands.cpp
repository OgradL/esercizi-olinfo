#include <functional>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Flowedge {
	int v, u;
	long long cap, flow = 0;
	Flowedge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
	const long long flow_inf = 1e18;
	vector<Flowedge> edges;
	vector<vector<int>> adj;
	int n, m = 0;
	int s, t;
	vector<int> level, ptr;
	queue<int> q;

	Dinic(int n, int s, int t) : n(n), s(s), t(t) {
		adj.resize(n);
		level.resize(n);
		ptr.resize(n);
	}

	void add_edge(int v, int u, long long cap) {
		edges.emplace_back(v, u, cap);
		edges.emplace_back(u, v, 0);
		adj[v].push_back(m);
		adj[u].push_back(m + 1);
		m += 2;
	}

	bool bfs() {
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int id : adj[v]) {
				if (edges[id].cap == edges[id].flow)
					continue;
				if (level[edges[id].u] != -1)
					continue;
				level[edges[id].u] = level[v] + 1;
				q.push(edges[id].u);
			}
		}
		return level[t] != -1;
	}

	long long dfs(int v, long long pushed) {
		if (pushed == 0)
			return 0;
		if (v == t)
			return pushed;
		for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
			int id = adj[v][cid];
			int u = edges[id].u;
			if (level[v] + 1 != level[u])
				continue;
			long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
			if (tr == 0)
				continue;
			edges[id].flow += tr;
			edges[id ^ 1].flow -= tr;
			return tr;
		}
		return 0;
	}

	long long flow() {
		long long f = 0;
		while (true) {
			fill(level.begin(), level.end(), -1);
			level[s] = 0;
			q.push(s);
			if (!bfs())
				break;
			fill(ptr.begin(), ptr.end(), 0);
			while (long long pushed = dfs(s, flow_inf)) {
				f += pushed;
			}
		}
		return f;
	}
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> G(N, vector<int>(M));
	for (auto& x : G){
		string s;
		cin >> s;
		for (int i = 0; i < M; i++){
			x[i] = s[i] != '?' ? s[i] - '0' : -1;
		}
	}

	
	vector<vector<int>> seen(N, vector<int>(M, 0));

	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};

	function<int(int, int)> dfs = [&](int x, int y) -> int {
		seen[x][y] = 1;
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;

			if (G[nx][ny] == -1)
				G[nx][ny] = 0;

			if (seen[nx][ny])
				continue;

			if (G[nx][ny] == 1)
				dfs(nx, ny);
		}
		return 1;
	};

	int ans = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (G[i][j] == 1 && !seen[i][j]){
				ans += dfs(i, j);
			}
		}
	}

	function<int(int, int)> dfs2 = [&](int x, int y) -> int {
		seen[x][y] = 1;
		int cnt = 1;
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;

			if (seen[nx][ny])
				continue;

		if (G[nx][ny] == -1)
			cnt += dfs2(nx, ny);
		}
		return cnt;
	};

	Dinic dinic(N*M+2, N*M, N*M+1);

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (G[i][j] == -1 && !seen[i][j]){
				int c = dfs2(i, j);
				if (c == 1){
					G[i][j] = 0;
					ans++;
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (G[i][j] != -1)
				continue;

			if ((i+j) & 1){
				dinic.add_edge(i*M+j, N*M+1, 1);
			} else {
				dinic.add_edge(N*M, i*M+j, 1);
			}
			cnt++;

			if (i && G[i-1][j] == -1){
				int a = i*M+j;
				int b = (i-1)*M+j;
				if ((i+j)&1) swap(a, b);
				dinic.add_edge(a, b, 1);
			}
			if (j && G[i][j-1] == -1){
				int a = i*M+j;
				int b = i*M+j-1;
				if ((i+j)&1) swap(a, b);
				dinic.add_edge(a, b, 1);
			}
		}
	}

	ans += cnt - dinic.flow();

	cout << ans << "\n";

	return 0;
}
