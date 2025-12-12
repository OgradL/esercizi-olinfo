#include <iostream>
#include <vector>
using namespace std;

void solve(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, H, W;
	cin >> N >> H >> W;

	const int V = 70;

	vector<int> low(N, 0), high(N, H);

	vector<int> X(W), S(W), E(W);
	for (int& x : X)
		cin >> x;
	for (int& x : S)
		cin >> x;
	for (int& x : E)
		cin >> x;

	for (int i = 0; i < W; i++){
		low[X[i]] = max(low[X[i]], S[i]);
		high[X[i]] = min(high[X[i]], E[i]);
	}


	vector<vector<bool>> dp(H, vector<bool>(V, 0));
	vector<vector<bool>> new_dp;
	dp[H/2][35] = 1;

	for (int i = 0; i < N-1; i++){
		new_dp.assign(H, vector<bool>(V, 0));

		auto upd = [&](int h, int x) -> void {
			if (h < 0 || h >= H)
				return;
			if (x < 0 || x >= V)
				return;

			new_dp[h][x] = 1;
		};

		for (int j = 0; j < H; j++){
			for (int k = 0; k < V; k++){
				if (!dp[j][k] || j < low[i] || j > high[i])
					continue;

				int v = k - 35;

				upd(j + v - 1, k - 1);
				upd(j + v + 0, k + 0);
				upd(j + v + 1, k + 1);
			}
		}

		swap(dp, new_dp);
	}

	int ok = 0;
	for (int j = 0; j < H; j++){
		for (int v = 0; v < V; v++){
			ok |= dp[j][v];
		}
	}

	if (ok){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
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
