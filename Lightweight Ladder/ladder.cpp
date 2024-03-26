/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 1000000

// input data
int N, i;
int C[MAXN];

int main() {
	
	freopen("input1.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &C[i]));
	
	int max = C[0];
	for (i = 0; i < N - 1; i++){
		if ((C[i + 1] - C[i]) > max)
			max = (C[i + 1] - C[i]);
	}
	
    printf("%d\n", max); // print the result
    return 0;
}
