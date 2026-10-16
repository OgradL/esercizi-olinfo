#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <random>
using namespace std;

void intrappola(int X);

bool ispeziona(vector<int> V);

void acchiappa(int N, vector<int> U, vector<int> V) {

	vector<vector<int>> adj(N);
	for (int i = 0; i < N-1; i++){
		adj[U[i]].push_back(V[i]);
		adj[V[i]].push_back(U[i]);
	}

	vector<int> subtree(N, 0);

	function<void(int, int)> dfs = [&](int v, int p) {
		subtree[v] = 1;
		for (int x : adj[v]){
			if (x == p) continue;
			dfs(x, v);
			subtree[v] += subtree[x];
		}
	};

	function<int(int, int)> find_centroid = [&](int v, int p) {
		for (int x : adj[v]){
			if (x == p) continue;
			if (2*subtree[x] > N)
				return find_centroid(x, v);
		}
		return v;
	};

	dfs(0, -1);
	int root = find_centroid(0, -1);
	dfs(root, -1);

	vector<int> evens;

	function<void(int, int, int, int, vector<int>&)> fill = [&](int v, int p, int d, int all, vector<int>& vec) {
		if (d || all)
			vec.push_back(v);
		for (int x : adj[v]){
			if (x == p) continue;
			fill(x, v, d^1, all, vec);
		}
	};

	fill(root, -1, 1, 0, evens);

	if (!ispeziona(evens)){
		intrappola(root);
	}

	function<void(int, int)> cattura = [&](int v, int p) {
		vector<int> nxt;
		for (int x : adj[v]){
			if (x == p) continue;
			if (subtree[x] > 1)
				nxt.push_back(x);
		}

		if (nxt.empty()){
			intrappola(v);
			intrappola(v);
			return;
		}

		sort(nxt.begin(), nxt.end(), [&](int a, int b){
			return subtree[a] > subtree[b];
		});

		int lo = -1, hi = nxt.size()-1, mid;
		while (lo + 1 < hi){
			mid = (lo + hi) / 2;

			if (v == root && subtree[nxt[lo+1]] >= 4){
				mid = lo + 1;
			}

			vector<int> V;
			for (int i = 0; i <= mid; i++){
				fill(nxt[i], v, 0, 1, V);
			}

			if (ispeziona(V)){
				hi = mid;
			} else {
				lo = mid;
			}

			intrappola(v);
		}

		intrappola(nxt[hi]);
		cattura(nxt[hi], v);
	};

	cattura(root, -1);
}



// GRADER DI ESEMPIO
// NON MODIFICARE AL DI SOTTO DI QUESTA LINEA


#ifndef EVAL
namespace {
	vector<vector<int>> adj;
	int N, R, S;
	bool win;

	mt19937 rng;

	void build(vector<int> &U, vector<int> &V) {
		adj.resize(N);
		for(int i=0; i<N-1; i++) {
			adj[U[i]].push_back(V[i]);
			adj[V[i]].push_back(U[i]);
		}
	}

	void move() {
		S = adj[S].back();
		// S = adj[S][rng()%adj[S].size()];
	}

	void end() {
		if(win) cout << "Successful. " << R << " queries.\n";
		else cout << "Unsuccessful.\n";
		exit(0);
	}
}

void acchiappa(int N, vector<int> U, vector<int> V);

void intrappola(int X) {
	R++;

	win = (X == S);
	if(win) end();

	move();
}

bool ispeziona(vector<int> V) {
	R++;

	bool res = false;
	for(auto x:V) res |= (x == S);

	move();

	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> S;

	vector<int> U(N-1), V(N-1);

	for(int i=0; i<N-1; i++)
		cin >> U[i] >> V[i];

	build(U, V);

	R = 0;
	win = false;

	acchiappa(N, U, V);

	end();
}

#endif
