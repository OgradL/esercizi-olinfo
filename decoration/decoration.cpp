#include <algorithm>
#include <array>
#include <vector>

using namespace std;

int decorate(int N, vector<int> A) {

	array<vector<vector<int>>, 2> cnt, pref;
	cnt[0].assign(N, vector<int>(N));
	cnt[1].assign(N, vector<int>(N));
	pref[0].assign(N, vector<int>(N, 0));
	pref[1].assign(N, vector<int>(N, 0));

	auto get = [&](int k, int l, int i0, int i1){
		int ret = pref[k][l][i1];
		if (i0){
			ret -= pref[k][l][i0-1];
		}
		return ret;
	};


	auto check = [&](int cutoff) -> bool {

		for (int i = 0; i < N; i++){
			cnt[0][0][i] = A[i] < cutoff;
			cnt[1][0][i] = A[i] >= cutoff;

			pref[0][0][i] = A[i] < cutoff;
			pref[1][0][i] = A[i] >= cutoff;
			if (i){
				pref[0][0][i] += pref[0][0][i-1];
				pref[1][0][i] += pref[1][0][i-1];
			}
		}
		
		int ans = 0;

		for (int l = 1; l < N; l++){
			for (int i = 0; i + l < N; i++){
				int s0 = cnt[0][l-1][i] + cnt[0][l-1][i+1];
				if ((l-1)/2 != l/2){
					int d = l-1 - (l-1)/2;
					s0 -= get(0, l/2-1, i, i+d+1);
				}
				if (l > 1){
					s0 -= cnt[0][l-2][i+1];
					if ((l-1)/2 != (l-2)/2){
						int d = l-2 - (l/2-1);
						s0 += get(0, l/2-1, i+1, i+1+d);
					}
				}

				int s1 = cnt[1][l-1][i] + cnt[1][l-1][i+1];
				if ((l-1)/2 != l/2){
					int d = l-1 - (l-1)/2;
					s1 -= get(1, l/2-1, i, i+d+1);
				}
				if (l > 1){
					s1 -= cnt[1][l-2][i+1];
					if ((l-1)/2 != (l-2)/2){
						int d = l-2 - (l/2-1);
						s1 += get(1, l/2-1, i+1, i+1+d);
					}
				}

				cnt[0][l][i] = s0 + (s1 == 0);
				cnt[1][l][i] = s1 + (s0 == 0);

				pref[0][l][i] = s1 == 0;
				pref[1][l][i] = s0 == 0;
				if (i){
					pref[0][l][i] += pref[0][l][i-1];
					pref[1][l][i] += pref[1][l][i-1];
				}
				ans = s1 != 0;
			}
		}

		return ans;
	};

	vector<int> sorted = A;
	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

	int lo = 0, hi = sorted.size(), mid;
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;

		if (check(sorted[mid])){
			lo = mid;
		} else {
			hi = mid;
		}
	}

	return sorted[lo];
}
