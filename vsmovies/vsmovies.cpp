#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU{
	vector<int> parent, sizes;
	DSU(int n){
		parent.assign(n, -1);
		sizes.assign(n, 0);
	}
	void make_set(int v){
		if (parent[v] != -1) return;
		parent[v] = v;
		sizes[v] = 1;
	}
	int find_parent(int v){
		make_set(v);
		if (parent[v] == v) return v;
		return parent[v] = find_parent(parent[v]);
	}
	int onion_set(int a, int b){
		a = find_parent(a);
		b = find_parent(b);
		if (a != b){
			if (sizes[a] < sizes[b])
				swap(a, b);
			sizes[a] += sizes[b];
			parent[b] = a;
			return 1;
		}
		return 0;
	}
};

struct edge{
	long long a, b, t, idx;
};

vector<vector<int>> bln, bl1;
vector<int> tin, tout, depth, v, lg;
vector<long long> wp;
int timer = 0;

void build_bln(int n, int u, long long w, int d, vector<vector<edge>>& G, vector<int>& pres){
	v[n] = 1;
	depth[n] = d;
	wp[n] = w;
	tin[n] = ++timer;
	bln[n][0] = u;
	for (int i = 1; i <= 17; i++){
		bln[n][i] = bln[bln[n][i-1]][i-1];
	}

	for (auto [a, b, t, idx] : G[n]){
		if (!v[b] && pres[idx])
			build_bln(b, n, t, d+1, G, pres);
	}

	tout[n] = ++timer;
}

bool is_ancestor(int u, int v){
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
	if (is_ancestor(u, v))
		return u;
	if (is_ancestor(v, u))
		return v;
	for (int i = 17; i >= 0; i--) {
		if (!is_ancestor(bln[u][i], v))
			u = bln[u][i];
	}
	return bln[u][0];
}

void build_bl1(int n, int u, int w, vector<vector<edge>>& G, vector<int>& pres){
	v[n] = 1;
	int a = w;
	bl1[n][0] = a;
	for (int i = 1; i <= 17; i++){
		bl1[n][i] = a = max(a, bl1[bln[n][i-1]][i-1]);
	}

	for (auto [a, x, d, idx] : G[n]){
		if (!v[x] && pres[idx])
			build_bl1(x, n, d, G, pres);
	}
}

int query1(int a, int b){
	if (depth[a] < depth[b])
		swap(a, b);
	int ans = 0;
	while (depth[a] > depth[b]){
		int k = lg[depth[a] - depth[b]];
		ans = max(ans, bl1[a][k]);
		a = bln[a][k];
	}
	return ans;
}

long long int massimo_peso(int u, int v){
	int t = lca(u, v);

	return max(query1(u, t), query1(v, t));
}

int main(){

	int N, S;
	cin >> N >> S;

	vector<vector<edge>> G(S);
	int i = 0;
	vector<edge> edges(N);
	for (edge& x : edges){
		cin >> x.a >> x.b >> x.t;
		x.idx = i++;
		G[x.a].push_back((edge){x.a, x.b, x.t, x.idx});
		G[x.b].push_back((edge){x.b, x.a, x.t, x.idx});
	}
	vector<edge> V = edges;

	sort(V.begin(), V.end(), [](const edge& a, const edge& b){
		return a.t < b.t;
	});

	DSU dsu(S);
	long long mst = 0;
	vector<int> pres(N, 0);
	for (edge x : V){
		if (dsu.onion_set(x.a, x.b)){
			mst += x.t;
			pres[x.idx] = 1;
		}
	}

	lg.resize(3 * N + 1);
	lg[1] = 0;
	for (int i = 2; i <= 3 * N; i++)
		lg[i] = lg[i/2] + 1;

	depth.resize(S);
	wp.resize(S);
	tin.resize(S);
	tout.resize(S);
	timer = 0;
	bln.assign(S, vector<int>(18));
	bl1.assign(S, vector<int>(18));
	v.assign(S, 0);
	build_bln(0, 0, 0, 0, G, pres);
	v.assign(S, 0);
	build_bl1(0, 0, 0, G, pres);

	vector<long long> ans(N, 0);
	for (int i = 0; i < N; i++){
		if (pres[i]){
			ans[i] = mst;
		} else {
			int a = edges[i].a, b = edges[i].b;
			long long save = massimo_peso(a, b);
			ans[i] = mst + edges[i].t - save;
		}
	}

	for (long long x : ans)
		cout << x << '\n';

	return 0;
}