#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

struct node{
	long long cnt = 0, ans = 0, lazy_add = 0;

	void merge(const node& a, const node& b){
		cnt = a.cnt + b.cnt;
		ans = a.ans + b.ans;
	}
};

struct segtree{

	int n;
	vector<node> st;

	segtree(int N) : n(N), st(4*N) {}

	void fix_lazy(int u, int l, int r){

		if (r - l > 1){
			st[u * 2].lazy_add += st[u].lazy_add;
			st[u*2+1].lazy_add += st[u].lazy_add;
		}

		st[u].ans += st[u].cnt * st[u].lazy_add;

		st[u].lazy_add = 0;
	}


	long long get(int u, int l, int r, int x, int y){
		fix_lazy(u, l, r);

		if (r <= x || y <= l)
			return 0;

		if (x <= l && r <= y)
			return st[u].ans;

		return get(u * 2, l, (l+r)/2, x, y) +
			   get(u*2+1, (l+r)/2, r, x, y);
	}

	long long get(int l, int r){
		return get(1, 0, n, l, r);
	}


	void inc(int u, int l, int r, int x, int y){
		fix_lazy(u, l, r);

		if (r <= x || y <= l)
			return;

		if (x <= l && r <= y){
			st[u].lazy_add++;
			fix_lazy(u, l, r);
			return;
		}

		inc(u * 2, l, (l+r)/2, x, y);
		inc(u*2+1, (l+r)/2, r, x, y);
		st[u].merge(st[u*2], st[u*2+1]);
	}

	void inc(int x, int y){
		inc(1, 0, n, x, y);
	}


	void add(int u, int l, int r, int x, int y){
		fix_lazy(u, l, r);

		if (r <= x || y <= l)
			return;

		if (x <= l && r <= y){
			st[u].cnt++;
			fix_lazy(u, l, r);
			return;
		}

		add(u * 2, l, (l+r)/2, x, y);
		add(u*2+1, (l+r)/2, r, x, y);
		st[u].merge(st[u*2], st[u*2+1]);
	}

	void add(int x){
		add(1, 0, n, x, x+1);
	}
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> P(N);
	for (int& x : P){
		cin >> x;
		--x;
	}

	vector<long long> cnt_d(N, 0);
	segtree st(N);

	for (int c = N-1; c >= 0; c--){
		cnt_d[c] = st.get(P[c], N);
		st.add(P[c]);
		st.inc(P[c], P[c]+1);
	}


	long long ans = 0;

	st = segtree(N);
	for (int c = 0; c < N; c++){
		long long cnt_a = st.get(0, P[c]);
		st.inc(P[c], N);
		st.add(P[c]);

		ans += cnt_d[c] * cnt_a;
		ans %= MOD;
	}

	cout << ans << "\n";

	return 0;
}
