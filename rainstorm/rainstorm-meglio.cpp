#include <bits/stdc++.h>

using namespace std;

int dfs(int n, vector<int>& visited, vector<vector<pair<int, int>>>& G, int val){
	if (visited[n]) return 0;
	visited[n] = 1;
	int r = 1;
	for (pair<int, int> p : G[n])
		if (p.second >= val)
			r += dfs(p.first, visited, G, val);
	return r;
}

int bfs(int n, vector<int>& visited, vector<vector<pair<int, int>>>& G, int val){

	queue<int> q;
	q.push(0);

	int count = 0;
	int nodo;
	while (!q.empty()){
		nodo = q.front();
		q.pop();

		count++;

		for (pair<int, int> p : G[nodo])
			if (p.second >= val && !visited[p.first]){
				visited[p.first] = 1;
				q.push(p.first);
			}
	}

	return count;
}

int main(){
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	cin.tie(0);
	cin.sync_with_stdio(false);

	int N, M;
	
	cin >> N >> M;
	
	vector<int> A(M), B(M), R(M);
	
	vector<vector<pair<int, int>>> G(N);
	
	for (int i = 0; i < M; i++){
		cin >> A[i] >> B[i] >> R[i];
		G[A[i]].push_back(make_pair(B[i], R[i]));
		G[B[i]].push_back(make_pair(A[i], R[i]));
	}

	vector<int> visited(N, 0);
	int lo = 0, hi = 1e6+10, mid;
	while (lo + 1 < hi){
		mid = (lo+hi)/2;

		visited.assign(N, 0);
		if (bfs(0, visited, G, mid) == N)
			lo = mid;
		else
			hi = mid;
	}
	
	cout << lo << "\n";

	return 0;
}
