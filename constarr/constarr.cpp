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

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, M, L, R, K;
	cin >> N >> M >> L >> R >> K;

	vector<long long> p(M, 0), ans(M, 0);

	long long lm = L % M;
	long long rm = R % M;
	for (int i = 0; i < M; i++){
		long long l0 = L + M - (L%M);
		long long r0 = R - (R%M);
		p[i] = (r0 - l0) / M + (i >= lm) + (i <= rm);
	}
	
	ans[0] = 1;

	while (N){
		if (N & 1){
			mul(ans, p);
		}
		mul(p, p);
		N /= 2;
	}

	cout << ans[K] << "\n";

	return 0;
}
