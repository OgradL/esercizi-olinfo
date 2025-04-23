#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<vector<long long>> D(N, vector<long long>(10, 0));
	vector<long long> S;
	for (auto& x : D){
		long long sum = 0;
		for (auto& y : x){
			cin >> y;
			sum += y;
		}
		S.push_back(sum / 2);
	}

	vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(10, vector<long long>(10, -1)));
	for (int i = 0; i < N; i++){
		long long s0 = 0, e0 = 0;
		for (int i0 = 0; i0 < 10; i0++){
			e0 += D[i][i0];

			long long s1 = 0, e1 = 0;
			for (int i1 = 0; i1 < 10; i1++){
				e1 += D[i][i1];

				long long ss1 = s1 + (i0 < i1 ? -S[i] : +S[i]);
				long long se1 = e1 + (i0 < i1 ? -S[i] : +S[i]);

				long long lb = max(s0, ss1);
				long long ub = min(e0, se1);
				if (lb < ub)
					dp[i][i0][i1] = min(lb, 2*S[i] - (ub - 1));

				if (i0 == i1 && e0 - s0 > S[i]){
					dp[i][i0][i1] = min(s0, 2*S[i] - (e0 - 1));
				}

				s1 += D[i][i1];
			}
			s0 += D[i][i0];
		}
	}

	string s;
	int Q;
	cin >> Q;

	while (Q--){
		cin >> s;

		long long ans = 0;
		bool ok = true;

		for (int i = 0; ok && i < N; i++){
			auto v = dp[N-i-1][s[2*N-i-1] - '0'][s[i] - '0'];
			if (v >= 0){
				ans += v;
			} else {
				ok = false;
			}
		}

		if (ok){
			cout << "POSSIBLE\n" << ans << "\n";
		} else {
			cout << "IMPOSSIBLE\n-1\n";
		}
	}


	return 0;
}
