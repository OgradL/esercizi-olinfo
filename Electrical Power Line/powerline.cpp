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

// input data
int N, i;
int H[MAXN];

int main() {
	
	freopen("input1.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &H[i]));
	
	bool done = false;
	int day = 0;
	
	for (i = 0; i < N - 1; i++){
		if (H[i] < H[i + 1]){
			day++;
		}
		
	}
	
	
    /*while (!done){
		day++;
		for (int i = 0; i < N - 1; i++){
			if (i == 0){
				done = true;
			}
			if (H[i] < H[i + 1]){
				H[i] = H[i + 1];
				if (i != 0){
					done = false;
				} else {
					done = true;
				}
				
			} else {
				if (done)
					done = true;
			}
			//cout << done << "\n";
			//cout << i << "\n";
		}
	}*/
	
	
    printf("%d\n", day); // print the result
    
    //for (i = 0; i < N; i++){
    	//cout << H[i] << " \n";
	//}

    return 0;
}
