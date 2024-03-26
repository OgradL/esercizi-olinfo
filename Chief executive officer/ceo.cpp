#include <assert.h>
#include <stdio.h>
#include <iostream>

using namespace std;

// constraints
#define MAXN 1000

// input data
int N, i;
int A[MAXN];

int main() {
	
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);

	assert(1 == scanf("%d", &N));
	for (i = 0; i < N; i++) assert(1 == scanf("%d", &A[i]));
	
	long long int out = 0;
	
	for (int u = 1; u < N; u++){
		//cout << "pizza " << u << "\n" << "  -----  " << out << " += "<< out << " * " << A[u] << " = ";
		A[u] *= A[u - 1];
		//cout << A[u] * out << "   out = " << out << "\n";
		//printf("%s%d%s%d\n", "pizza ", u, " ", out);
	}
	
	for (int y = 0; y < N ;y++){
		out += A[y];
	}
	
	
	out++;
	
  printf("%lld\n", out);
  return 0;
}
