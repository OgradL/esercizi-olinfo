#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	string s;
	cin >> s;

	vector<vector<int>> dp(N, vector<int>(26, 1));
	vector<vector<int>> prev(N, vector<int>(26, 0));
	dp[0][s[0]-'a'] = 0;

	for (int i = 1; i < N; i++){
		for (int j = 0; j < 26; j++){
			if (j > 0){
				prev[i][j] = prev[i][j-1];
				if (dp[i-1][prev[i][j]] > dp[i-1][j])
					prev[i][j] = j;
			}
			dp[i][j] = dp[i-1][prev[i][j]] + (j != (s[i]-'a'));
		}
	}

	vector<pair<int, int>> ans;

	int m = 0;
	for (int i = 0; i < 26; i++){
		if (dp[N-1][i] < dp[N-1][m])
			m = i;
	}

	for (int i = N-1; i >= 0; i--){
		if (m != (s[i]-'a'))
			ans.push_back({i, m});
		m = prev[i][m];
	}

	cout << ans.size() << "\n";
	for (auto [i, c] : ans)
		cout << i << " " << (char)(c + 'a') << "\n";

	return 0;
}
