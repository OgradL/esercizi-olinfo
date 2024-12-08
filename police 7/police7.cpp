#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, Q;
vector<long long> V;

struct node{
	long long ma, sum;
	long long left_cut;

	node(long long v = 0) : ma(v), sum(v), left_cut(0) {}
	node(long long m, long long s) : ma(m), sum(s), left_cut(0) {}
};

vector<node> st;

long long query(int u, int l, int r, long long v){
	if (r - l == 1)
	       return st[u].ma > v ? 0 : st[u].ma;
	if (v >= st[u].ma)
		return st[u].sum;
	if (v >= st[u*2+1].ma)
		return st[u*2+1].sum - st[u].left_cut + query(2 * u, l, (l+r)/2, v);
	return query(2*u+1, (l+r)/2, r, v);
}

void merge(int u, int l, int r){
	st[u].left_cut = query(2 * u, l, (l+r)/2, st[2*u+1].ma);
	st[u].sum = st[u*2].sum - st[u].left_cut + st[u*2+1].sum;
	st[u].ma = max(st[2*u].ma, st[2*u+1].ma);
}

void build(int u, int l, int r){
	if (r - l == 1){
		st[u] = node(V[l]);
		return;
	}

	build(2 * u, l, (l+r)/2);
	build(2*u+1, (l+r)/2, r);

	merge(u, l, r);
}

void update(int u, int l, int r, int i, long long v){
	if (r - l == 1){
		st[u] = node(v);
		return;
	}
	if (i < (l+r)/2)
		update(2 * u, l, (l+r)/2, i, v);
	else
		update(2*u+1, (l+r)/2, r, i, v);

	merge(u, l, r);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> Q;

	V.resize(N);
	for (long long& x : V)
		cin >> x;

	st.assign(4*N, node(0));
	build(1, 0, N);

	long long i, x;
	while (Q--){
		cin >> i >> x;

		update(1, 0, N, i, x);
cout << st[1].sum << "\n";
	}

	return 0;
}
