#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree {
	vector<int> fen;
	int n;

	FenwickTree(int N) {
		n = N + 1;
		fen.assign(n, 0);
	}

	FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
		for (int i = 0; i < a.size(); i++)
			upd(i, a[i]);
	}

	int get_max(int r) {
		int ret = 0;
		for (++r; r > 0; r -= r & -r){
			ret = max(ret, fen[r]);
		}
		return ret;
	}

	// int sum(int l, int r) {
	// 	return sum(r) - sum(l - 1);
	// }

	void upd(int idx, int delta) {
		for (++idx; idx < n; idx += idx & -idx){
			fen[idx] = max(fen[idx], delta);
		}
	}
};

int main(){

	int N;
	cin >> N;

	vector<int> P(N), C(N);
	for (int &n : P)
		cin >> n;
	
	for (int &n : C)
		cin >> n;
	

	// vector<int> vm(N, 0);
	FenwickTree fentree(N);
	int v = 0;
	for (int i = N-1; i >= 0; i--){
		v = max(fentree.get_max(N - P[i] - 1), 0) + 1;

		// vm[N - P[i]] = max(vm[N - P[i]], v);
		fentree.upd(N - P[i], v);
	}

	cout << fentree.get_max(N - 1) << "\n";

	return 0;
}