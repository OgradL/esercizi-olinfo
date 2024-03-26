#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long smaltisci(int N, int M, vector<int> A, vector<vector<int>> B){

	vector<vector<pair<int, int>>> G(N);
	for (int i = 0; i < M; i++){
		for (int x : B[i]){
			G[x].push_back({A[i], i});
		}
	}

	vector<pair<int, long long>> dep(M, {0, 0});
	vector<long long> cost(N, 1e18);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	for (int i = 0; i < M; i++){
		dep[i].first = B[i].size();
		if (B[i].size() == 0 && cost[A[i]]){
			cost[A[i]] = 1;
			pq.push({1, A[i]});
		}
	}

	while (!pq.empty()){
		auto [d, n] = pq.top();
		pq.pop();

		if (cost[n] < d)
			continue;

		for (auto [x, idx] : G[n]){
			dep[idx].first--;
			dep[idx].second += cost[n];
			if (!dep[idx].first && dep[idx].second + 1 < cost[x]){
				cost[x] = dep[idx].second + 1;
				pq.push({cost[x], x});
			}
		}
	}

	return cost[0];
}
