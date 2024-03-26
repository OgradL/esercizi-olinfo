#include <iostream>

constexpr const long long MOD = 1e9 + 7;

long long POW(long long b, long long e){
	if (e == 0) return 1;
	long long v = POW(b, e/2);
	return (v * v % MOD) * (e&1?b:1) % MOD;
}

int progetti(int N, int K){
	
}