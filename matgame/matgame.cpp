#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
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

	int N;
	cin >> N;

	vector<vector<int>> M(N, vector<int>(N));
	int m = 0;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> M[i][j];
			m = max(m, M[i][j]);
		}
	}


	auto check = [&](int x) -> bool {

		Dinic f(2*N+2, 2*N, 2*N+1);
		
		for (int i = 0; i < N; i++){
			f.add_edge(2*N, i, 1);

			f.add_edge(i+N, 2*N+1, 1);
		}

		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (M[i][j] >= x){
					f.add_edge(i, j+N, 1e9);
				}
			}
		}

		int flow = f.flow();
		return flow == N;
	};

	int lo = 0, hi = m+1, mid;
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;

		if (check(mid)){
			lo = mid;
		} else {
			hi = mid;
		}
	}

	cout << lo << "\n";

	return 0;
}
