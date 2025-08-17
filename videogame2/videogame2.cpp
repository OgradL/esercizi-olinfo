#include <functional>
#include <iostream>
#include <vector>
using namespace std;

long long MOD;

long long POW(long long b, long long e){
	long long ans = 1;
	while (e){
		if (e&1)
			ans = ans * b % MOD;
		b = b * b % MOD;
		e >>= 1;
	}
	return ans;
}

long long inv(long long x){
	return POW(x, MOD-2);
}

long long lagrange(long long n, long long k, function<long long(long long)> f){

	vector<long long> P;
	P.push_back(f(0));

	for (int i = 1; i < k + 2; i++){
		P.push_back(P.back() + f(i));
		P.back() %= MOD;
	}

	if (n < P.size()){
		return P[n];
	}

	long long ans = 0;
	long long c = 1;

	for (int i = 1; i < k + 2; i++){
		c = c * (MOD + n - i) % MOD;
		c = c * inv(MOD - i) % MOD;
	}

	for (int i = 0; i < k + 2; i++){
		if (i > 0){
			c = c * (MOD + n - i + 1) % MOD;
			c = c * inv(MOD + n - i) % MOD;
			c = c * (MOD + i - 2 - k) % MOD;
			c = c * inv(i) % MOD;
		}

		ans += P[i] * c % MOD;
	}

	ans = ans % MOD;
	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, K;
	cin >> N >> K >> MOD;

	N %= MOD;
	long long N1 = (MOD + N - 1) % MOD;

	long long ans = lagrange(N1, K+2, [&](long long i){
		long long res = (MOD + POW(i+1, K) - POW(i, K));
		if (res >= MOD)
			res -= MOD;

		long long Ni = MOD + N - i;
		if (Ni >= MOD)
			Ni -= MOD;

		Ni = Ni * Ni % MOD;
		res = res * Ni % MOD;
		return res;
	});

	cout << ans << "\n";

	return 0;
}
