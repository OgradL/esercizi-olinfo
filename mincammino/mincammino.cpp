#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int>& D){
		
	vector<vector<pair<int, int>>> G(N);
	
	for (int i = 0; i < M; i++){
	   // cout << X[i] << " " << Y[i] << " " << p[]
		G[X[i]].push_back({Y[i], P[i]});
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 0});
	
	vector<int> distances(N, INF);
	distances[0] = 0;
	int vert, d;
	pair<int, int> node;
	while (!pq.empty()){
		node = pq.top();
		pq.pop();
		d = node.first;
		vert = node.second;
		
		// cout << vert << " " << d << "\n";
		if (d > distances[vert])
			continue;
		
		for (int i = 0; i < G[vert].size(); i++){
			if (distances[G[vert][i].first] > d + G[vert][i].second){
				distances[G[vert][i].first] = d + G[vert][i].second;
				pq.push({d + G[vert][i].second, G[vert][i].first});
			}
		}
		
	}
	
	for (int i = 0; i < N; i++)
		D[i] = distances[i]==INF?-1:distances[i];

}