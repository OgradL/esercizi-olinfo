/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>

// constraints
#define MAXN 200000

// input data
int T, N, K, i, j;
long double prob[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &T));
    for(i=0; i<T; i++) {
        assert(2 == scanf("%d %d", &N, &K));
        for(j=0; j<N; j++)
            assert(1 == scanf("%Lf", &prob[j]));
    
        // insert your code here

        long double result = 1.54368512435;

        // print result (round down and print six decimals)
        // DO NOT EDIT!
        result = floor(result * 1000000) / 1000000;
        printf("%.6Lf\n", result);
    
    }

    return 0;
}
