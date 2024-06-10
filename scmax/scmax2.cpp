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

	int get_max(int idx) {
		int ret = 0;
		for (++idx; idx > 0; idx -= idx & -idx){
			ret = max(ret, fen[idx]);
		}
		return ret;
	}

	void upd(int idx, int delta) {
		for (++idx; idx < n; idx += idx & -idx){
			fen[idx] = max(fen[idx], delta);
		}
	}
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

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
		v = max(fentree.get_max(P[i] - 2), vm[P[i]]) + 1;
		vm[C[P[i]-1]] = max(vm[C[P[i]-1]], v);
		fentree.upd(P[i]-1, v);
	}

	cout << fentree.get_max(N-1) << "\n";

	return 0;
}
