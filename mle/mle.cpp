#include <iostream>
#include <vector>
using namespace std;


vector<long long> parent, sizes;
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
			swap(a, b);
		parent[b] = a;
		sizes[a] += sizes[b];
		return 1;
	}
	return 0;
}


void Colora(int N, int Q, vector <int> &A, vector <int> &B, vector <int> &C, vector <int> &murale) {
	DSU(N);

	murale.assign(N, 0);

	for (int q = Q - 1; q >= 0; q--) {
		int j = find_parent(A[q]);
		for (; j <= B[q];) {
			murale[j] = C[q];
			parent[j] = j + 1;
			j = find_parent(j);
		}
	}
}