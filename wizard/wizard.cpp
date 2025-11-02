#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct segtree{
	int n;
	vector<long long> sum, cnt;

	segtree(int N){
		n = 1 << (32 - __builtin_clz(N));
		sum.assign(2*n, 0);
		cnt.assign(2*n, 0);
	}

	void update(int p, long long x, long long sgn){
		p += n;
		sum[p] += x * sgn;
		cnt[p] += sgn;
		for (; p > 1; p >>= 1){
			sum[p >> 1] += x * sgn;
			cnt[p >> 1] += sgn;
		}
	}

	long long prefix_sum_kth(int k){
		int p = 1;
		long long ans = 0;

		while (k && p < n){
			p <<= 1;
			if (cnt[p | 1] <= k){
				ans += sum[p | 1];
				k -= cnt[p | 1];
			} else {
				p |= 1;
			}
		}

		return ans;
	}
};

long long solve(int N, int K, vector<int>& V){

	vector<long long> values;
	for (int x : V){
		values.push_back(x);
		values.push_back(-x);
	}

	sort(values.begin(), values.end());

	auto compressed_p = V;
	auto compressed_n = V;
	vector<int> cnt_idx(2*N, 0);
	for (int& x : compressed_p){
		int idx = lower_bound(values.begin(), values.end(), x) - values.begin();
		x = idx + cnt_idx[idx]++;
	}
	for (int& x : compressed_n){
		int idx = lower_bound(values.begin(), values.end(), -x) - values.begin();
		x = idx + cnt_idx[idx]++;
	}

	segtree st(2*N);

	vector<int> suff_max(N+1, -1e9);
	for (int i = N-1; i >= 0; i--){
		st.update(compressed_p[i], V[i], 1);
		suff_max[i] = max(suff_max[i+1], compressed_p[i]);
	}
	int best = -1e9;

	long long ans = 0;
	for (int i = 0; i < N-1; i++){
		best = max(best, compressed_n[i]);
		st.update(compressed_n[i], -V[i], +1);
		st.update(compressed_p[i], V[i], -1);

		st.update(best, values[best], -1);
		st.update(suff_max[i+1], values[suff_max[i+1]], -1);

		ans = max(ans, values[best] + values[suff_max[i+1]] + st.prefix_sum_kth(K-2));

		st.update(best, values[best], +1);
		st.update(suff_max[i+1], values[suff_max[i+1]], +1);
	}

	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	vector<int> V(N);
	for (int& x : V){
		cin >> x;
	}

	long long ans = solve(N, K, V);

	reverse(V.begin(), V.end());

	ans = max(ans, solve(N, K, V));

	cout << ans << "\n";

	return 0;
}
