#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> dijkstra(int node, vector<pair<int, int>> *G){
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, node});
	vector<int> d(2001, 1e9);
	d[node] = 0;

	pair<int, int> n, ans;
	while (!pq.empty()){
		n = pq.top();
		pq.pop();
		
		if (n.first > d[n.second])
			continue;
		
		ans = n;
		
		for (auto p : G[n.second]){
			if (n.first + p.second < d[p.first]){
				pq.push({n.first + p.second, p.first});
				d[p.first] = n.first + p.second;
			}
		}
	}
	
	return {ans.second, ans.first};
}

int latenza(int N, int M, int A[], int B[], int L[]) {
	
	vector<pair<int, int>> G[2001];
	
	for (int i = 0; i < M; i++){
		
		G[A[i]].push_back({B[i], L[i]});
		G[B[i]].push_back({A[i], L[i]});
	}
	
	int ans = 0;
	for (int i = 0; i < N; i++){
		ans = max(ans, dijkstra(i, G).second);
	}
	
	return ans;
}