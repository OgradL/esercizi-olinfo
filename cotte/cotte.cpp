#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct FenwickTree{
	int n;
	vector<int> fen;
	FenwickTree(int N) : n(N+1) {
		fen.assign(n, 0);
	}

	int get_max(int idx){
		int ret = 0;
		for (idx++; idx > 0; idx -= idx & (-idx))
			ret = max(ret, fen[idx]);
		return ret;
	}

	void set_max(int idx, int val){
		for (idx++; idx < n; idx += idx & (-idx))
			fen[idx] = max(fen[idx], val);
	}
};

int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int M, F;
	cin >> M >> F;

	int C;
	cin >> C;

	vector<pair<int, int>> points;
	int a, b;
	for (int i = 0; i < C; i++){
		cin >> a >> b;
		points.push_back({a-1, b});
	}

	sort(points.begin(), points.end(), [](pair<int, int> a, pair<int, int> b){
		if (a.first == b.first)
			return a.second > b.second;
		return a.first < b.first;
	});

	FenwickTree fentree(F+1);

	int ans = 0;
	for (auto [a, b] : points){
		int v = fentree.get_max(b-1) + 1;
		ans = max(ans, v);
		fentree.set_max(b, v);
	}
	
	cout << 2*ans << "\n";

	return 0;
}
