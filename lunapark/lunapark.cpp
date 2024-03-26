#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU{
	vector<int> parent, sizes;
	DSU(int n){
		parent.assign(n+1, -1);
		sizes.assign(n+1, -1);
	}
	void make_set(int v){
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
				swap(a, b);
			sizes[a] += sizes[b];
			parent[b] = a;
			return 1;
		}
		return 0;
	}
};

int progetta(int N, int M, int K, vector<int> &A, vector<int> &B, vector<int> &W){
	vector<int> edges(M);
	for (int i = 0; i < M; i++){
		edges[i] = i;
	}
	
	sort(edges.begin(), edges.end(), [&](int a, int b){
		return W[a] > W[b];
	});
	
	DSU dsu(N);
	int c = N, ans = 0;
	
	for (int i = 0; i < M && c > K; i++){
		if (dsu.union_set(A[edges[i]], B[edges[i]])){
			c--;
			ans += W[edges[i]];
		}
	}
	
	return ans;
}