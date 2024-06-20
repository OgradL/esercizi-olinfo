#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

long long edmonds_karp(int N, int M, int source, int sink, vector<vector<int>>& adj, unordered_map<int, unordered_map<int, long long>>& capacity){
	
	vector<int> parent(N, -1);

	auto reachable = [&](){
		fill(parent.begin(), parent.end(), -1);
		queue<int> q;
		q.push(source);
		while (!q.empty()){
			int node = q.front();
			q.pop();
			for (int x : adj[node]){
				long long w = capacity[node][x];
				if (w <= 0 || parent[x] != -1) continue;
				q.push(x);
				parent[x] = node;
			}
		}
		return parent[sink] != -1;
	};

	long long flow = 0, curr_flow = 0;
	
	while (reachable()){
		curr_flow = 1e18;

		int node = sink;
		while (node != source){
			curr_flow = min(curr_flow, capacity[parent[node]][node]);
			node = parent[node];
		}
		node = sink;
		while (node != source){
			capacity[parent[node]][node] -= curr_flow;
			capacity[node][parent[node]] += curr_flow;

			node = parent[node];
		}
		flow += curr_flow;
	}

	return flow;
}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int M = 2*N+2;
	vector<vector<int>> adj(M);
	unordered_map<int, unordered_map<int, long long>> capacity;

	auto add_edge = [&](int a, int b, long long w){
		adj[a].push_back(b);
		adj[b].push_back(a);
		capacity[a][b] += w;
	};

	int a, b;
	for (int i = 0; i < N; i++){
		add_edge(0, i+1, 1);
		add_edge(i+1+N, 2*N+1, 1);

		cin >> a >> b;
		add_edge(a, b+N, 1e9);
	}

	cout << edmonds_karp(M, M, 0, 2*N+1, adj, capacity) << "\n";

	return 0;
}
