#include <stdlib.h>

long long min(long long a, long long b){
	if (a < b)
		return a;
	return b;
}


int speedrunna(int N, int K, int a, int b){

	long long **dp;

	dp = (long long**) malloc(sizeof(long long*) * 2);
	dp[0] = (long long*) malloc(sizeof(long long) * 51);
	dp[1] = (long long*) malloc(sizeof(long long) * 51);
	for (int i = 0; i < 51; i++)
		dp[0][i] = dp[1][i] = 1LL<<60;
	dp[0][0] = 0;

	int c = 1, k = 1;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 51; j++)
			dp[i&1][j] = 1LL<<60;
		
		for (int j = 0; j <= K; j++){
			dp[(i+1)&1][min(j+k, K)] = min(dp[i&1][j] + c, dp[(i+1)&1][min(j+k, K)]);
			if (j == K)
				dp[(i+1)&1][0] = min(dp[(i+1)&1][0], dp[i&1][j]);
		}
		c = c * a % 1000;
		k = k * b % K;
	}

	long long ans = 1<<30;
	for (int i = 0; i < K; i++)
		ans = min(ans, dp[K&1][i]);

	return ans;
}