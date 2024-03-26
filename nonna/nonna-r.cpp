#include <bits/stdc++.h>
using namespace std;

#define INF (long long)(1e18)


long long f(int n, long long k, vector<int>& valori, vector<vector<int>> &memo) {
	if (k <= 0) return -k;
	if (n == N) return INF;
	if (memo[k][n] != -1) return memo[k][n];
	
	int eat = f(n + 1, k - valori[n], memo);
	if (eat == 0) {
		memo[k][n] = eat;
		return eat;
	}
	int donteat = f(n + 1, k, memo);
	int mi = min(eat, donteat);
	memo[k][n] = mi;
	return mi;
}


int main() {
#ifdef EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int N, K;
	cin >> N >> K;
	vector<int> valori(N);
	
	for (int i = 0; i < N; i++) {
		cin >> valori[i];
	}
	vector<vector<int>> memo(K + 1, vector<int>(N, -1));
	cout << K + f(0, K, valori, memo) << endl;
	
	return 0;
}