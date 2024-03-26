#include <iostream>
#include <vector>
using namespace std;

#define MAXN 100001

int tour[3 * MAXN];
int height[MAXN];
int fo[MAXN];
int st[20][3 * MAXN];
int v[MAXN];
int lg[3 * MAXN + 1];
int eut = 0;
int bl[MAXN][18];
int bln[MAXN][18];
int briganti[MAXN];

void euler_tour(int n, int h, vector<vector<int>>& G){
	v[n] = 1;

	fo[n] = eut;
	height[n] = h;
	tour[eut] = n;
	eut++;

	for (auto x : G[n]){
		if (!v[x])
			euler_tour(x, h + 1, G);
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

void build_bl(int n, int u, vector<vector<int>>& G, vector<int>& v){
	v[n] = 1;
	int a = briganti[n];
	bl[n][0] = a;
	bln[n][0] = u;
	// cerr << "bl: " << n << "\n";
	for (int i = 1; i <= 17; i++){
		bln[n][i] = bln[bln[n][i-1]][i-1];
		bl[n][i] = a = max(a, bl[bln[n][i-1]][i-1]);
		// cerr << "step: " << bln[n][i] << " " << bl[n][i] << "\n";
	}

	for (int x : G[n]){
		if (!v[x])
			build_bl(x, n, G, v);
	}
}

int query(int a, int b){
	if (height[a] < height[b])
		swap(a, b);
	// cerr << "query: " << a << " " << b << "\n";
	int ans = bl[a][0];
	while (height[a] > height[b]){
		int k = lg[height[a] - height[b]];
		ans = max(ans, bl[a][k]);
		// cerr << "step: " << a << " " << b << " = " << bl[a][k] << "\n";
		a = bln[a][k];
	}
	ans = max(ans, bl[b][0]);
	return ans;
}

void solve(int N, int Q, int *briganti, int *A, int *B, int *start, int *end, int *sol){
	
	for (int i = 0; i < N; i++){
		::briganti[i] = briganti[i];
	}

	vector<vector<int>> G(N);
	for (int i = 0; i < N-1; i++){
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	lg[1] = 0;
	for (int i = 2; i <= 3 * MAXN; i++)
		lg[i] = lg[i/2] + 1;

	euler_tour(0, 0, G);
	build_st(N);

	vector<int> v(N, 0);
	build_bl(0, 0, G, v);

	int a, b, u;
	for (int i = 0; i < Q; i++){
		a = start[i];
		b = end[i];
		u = lca(a, b);

		sol[i] = max(query(a, u), query(b, u));
	}
}