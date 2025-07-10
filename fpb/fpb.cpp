#include <iostream>
#include <numeric>
#include <vector>
#include <set>
using namespace std;

const long long MOD = 1e9 + 7;
const int MAXN = 1e5 + 42;

long long fact[MAXN], invfact[MAXN];

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

long long binomial(long long a, long long b){
	if (b < 0 || b > a)
		return 0;
	long long res = fact[a] * invfact[b] % MOD;
	return res * invfact[a - b] % MOD;
}

long long f(long long a, long long b){
	if (a > b)
		return 0;
	return binomial(a + b, 2 * a);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fact[0] = 1;
	for (int i = 1; i < MAXN; i++){
		fact[i] = fact[i-1] * i % MOD;
	}

	invfact[MAXN-1] = POW(fact[MAXN-1], MOD - 2);
	invfact[0] = 1;
	for (int i = MAXN-2; i > 0; i--){
		invfact[i] = invfact[i+1] * (i+1) % MOD;
	}

	int N, K;
	cin >> N >> K;

	vector<int> A(N);
	for (int& x : A){
		cin >> x;
	}

	long long ans = 0;

	for (int k = 0; k < K; k++){
		vector<long long> pref(N+1, 0);
		set<int> gcd_change;
		vector<int> gcd_vals(N+1, 0);

		gcd_change.insert(N);
		gcd_vals[N] = 0;

		for (int i = N-1; i >= 0; i--){
			long long mul = f(k, i);

			pref[i] = f(K-k-1, N-i-1);
			pref[i] += pref[i+1];
			if (pref[i] >= MOD)
				pref[i] -= MOD;

			long long tmp = 0;

			vector<int> to_delete;
			int last_idx = i;
			long long last_v = A[i];

			for (auto it = gcd_change.begin(); it != gcd_change.end(); ++it){
				int v = gcd_vals[*it];
				v = gcd(v, A[i]);

				if (v == last_v && gcd_vals[*it] != 0){
					to_delete.push_back(*it);
					continue;
				}

				tmp += (pref[last_idx] - pref[*it] + MOD) * (long long)(last_v) % MOD;
				tmp = tmp % MOD;
				if (gcd_vals[*it] != 0)
					gcd_vals[*it] = v;
				last_idx = *it;
				last_v = v;
			}

			for (auto e : to_delete){
				gcd_change.erase(e);
			}

			gcd_change.insert(i);
			gcd_vals[i] = A[i];

			ans += mul * tmp % MOD;
			ans %= MOD;
		}
	}

	cout << ans << "\n";

	return 0;
}
