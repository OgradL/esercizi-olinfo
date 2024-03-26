#include <stdio.h>

long long solve(long long N, int start){
	if (N == 1) return 0;
	long long ans = 2 * solve((N+1-start)/2, start ^ (N&1));
	return ans + start;
}

int main(){

	int Q;
	scanf("%d", &Q);

	long long N;
	while (Q--){
		scanf("%lld", &N);
		printf("%lld\n", solve(N, 0)+1, 0);
	}

	return 0;
}