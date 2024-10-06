#include <iostream>
#include <vector>
using namespace std;
const long long MOD = 1e9 + 7;

void mul(vector<long long>& a, vector<long long>& b){
	int M = a.size();
	vector<long long> ans(M, 0);
	for (int i = 0; i < M; i++){
		for (int j = 0; j < M; j++){
			ans[(i+j)%M] += a[i] * b[j] % MOD;
			ans[(i+j)%M] %= MOD;
		}
	}

	a = ans;
}

void solve(){

	long long N, M, L, R, K;
	cin >> N;

	vector<long long> p = {0, 1, 1}, ans = {1, 0, 0};

	while (N){
		if (N & 1){
			mul(ans, p);
		}
		mul(p, p);
		N /= 2;
	}

	cout << ans[0] << "\n";
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
