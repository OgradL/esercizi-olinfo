//Scrivi qui il tuo codice
/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// constraints
#define MAXN 100000

// input data
int N, D, i;
int P[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &N, &D));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &P[i]));

    // insert your code here
    long long answer = 0;
    long long j = 0;
    for (i = 0; i < N; i++){
        j = i + 1;
        if (j < N){
            while (abs(P[i] - P[j]) < D){
                
                answer++;
                j++;
                if (j >= N)
                    break;
                
            }
        }
    }
    
    
    printf("%lld\n", answer); // print the result
    return 0;
}