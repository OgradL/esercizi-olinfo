#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, R, T, L;
	cin >> N >> R >> T >> L;

	vector<long long> X(N);
	for (long long& i: X) cin >> i;
	X.push_back(L);

	vector<vector<long long>> dp(N + 1, vector<long long>(R + 2, 1e18));

	dp[0][0] = X[0];

	for (int i = 1; i <= N; i++){
		for (int j = 0; j <= R; j++){
			if (dp[i-1][j] != 1e18){
				long long time = dp[i-1][j];
				long long stop_time = 0;
				if ((time / T) % 2){
					stop_time = time % T;
					stop_time = T - stop_time;
				}
				dp[i][j] = min(dp[i][j], time + stop_time + X[i] - X[i-1]);

				if (j <= R && stop_time > 0)
					dp[i][j+1] = min(dp[i][j+1], time + X[i] - X[i-1]);
			} else {
				break;
			}
		}
	}

	
	long long ans = 1e18;
	for (int i = 0; i <= R; i++){
		ans = min(ans, dp[N][i]);
	}

	cout << ans << "\n";

	return 0;
}
