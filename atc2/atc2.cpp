#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

#define f first
#define s second

vector<pair<int, int>> to;

struct comp{
	const bool operator() (const pair<int, int> a, const pair<int, int> b) const {
		return (to[a.f].f-to[a.s].f)*(to[a.f].f-to[a.s].f) + (to[a.f].s-to[a.s].s)*(to[a.f].s-to[a.s].s) < 
			(to[b.f].f-to[b.s].f)*(to[b.f].f-to[b.s].f) + (to[b.f].s-to[b.s].s)*(to[b.f].s-to[b.s].s);
	}
};

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

int main(){

	int N;
	cin >> N;

	string s;
	for (int j = 0; j < N; j++){
		cin >> s;
		for (int i = 0; i < N; i++){
			if (s[i] == 'T') to.emplace_back(i, j);
		}
	}

	set<pair<int, int>, comp> edges;
	int k = 0;
	for (int i = 0; i < to.size(); i++){
		for (int j = i + 1; j < to.size(); j++){
			edges.insert({i, j});
			if (edges.size() > to.size() * 300)
				edges.erase(prev(edges.end()));
		}
	}

	DSU dsu(to.size());

	long long ans = 0;
	for (pair<int, int> e : edges){
		if (dsu.union_set(e.f, e.s)){
			ans += (to[e.f].f-to[e.s].f)*(to[e.f].f-to[e.s].f) + (to[e.f].s-to[e.s].s)*(to[e.f].s-to[e.s].s);
		}
	}

	cout << ans << "\n";

	return 0;
}