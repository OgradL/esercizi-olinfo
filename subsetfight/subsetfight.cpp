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

void pow_mul(vector<long long>& ans, int e){
	vector<long long> p = ans;
	e--;
	while (e){
		if (e & 1){
			mul(ans, p);
		}
		mul(p, p);
		e /= 2;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int K;
	cin >> K;

	vector<int> V(K);
	for (int &x : V)
		cin >> x;
	
	vector<vector<long long>> P(K);
	for (int i = 0; i < K; i++){
		P[i].assign(K, 0);
		P[i][(i+1)%K]++;
		P[i][0]++;
		pow_mul(P[i], V[i]);
	}

	vector<long long> ans(K, 0);
	ans[0] = 1;

	for (int i = 0; i < K; i++){
		mul(ans, P[i]);
	}

	cout << ans[0] << "\n";

	return 0;
}
