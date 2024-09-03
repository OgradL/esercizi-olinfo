#include <vector>
#include <algorithm>

using namespace std;

struct seg{
	long long v[2][2];

	seg(){
		*this = seg(0, 0, 0);
	}

	seg(long long a, long long b, long long c){
		v[0][0] = a;
		v[0][1] = b + c;
		v[1][0] = a;
		v[1][1] = c;
	}

	long long get(){
		return min({v[0][0], v[0][1]});
	}
};

seg merge(const seg& a, const seg& b){
	if (a.v[0][0] == 0)
		return b;
	if (b.v[0][0] == 0)
		return a;
	seg ans;
	for (int i = 0; i < 4; i++){
		int i0 = i & 1;
		int i1 = i / 2;
		ans.v[i0][i1] = min(a.v[i0][0] + b.v[0][i1], a.v[i0][1] + b.v[1][i1]);
	}
	return ans;
}

int t = 0;
vector<int> tin, tout;
vector<int> depth;
vector<vector<int>> up;
vector<vector<seg>> b1, b2;
vector<vector<int>> adj;
vector<int> A, B;
int C;

void dfs(int v, int p = 0, int d = 0){
	depth[v] = d;
	tin[v] = t++;
	up[v][0] = p;
	b1[v][0] = seg(A[v], B[v], C);
	b2[v][0] = seg(A[p], B[p], C);
	for (int i = 1; i < 19; i++){
		up[v][i] = up[up[v][i-1]][i-1];
		b1[v][i] = merge(b1[v][i-1], b1[up[v][i-1]][i-1]);
		b2[v][i] = merge(b2[up[v][i-1]][i-1], b2[v][i-1]);
	}

	for (int x : adj[v]){
		if (x == p) continue;
		dfs(x, v, d+1);
	}
	tout[v] = t;
}

int is_ancestor(int a, int b){
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int X, int Y){
	if (is_ancestor(X, Y))
		return X;
	if (is_ancestor(Y, X))
		return Y;
	int res = X;
	for (int i = 18; i >= 0; i--){
		if (!is_ancestor(up[res][i], Y))
			res = up[res][i];
	}
	return up[res][0];
}

seg query1(int a, int b){
	seg res;
	if (a == b)
		return res;
	int x = a;
	for (int i = 18; i >= 0; i--){
		if (!is_ancestor(up[x][i], b)){
			res = merge(res, b1[x][i]);
			x = up[x][i];
		}
	}

	res = merge(res, b1[x][0]);

	return res;
}

seg query2(int a, int b){
	seg res;
	if (a == b)
		return res;
	int x = a;
	for (int i = 18; i >= 0; i--){
		if (!is_ancestor(up[x][i], b)){
			res = merge(b2[x][i], res);
			x = up[x][i];
		}
	}

	res = merge(b2[x][0], res);

	return res;
}

void init(int N, int C, vector<int> A, vector<int> B, vector<int> U, vector<int> V){
	::A = A;
	::B = B;
	::C = C;

	adj.resize(N);
	for (int i = 0; i < N-1; i++){
		adj[U[i]].push_back(V[i]);
		adj[V[i]].push_back(U[i]);
	}

	depth.resize(N);
	tin.resize(N);
	tout.resize(N);
	up.assign(N, vector<int>(19));
	b1.assign(N, vector<seg>(19));
	b2.assign(N, vector<seg>(19));

	dfs(0);
}


long long query(int X, int Y){

	int v = lca(X, Y);
	seg s1 = query1(X, v);
	seg s2 = query2(Y, v);

	seg ans = merge(s1, s2);

	return ans.get();
}
