#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<long long>> A(N, vector<long long>(M, 0));
	vector<vector<long long>> C(N, vector<long long>(M, 0));

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> C[i][j];
		}
	}

	long long ans = -1e18;
	vector<vector<long long>> dp(N, vector<long long>(M, -1e18));
	for (int c = 1; c <= 500; c++){
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				dp[i][j] = -1e18;
				if (i)
					dp[i][j] = max(dp[i][j], dp[i-1][j] + A[i][j]);
				if (j)
					dp[i][j] = max(dp[i][j], dp[i][j-1] + A[i][j]);

				if (C[i][j] == c){
					dp[i][j] = max(dp[i][j], A[i][j]);
					ans = max(ans, dp[i][j]);
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
