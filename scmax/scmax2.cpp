#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree {
	vector<int> fen;
	int n;

	FenwickTree(int N) {
		n = N + 2;
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
	

	vector<int> vm(N + 1, 0);
	FenwickTree fentree(N);
	int v = 0;
	for (int i = 0; i < N; i++){
		v = fentree.get_max(P[i] - 1);
		cout << i << " " << v << "\n";
		v = max(v, vm[P[i]]);
		v++;
		cout << i << " " << v << "\n";
		vm[C[i]] = max(vm[C[i]], v);
		fentree.upd(P[i], v);
	}

	cout << fentree.get_max(N) << "\n";

	return 0;
}