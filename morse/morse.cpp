#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9+7;
const long long b = 29;
const long long maxn = 1e6+42;

long long pref[maxn], pw[maxn];

long long get_hash(int l, int r){
	return (MOD + pref[r+1] - (pref[l] * pw[r-l+1] % MOD)) % MOD;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	pw[0] = 1;
	for (int i = 1; i < maxn; i++)
		pw[i] = pw[i-1] * b % MOD;

	int N, M;
	cin >> N >> M;

	string s;
	cin >> s;

	pref[0] = 0;
	for (int i = 0; i < N; i++){
		pref[i+1] = (pref[i] * b % MOD + (int)s[i]) % MOD;
	}

	vector<int> sizes(M);
	vector<long long> W(M);
	long long ha = 0;
	for (int i = 0; i < M; i++){
		cin >> s;
		sizes[i] = s.size();
		long long &x = W[i];
		x = 0;
		for (int j = 0; j < s.size(); j++)
			x = (x * b % MOD + s[j]) % MOD;
	}
	
	vector<long long> dp(N+1, 0);
	dp[0] = 1;
	for (int i = 1; i <= N; i++){
		for (int j = 0; j < M; j++){
			if (i >= sizes[j]){
				if (W[j] == get_hash(i - sizes[j], i - 1))
					dp[i] = (dp[i] + dp[i - sizes[j]]) % MOD;
			}
		}
	}

	cout << dp[N] << "\n";

	return 0;
}