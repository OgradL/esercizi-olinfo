#include <stdio.h>

const long long MOD = 666013;

long long POW(long long b, long long e){
	if (!e) return 1;
	long long v = POW(b, e/2);
	v = v * v % MOD;
	if (e&1)
		v = v * b % MOD;
	return v;
}

long long inv(long long i){
	return POW(i, MOD-2);
}

long long sign(long long k){
	return 2 * (k&1^1) - 1;
}

int main(){

	long long N, K;
	scanf("%lld %lld", &N, &K);

	// N = N % MOD;

	long long ans = 0;
	for (int i = 0; i < K; i++){
		ans = (MOD + ((MOD+N-1)%MOD) * ans + sign(i)) % MOD;
	}

	printf("%lld\n", (MOD+ans+sign(K))%MOD);

	return 0;
}