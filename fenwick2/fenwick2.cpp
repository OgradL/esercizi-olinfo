#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define all(v) v.begin(), v.end()
#define MOD (long long)(1e9+7)

struct FenwickTree {
	vector<int> fen;
	int n;

	FenwickTree(int N) {
		n = N;
		fen.assign(N, 0);
	}

	FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
		for (int i = 0; i < a.size(); i++)
			add(i, a[i]);
	}

	int sum(int r) {
		int ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1){
			ret += fen[r];
			ret = ret % MOD;
		}
		return ret;
	}

	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	void add(int idx, int delta) {
		for (; idx < n; idx = idx | (idx + 1)){
			fen[idx] += delta;
			fen[idx] = fen[idx] % MOD;
		}
	}
};

int main(){

	#ifdef EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int N;
	cin >> N;

	vector<int> V(N);
	for (int &n : V) cin >> n;

	vector<int> v2 = V;
	sort(all(v2));

	unordered_map<int, int> m;
	for (int i = 0; i < N; i++){
		m[v2[i]] = (!m[v2[i]]) ? i+1 : m[v2[i]];
	}
	for (int i = 0; i < N; i++){
		V[i] = m[V[i]];
	}

	FenwickTree fenwick(N);
	fenwick.add(V[0], 1);

	long long is = 1;
	long long ans = 1;
	for (int i = 1; i < N; i++){
		is = (fenwick.sum(V[i]-1)+1) % MOD;
		fenwick.add(V[i], is);
		ans += is;
		ans = ans % MOD;
	}

	cout << ans << "\n";

	return 0;
}