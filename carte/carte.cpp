#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int gioca(int N, int K, vector<vector<int>> M){
	
	vector<int> ind(N, 0);
	int ans = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int ma = 0;

	for (int i = 0; i < N; i++)
		pq.push({M[i][0], i});

	while (!pq.empty()){
		auto [x, i] = pq.top();
		pq.pop();

		ind[i]++;

		if (x > ma){
			ans++;
			ma = x;
		}

		if (ind[i] < K){
			pq.push({M[i][ind[i]], i});
		}
	}

	return ans;
}