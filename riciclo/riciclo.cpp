#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long riciclo(int N, int M, vector<int> T, vector<int> P){

	sort(T.begin(), T.end(), greater<int>());

	vector<int> U(M, 0), tmp(M, 0);
	for (int t : T){
		for (int i = M-1; i >= 0; i--){
			int p = min(t / (1 << i), P[i]);
			tmp[i] += p;
			P[i] -= p;
			t -= p * (1 << i);
		}
	}

	for (int i = M-1; i >= 0; i--){
		long long ts = 0;
		for (int j = i-1; j >= 0; j--){
			ts += (1LL<<j) * min((long long)(1LL<<i-j)*P[j], (long long)(P[j] + tmp[j]));
		}
		int c = min((long long)U[i] + tmp[i], ts / (1<<i));
		U[i] -= c;
		P[i] += c;
		long long s = 0;
		for (int j = i-1; j >= 0 && c; j--){
			int p = min(min((long long)(1LL<<i-j)*P[j], (long long)(P[j] + tmp[j])), (c * (1LL<<i) - s) / (1LL<<j));
			U[j] += p;
			P[j] -= p;
			if (P[j] < 0){
				tmp[j] += P[j];
				P[j] = 0;
			}
			s += (1LL<<j) * p;
			c -= s / (1LL<<i);
			ts -= s / (1LL<<i);
			s = s % (1LL<<i);
		}
	}

	long long ans = 0;
	for (long long v : U)
		ans += v;
	for (long long v : tmp)
		ans += v;
	return ans;
}