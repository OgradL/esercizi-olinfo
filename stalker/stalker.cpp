#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

struct Node{
	long long mi;
	Node(){}
	Node(long long x) : mi(x) {}
	void merge(const Node& a, const Node& b){
		mi = min(a.mi, b.mi);
	}
};

struct ST{
	int n;
	int real_size;
	vector<Node> nodes;

	ST(int N){
		n = N;
		real_size = 1LL<<(int)ceil(log2(n));
		nodes.assign(2 * real_size, Node(1e18));
	}

	ST(vector<long long>& V){

		n = V.size();
		real_size = 1LL<<(int)ceil(log2(n));
		nodes.assign(2 * real_size, Node());

		build(1, 0, n, V);
	}

	void build(int u, int l, int r, vector<long long>& V){
		if (r - l == 1){
			nodes[u] = Node(l < n ? V[l] : 1e18);
			return;
		}

		build(2 * u, l, (l+r)/2, V);
		build(2*u+1, (l+r)/2, r, V);
		nodes[u].merge(nodes[u*2], nodes[u*2+1]);
	}

	void update(int u, long long d){
		u += real_size;
		nodes[u] = min(nodes[u].mi, d);
		while (u > 1){
			u /= 2;
			nodes[u].merge(nodes[u*2], nodes[u*2+1]);
		}
	}

	long long get_min(int u, int l, int r, int x, int y){
		if (r <= x || y <= l) return 1e18;
		if (x <= l && r <= y) return nodes[u].mi;
		return min(
			get_min(u * 2, l, (l+r)/2, x, y),
			get_min(u*2+1, (l+r)/2, r, x, y)
		);
	}

	long long get_min(int l, int r){
		return get_min(1, 0, real_size, l, r);
	}
};

int check(long long diffidenza, vector<long long>& pref, int N, int K){
	vector<long long> compr;
	for (int i = 0; i <= N; i++){
		compr.push_back(pref[i]);
		compr.push_back(pref[i] + diffidenza);
	}
	vector<long long> values = compr;
	sort(compr.begin(), compr.end());

	for (long long& x : values){
		x = lower_bound(compr.begin(), compr.end(), x) - compr.begin();
	}

	int n = compr.size();
	ST segtree(n);

	segtree.update(values[2*N], 0);
	
	for (int i = N; i >= 0; i--){
		long long v = segtree.get_min(0, values[2*i+1]+1);
		segtree.update(values[2*i], v+1);
	}

	return segtree.get_min(values[0], values[0]+1) <= K;
}

long long stalkera(int N, int K, vector<int> S){

	vector<long long> pref(N+1);
	pref[0] = 0;
	for (int i = 0; i < N; i++)
		pref[i+1] = pref[i] + S[i];

	long long sum = 0;
	for (int i = 0; i < N; i++)
		sum += S[i];

	long long lo = sum < 0 ? sum-1 : 0,
			  hi = sum >= 0 ? sum : 0,
			  mid;
	
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;
		if (check(mid, pref, N, K))
			hi = mid;
		else
			lo = mid;
	}

	return hi;
}
