#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, E;
	cin >> N >> M >> E;

	vector<vector<int>> adj(N+M);
	vector<int> deg(N+M, 0), degbig(N+M, 0);
	int a, b;
	for (int i = 0; i < E; i++){
		cin >> a >> b;
		adj[a].push_back(b+N);
		adj[b+N].push_back(a);
		deg[a]++;
		deg[b+N]++;
	}

	for (int i = 0; i < N+M; i++){
		for (int x : adj[i])
			degbig[i] += deg[x] > 1;
		if (degbig[i] > 2){
			cout << "-1\n";
			return 0;
		}
	}

	vector<int> A, B, visited(N+M, 0);

	auto dfs = [&](auto&& dfs, int v, int p) -> void {
		visited[v] = 1;
		
		sort(adj[v].begin(), adj[v].end(), [&](int a, int b){
			return deg[a] < deg[b];
		});

		if (adj[v].empty())
			return;

		int last = adj[v][0];
		for (int x : adj[v]){
			if (x == p) continue;
			last = x;
			if (visited[x]){
				cout << "-1\n";
				exit(0);
			}
			visited[x] = 1;
			if (deg[x] <= 1){
				if (x >= N)
					B.push_back(x - N);
				else
					A.push_back(x);
			}
		}
		if (last != p && deg[last] > 1){
			
			if (last >= N)
				B.push_back(last - N);
			else
				A.push_back(last);
			dfs(dfs, last, v);
		}
	};

	for (int i = 0; i < N+M; i++){
		if (!visited[i] && degbig[i] == 1 && deg[i] >= 2){
			int node = i;
			if (deg[i] == 1)
				node = adj[i][0];
			if (node >= N)
				B.push_back(node - N);
			else
				A.push_back(node);

			dfs(dfs, node, node);
		}
	}

	for (int i = 0; i < N+M; i++){
		if (!visited[i] && degbig[i] == 0){
			int node = i;
			if (node >= N)
				B.push_back(node - N);
			else
				A.push_back(node);

			dfs(dfs, node, node);
		}
	}


	if (count(visited.begin(), visited.end(), 1) != N+M){
		cout << "-1\n";
		return 0;
	}

	for (int& x : A)
		cout << x << " ";
	cout << "\n";

	for (int& x : B)
		cout << x << " ";
	cout << "\n";

	return 0;
}
