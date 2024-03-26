#include <iostream>
#include <vector>
using namespace std;

struct DSU{
	vector<long long> parent, sizes;
	DSU(int N){
		parent.assign(N+1, 0);
		for (int i = 0; i <= N; i++)
			parent[i] = i;
		sizes.assign(N+1, 1);
	}
	void make_set(int v){
		parent[v] = v;
		sizes[v] = 1;
	}
	int find_parent(int v){
		if (parent[v] == -1) return -1;
		if (parent[v] == v) return v;
		return parent[v] = find_parent(parent[v]);
	}
	int onion_set(int a, int b){
		a = find_parent(a);
		b = find_parent(b);
		if (a != b){
			if (sizes[a] < sizes[b])
				swap(a, b);
			parent[b] = a;
			sizes[a] += sizes[b];
			return 1;
		}
		return 0;
	}
};

void dfs(int u, long long v, vector<vector<pair<int, int>>>& G, vector<long long>& P, int p){
	P[u] = v;
	for (auto x : G[u])
		if (x.first != p)
			dfs(x.first, v + x.second, G, P, u);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	DSU dsu(N);
	vector<vector<pair<int, int>>> G(N);
	vector<long long> P(N, 0);
	int ans = 0;
	int a, b, z;
	for (int i = 0; i < M; i++){
		cin >> a >> b >> z;

		if (dsu.onion_set(a, b)){
			G[a].push_back({b, -z});
			G[b].push_back({a, z});
			if (dsu.sizes[a] < dsu.sizes[b])
				swap(a, b), z = -z;
			dfs(b, P[a] - z, G, P, a);
		} else {
			if (P[a] - P[b] != z)
				break;
		}
		ans++;
	}

	cout << ans << "\n";

	return 0;
}