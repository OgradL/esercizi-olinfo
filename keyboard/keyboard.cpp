#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int flip(int idx, int i0, int i1){
	return (idx == i0) ? i1 : (idx == i1) ? i0 : idx;
}

void solve(){

	string s;
	cin >> s;

	int N = s.size();

	vector<int> S(N);
	for (int i = 0; i < N; i++)
		S[i] = s[i] - '0';

	vector<vector<int>> dp(10, vector<int>(10, 0));
	for (int i0 = 0; i0 < 10; i0++){
		for (int i1 = 0; i1 < 10; i1++){
			dp[i0][i1] = max(i0, i1);
		}
	}
	int clean = 0, last = 0, delta;
	for (int i = 0; i < N; i++){
		for (int i0 = 0; i0 < 10; i0++){
			for (int i1 = 0; i1 < 10; i1++){
				int idx0 = flip(S[i], i0, i1);
				int idx1 = flip(last, i0, i1);
				int steps0 = abs(idx0 - idx1);
				int steps1 = abs(idx0 - last);
				dp[i0][i1] = min(dp[i0][i1] + steps0, clean + steps1);
			}
		}
		clean += abs(S[i] - last);
		last = S[i];
	}

	int ans = clean;
	for (int i0 = 0; i0 < 10; i0++)
		for (int i1 = 0; i1 < 10; i1++)
			ans = min(ans, dp[i0][i1]);

	cout << ans << "\n";

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) solve();

	return 0;
}
