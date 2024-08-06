#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, M;
	cin >> N >> M;

	string s;
	cin >> s;

	vector<vector<long long>> dp(N+1, vector<long long>(8));
	dp[0][0b000] = dp[0][0b111] = 1;
	for (int i = 1; i < N; i++){
		vector<long long> nxt(8, 0);
		for (int j = 0; j < 8; j++){
			int idx = (j << 1) & 0b111;
			nxt[idx] += dp[j];
			idx++;
			nxt[idx] += dp[j];
		}
		nxt[0b111] = nxt[0b000] = 0;
	}
	long long ans = 1 + (s[0] == 'P' ? dp[N-1][0] + dp[N-1][1] : 0);
	int pos = (s[0] == 'P') * 2;
	char last = s[0];
	for (int i = 1; i < N; i++){
		if (s[i] == 'P'){
			if (pos == 2){
				ans += dp[N-i-1][0] + dp[N-i-1][1];
			} else if (pos == 0){
				ans += dp[N-i-1][0];
			}
		}
		if (s[i] == last){
			pos++;
		} else {
			pos = (s[i] == 'P') * 2;
		}
		last = s[i];
		ans = (M + ans) % M;
	}

	cout << ans << "\n";

	return 0;
}
