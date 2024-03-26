#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int Analizza(int N, int M, int W, int L, int arco_da[], int arco_a[], int capacita[], int R, int C){
	vector<vector<pair<int, int>>> G(N+1);
	for (int i = 0; i < M; i++){
		G[arco_da[i]].push_back({arco_a[i], capacita[i]});
		G[arco_a[i]].push_back({arco_da[i], capacita[i]});
	}
	
	queue<pair<int, pair<int, int>>> q;
	q.push({W, {1e9, 0}});
	vector<pair<int, int>> d(N+1, {1e9, 1e9});
	pair<int, pair<int, int>> n;
	int l = 1e9;
	while (!q.empty()){
		n = q.front();
		q.pop();
		
		if (n.first == L) l = n.second.second;
		if (n.second.second > l) break;
		
		for (auto p : G[n.first]){
			if (min(n.second.first, p.second) < d[p.first].first && n.second.second+1 <= d[p.first].second){
				d[p.first].first = min(n.second.first, p.second);
				d[p.first].second = n.second.second + 1;
				q.push({p.first, {min(n.second.first, p.second), d[p.first].second}});
			}
		}
	}
	
	return d[L].first;
}