#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <random>
#include <vector>
using namespace std;
constexpr int MOD = 676767677;


random_device rd;
mt19937 gen(rd());
uniform_int_distribution<long long> rng(0, (long long)1e18);

template<int sz_x, int sz_y>
struct matrix{
	array<array<long long, sz_y>, sz_x> m;

	template<int sz_k>
	matrix<sz_k, sz_y> operator*(const matrix<sz_k, sz_x>& a) const {
		matrix<sz_k, sz_y> res = {0};

		for (int x = 0; x < sz_k; x++){
			for (int y = 0; y < sz_y; y++){
				for (int k = 0; k < sz_x; k++){
					long long v = m[k][y] * a.m[x][k];
					if (v >= MOD){
						v %= MOD;
					}
					res.m[x][y] += v;

					if (res.m[x][y] >= MOD)
						res.m[x][y] -= MOD;
				}
			}
		}

		return std::move(res);
	}

	matrix<sz_x, sz_y> operator%(const long long mod) {
		matrix<sz_x, sz_y> res = {0};

		for (int x = 0; x < sz_x; x++){
			for (int y = 0; y < sz_y; y++){
				res.m[x][y] = m[x][y] % mod;
			}
		}

		return std::move(res);
	}

	static matrix<sz_x, sz_x> identity(){
		matrix<sz_x, sz_x> res = {0};
		for (int i = 0; i < sz_x; i++){
			res.m[i][i] = 1;
		}
		return std::move(res);
	}
};

matrix<5, 5> POW(matrix<5, 5> b, long long e){
	matrix<5, 5> ans = matrix<5, 5>::identity();

	while (e){
		if (e & 1){
			ans = ans * b;
		}
		b = b * b;
		e >>= 1;
	}
	return std::move(ans);
}

map<long long, short> corridoio;
vector<matrix<5, 5>> transitions = {
	{ // 000
		1, 1, 1, 0, 1,
		1, 1, 1, 0, 0,
		1, 1, 1, 1, 0,
		1, 0, 0, 1, 0,
		0, 0, 1, 0, 1
	},
	{ // 001
		0, 0, 0, 0, 0,
		0, 1, 1, 0, 0,
		0, 1, 1, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	},
	{ // 010
		1, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 1, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	},
	{ // 011
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 1, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	},
	{ // 100
		1, 1, 0, 0, 0,
		1, 1, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	},
	{ // 101
		0, 0, 0, 0, 0,
		0, 1, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	},
	{ // 110
		1, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	},
	{ // 111
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	},
};

// {# (x,0); #(x,1); #(x,2); sum on 0; sum on 2}

struct Treap{
	int l, r;
	long long pri;
	long long ll, rr;
	matrix<5, 5> val, tot;
};

vector<Treap> nodes(3e5 + 42);
int nodes_idx = 1;

int get_new_node(long long ll, long long rr){
	nodes[nodes_idx].l = 0;
	nodes[nodes_idx].r = 0;
	nodes[nodes_idx].pri = rng(gen);
	nodes[nodes_idx].ll = ll;
	nodes[nodes_idx].rr = rr;
	nodes[nodes_idx].val = POW(transitions[0], rr - ll);
	nodes[nodes_idx].tot = nodes[nodes_idx].val;

	assert(nodes_idx <= nodes.size());
	return nodes_idx++;
}

int root;

const matrix<5, 5>& get_tot(int n){
	return nodes[n].tot;
}

void join(int p, int l, int r){
	nodes[p].l = l;
	nodes[p].r = r;

	if (l && r){
		nodes[p].tot = get_tot(l) * nodes[p].val * get_tot(r);
	}
	if (l && !r){
		nodes[p].tot = get_tot(l) * nodes[p].val;
	}
	if (!l && r){
		nodes[p].tot = nodes[p].val * get_tot(r);
	}
	if (!l && !r){
		nodes[p].tot = nodes[p].val;
	}
}

pair<int, int> split(int n, long long x){
	if (!n) return {0, 0};

	if (x <= nodes[n].ll){
		auto [LL, LR] = split(nodes[n].l, x);
		join(n, LR, nodes[n].r);
		return {LL, n};
	} else {
		auto [RL, RR] = split(nodes[n].r, x);
		join(n, nodes[n].l, RL);
		return {n, RR};
	}
}

int merge(int l, int r){
	if (!l) return r;
	if (!r) return l;

	if (nodes[l].pri < nodes[r].pri){
		join(l, nodes[l].l, merge(nodes[l].r, r));
		return l;
	} else {
		join(r, merge(l, nodes[r].l), nodes[r].r);
		return r;
	}
}

long long calc(){

	matrix<5, 1> ans = {0, 1, 0, 0, 0};

	ans = ans * get_tot(root);

	return ans.m[1][0];
}

int inizia(long long N) {
	corridoio[-1] = corridoio[N] = 0;
	nodes[0].tot = matrix<5, 5>::identity();

	root = get_new_node(0, N);
	return calc();
}

int aggiorna(long long x, int y) {

	long long lb, ub;

	if (corridoio.count(x)){
		lb = x;
		ub = x+1;
	} else {
		auto it = corridoio.upper_bound(x);
		lb = prev(it)->first;
		ub = it->first;
	}

	long long ll = lb + (lb != x);
	long long rr = ub;

	auto [L, XR] = split(root, ll);
	auto [X, R] = split(XR, rr);

	corridoio[x] ^= 1 << y;
	X = get_new_node(x, x+1);
	nodes[X].val = transitions[corridoio[x]];
	nodes[X].tot = nodes[X].val;

	if (ll < x){
		int Xl = get_new_node(ll, x);

		X = merge(Xl, X);
	}
	if (x+1 < rr){
		int Xr = get_new_node(x+1, rr);

		X = merge(X, Xr);
	}

	X = merge(L, X);
	root = merge(X, R);

	return calc();
}

// O(4Q(log(3Q)) * 2 * 5^3)
// O(Q (log(Q) + log(N)))
// c = 8*5^3 = 1000


// GRADER DI ESEMPIO
// NON MODIFICARE AL DI SOTTO DI QUESTA LINEA

#ifndef EVAL
int main() {
	long long N;
	int Q;
	cin >> N >> Q;

	cout << inizia(N) << '\n';
	for (int i = 0; i < Q; i++) {
		long long x;
		int y;
		cin >> x >> y;

		cout << aggiorna(x, y) << '\n';
	}
}

#endif
