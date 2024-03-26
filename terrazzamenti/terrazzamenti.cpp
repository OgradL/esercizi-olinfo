#include <iostream>
#include <vector>
using namespace std;

long long calc(int q, int H[], int N){
	long long tdist = 0;
	for (int i = 0; i < N; i++){
		tdist += abs(H[i] - i - q);
	}
	return tdist;
}

long long stima(int N, int h[]){

	int lo = 0, hi = 1e9 + 1e7, mid;
	while (lo + 100 < hi){
		mid = (lo + hi) / 2;

		if (calc(mid, h, N) < calc(mid + 5, h, N)){
			hi = mid;
		} else {
			lo = mid;
		}
	}
	long long ans = 1e18;
	for (int i = lo; i <= hi; i++){
		ans = min(ans, calc(i, h, N));
	}

	return ans;
}