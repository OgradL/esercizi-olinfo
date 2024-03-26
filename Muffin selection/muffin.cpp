
#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

// constraints
#define MAXN 1000000

// input data
int N, K, i;
int T[MAXN];

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &K));
    for (i = 0; i < N; i++)
        assert(1 == scanf("%d", &T[i]));
	
	int maxo = 0;
	int sum = 0;
	for (int i = 0; i < K; i++){
		sum += T[i];
	}
	
	maxo = sum;
	for (i = 0; i < N - K; i++){
		sum -= T[i];
		sum += T[i + K];
		maxo = max(maxo, sum);
		//cout << sum << " " << maxo << " -|- " << i << " " << T[i + K] << " " << T[i] << "\n";
	}
    
	
    printf("%d\n", maxo);
    return 0;
}
