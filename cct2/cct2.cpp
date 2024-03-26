#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>
using namespace std;

void memsetta(int* v, int val, int n){
	for (int i = 0; i < n; i++){
		v[i] = val;
	}
}

int speedrunna(int N, int K, int a, int b){
	
	int *dp, *next;

	dp = (int*) malloc(sizeof(int) * 51);
	memsetta(dp, 1<<30, 51);
	dp[0] = 0;

	int c = 1, k = 1;
	for (int i = 0; i < N; i++){
		next = (int*) malloc(sizeof(int) * 51);
		memsetta(next, 1<<30, 51);
		
		c *= a; c %= 1000;
		k *= b; k %= K;
		for (int j = 0; j <= K; j++){
			if (dp[j] >= 1<<29) continue;
			next[min(j+k, K)] = min(dp[j] + c, next[min(j+k, K)]);
			if (j == K)
				next[0] = min(next[0], dp[j]);
		}
		free(dp);
		dp = next;
	}

	int ans = 1<<30;
	for (int i = 0; i < K; i++)
		ans = min(ans, dp[i]);

	return ans;
}