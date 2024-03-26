#include <iostream>
#include <vector>
using namespace std;

#define all(v) v.begin(), v.end()
#define pb push_back

pair<int, int> fill(int p, int idx, vector<int>& fen, vector<vector<int>>& childs, vector<pair<int, int>>& pos){
	fen[p] = idx;
	int end = idx;
	for(int i = 0; i < childs[idx].size(); i++){
		end = fill(end+1, childs[idx][i], fen, childs, pos).second;
	}
	pos[idx] = {p, end};
	return pos[idx];
}


struct FenwickTree {
	vector<int> fen1, fen2;
	int n;

	FenwickTree(int N) {
		n = N+1;
		fen1.assign(N+1, 0);
		fen2.assign(N+1, 0);
	}

	FenwickTree(const vector<int>& a) : FenwickTree(a.size()) {
		for (int i = 0; i < n-1; i++){
			range_add(i, i, a[i]);
			cerr << "range add " << i << " " << i << " " << a[i] << "\n"; 
		}
	}

	int sum(vector<int>& bit, int idx){
		int ret = 0;
		for (++idx; idx > 0; idx -= idx & -idx)
			ret += bit[idx];
		return ret;
	}

	int prefix_sum(int idx){
		return sum(fen1, idx)*idx -  sum(fen2, idx);
	}

	int range_sum(int l, int r){
		return prefix_sum(r) - prefix_sum(l-1);
	}

	void range_add(int l, int r, int val) {
		add(fen1, l, val);
		add(fen1, r+1, -val);
		add(fen2, l, val*(l-1));
		add(fen2, r+1, -val*r);
	}

	void add(vector<int>& bit, int idx, int delta) {
		cerr << "add\n";
		for (++idx; idx <= n; idx += idx & -idx){
			bit[idx] += delta;
		}
	}
};


int main(){

	int N, M;
	cin >> N >> M;

	vector<int> wages(N);
	vector<int> parent(N);
	vector<vector<int>> childs(N);
	parent[0] = 0;
	cin >> wages[0];
	for (int i = 1; i < N; i++){
		cin >> wages[i] >> parent[i];
		childs[parent[i]-1].pb(i);
	}

	vector<pair<int, int>> pos(N);
	vector<int> temp(N);
	fill(0, 0, temp, childs, pos);
	
	cerr << "eh\n";

	FenwickTree fentree(wages);

	cerr << "eh\n";


	char op;
	int A, X;
	while (M--){
		cin >> op;
		if (op == 'p'){
			cin >> A >> X;
			fentree.range_add(pos[A].first, pos[A].second, X);
		}
		if (op == 'u'){
			cin >> A;
			cout << fentree.range_sum(pos[A].first, pos[A].second) << "\n";
		}
	}


	return 0;
}