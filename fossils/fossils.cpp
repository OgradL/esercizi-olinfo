#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> adj1;
vector<vector<int>> adj2;
vector<int> sz, depth, head, par;
vector<int> pos;
vector<long long> nodes;
int n;
int curr_pos = 0;

int dfs(int v){
	sz[v] = 1;
	for (int x : adj2[v]){
		if (x == par[v]) continue;
		par[x] = v;
		depth[x] = depth[v] + 1;
		sz[v] += dfs(x);
	}
	sort(adj2[v].begin(), adj2[v].end(), [&](int i, int j){return sz[i] > sz[j];});
	return sz[v];
}

void decompose(int v, int h){
	pos[v] = curr_pos++;
	head[v] = h;
	bool found = false;
	for (int x : adj2[v]){
		if (x == par[v]) continue;
		if (!found){
			found = true;
			decompose(x, h);
		} else {
			decompose(x, x);
		}
	}
}

long long get_sum(int l, int r){
	long long ret = 0;
	l += n;
	r += n;
	for (; l < r; l >>= 1, r >>= 1){
		if (l & 1) ret += nodes[l++];
		if (r & 1) ret += nodes[--r];
	}
	return ret;
}

void add(int p, long long v){
	for (nodes[p += n] += v; p > 1; p >>= 1){
		nodes[p >> 1] = nodes[p] + nodes[p ^ 1];
	}
}

long long query(int b){
	int a = 0;
	long long res = 0;
	for (; head[a] != head[b]; b = par[head[b]]){
		if (depth[head[a]] > depth[head[b]])
			swap(a, b);
		res = res + get_sum(pos[head[b]], pos[b]+1);
	}
	if (depth[a] > depth[b])
		swap(a, b);
	res = res + get_sum(pos[a], pos[b]+1);
	return res;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	adj1.resize(N);
	int p;
	for (int i = 1; i < N; i++){
		cin >> p;
		adj1[i].push_back(p-1);
		adj1[p-1].push_back(i);
	}

	int M;
	cin >> M;

	adj2.resize(M);
	for (int i = 1; i < M; i++){
		cin >> p;
		adj2[i].push_back(p-1);
		adj2[p-1].push_back(i);
	}

	int K;
	cin >> K;

	vector<vector<pair<int, int>>> conn(N);
	int x, y, c;
	for (int i = 0; i < K; i++){
		cin >> x >> y >> c;
		--x, --y;
		conn[x].push_back({y, c});
	}

	int Q;
	cin >> Q;

	vector<vector<pair<int, int>>> queries(N);
	vector<long long> answer(Q);
	for (int i = 0; i < Q; i++){
		cin >> x >> y;
		--x, --y;
		queries[x].push_back({y, i});
	}

	head.resize(M);
	sz.resize(M);
	depth.resize(M);
	par.resize(M);
	pos.resize(M);
	n = M;
	nodes.assign(4*M, 0);

	dfs(0);
	decompose(0, 0);

	auto dfs2 = [&](auto&& dfs2, int v, int p) -> void {
		for (auto [x, c] : conn[v]){
			add(pos[x], c);
		}
		for (auto [y, i] : queries[v]){
			answer[i] = query(y);
		}
		for (int x : adj1[v]){
			if (x == p) continue;
			dfs2(dfs2, x, v);
		}
		for (auto [x, c] : conn[v]){
			add(pos[x], -c);
		}
	};

	dfs2(dfs2, 0, 0);

	for (long long x : answer){
		cout << x << "\n";
	}

	return 0;
}
