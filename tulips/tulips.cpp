#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	vector<long long> T(N);
	for (long long& x : T)
		cin >> x;

	array<vector<long long>, 2> dp;
	dp[0].assign(N, 0);
	dp[0][0] = T[0];
	for (int i = 1; i < N; i++)
		dp[0][i] = min(T[i], dp[0][i-1]);

	for (int j = 1; j < K; j++){
		vector<int> seen(N, 0);
		auto& dp0 = dp[j & 1 ^ 1];
		auto& dp1 = dp[j & 1];
		dp1.assign(N, 0);

		vector<pair<pair<long long, long long>, long long>> minstack;
		for (int i = 0; i < N; i++){
			long long best_dp = i == 0 ? 0 : dp0[i-1];
			while (minstack.size() && minstack.back().first.first > T[i]){
				best_dp = max(best_dp, minstack.back().first.second);
				minstack.pop_back();
			}
			long long best_ans = minstack.size() ? minstack.back().second : 0;
			best_ans = max(best_ans, T[i] + best_dp);
			minstack.push_back({{T[i], best_dp}, best_ans});

			dp1[i] = minstack.back().second;
		}
	}

	cout << dp[K&1^1][N-1] << "\n";

	return 0;
}
