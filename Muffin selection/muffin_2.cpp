//Scrivi qui il tuo codice
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
    
    int sum = 0;
    int maxo = 0;
    for (i = 0; i < K; i++){
        sum += T[i];
    }
    //cout << sum << " " << maxo << " -|- " << "-1\n"; //<< " " << T[i + K] << " " << T[i] << "\n";
    maxo = max(maxo, sum);
    for (i = 1; i < N - K + 1; i++){
        sum -= T[i - 1];
        sum += T[i + K - 1];
        maxo = max(maxo, sum);
        //cout << sum << " " << maxo << " -|- " << i << " " << T[i + K] << " " << T[i] << "\n";
    }
    
    
    printf("%d\n", maxo);
    return 0;
}

/*

5 2
1 -2 4 -8 16


7 3
10 -3 -1 6 4 1 -10


*/
