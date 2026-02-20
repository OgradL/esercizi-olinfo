#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;

long long fact[2000003];
long long invfact[2000003];

long long POW(long long b, long long e){
	long long ret = 1;
	while (e){
		if (e & 1){
			ret = ret * b % MOD;
		}
		b = b * b % MOD;
		e >>= 1;
	}
	return ret;
}

long long inv(long long x){
	return POW(x, MOD-2);
}

long long binomial(long long a, long long b){
	long long ret = fact[a] * invfact[b] % MOD;
	ret = ret * invfact[a-b] % MOD;
	return ret;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fact[0] = invfact[0] = 1;
	for (int i = 1; i < 2e6+3; i++){
		fact[i] = fact[i-1] * i % MOD;
		invfact[i] = inv(fact[i]);
	}

	long long N;
	cin >> N;

	long long Cn = MOD + binomial(2*N, N) - binomial(2*N, N+1);
	Cn = Cn % MOD;

	long long ans = MOD + fact[N] - Cn;
	ans = ans % MOD;
	
	cout << ans << "\n";

	return 0;
}
