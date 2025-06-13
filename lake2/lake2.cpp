#include <iostream>
#include <vector>
using namespace std;

struct segtree{

	int N;
	vector<int> sum;

	segtree(int sz){
		N = 1;
		while (N < sz)
			N <<= 1;

		sum.assign(2*N, 0);
	}

	void fix_lazy(int u, int l, int r){
		if ((sum[u] & (1<<30)) == 0)
			return;

		sum[u] = r - l - sum[u];

		if (r - l > 1){
			sum[2 * u] ^= 1 << 30;
			sum[2*u+1] ^= 1 << 30;
		}

		sum[u] &= ~(1 << 30);
	}

	void flip(int u, int l, int r, int x, int y){
		fix_lazy(u, l, r);

		if (r <= x || y <= l)
			return;

		if (x <= l && r <= y){
			sum[u] ^= 1 << 30;
			fix_lazy(u, l, r);
			return;
		}

		flip(u * 2, l, (l+r)/2, x, y);
		flip(u*2+1, (l+r)/2, r, x, y);

		sum[u] = sum[u * 2] + sum[u*2+1];
	}

	void flip(int l, int r){
		flip(1, 0, N, l, r);
	}

	long long get(){
		fix_lazy(1, 0, N);
		return sum[1] & ((1<<30)-1);
	}

	void reset(){
		sum.assign(2*N, 0);
	}
};

struct query{
	int l, r, t;
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, Q;
	cin >> N >> M >> Q;

	auto delta = [&](int a, int b, segtree& st){
		long long prev = st.get();

		st.flip(a, b);

		return st.get() - prev;
	};


	vector<vector<query>> horizontal_queries(N+1), vertical_queries(M+1);

	int x0, x1, y0, y1;
	for (int t = 0; t < Q; t++){
		cin >> x0 >> x1 >> y0 >> y1;
		--x0, --y0;

		horizontal_queries[x0].push_back({y0, y1, t});
		horizontal_queries[x1].push_back({y0, y1, t});

		vertical_queries[y0].push_back({x0, x1, t});
		vertical_queries[y1].push_back({x0, x1, t});
	}

	vector<long long> answers(Q, 0);

	segtree st = segtree(M);
	for (auto& v : horizontal_queries){
		st.reset();
		for (auto [l, r, t] : v){
			answers[t] += delta(l, r, st);
		}
	}

	st = segtree(N);
	for (auto& v : vertical_queries){
		st.reset();
		for (auto [l, r, t] : v){
			answers[t] += delta(l, r, st);
		}
	}

	long long ans = 0;
	for (long long& x : answers){
		ans += x;
		cout << ans << "\n";
	}

	return 0;
}
