#include <iostream>
#include <numeric>
#include <vector>
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
		for (int i = k; i < N; i++){
			long long g = A[i];
			for (int j = i; j < N - (K - k - 1); j++){
				g = gcd(g, A[j]);
				long long t = f(k, i) * f(K-k-1, N-j-1) % MOD;
				ans += g * t % MOD;
				ans %= MOD;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
