#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct DSU{
	int N;
	vector<int> parent, sizes;
	DSU(int n){
		N = n+1;
		parent.assign(N, -1);
		sizes.assign(N, 1);
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
	int union_set(int a, int b){
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
	int a, b, c;
};

int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N, M;
	cin >> N >> M;

	vector<edge> edges(M);
	int a, b, c;
	for (int j = 0; j < M; j++){
		cin >> a >> b >> c;
		edges[j] = (edge){a, b, c};
	}

	sort(edges.begin(), edges.end(), [](edge a, edge b){
		return a.c < b.c;
	});
	
	DSU dsu(N);

	vector<pair<int, int>> edges_ans;
	long long ans = 0;
	for (edge e : edges){
		if (dsu.union_set(e.a, e.b)){
			ans += e.c;
			edges_ans.push_back({e.a, e.b});
		}
	}

	cout << ans << "\n";

	for (auto x : edges_ans)
		cout << x.first << " " << x.second << "\n";

	return 0;
}