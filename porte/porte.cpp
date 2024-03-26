#include <iostream>
#include <vector>
using namespace std;

#define MOD int(1e9+7)

int main(){

	int N;
	cin >> N;

	vector<int> V(N);
	for (int &n : V)
		cin >> n;
	
	vector<int> dp(N, 0);
	dp[0] = 1;
	for (int i = 1; i < N; i++){
		for (int j = 0; (1<<j) <= i; j++){
			if ((V[i] + V[i-(1<<j)]) % (1<<j) == 0){
				dp[i] = (dp[i] + dp[i-(1<<j)]) % MOD;
			}
		}
	}

	cout << dp[N-1] << "\n";

	return 0;
}