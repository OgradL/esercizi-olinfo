#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> nodes;
int real_size = 1;
void add(int u, int d){
	u += real_size;
	nodes[u] += d;
	while (u > 1){
		u /= 2;
		nodes[u] = nodes[2*u] + nodes[2*u+1];
	}
}

int nth_elem(int x){
	x++;
	int idx = 0;
	int size = real_size;
	int u = 1;
	while (u < real_size){
		if (nodes[2*u] < x){
			x -= nodes[2*u];
			idx += size / 2;
			u = 2 * u + 1;
		} else {
			u = 2 * u;
		}
		size /= 2;
	}
	return idx;
}

const int INF = 1e9+42;
vector<vector<int>> G;
vector<int> sort_dolcezza, comp_dolcezza;
int dfs(int u, vector<int>& C, int p = 0, int minmax = 0){

	add(comp_dolcezza[u], 1);
	
	if (G[u].size() == 1){
		int ans = sort_dolcezza[nth_elem(C[u])];
		add(comp_dolcezza[u], -1);
		return ans;
	}

	int best = INF * minmax;
	for (int x : G[u]){
		if (x == p) continue;
		int v = dfs(x, C, u, !minmax);
		if (minmax){
			best = min(best, v);
		} else {
			best = max(best, v);
		}
	}

	add(comp_dolcezza[u], -1);

	return best;
}

int visita(int N, vector<int> &A, vector<int> &B, vector<int> &dolcezza, vector<int> &C) {

	real_size = 1LL<<(int)ceil(log2(N));
	nodes.assign(2*real_size, 0);

	G.resize(N);
	for (int i = 0; i < N-1; i++){
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	sort_dolcezza = dolcezza;
	sort(sort_dolcezza.begin(), sort_dolcezza.end());
	comp_dolcezza = dolcezza;
	for (int& x : comp_dolcezza)
		x = lower_bound(sort_dolcezza.begin(), sort_dolcezza.end(), x) - sort_dolcezza.begin();

	int ans = dfs(0, C);

	return ans;
}

int main(){
	int N;
	cin >> N;
	vector<int> dolcezza(N), C(N), A(N - 1), B(N - 1);
	for (int i = 0; i < N; i++) {
		cin >> dolcezza[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> A[i] >> B[i];
	}
	cout << visita(N, A, B, dolcezza, C) << endl;
	return 0;
}