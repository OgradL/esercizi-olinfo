#include <cassert>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

struct DSU{
	int n, ans;
	vector<int> sz;
	vector<pair<int, int>> par;
	vector<array<int, 4>> history;

	DSU(int N){
		n = N+1;
		par.resize(n);
		for (int i = 0; i < n; i++){
			par[i] = {i, 0};
		}
		sz.assign(n, 0);
		ans = 0;
	}

	pair<int, int> get_par(int x){
		if (par[x].first == x)
			return par[x];
		auto a = get_par(par[x].first);
		return {a.first, a.second ^ par[x].second};
	}

	int onion_set(int a, int b){
		auto A = get_par(a);
		auto B = get_par(b);

		if (A.first != B.first){
			if (sz[A.first] < sz[B.first])
				swap(A, B);

			history.push_back({B.first, A.first, par[B.first].second, ans});

			sz[A.first] += sz[B.first];
			par[B.first].first = A.first;
			par[B.first].second = B.second ^ 1 ^ A.second;

			return 0;
		}
		history.push_back({-1, -1, -1, ans});
		ans |= A.second ^ B.second ^ 1;
		return A.second ^ B.second ^ 1;
	}

	void roll_back(int k = 1){
		while (k > 0){
			k--;

			auto [B, A, d, pre_ans] = history.back();
			history.pop_back();
			ans = pre_ans;
			if (B == -1)
				continue;

			sz[A] -= sz[B];
			par[B].first = B;
			par[B].second = d;
		}
	}
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> edges;
	int a, b;
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		--a, --b;

		edges.push_back({a, b});
	}

	vector<int> last(M, -1);
	
	function<void(int, int, int, int, DSU&)> rec = [&](int l, int r, int ql, int qr, DSU& dsu) -> void {
		int m = (l + r) / 2;

		// 1. aggiungo [m, r)
		last[m] = m;
		int end = min(r, ql);
		for (int i = m; i < end; i++){
			auto [a, b] = edges[i];
			dsu.onion_set(a, b);

			assert(!dsu.ans);
		}

		// 2. proseguo da [ql, ...) fino a rompersi
		int start = max(ql, m);
		for (int i = start; i < qr && !dsu.ans; i++){
			auto [a, b] = edges[i];
			dsu.onion_set(a, b);

			last[m] = i;
		}
		if (dsu.ans){
			dsu.roll_back();
		} else {
			last[m]++;
		}

		// 3. torno a 1 e faccio query_left
		dsu.roll_back(last[m] - start);

		if (r - l <= 1){
			dsu.roll_back(max(0, end - m));
			return;
		}

		rec(l, m, ql, last[m], dsu);

		// 4. torno a 0, riaggiungo gli archi di 2 e faccio query_right
		dsu.roll_back(max(0, end - m));

		start = max(r, ql);
		for (int i = start; i < last[m]; i++){
			auto [a, b] = edges[i];
			dsu.onion_set(a, b);
		}

		rec(m, r, last[m]-1, qr, dsu);

		// 5. torno a 0
		dsu.roll_back(last[m] - start);
	};

	DSU dsu(N);

	rec(0, M, 0, M, dsu);

	long long ans = 0;
	for (int i = 0; i < M; i++){
		ans += last[i] - i;
	}

	cout << ans << "\n";

	return 0;
}
