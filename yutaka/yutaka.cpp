#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

int taglia(int N, int V[]){

	vector<long long> pref(N+1, 0);
	vector<long long> dp(N+1, 0);
	vector<int> last_oc(1e6, -1);

	pref[0] = 1;
	dp[0] = 1;
	int pos = 0;
	for (int i = 1; i <= N; i++){
		pos = max(pos, last_oc[V[i-1]]);
		dp[i] = (pref[i-1] - (pos ? pref[pos-1] : 0) + MOD) % MOD;
		pref[i] = (pref[i-1] + dp[i]) % MOD;
		last_oc[V[i-1]] = i;
	}

	return dp[N];
}