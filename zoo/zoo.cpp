#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int s, vector<vector<int>>& adj, vector<int>& dist, vector<int>& count){
	queue<int> q;

	q.push(s);
	dist[s] = 0;

	while (!q.empty()){
		int v = q.front();
		q.pop();

		count[dist[v]]++;

		for (int x : adj[v]){
			if (dist[x] > dist[v] + 1){
				dist[x] = dist[v] + 1;
				q.push(x);
			}
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, M;
	cin >> N >> M;

	vector<vector<int>> adj(N);
	int a, b;
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> dist0(N, 1e9), distN(N, 1e9), count0(N, 0), count1(N, 0);

	bfs(0, adj, dist0, count0);
	bfs(N-1, adj, distN, count1);

	for (int i = 1; i < N; i++){
		count0[i] += count0[i-1];
		count1[i] += count1[i-1];
	}

	// dist0[a] + 1 + distN[b] <= dist0[N-1]
	
	long long ans = 0;

	for (int i = 0; i < N; i++){
		if (dist0[N-1] - 2 - dist0[i] >= 0)
			ans += count1[dist0[N-1] - 2 - dist0[i]];
	}

	cout << N*(N-1)/2 - ans - M << "\n";

	return 0;
}
