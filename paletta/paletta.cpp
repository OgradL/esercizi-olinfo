#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree {
	vector<long long> fen;
	int n;

	FenwickTree() {
		n = 1;
	}

	FenwickTree(int N) {
		n = N + 1;
		fen.assign(n, 0);
	}

	FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
		for (int i = 0; i < a.size(); i++)
			add(i, a[i]);
	}

	long long sum(int idx) {
		int ret = 0;
		for (++idx; idx > 0; idx -= idx & -idx){
			ret += fen[idx];
		}
		return ret;
	}

	long long sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	void add(int idx, int delta) {
		for (++idx; idx < n; idx += idx & -idx){
			fen[idx] += delta;
		}
	}

	void clear(){
		fen.assign(n+1, 0);
	}
};

long long paletta_sort(int N, int V[]){

	for (int i = 0; i < N; i++) {
		if ((V[i] % 2) != (i % 2)) return -1;
	}

	long long ans = 0;

	FenwickTree trees[2];
	trees[0] = FenwickTree(N);
	trees[1] = FenwickTree(N);

	for (int i = N-1; i >= 0; i--){
		ans += trees[i%2].sum(V[i]);
		trees[i%2].add(V[i], 1);
	}

	return ans;
}