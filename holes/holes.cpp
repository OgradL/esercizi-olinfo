#include <iostream>
#include <vector>
using namespace std;

long long MOD;

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

long long fact[1000042];
long long invfact[1000042];

long long binomial(long long a, long long b){
	long long res = fact[b];
	res = res * invfact[a] % MOD;
	res = res * invfact[b-a] % MOD;
	return res;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N >> MOD;

	fact[0] = 1;
	invfact[0] = 1;
	for (int i = 1; i < 1000042; i++){
		fact[i] = fact[i-1] * i % MOD;
	}

	invfact[1000041] = POW(fact[1000041], MOD - 2);
	for (int i = 1000040; i > 0; i--){
		invfact[i] = invfact[i+1] * (i+1) % MOD;
	}

	vector<long long> S(N+1);
	S[0] = 1;
	
	for (int i = 1; i <= N; i++){
		S[i] = S[i-1] * (2*i - 1) % MOD;
	}

	for (int i = 0; i <= N; i++){
		long long ans = S[i] * S[N-i] % MOD;
		ans = ans * binomial(i, N) % MOD;
		cout << ans << " ";
	}
	cout << "\n";

	return 0;
}
