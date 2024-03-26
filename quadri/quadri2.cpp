#include <iostream>
#include <vector>
using namespace std;

int quadri(int N, long long M, int V[]) {
    int i = 0, j = 0, sum = V[0], B = INT_MAX;
	while (j < N - 1){
		if (sum < M){
			sum += V[++j];
		} else {
			sum -= V[i++];
			B = min(B, j - i);
		}
	}
    return B;
}
