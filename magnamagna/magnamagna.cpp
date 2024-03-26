#include <iostream>
#include <vector>
using namespace std;

long long p2[1002];

int move(int i, int j, int t, vector<int>& V, vector<vector<int>>& moves, vector<vector<int>>& dp, vector<int>& pref){
	// if (t == 0 && dp[i][j] != -1) return dp[i][j];

	cout << i << " " << j << " " << t << "\n";
	if (j - i == 0){
		return dp[i][j] = V[i];
	}
	if (t == 0){
		dp[i][j] = pref[j] - i?(pref[i-1]):0 - 
						min(move(i+1, j, 1, V, moves, dp, pref),
							move(i, j-1, 1, V, moves, dp, pref)
						);
		cout << "r " << dp[i][j] << "\n";
		return dp[i][j];
	}
	if (t == 1){
		if (moves[i][j] == 0){
			return pref[j] - i?(pref[i-1]):0 - (move(i+1, j, 0, V, moves, dp, pref));
		}
		if (moves[i][j] == 1){
			return pref[j] - i?(pref[i-1]):0 - (move(i, j-1, 0, V, moves, dp, pref));
		}
		if (moves[i][j] == 2){
			return pref[j] - i?(pref[i-1]):0 - max(move(i+1, j, 0, V, moves, dp, pref), move(i, j-1, 0, V, moves, dp, pref));
		}
	}

	return 42;
}

int main() {
	
	p2 [0] = 1;
	for (int i = 1; i < 1002; i++){
		p2[i] = 2 * p2[i-1];
		if (p2[i-1] >= 1e16) p2[i] = 1e17;
	}
	
	int N;
	cin >> N;
	
	vector<int> V(N);
	for (int &n : V)
		cin >> n;
	
	vector<int> pref(N, V[0]);
	for (int i = 1; i < N; i++){
		pref[i] = pref[i-1] + V[i];
	}
	
	vector<vector<int>> moves(N, vector<int>(N, 0)), dp(N, vector<int>(N, -1));
	
	for (int i = 0; i < N; i++){
		double l = 0, r = 0;
		for (int j = i; j < N; j++){
			l = l + V[j] / double(p2[j - i]) * (((j-i+1)%2)*2-1);
			r = -r / 2 + V[j];
			moves[i][j] = (r < l) ? 0 : ((r > l) ? 1 : 2);
			//cout << i << " " << j << " - " << l << " " << r << " " << moves[i][j] << "\n";
		}
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j + i < N; j++){
			move(j, j+i, i%2==N%2, V, moves, dp, pref);
		}
	}

	for (auto x : dp){
		for (auto y : x){
			cout << y << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}