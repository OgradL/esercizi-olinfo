#include <iostream>
#include <vector>
using namespace std;

const int maxn = 50001;

string rep(char c, int t){
	string ret;
	while (t--)
		ret += c;
	return ret;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> A(N);
	for (int& x : A)
		cin >> x;

	vector<vector<pair<int, int>>> dp(N+1, vector<pair<int, int>>(maxn, {0, 0}));
	dp[0][0] = {1, 0};

	for (int i = 0; i < N; i++){
		for (int j = 0; j < maxn; j++){
			if (j - A[i] >= 0)
				if (dp[i][j - A[i]].first)
					dp[i+1][j] = {1, 0};
			if (j + A[i] < maxn)
				if (dp[i][j + A[i]].first)
					dp[i+1][j] = {1, 1};
		}
	}

	if (dp[N][0].first){
		string ans;
		int j = 0;
		for (int i = N; i > 0; i--){
			ans = rep('(' + dp[i][j].second, A[i-1]) + ans;
			j += A[i-1] * (dp[i][j].second * 2 - 1);
		}
		cout << ans << "\n";
	} else {
		cout << "-1\n";
	}

	return 0;
}