#include <iostream>
#include <vector>
using namespace std;

struct edge{
	int a, b, t, d;
};

vector<vector<edge>> G;
vector<vector<int>> bl;
vector<int> tour, tin, tout;
int timer = 0;
vector<long long> depth, depth1, depth2;

void dfs(int u, int p, int d = 0, long long w1 = 0, long long w2 = 0){
	depth[u] = d;
	depth1[u] = w1;
	depth2[u] = w2;
	
	bl[u][0] = p;
	for (int i = 1; i < 20; i++)
		bl[u][i] = bl[bl[u][i-1]][i-1];
	
	tin[u] = timer++;
	tour.push_back(u);
	for (auto [_, x, t, d1] : G[u]){
		if (x != p)
			dfs(x, u, d+1, w1+t, w2+d1);
	}
	tout[u] = timer++;
	tour.push_back(u);
}

bool is_ancestor(int a, int b){
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b){
	if (is_ancestor(a, b))
		return a;
	if (is_ancestor(b, a))
		return b;
	for (int i = 19; i >= 0; i--)
		if (!is_ancestor(bl[a][i], b))
			a = bl[a][i];
	return bl[a][0];
}


long long comunica(int N, int M, int K, int S, int E, vector<int> A, vector<int> B, vector<int> T, vector<int> D){

	G.resize(N);
	for (int i = 0; i < N-1; i++){
		G[A[i]].push_back((edge){A[i], B[i], T[i], D[i]});
		G[B[i]].push_back((edge){B[i], A[i], T[i], D[i]});
	}

	tout.resize(N);
	tin.resize(N);
	bl.assign(N, vector<int>(20, 0));
	depth.resize(N);
	depth1.resize(N);
	depth2.resize(N);

	dfs(0, 0);

	int v = lca(S, E);
	
	long long d1 = depth1[S] + depth1[E] - 2*depth1[v];
	long long d2 = depth2[S] + depth2[E] - 2*depth2[v];
	
	long long ans = d1 * K - d2 * K * (K-1) / 2;

	return ans;
}