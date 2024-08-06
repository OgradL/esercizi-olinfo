#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> endpoints(1, -1);
	int x;
	for (int i = 0; i < N; i++){
		cin >> x;
		endpoints.push_back(x);
	}
	endpoints.push_back(M);

	N += 2;

	vector<vector<long long>> dp(N, vector<long long>(N, 1e18));
	for (int s = 0; s < N; s++){
		for (int i = 0; i+s < N; i++){
			if (s <= 1){
				dp[i][i+s] = 0;
				continue;
			}
			int steps = endpoints[i+s] - endpoints[i] - 1;
			if (steps <= 1)
				steps = 0;

			int lo = i+1, hi = i+s, mid;
			long long value = 0;
			while (lo + 1 < hi){
				mid = (lo + hi) / 2;
				if (dp[i][lo] + dp[lo][i+s] < dp[i][lo+1] + dp[lo+1][i+s]){
					hi = mid;
				} else {
					lo = mid;
				}
			}
			dp[i][i+s] = min(dp[i][i+s], dp[i][lo] + dp[lo][i+s] + steps);
		}
	}


	cout << dp[0][N-1] << "\n";

	return 0;
}
