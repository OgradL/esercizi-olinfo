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
	
	freopen("input0.txt", "r", stdin);
	//freopen("output0.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for( i = 0; i < N; i++)
        assert(1 == scanf("%d", &F[i]));
    assert(1 == scanf("%d", &Q));
    for( i = 0; i < Q; i++)
        assert(2 == scanf("%d %d", &P[i], &V[i]));


	
    int count[MAXN];
    int current = F[0];
    int index;
    int max = 0;
    
    
    
	for (int e = 0; e < Q; e++){
		//cout << "P[e] " << P[e] << " V[e] " << V[e] << "\n";
		F[P[e]] = V[e];
		max = 0;
		for (int y = 0;  y < N; y++){
			count[y] = 0;
		}
		
		for (int u = 0; u < N - 1; u++){
			
    		current = F[u];
    		//cout << "current " << current << "\n";
    		
    		if (F[u] > F[u + 1]){
    			
    			//cout << "F[u + 1]" << F[u + 1] << "\n";
    			for (int y = current - 1; y >= F[u + 1]; y--){
    				count[y] = count[y] + 1;
    				//cout << "count " << count[y] << "\n";
				}
				//cout << "out loop \n";
				
			} else {
				
				//cout << "F[u + 1]" << F[u + 1] << "\n";
				for (int y = current + 1; y <= F[u + 1]; y++){
					count[y] = count[y] + 1;
					//cout << "count " << count[y] << "\n";
				}
				//cout << "out loop \n";
			}
		
    

		}

    	
    		for (int u = 0; u < N; u++){
    			if (count[u] > max){
    				max = count[u];
    				index = u;
    				//cout << "max " << max << " index " << index << "\n";
				}
			}
			
			
		printf("%s%d%s%d\n", "risultato ", index ," ", max);
		//cout << "\n\n\n\n";
	}
    
    
    
    return 0;
}
