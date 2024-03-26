#include <iostream>
#include <vector>
using namespace std;

void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){
	cout << ' ' << H; dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define MOD 46337

long long pow(long long b, long long e){
	if (e == 0) return 1;
	long long v = pow(b, e/2);
	v = (v * v) % MOD;
	return (v * ((e%2)?(b):(1))) % MOD;
}

int preinv[MOD+1];

void precalcinv(){
	preinv[1] = 1;
	for(int i = 2; i < MOD; ++i)
		preinv[i] = MOD - (long long)(MOD/i) * preinv[MOD%i] % MOD;
}

long long inv(long long i){
	return preinv[i%MOD];
	return pow(i, MOD - 2);
}


int conta(int N, int K, vector<int>& V){
	precalcinv();
	
	vector<long long> S(K, 0);
	int diff = K;
	int i = 0, j = 0;
	int le = N;
	while (i < N && j <= N){
		if (j == N){
			S[V[i]]--;
			diff += (S[V[i]] == 0);
			i++;
		} else if (diff == 0){
			S[V[i]]--;
			diff += (S[V[i]] == 0);
			i++;
		} else {
			S[V[j]]++;
			diff -= (S[V[j]] == 1);
			j++;
		}
		if (diff == 0){
			le = min(le, j - i);
		}
	}

	long long ans = 0;
	long long m = 1;
	i = j = 0;
	while (i < N && j <= N){
		if (j - i == le && diff == 0){
			m = (m * inv(S[V[j-1]])) % MOD;
			ans = (ans + m) % MOD;
			m = (m * S[V[j-1]]) % MOD;

			if (j < N){
				if (S[V[j]])
					m = (m * inv(S[V[j]])) % MOD;
				S[V[j]]++;
				m = (m * S[V[j]]) % MOD;
				diff -= (S[V[j]] == 1);
				j++;
			} else {
				break;
			}
		} else if (j - i < le){
			if (S[V[j]])
				m = (m * inv(S[V[j]])) % MOD;
			S[V[j]]++;
			m = (m * S[V[j]]) % MOD;
			diff -= (S[V[j]] == 1);
			j++;
		} else {
			m = (m * inv(S[V[i]])) % MOD;
			S[V[i]]--;
			if (S[V[i]])
				m = (m * S[V[i]]) % MOD;
			diff += (S[V[i]] == 0);
			i++;
		}
	}

	return ans;
}