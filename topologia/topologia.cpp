#include <iostream>
#include <vector>
using namespace std;


std::vector<long long> parent, sizes;
void DSU(int N){
	parent.assign(N+1, -1);
	sizes.assign(N+1, -1);
}
void make_set(int v){
	if (parent[v] != -1) return;
	parent[v] = v;
	sizes[v] = 1;
}
int find_parent(int v){
	if (parent[v] == -1) make_set(v);
	if (parent[v] == v) return v;
	return parent[v] = find_parent(parent[v]);
}
int union_set(int a, int b){
	a = find_parent(a);
	b = find_parent(b);
	if (a != b){
		if (sizes[a] < sizes[b])
			std::swap(a, b);
		parent[b] = a;
		sizes[a] += sizes[b];
		return 1;
	}
	return 0;
}


void Analizza(int N, int M, int* A, int* B, int* T) {
	
	DSU(N);
	std::vector<std::vector<int>> G(N+1);
	for (int i = 0; i < M; i++){
		make_set(A[i]);
		make_set(B[i]);
		union_set(A[i], B[i]);
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	std::vector<std::vector<int>> groups(N+1);

	for (int i = 1; i <= N; i++){
		groups[find_parent(i)].push_back(i);
	}

	for (int i = 1; i <= N; i++){
		if (groups[i].size() != 0){
			
			int conn = 0, idx = groups[i][0];
			for (int p : groups[i]){
				conn += G[p].size();
				if (G[idx].size() < G[p].size())
					idx = p;
			}
			conn = conn / 2;
			int ok1 = 1;
			if (conn == groups[i].size()-1 && groups[i].size() >= 2) {
				for (int p : groups[i]){
					ok1 &= G[p].size() <= 2;
				}
				if (ok1){
					T[0]++;
					continue;
				}
			}
			int ok2 = 1;
			if (conn == groups[i].size() && groups[i].size() >= 3){
				for (int p : groups[i]){
					ok2 &= G[p].size() == 2;
				}
				if (ok2){
					T[1]++;
					continue;
				}
			}

			int err = 0;
			if (conn == groups[i].size() - 1 && groups[i].size() >= 4){
				for (int p : groups[i]){
					if (G[p].size() >= 2){
						err++;
					}
				}
				if (err == 1){
					T[2]++;
					continue;
				}
			}

		}
	}

}
