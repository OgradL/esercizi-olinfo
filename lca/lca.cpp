#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100001

struct seg{
	long long mal, mar, mam, sum;
	seg() {mal = mar = mam = sum = 0;};
	seg(long long v){sum = v; mal = max(v, 0LL); mar = max(v, 0LL); mam = max(v, 0LL);};
	void merge(const seg a, const seg b){
		sum = a.sum + b.sum;
		mal = max({a.mal, a.sum + b.mal, 0LL});
		mar = max({a.mar + b.sum, b.mar, 0LL});
		mam = max({a.mar + b.mal, a.sum, a.mal, a.mar, a.mam, b.sum, b.mal, b.mar, b.mam, mal, mar, sum, 0LL});
	}
	seg rev(){
		swap(mal, mar);
		return *this;
	}
};

int tour[3 * MAXN];
long long height[MAXN];
long long wheight[MAXN];
int fo[MAXN];
int st[20][3 * MAXN];
int v[MAXN];
int lg[3 * MAXN + 1];
int eut = 0;
int bl1[MAXN][18];
seg bl2[MAXN][18];
int bln[MAXN][18];

void euler_tour(int n, int h, long long wh, vector<vector<pair<int, int>>>& G){
	v[n] = 1;

	fo[n] = eut;
	height[n] = h;
	wheight[n] = wh;
	tour[eut] = n;
	eut++;

	for (auto [x, d] : G[n]){
		if (!v[x])
			euler_tour(x, h + 1, wh + d, G);
		tour[eut++] = n;
	}
}

void build_st(int N){
	N = eut;
	for (int i = 0; i < N; i++){
		st[0][i] = tour[i];
	}
	for (int i = 1; i <= 19; i++){
		for (int j = 0; j + (1 << i) <= N; j++){
			if (height[st[i-1][j]] < height[st[i-1][j + (1 << (i-1))]])
				st[i][j] = st[i-1][j];
			else
				st[i][j] = st[i-1][j + (1 << (i-1))];
		}
	}
}

int lca(int a, int b){
	if (a == b)
		return a;
	if (fo[a] > fo[b])
		swap(a, b);
	int i = lg[fo[b] - fo[a] + 1];
	int ans = (height[st[i][fo[a]]] < height[st[i][fo[b] - (1 << i) + 1]]) ? st[i][fo[a]] : (st[i][fo[b] - (1 << i) + 1]);
	return ans;
}

void build_bln(int n, int u, vector<vector<pair<int, int>>>& G){
	v[n] = 1;
	bln[n][0] = u;
	for (int i = 1; i <= 17; i++){
		bln[n][i] = bln[bln[n][i-1]][i-1];
	}

	for (auto [x, w] : G[n]){
		if (!v[x])
			build_bln(x, n, G);
	}
}

void build_bl1(int n, int u, int w, vector<vector<pair<int, int>>>& G){
	v[n] = 1;
	int a = w;
	bl1[n][0] = a;
	for (int i = 1; i <= 17; i++){
		bl1[n][i] = a = min(a, bl1[bln[n][i-1]][i-1]);
	}

	for (auto [x, d] : G[n]){
		if (!v[x])
			build_bl1(x, n, d, G);
	}
}

int query1(int a, int b){
	if (height[a] < height[b])
		swap(a, b);
	int ans = 1e9;
	while (height[a] > height[b]){
		int k = lg[height[a] - height[b]];
		ans = min(ans, bl1[a][k]);
		a = bln[a][k];
	}
	return ans;
}

void build_bl2(int n, int u, int w, vector<vector<pair<int, int>>>& G){
	v[n] = 1;
	seg a(w);
	bl2[n][0] = a;
	for (int i = 1; i <= 17; i++){
		a.merge(a, bl2[bln[n][i-1]][i-1]);
		bl2[n][i] = a;
	}

	for (auto [x, d] : G[n]){
		if (!v[x])
			build_bl2(x, n, d, G);
	}
}

seg query2(int a, int b){
	if (height[a] < height[b])
		swap(a, b);
	seg ans;
	while (height[a] > height[b]){
		int k = lg[height[a] - height[b]];
		ans.merge(ans, bl2[a][k]);
		a = bln[a][k];
	}
	return ans;
}

void inizia(int N, int T, int A[], int B[], int C[]){
	vector<vector<pair<int, int>>> G(N);
	for (int i = 0; i < N-1; i++){
		G[A[i]].push_back({B[i], C[i]});
		G[B[i]].push_back({A[i], C[i]});
	}
	lg[1] = 0;
	for (int i = 2; i <= 3 * MAXN; i++)
		lg[i] = lg[i/2] + 1;
	
	for (int i = 0; i < MAXN; i++) v[i] = 0;
	euler_tour(0, 0, 0, G);
	build_st(N);

	for (int i = 0; i < MAXN; i++) v[i] = 0;
	build_bln(0, 0, G);

	for (int i = 0; i < MAXN; i++) v[i] = 0;
	build_bl1(0, 0, 0, G);

	for (int i = 0; i < MAXN; i++) v[i] = 0;
	build_bl2(0, 0, 0, G);
}

long long int distanza1(int u, int v){
	int t = lca(u, v);
	return height[u] + height[v] - 2 * height[t];
}

long long int distanza2(int u, int v){
	int t = lca(u, v);
	return wheight[u] + wheight[v] - 2 * wheight[t];
}

long long int minimo(int u, int v){
	int t = lca(u, v);

	return min(query1(u, t), query1(v, t));
}

long long int massimo(int u, int v){
	int t = lca(u, v);

	seg info;

	info.merge(
		query2(u, t),
		query2(v, t).rev()
	);

	long long ans = max({info.mal, info.mam, info.mar, info.sum});

	return ans;
}
