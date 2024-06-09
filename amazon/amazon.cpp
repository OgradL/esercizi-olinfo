#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct segtree{

	vector<long long> nodes;
	int real_size, n;

	segtree(){}

	void build(vector<int>& V){
		real_size = 1;
		n = V.size();
		while (real_size < n)
			real_size *= 2;

		nodes.assign(2 * real_size, -1e9);
		build(1, 0, real_size, V);
	}

	void build(int u, int l, int r, vector<int>& V){
		if (r - l == 1){
			if (l < n)
				nodes[u] = V[l];
			else
				nodes[u] = -1e9;
			return;
		}

		build(2 * u, l, (l+r)/2, V);
		build(2*u+1, (l+r)/2, r, V);
		nodes[u] = max(nodes[u*2], nodes[u*2+1]);
	}

	int get_max(int u, int l, int r, int x, int y){
		if (y <= l || r <= x) return -1e9;
		if (x <= l && r <= y) return nodes[u];
		return max(
			get_max(2 * u, l, (l+r)/2, x, y),
			get_max(2*u+1, (l+r)/2, r, x, y)
		);
	}

	int get_max(int l, int r){
		return get_max(1, 0, real_size, l, r);
	}
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<pair<long long, long long>> trips(N);
	vector<long long> points;
	for (int i = 0; i < N; i++){
		cin >> trips[i].first >> trips[i].second;
		points.push_back(trips[i].first);
		points.push_back(trips[i].second);
	}
	
	sort(points.begin(), points.end());
	points.erase(unique(points.begin(), points.end()), points.end());
	vector<long long> compinv(points.size());
	for (int i = 0; i < N; i++){
		int idx0 = lower_bound(points.begin(), points.end(), trips[i].first) - points.begin();
		int idx1 = lower_bound(points.begin(), points.end(), trips[i].second) - points.begin();

		compinv[idx0] = trips[i].first;
		compinv[idx1] = trips[i].second;
		trips[i].first = idx0;
		trips[i].second = idx1;
	}

	sort(trips.begin(), trips.end(), [](pair<int, int> a, pair<int, int> b){
		if (a.first == b.first)
			return a.second < b.second;
		return a.first < b.first;
	});
	reverse(trips.begin(), trips.end());

	vector<vector<int>> maxjump(points.size(), vector<int>(N+1, -1));
	for (auto [l, r] : trips){
		vector<int> tmp(N+1, -1);
		tmp[0] = l;
		maxjump[r][0] = r;
		for (int i = 1; i <= N; i++){
			tmp[i] = max(maxjump[l][i], maxjump[r][i-1]);
		}
		for (int i = 0; i <= N; i++){
			maxjump[l][i] = tmp[i];
		}
	}

	vector<segtree> maxtree(points.size());
	for (int i = 0; i < points.size(); i++){
		maxtree[i].build(maxjump[i]);
	}

	int Q;
	cin >> Q;
	
	long long X, U, V;
	while (Q--){
		cin >> X >> U >> V;
		if (X != compinv[lower_bound(points.begin(), points.end(), X) - points.begin()]){
			if (U == 0){
				cout << X << " ";
			} else {
				cout << "-1 ";
			}
			continue;
		}
		X = lower_bound(points.begin(), points.end(), X) - points.begin();

		int ans = maxtree[X].get_max(U, V+1);

		if (ans == -1){
			cout << "-1 ";
		} else {
			cout << compinv[ans] << " ";
		}
	}

	cout << "\n";

	return 0;
}
