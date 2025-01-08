#include <iostream>
#include <vector>
using namespace std;

int Gira(int N, int* freccia){
	vector<int> dp(N/2+1, 1e9);

	vector<int> pref(N+1, 0);
	for (int i = 0; i < N; i++)
		pref[i+1] = pref[i] + freccia[i];

	dp[0] = 0;
	for (int i = 0; 2*i < N; i++){
		for (int j = 1; i*2 + j*2 <= N; j++){
			int l = 2*i, r = 2*i + 2*j;
			int m = (l+r)/2;
			int cost = r - m - pref[r] + 2 * pref[m] - pref[l];
			dp[i+j] = min(dp[i+j], dp[i] + cost);
		}
	}

	return dp[N/2];
}
