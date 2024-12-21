#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, M, x, y, K;
	cin >> N >> M >> x >> y >> K;

	--x, --y;

	vector<vector<long long>> V(N, vector<long long>(M));
	for (auto& v0 : V){
		for (long long& v1 : v0){
      			cin >> v1;
		}
	}

	int bound = min(N*M, K/2);

	vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(N, vector<long long>(M, -1e18)));

	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};

	vector<vector<long long>> mnear(N, vector<long long>(M, 0));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			mnear[i][j] = max({
					i > 0 ? V[i-1][j] : 0,
					i < N-1 ? V[i+1][j] : 0,
					j > 0 ? V[i][j-1] : 0,
					j < M-1 ? V[i][j+1] : 0
				});
		}
	}

	long long ans = 0;
	dp[0][x][y] = 0;
	for (int steps = 1; steps <= bound; steps++){
		dp[steps&1].assign(N, vector<long long>(M, -1e18));
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				for (int k = 0; k < 4; k++){
					x = i + dx[k];
					y = j + dy[k];
					if (x < 0 || x >= N) continue;
					if (y < 0 || y >= M) continue;

					dp[steps&1][i][j] = max(dp[steps&1][i][j], dp[steps&1^1][x][y] + V[i][j]);

				}

				long long left = K - 2 * steps;
				long long curr = 2 * dp[steps&1][i][j] - V[i][j];

				ans = max(ans, curr + left / 2 * (V[i][j] + mnear[i][j]));
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
