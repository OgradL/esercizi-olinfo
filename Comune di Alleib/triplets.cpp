#include <vector>
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

const static constexpr int MAX = numeric_limits<int>::max();
const static constexpr int MIN = numeric_limits<int>::min();

int maxi(vector<int>& v){
	int idx = 0;
	for (int i = 0; i < v.size(); i++){
		if (v[i] > v[idx]) idx = i;
	}
	return idx;
}

int maxi(vector<int>& v1, vector<int>& v2){
	int idx = 0;
	for (int i = 0; i < v1.size(); i++){
		if (v1[i] + v2[i] > v1[idx] + v2[idx]) idx = i;
	}
	return idx;
}

void bfs(int N, int p, vector<int>& dist, vector<vector<int>>& adj){
	queue<int> q;
	dist[p] = 0;
	q.push(p);

	while (!q.empty()){
		int n = q.front();
		q.pop();

		for (int x: adj[n]){
			if (dist[n] + 1 < dist[x]){
				dist[x] = dist[n] + 1;
				q.push(x);
			}
		}

	}
}

int build(int N, std::vector<int> A, std::vector<int> B) {
	vector<vector<int>> adj(N);
	for (int i = 0; i < N - 1; i++){
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
	}
	vector<int> dist1(N, MAX);
	bfs(N, 0, dist1, adj);
	int n1, n2, n3;
	n1 = maxi(dist1);

	vector<int> dist2(N, MAX);
	bfs(N, n1, dist2, adj);
	n2 = maxi(dist2);

	vector<int> dist3(N, MAX);
	bfs(N, n2, dist3, adj);
	n3 = maxi(dist2, dist3);
	
	// distanza n1-n2   +   n2-n3   +   n1-n3
	int ans = dist2[n2] + dist3[n3] + dist2[n3];

	return ans;
}
