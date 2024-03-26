#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long somma(int l, int r);
long long subarray_massimo(int l, int r);
long long subarray_minimo(int l, int r);

long long trova(int N) {
	int lo = 0, hi = N;
	while (lo + 1 < hi){
		int mid = (lo+hi)/2;
		int v = somma(mid, mid - 1);
		if (v >= 0){
			lo = mid - 1;
		} else if (v < 0){
			hi = mid - 1;
		}
	}

	if (hi != N) return somma(0, lo);

	int sum = 0;
	int s = sqrt(N);
	for (int i = 0; i < s; i++){
		sum += subarray_massimo(s * i, s * (i + 1) - 1);
	}
	return sum;
}
