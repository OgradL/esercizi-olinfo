#include <iostream>
#include <vector>
using namespace std;

int f(int v){
	return 100 + 200 * v;
}

int min(int a, int b, int c){
	return min(a, min(b, c));
}

int max(int a, int b, int c){
	return max(a, max(b, c));
}

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin.tie(0);
	cin.sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	vector<int> M(N);
	for (int &n : M) cin >> n;
	
	vector<int> dp(N, 0), pref(N, 0);
	pref[0] = f(M[0]);
	for (int i = 1; i < N; i++){
		pref[i] = pref[i-1] + f(M[i]);
	}
	
	dp[0] = f(M[0]);
	dp[1] = dp[0] + f(M[1]);
	dp[2] = dp[1] + f(M[2]);
	for (int i = 3; i < N; i++){
		dp[i] = pref[i] - min(
					dp[i-1],
					dp[i-2],
					dp[i-3]
					);
	}
	
	cout << dp[N-1] << "\n";
	
	return 0;
}