/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <assert.h>
#include <stdio.h>
#include <iostream>

using namespace std;

// constraints
#define MAXN 100000

// input data
int N, K, i;
int V[MAXN + 1];

int main() {
	freopen("input2.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
  	assert(2 == scanf("%d %d", &N, &K));
  	for (i = 1; i <= N; i++) assert(1 == scanf("%d", &V[i]));
	
	int current = 1;
	//int index = 0;
	int attemp = 0;
	bool giaVisitata[MAXN];
	
	//cout << K;

	
	if (K != 1){
		while (current != K && !giaVisitata[current]){
			
			if (K != current){
				//cout << giaVisitata[current] << " " << current << "\n";
				giaVisitata[current] = true;
				current = V[current];
				//index = V[index];
				attemp++;
				//cout << giaVisitata[current] << " " << current << " " << attemp << "\n";
				//cout << attemp << "\n";
			} else {
				break;
			}
		}
	}
	
	if (giaVisitata[current]){
		attemp = -1;
	}
	
	if (K == 1){
		attemp = 0;
	}
	
	
  	printf("%d\n", attemp);  // print the result
  	return 0;
}
