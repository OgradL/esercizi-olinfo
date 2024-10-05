#include <vector>
#include <algorithm>
using namespace std;

long long alleggerisci(int N, int M, vector<int> V, vector<int> L, vector<int> R, vector<long long> K) {

	vector<long long> pref(N+1, 0);
	for (int i = 0; i < N; i++){
		pref[i+1] = pref[i] + V[i];
	}
	vector<int> idx1, idx2;
	for (int i = 0; i < M; i++){
		idx1.push_back(i);
		idx2.push_back(i);
	}
	sort(idx1.begin(), idx1.end(), [&](int a, int b){
		return L[a] < L[b];
	});
	sort(idx2.begin(), idx2.end(), [&](int a, int b){
		return R[a] < R[b];
	});

	vector<long long> P(M, 0), P1(M, 0);
	long long ans = 0, curr = 0, left = 0, x, i1 = 0, i2 = 0, idx;
	for (int i = 0; i < N; i++){
		while (i1 < M && i >= L[idx1[i1]]){
			idx = idx1[i1];
			x = max(0LL, pref[R[idx]+1] - pref[L[idx]] - K[idx] - curr);
			P[idx] = left;
			P1[idx] = pref[R[idx]+1] - pref[L[idx]] - K[idx];
			ans += x;
			curr += x;
			i1++;
		}
		while (i2 < M && i >= R[idx2[i2]]){
			idx = idx2[i2];
			x = max(0LL, P1[idx] - left + P[idx]);
			curr -= x;
			left += x;
			i2++;
		}
	}

	return ans;
}