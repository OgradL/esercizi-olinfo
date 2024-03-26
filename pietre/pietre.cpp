#include <iostream>
using namespace std;

int Confronta(int a, int b);

int Trova(int N, int G){
	int lo = max(0, G - N), hi = min(G + 1, N + 1), mid;
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;
		// cout << mid << " " << N + G - mid << "\n";
		if (Confronta(mid, N + G - mid)){
			hi = mid;
		} else {
			lo = mid;
		}
	}
	if (!Confronta(hi, min(2*N, N + G - hi + 1)))
		return hi;
	
	lo = max(N, G), hi = min(N + G + 1, 2 * N + 1);
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;
		if (Confronta(mid, -mid + N + G)){
			hi = mid;
		} else {
			lo = mid;
		}
	}
	return hi;
}

/*
int Trova(int N, int G){

	int lo1 = 0, hi1 = N+1, mid1, anslo = N, anshi = 2*N+1;
	int lo2 = N, hi2 = 2*N+1, mid2;
	while (lo1 + 1 < hi1){
		mid1 = (lo1+hi1)/2;
		lo2 = N; hi2 = 2*N+1;
		while (lo2 + 1 < hi2){
			mid2 = (lo2+hi2)/2;
			// cout << mid1 << " " << mid2 << "\n";
			if (Confronta(mid1, mid2)){
				lo2 = mid2;
			} else {
				hi2 = mid2;
			}
		}
		// cout << mid1 << " " << lo2 << "\n";
		if (mid1 + lo2 - N > G){
			hi1 = mid1;
			// hi2 = lo2;
			// lo2 = N;
		} else {
			lo1 = mid1;
			anslo = lo2;
			anshi = hi2;
			// lo2 = lo2;
			// hi2 = 2*N+1;
		}
	}
	// cout << lo1 << " " << anslo << "\n";
	// cout << lo1 + lo2 - N << "\n";
	if (lo1 + anslo - N == G){
		return lo1;
	}
	
	lo1 = anslo; hi1 = anshi;
	lo2 = 0; hi2 = N+1;
	while (lo1 + 1 < hi1){
		mid1 = (lo1+hi1)/2;
		lo2 = 0; hi2 = N+1;
		while (lo2 + 1 < hi2){
			mid2 = (lo2+hi2)/2;
			// cout << mid1 << " " << mid2 << "\n";
			if (Confronta(mid1, mid2)){
				lo2 = mid2;
			} else {
				hi2 = mid2;
			}
		}
		// cout << mid1 << " " << lo2 << "\n";
		if (mid1 + lo2 - N > G){
			hi1 = mid1;
			// hi2 = lo2;
			// lo2 = 0;
		} else {
			lo1 = mid1;
			// lo2 = lo2;
			// hi2 = N+1;
		}
	}

	return lo1;
}
*/