#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

struct FenwickTree {
	vector<int> fen;
	int n;

	FenwickTree(int N) {
		n = N;
		fen.assign(N, 1e9);
	}

	FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
		for (int i = 0; i < a.size(); i++)
			set(i, a[i]);
	}

	int get_min(int r) {
		int ret = 1e9;
		for (; r >= 0; r = (r & (r + 1)) - 1){
			ret = min(ret, fen[r]);
		}
		return ret;
	}

	void set(int idx, int delta) {
		for (; idx < n; idx = idx | (idx + 1)){
			fen[idx] = min(fen[idx], delta);
		}
	}
};

int check(long long diffidenza, vector<long long>& pref, int N, int K){
	vector<long long> compr;
	for (int i = 0; i <= N; i++){
		compr.push_back(pref[i]);
		compr.push_back(pref[i] + diffidenza);
	}
	vector<long long> values = compr;
	sort(compr.begin(), compr.end());

	for (long long& x : values){
		x = lower_bound(compr.begin(), compr.end(), x) - compr.begin();
	}

	int n = compr.size();
	FenwickTree fentree(n);

	fentree.set(values[2*N], 0);
	
	for (int i = N; i >= 0; i--){
		long long v = fentree.get_min(values[2*i+1]);
		fentree.set(values[2*i], v+1);
	}

	return fentree.get_min(values[0]) <= K;
}

long long stalkera(int N, int K, vector<int> S){

	vector<long long> pref(N+1);
	pref[0] = 0;
	for (int i = 0; i < N; i++)
		pref[i+1] = pref[i] + S[i];

	long long sum = 0;
	for (int i = 0; i < N; i++)
		sum += S[i];

	long long lo = sum < 0 ? sum-1 : 0,
			  hi = sum >= 0 ? sum : 0,
			  mid;
	
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;
		if (check(mid, pref, N, K))
			hi = mid;
		else
			lo = mid;
	}

	return hi;
}
