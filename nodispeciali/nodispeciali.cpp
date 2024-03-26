#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <array>
using namespace std;

int is_filiale[1<<20];
array<long long, 2> dist1[1<<20];
long long dist2[1<<20];

array<long long, 2> dfs(int u, int p, vector<vector<array<int, 2>>>& G){
	array<long long, 2> ans = {0, 0};
	for (auto v : G[u]){
		if (v[0] != p){
			auto x = dfs(v[0], u, G);
			ans[0] += x[1] * v[1] + x[0];
			ans[1] += x[1];
		}
	}
	ans[1] += is_filiale[u];
	dist1[u] = ans;
	return ans;
}

void dfs2(int u, int p, array<long long, 2> to_p, vector<vector<array<int, 2>>>& G){
	dist2[u] = dist1[u][0] + to_p[0];
	for (auto v : G[u]){
		if (v[0] != p){
			dfs2(v[0], u, {dist2[u] - dist1[v[0]][0] - dist1[v[0]][1] * v[1] + (dist1[u][1] - dist1[v[0]][1] + to_p[1]) * v[1], dist1[u][1] - dist1[v[0]][1] + to_p[1]}, G);
		}
	}
}

int trova_sede(int N, int K, int A[], int B[], int P[], int filiali[]){
	for (int i = 0; i < K; i++) is_filiale[filiali[i]-1] = 1;

	vector<vector<array<int, 2>>> G(N);
	for (int i = 0; i < N-1; i++){
		--A[i], --B[i];
		G[A[i]].push_back({B[i], P[i]});
		G[B[i]].push_back({A[i], P[i]});
	}

	dfs(0, -1, G);
	dfs2(0, -1, {0, 0}, G);

	int ans = 0;
	for (int i = 0; i < N; i++){
		if (dist2[i] < dist2[ans])
			ans = i;
	}

	return ans + 1;
}