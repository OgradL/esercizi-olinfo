#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj, bl, bl2;
vector<int> tin, tout;
int timer = 0;
vector<int> dp1, dp2;
vector<int> subtree;
vector<int> big0, big1, big2;
vector<int> C;

void dfs(int u, int p){
	bl[u][0] = p;
	for (int i = 1; i < 20; i++)
		bl[u][i] = bl[bl[u][i-1]][i-1];
	
	subtree[u] = C[u];
	tin[u] = timer++;
	for (int x : adj[u]){
		if (x == p) continue;
		dfs(x, u);
		subtree[u] = max(subtree[u], subtree[x]);
	}
	tout[u] = timer++;
}

int max_ex(int u, int x, int x2 = -1){
	if (x == -1)
		return big0[u];

	if (x2 == -1)
		return subtree[x] == big0[u] ? big1[u] : big0[u];

	if (subtree[x] < subtree[x2])
		swap(x, x2);

	if (subtree[x] == big0[u] && subtree[x2] == big1[u])
		return big2[u];

	return max_ex(u, x);
}

void update_big(int u, int val){
	if (val > big0[u]){
		big2[u] = big1[u];
		big1[u] = big0[u];
		big0[u] = val;
		return;
	}
	if (val > big1[u]){
		big2[u] = big1[u];
		big1[u] = val;
		return;
	}
	if (val > big2[u]){
		big2[u] = val;
		return;
	}
}

void dfs2(int u, int p, int m1 = 0, int m2 = 0){
	bl2[u][0] = max_ex(bl[u][0], u);
	for (int i = 1; i < 20; i++)
		bl2[u][i] = max(bl2[u][i-1], bl2[bl[u][i-1]][i-1]);


	for (int x : adj[u]){
		if (x == p) continue;
		update_big(u, subtree[x]);
	}

	dp1[u] = m1;
	dp2[u] = big0[u];

	for (int x : adj[u]){
		if (x == p) continue;

		int w_ex = max_ex(u, x);

		dfs2(x, u, max({m1, w_ex, C[u]}), max(m2, w_ex));
	}
}

bool is_ancestor(int a, int b){
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b, bool prev = false){
	if (is_ancestor(a, b) && !prev)
		return a;
	if (is_ancestor(b, a) && !prev)
		return b;
	for (int i = 19; i >= 0; i--)
		if (!is_ancestor(bl[a][i], b))
			a = bl[a][i];
	return prev ? a : bl[a][0];
}

int query(int a, int l){
	int res = 0;
	for (int i = 19; i >= 0; i--){
		if (!is_ancestor(bl[a][i], l)){
			res = max(res, bl2[a][i]);
			a = bl[a][i];
		}
	}
	return res;
}

vector<int> raccogli(int N, int Q, vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &L, vector<int> &T){
	::C = C;

	adj.resize(N);
	for (int i = 0; i < N-1; i++){
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
	}

	tout.resize(N);
	tin.resize(N);
	bl.assign(N, vector<int>(20, 0));
	bl2.assign(N, vector<int>(20, 0));
	dp1.assign(N, 0);
	dp2.assign(N, 0);
	big0.assign(N, 0);
	big1.assign(N, 0);
	big2.assign(N, 0);
	subtree.assign(N, 0);

	dfs(0, 0);
	dfs2(0, 0);

	vector<int> answer(Q, 0);

	for (int i = 0; i < Q; i++){
		int u = L[i], v = T[i];
		int l = lca(u, v);
		int u1 = -1, v1 = -1;

		answer[i] = dp1[l];
		if (l != u){
			answer[i] = max(answer[i], dp2[u]);
			answer[i] = max(answer[i], query(u, l));
			u1 = lca(u, l, true);
		}
		if (l != v){
			answer[i] = max(answer[i], dp2[v]);
			answer[i] = max(answer[i], query(v, l));
			v1 = lca(v, l, true);
		}

		if (u1 < v1)
			swap(u1, v1);
		answer[i] = max(answer[i], max_ex(l, u1, v1));
	}

	return answer;
}
