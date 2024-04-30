#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node{
	int n, d, l, i;
};

int pianifica(int N, int L, vector<vector<int>> F){
	
	vector<vector<pair<int, int>>> G(N);
	vector<vector<int>> used(L);
	for (int i = 0; i < L; i++){
		used[i].assign(F[i].size(), 0);
		for (int j = 0; j < F[i].size()-1; j++){
			G[F[i][j]].push_back({i, j});
		}
	}
	
	deque<node> q;
	q.push_front(node{0, -1, -1, 0});
	
	vector<int> dist(N, 1e9);

	while (!q.empty()){
		node n = q.front();
		q.pop_front();
	
		if (n.n == N-1)
			break;

		if (dist[n.n] < n.d)
			continue;

		for (auto [l, idx] : G[n.n]){
			int cost = (l != n.l) || (idx != n.i);
			if (dist[F[l][idx+1]] >= (n.d + cost) && !used[l][idx]){
				used[l][idx] = 1;
				if (!cost)
					q.push_front(node{F[l][idx+1], n.d, l, idx+1});
				else
					q.push_back(node{F[l][idx+1], n.d + 1, l, idx+1});
				dist[F[l][idx+1]] = n.d + cost;
			}
		}
	}
	
	if (dist[N-1] == 1e9)
		dist[N-1] = -1;

	return dist[N-1];
}
