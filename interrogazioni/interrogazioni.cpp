#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct FenwickTree {
	vector<long long> fen;
	int n;

	FenwickTree(int N) {
		n = N;
		fen.assign(N, 0);
	}

	FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
		for (int i = 0; i < a.size(); i++)
			add(i, a[i]);
	}

	long long sum(int r) {
		long long ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1){
			ret += fen[r];
		}
		return ret;
	}

	long long sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	void add(int idx, long long delta) {
		for (; idx < n; idx = idx | (idx + 1)){
			fen[idx] += delta;
		}
	}
};

int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N;
	cin >> N;

	vector<int> v(N);
	for (int &n : v)
		cin >> n;

	vector<int> d = v;
	sort(d.begin(), d.end());
	for (int i = 0; i < N; ++i) {
		v[i] = lower_bound(d.begin(), d.end(), v[i]) - d.begin();
	}

	FenwickTree fentree(N+1);

	long long ans = 0;
	for (int i = 0; i < N; i++){
		ans += fentree.sum(v[i], N);
		fentree.add(v[i], 1);
	}

	cout << ans << "\n";

	return 0;
}