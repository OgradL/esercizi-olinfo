#include <iostream>
#include <vector>
using namespace std;

vector<int> G[200001];
int subtree[200001], maxi[200001], maxi2[200001], ans[200001];

void new_max(int& m1, int& m2, int v){
	if (v > m1){
		m2 = m1;
		m1 = v;
	} else if (v > m2){
		m2 = v;
	}
}

void dfs1(int u, int p = -1){
	subtree[u] = maxi[u] = maxi2[u] = 0;
	for (auto v : G[u]){
		if (v == p) continue;
		dfs1(v, u);
		new_max(maxi[u], maxi2[u], subtree[v]);
		subtree[u] += subtree[v];
	}
	subtree[u] += 1 - maxi[u];
}

void dfs2(int u, int p = -1, int to_p = 0){
	subtree[u] += maxi[u] + to_p;
	ans[u] = subtree[u] - to_p;
	new_max(maxi[u], maxi2[u], to_p);
	for (auto v : G[u]){
		if (v == p) continue;
		ans[u] = min(ans[u], subtree[u] - subtree[v]);
		dfs2(v, u, subtree[u] - subtree[v] - maxi[u] - maxi2[u] + max(maxi2[u], subtree[v]));
	}
}


int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs1(0);
	dfs2(0);

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << "\n";

	return 0;
}