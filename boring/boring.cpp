#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define MOD (long long)(1e9+7)
#define INF (long long)(1e18)
#define pairl pair<long long, long long>

long long fast_pow(long long b, long long e, long long m){
	if (e == 0) return 1;
	
	long long v = fast_pow(b, e/2, m);
	v = v * v; v = v % m;
	if (e%2) v *= b;
	return v % m;
}

pairl mmax(pairl& a, pairl& b){
	if (a.first == 0) return b;
	if (b.first == 0) return a;

	

	return {INF, INF};
}

pairl mmin(pairl& a, pairl& b){
	if (a == mmax(a, b))
		return b;
	return a;
}


struct Node{
	pairl m = {0, 0};
	pairl lazy = {0, 0};
	Node(){};
	Node(pairl m): m(m){};
	void merge(Node& a, Node& b){
		m = mmax(a.m, b.m);
	}
};

struct ST{

	int n, real_size;
	vector<Node> nodes;

	ST(){

	}
	
	ST(vector<int>& V){
		n = V.size();

		real_size = 1;
		while (real_size < n)
			real_size *= 2;
		
		nodes.assign(2 * real_size, Node());

		build(1, 0, real_size, V);
	}

	void build(int u, int l, int r, vector<int>& V){
		if (r - l == 1){
			if (l < n)
				nodes[u] = Node({V[l], 0});
			else
				nodes[u] = Node({0, 0});
			return;
		}
		build(u * 2, l, (l+r)/2, V);
		build(u*2+1, (l+r)/2, r, V);
		nodes[u].merge(nodes[u+2], nodes[u*2+1]);
	}

	void fix_lazy(int u, int l, int r){
		
		if (nodes[u].lazy == make_pair(0LL, 0LL))
			return;
		
		if (r - l == 1){
			nodes[u].m = mmax(nodes[u].m, nodes[u].lazy);
			nodes[u].lazy = {0, 0};
		} else {
			nodes[u].m = mmax(nodes[u].m, nodes[u].lazy);

			nodes[u * 2].lazy = mmax(nodes[u * 2].lazy, nodes[u].lazy);
			nodes[u*2+1].lazy = mmax(nodes[u*2+1].lazy, nodes[u].lazy);

			nodes[u].lazy = {0, 0};
		}

	}

	void set_range(int u, int l, int r, int x, int y, pairl& val){
		fix_lazy(u, l, r);
		if (r <= x || y <= l) return;

		if (x <= l && r <= y) {
			nodes[u].lazy = val;
			return;
		}

		set_range(u * 2, l, (l+r)/2, x, y, val);
		set_range(u*2+1, (l+r)/2, r, x, y, val);
		nodes[u].merge(nodes[u*2+1], nodes[u*2]);
	}

	void set_range(int x, int y, pairl& val){
		set_range(1, 0, real_size, x, y, val);
	}


	long long get_pos(int x){
		int u = 1, l = 0, r = real_size;
		while (l < r - 1){
			fix_lazy(u, l, r);
			if (x < (l+r)/2){
				r = (l+r)/2;
				u = u*2;
			} else {
				l = (l+r)/2;
				u = u*2+1;
			}
		}
		long long ans = nodes[u].m.first * fast_pow(x+1, nodes[u].m.second, MOD);
		return ans % MOD;
	}

};

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N, Q;
	cin >> N;
	
	vector<pairl> A(N+1, {0, 0});
	
	for (int i = 1; i <= N; i++) {
		cin >> A[i].first;
	}

	cin >> Q;
	while (Q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;

			long long ans = A[x].first * fast_pow(x, A[x].second, MOD);

			cout << ans % MOD << endl;
		} else {
			int x, y, b, c;
			cin >> x >> y >> b >> c;
			for (int j = x; j <= y; j++) {
				if (c - A[j].second >= 30){
					A[j] = {b, c};
				} else if (A[j].first < fast_pow(j, c - A[j].second, INF) * b) A[j] = {b, c};
			}
		}
	}

	return 0;
}