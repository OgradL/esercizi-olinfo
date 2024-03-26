#include <iostream>
#include <vector>
#include <set>
using namespace std;

const long long INF = 1e18 + 42;

vector<set<pair<long long, long long>>> fruits;

void dfs(int n, vector<vector<int>>& G, vector<pair<long long, long long>>& F){

	for (int u : G[n]){
		dfs(u, G, F);
		if (fruits[n].size() < fruits[u].size()) swap(fruits[n], fruits[u]);
		for (auto x : fruits[u]) fruits[n].insert(x);
	}
	
	if (F[n].first != INF){
		long long sum = 0;
		set<pair<long long, long long>>::iterator it = fruits[n].end();
		for (auto i = fruits[n].begin(); i != fruits[n].end(); ++i){
			if (i->first > F[n].first){
				sum += i->second;
				if (it == fruits[n].end())
					it = i;
			}
		}
		if (sum < F[n].second){
			fruits[n].erase(it, fruits[n].end());
			fruits[n].insert(F[n]);
		}
	}
}

long long harvest(int n, int m, int k, vector<int>& p, vector<int>& v, vector<int>& d, vector<int>& w){

	vector<vector<int>> G(n);
	for (int i = 1; i < n; i++){
		G[p[i]].push_back(i);
	}

	fruits.resize(n);
	vector<pair<long long, long long>> F(n, {INF, INF});
	for (int i = 0; i < m; i++){
		F[v[i]] = {d[i], w[i]};
	}

	dfs(0, G, F);

	long long sum = 0;
	for (auto x : fruits[0]) sum += x.second;

	return sum;
}