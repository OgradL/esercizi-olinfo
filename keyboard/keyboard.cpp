#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	int T;
	cin >> T;

	while (T--){

		string s;
		cin >> s;

		int N = s.size();

		vector<int> S(N);
		for (int i = 0; i < N; i++)
			S[i] = s[i] - '0';

		vector<vector<int>> dp(10, vector<int>(10, 0)), next;
		int step = 0, last = 0, delta;
		for (int i = 0; i < N; i++){
			next.assign(10, vector<int>(10, 1e9));
			for (int j = 0; j < 10; j++){
				for (int k = 0; k < 10; k++){
					int na = S[i] == j ? k : (S[i] == k ? j : S[i]);
					int nb = i == 0 ? 0 : (S[i-1] == j ? k : (S[i-1] == k ? j : S[i-1]));
					delta = abs(na - nb);
					next[j][k] = min(dp[j][k] + delta, step + delta);
					// cout << i << " " << j << " " << k << " " << delta << " " << next[j][k] << "\n";
				}
			}
			step += abs(S[i] - last);
			dp = next;
			last = S[i];
		}

		int ans = step;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				ans = min(ans, dp[i][j]), cout << i << " " << j << " " << dp[i][j] << "\n";

		cout << ans << "\n";
	}

	return 0;
}