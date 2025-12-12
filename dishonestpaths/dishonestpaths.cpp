#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const long long MOD = 998244353;

struct mat{
	array<array<long long, 3>, 3> entries;

	mat() {
		entries = {0};
	}
	mat(const array<array<long long, 3>, 3>& m){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				entries[i][j] = m[i][j];
			}
		}
	}

	mat operator*(const mat& a){
		mat res;
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				for (int k = 0; k < 3; k++){
					res.entries[i][j] += entries[i][k] * a.entries[k][j];
				}
			}
		}
		return res % MOD;
	}

	mat operator%(const long long m){
		mat res;
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				res.entries[i][j] = entries[i][j] % m;
			}
		}
		return res;
	}

	mat operator=(const mat& a){
		entries = a.entries;
		return *this;
	}

	array<long long, 3>& operator[](int i){
		return entries[i];
	}
};

mat POW(mat b, long long e){
	mat res = b;
	e--;
	while (e){
		if (e & 1){
			res = res * b % MOD;
		}
		b = b * b % MOD;
		e >>= 1;
	}
	return res;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, M;
	cin >> N >> M;

	vector<array<long long, 2>> edges;
	map<long long, map<long long, int>> adj;

	long long a, b;
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		--a, --b;

		if (a < b)
			swap(a, b);

		adj[a][b] = 1;
		edges.push_back({b, a});
	}

	sort(edges.begin(), edges.end());

	long long r = 0;
	array<long long, 3> dp = {0, 0, 1};

	auto advance_fast = [&](long long idx) -> void {
		long long steps = idx - r;
		if (steps <= 0)
			return;

		mat m({
			0, 1, 0,
			0, 0, 1,
			1, 1, 1
		});

		m = POW(m, steps);

		array<long long, 3> new_dp = {0};

		for (int i = 0; i < 3; i++){
			for (int k = 0; k < 3; k++){
				new_dp[i] += dp[k] * m[i][k];
			}
			new_dp[i] %= MOD;
		}

		dp = new_dp;
		r = idx;
	};

	auto advance_slow = [&](long long idx) -> void {
		idx = min(idx, N-1);
		while (r < idx){
			r++;

			int ok1 = !adj[r][r-1];
			int ok2 = !adj[r][r-2];
			int ok3 = !adj[r-1][r-2] && !adj[r-1][r-3] && ok2;

			long long dp3 = 0;
			if (ok1)
				dp3 += dp[2];
			if (ok2)
				dp3 += dp[1];
			if (ok3)
				dp3 += dp[0];

			while (dp3 >= MOD)
				dp3 -= MOD;

			array<long long, 3> new_dp = {dp[1], dp[2], dp3};

			dp = new_dp;
		}
	};
	
	for (auto [a, b] : edges){
		advance_fast(a);
		advance_slow(a+3);
	}

	advance_fast(N-1);

	cout << dp[2] << "\n";

	return 0;
}
