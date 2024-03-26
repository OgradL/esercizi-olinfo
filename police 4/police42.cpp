#include <iostream>
#include <vector>
using namespace std;

#define INF 1e9+7

int dp(int i, int r, int N, int L, vector<int>& X, vector<vector<int>>& memo){
	if (i >= N) return L - X[i-1];
	if (r <= 0) return L - X[i-1];
	if (memo[i][r] != -1) return memo[i][r];

	int stop_time = 0;
	// if ()
	int wait = 42;

	return wait;
}

int main(){

	// if (argc >= 2){
	// 	freopen(argv[1], "r", stdin);
	// }

	int N, R, T, L;
	cin >> N >> R >> T >> L;

	vector<int> X(N);
	for (int &i: X) cin >> i;

	vector<vector<int>> memo(N + 1, vector<int>(R + 1, -1));

	int ans = dp(0, R, N, L, X, memo);


	cout << ans << "\n";

	return 0;
}