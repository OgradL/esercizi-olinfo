/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

// constraints
#define MAXN 100000
#define MAXQ 100000

// input data
int N, Q, i;
int F[MAXN], P[MAXQ], V[MAXQ];

int main() {
	
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &F[i]));
    assert(1 == scanf("%d", &Q));
    for(i=0; i<Q; i++)
        assert(2 == scanf("%d %d", &P[i], &V[i]));
	
	int current = 0;
	int count[MAXN];
	int max = 0;
	int index = 0;
	
	for (int u = 0; u < Q; u++){
		F[P[u]] = V[u];
		max = 0;
		
		for (int y = 0; y < MAXN; y++){
			count[y] = 0;
		}
		
		count[F[0]] = 1;
		
		//cout << "erkj\n";
		
		for (int y = 0; y < N - 1; y++){
			current = F[y];
			if (F[y] < F[y + 1]){
				for (int t = current + 1; t <= F[y + 1]; t++){
					count[t]++;
				}
			} else {
				for (int t = current - 1; t >= F[y + 1]; t--){
					count[t]++;
				}
			}
			
		}
		
		for (int y = 0; y < MAXN; y++){
			if (count[y] > max){
				max = count[y];
				index = y;
			}
		}
		printf("%d%s%d\n", index, " ", max);
		
	}
	
	
	
	
    //printf("%d%s%d\n", index, " ", max);
    return 0;
}
