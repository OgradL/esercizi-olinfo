/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

#define MAXN 100

// input data
int N, i, j;
int vote;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int points[MAXN];
	for (j = 0; j < MAXN; j++)
    	points[j] = 0;
    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++) {
    	
    	
        for(j=0; j<=N; j++) {
            assert(1 == scanf("%d", &vote));
            if (vote != -1 && vote >= 0 && vote <= 10){
            	points[i] += vote;
			}
        }
        
        int maxo = 0;
        int index = 0;
        for (j = 0; j < N; j++){
        	//cout << maxo << " " << points[j] << " " << max(maxo, points[j]) << " " << j << "\n";
        	if (maxo < max(maxo, points[j])){
        		//cout << "                      " << "sium\n";
        		index = j;
				maxo = max(maxo, points[j]);
			}
		}
        
        int leader = index + 1;
        printf("%d\n", leader);
    }

    return 0;
}
