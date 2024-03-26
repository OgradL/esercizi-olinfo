/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 10000

// input data
int N, i;
int T[MAXN];

int main() {
	
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &T[i]));
	
	int best = T[0];
	int ordini = 0;
	for (int i = 1; i < N; i++){
		if (i + T[i] < best){
			ordini++;
			best = i + T[i];
		}
		
		
	}
	
	
    printf("%d %d\n", best, ordini); // print the result
    return 0;
}
