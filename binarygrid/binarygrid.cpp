#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--){
		int N, M;
		cin >> N >> M;

		vector<vector<int>> A(N, vector<int>(M));
		string s;
		for (auto& a0 : A){
			cin >> s;
			for (int i = 0; i < M; i++){
				a0[i] = s[i] - '0';
			}
		}

		auto solve = [&]() -> int {
			int n = A.size();
			int m = A[0].size();

			array<int, 8> dp, new_dp;
			dp.fill(0);
			for (int i = 0; i < 8; i++){
				dp[i] = __builtin_popcount(i);
			}

			for (int i = 2; i < n; i++){
				new_dp.fill(1e9);
				for (int mask = 0; mask < 8; mask++){
					for (int j = 0; j < m && new_dp[mask] != -1; j++){
						int vals[3];
						for (int k = 0; k < 3; k++){
							vals[k] = A[i-k][j] ^ ((mask >> k) & 1);
						}
						if (vals[0] == vals[1] && vals[1] == vals[2]){
							new_dp[mask] = -1;
						}
						int new_mask = mask >> 1;

						int m = min(dp[new_mask ^ 0], dp[new_mask ^ 4]);
						new_dp[mask] = min(new_dp[mask], m + (mask & 1));
					}
				}
				dp = new_dp;
				for (int k = 0; k < 8; k++){
					if (dp[k] == -1)
						dp[k] = 1e9;
				}
			}

			int ans = 1e9;
			for (int k = 0; k < 8; k++){
				ans = min(ans, dp[k]);
			}

			return ans;
		};

		int ans = solve();

		vector<vector<int>> B(M, vector<int>(N));
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				B[j][i] = A[i][j];
			}
		}
		A = B;

		ans += solve();

		cout << (ans >= 1e9 ? -1 : ans) << "\n";
	}

	return 0;
}
