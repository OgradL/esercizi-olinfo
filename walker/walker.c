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
	long long ans = POW(i, MOD-2);
	return ans ? ans : 1;
}

long long sign(long long k){
	return 2 * (k&1^1) - 1;
}

int main(){

	long long N, K;
	scanf("%lld %lld", &N, &K);

	N = (MOD+N-1) % MOD;

	long long ans = (POW(N, K) + sign(K+1)) % MOD;
	ans = ans * inv(N+1) % MOD;
	ans = (MOD+ans+sign(K)) % MOD;
	
	printf("%lld\n", ans);

	return 0;
}