#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;

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

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, K;
	cin >> N >> K;

	long long ans = (POW(N-1, K) + (N-1) * sign(K)) % MOD;
	ans = ans * inv(N) % MOD;

	cout << ans << "\n";

	return 0;
}