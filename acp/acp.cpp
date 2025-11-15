#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

long long POW(long long b, long long e){
	long long res = 1;
	while (e){
		if (e & 1){
			res = res * b % MOD;
		}
		b = b * b % MOD;
		e >>= 1;
	}
	return res;
}

struct node{
	long long sz;
	long long prod;
	long long sum, sum_L, sum_R;
	long long ans;
	long long lazy_set;

	node(long long x = 0, int size = 1){
		lazy_set = -1;
		sz = size;
		prod = POW(x+1, sz);

		sum = x * sz % MOD;

		long long cnt = sz * (sz + 1) * (sz + 1) / 2;
		cnt = cnt - sz * (sz + 1) * (2 * sz + 1) / 6;
		cnt = cnt % MOD;

		ans = x * cnt % MOD;

		sum_L = x * ((sz * (sz + 1) / 2) % MOD) % MOD;
		sum_R = x * ((sz * (sz + 1) / 2) % MOD) % MOD;
	}

	void merge(const node& L, const node& R){
		sz = L.sz + R.sz;
		prod = L.prod * R.prod % MOD;

		sum = (L.sum + R.sum) % MOD;


		long long left = (L.sum_R * R.sz + L.ans) % MOD;

		long long right = (R.sum_L * L.sz + R.ans) % MOD;

		ans = (left + right) % MOD;


		sum_L = (L.sum * R.sz + L.sum_L + R.sum_L) % MOD;
		
		sum_R = (R.sum * L.sz + R.sum_R + L.sum_R) % MOD;
	}
};

struct segtree{

	vector<node> nodes;
	int n;

	segtree(vector<long long>& V){
		n = V.size();
		nodes.resize(4*n);
		
		build(1, 0, n, V);
	}

	void build(int u, int l, int r, vector<long long>& V){
		if (r - l == 1){
			nodes[u] = node(V[l], 1);
			return;
		}
		build(2 * u, l, (l+r)/2, V);
		build(2*u+1, (l+r)/2, r, V);
		nodes[u].merge(nodes[2*u], nodes[2*u+1]);
	}

	void fix_lazy(int u, int l, int r){
		long long x = nodes[u].lazy_set;

		if (x == -1)
			return;

		if (r - l != 1){
			nodes[u * 2].lazy_set = x;
			nodes[u*2+1].lazy_set = x;
		}

		nodes[u] = node(x, r - l);

		nodes[u].lazy_set = -1;
	}


	void update(int u, int l, int r, int x, int y, long long v){
		fix_lazy(u, l, r);

		if (r <= x || y <= l)
			return;

		if (x <= l && r <= y){
			nodes[u].lazy_set = v;
			fix_lazy(u, l, r);
			return;
		}

		update(2 * u, l, (l+r)/2, x, y, v);
		update(2*u+1, (l+r)/2, r, x, y, v);
		nodes[u].merge(nodes[u*2], nodes[u*2+1]);
	}

	void update(int x, int y, long long v){
		update(1, 0, n, x, y, v);
	}


	node query(int u, int l, int r, int x, int y){
		fix_lazy(u, l, r);

		if (r <= x || y <= l){
			return node(0, 0);
		}

		if (x <= l && r <= y){
			return nodes[u];
		}

		node ans(0);
		ans.merge(
			query(u * 2, l, (l+r)/2, x, y),
			query(u*2+1, (l+r)/2, r, x, y)
		);
		return ans;
	}

	long long query(int x, int y){
		node ans = query(1, 0, n, x, y);

		return (ans.ans * ans.prod % MOD) * 500000004 % MOD;
	}
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, Q;
	cin >> N >> Q;

	vector<long long> V(N);
	for (long long& x : V){
		cin >> x;
	}

	segtree ST(V);

	int op, l, r, val;
	while (Q--){
		cin >> op;

		if (op == 1){
			cin >> l >> r >> val;

			ST.update(l, r+1, val);
		}
		if (op == 2){
			cin >> l >> r;

			cout << ST.query(l, r+1) << "\n";
		}
	}

	return 0;
}
