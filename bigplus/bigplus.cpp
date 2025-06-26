#include <vector>
#include <algorithm>
#include <array>
using namespace std;

struct Node{
	int L, R;
	int ma, lazyAdd;

	Node(){
		L = R = -1;
		ma = lazyAdd = 0;
	}

	void merge(int left, int right);
};

Node nodes[1<<24];
int alloc_idx = 0;
int get_node(){
	nodes[alloc_idx].L = -1;
	nodes[alloc_idx].R = -1;
	nodes[alloc_idx].ma = 0;
	nodes[alloc_idx].lazyAdd = 0;
	alloc_idx++;
	return alloc_idx-1;
}

void Node::merge(int left, int right){
	L = left;
	R = right;
	ma = lazyAdd = 0;
	if (L != -1)
		ma = max(ma, nodes[L].ma);
	if (R != -1)
		ma = max(ma, nodes[R].ma);
}

struct SegmentTree{

	int sz;
	int root;

	SegmentTree(int N){
		sz = 1;
		while (sz < N)
			sz *= 2;

		root = get_node();
	}

	void fix_lazy(int node, int l, int r){
		nodes[node].ma += nodes[node].lazyAdd;

		if (r - l > 1){
			if (nodes[node].L == -1)
				nodes[node].L = get_node();
			nodes[nodes[node].L].lazyAdd += nodes[node].lazyAdd;

			if (nodes[node].R == -1)
				nodes[node].R = get_node();
			nodes[nodes[node].R].lazyAdd += nodes[node].lazyAdd;
		}

		nodes[node].lazyAdd = 0;
	}

	void range_add(int node, int l, int r, int x, int y, int d){
		fix_lazy(node, l, r);
		if (r <= x || y <= l)
			return;

		if (x <= l && r <= y){
			nodes[node].lazyAdd += d;
			fix_lazy(node, l, r);
			return;
		}

		range_add(nodes[node].L, l, (l+r)/2, x, y, d);
		range_add(nodes[node].R, (l+r)/2, r, x, y, d);
		nodes[node].merge(nodes[node].L, nodes[node].R);
	}

	void range_add(int x, int y, int d){
		range_add(root, 0, sz, x, y, d);
	}

	int first_greater(int node, int l, int r, int v){
		fix_lazy(node, l, r);
		if (nodes[node].ma < v)
			return -1;

		if (r - l <= 1)
			return l;

		int le = first_greater(nodes[node].L, l, (l+r)/2, v);
		if (le != -1)
			return le;

		int ri = first_greater(nodes[node].R, (l+r)/2, r, v);
		return ri;
	}

	int first_greater(int v){
		return first_greater(root, 0, sz, v);
	}
};

array<int, 3> find_plus(int N, int S, int F, vector<int> y, vector<int> x){

	vector<pair<int, int>> points;
	for (int i = 0; i < N; i++){
		points.push_back({x[i], y[i]});
	}

	sort(points.begin(), points.end(), [](const pair<int, int>& a, const pair<int, int>& b){
		if (a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
	});

	auto check = [&](int L) -> pair<int, int> {

		if (F >= 4*L + 1)
			return {0, 0};

		alloc_idx = 0;
		SegmentTree st(S);

		vector<int> importantY;

		auto add_y = [&](int y){
			if (0 <= y && y < S)
				importantY.push_back(y);
		};

		for (auto [px, py] : points){
			add_y(py);
			add_y(py + L);
			add_y(py - L);
		}
		importantY.push_back(0);

		sort(importantY.begin(), importantY.end());
		importantY.erase(unique(importantY.begin(), importantY.end()), importantY.end());

		int idxa = 0, idxc = 0, idxd = 0;

		for (auto y : importantY){
			int idxp = idxc;

			while (idxc < N && points[idxc].second <= y){
				st.range_add(points[idxc].first - L, points[idxc].first, 1);
				st.range_add(points[idxc].first + 1, points[idxc].first + L + 1, 1);
				++idxc;
			}
			while (idxa < N && points[idxa].second <= y + L){
				st.range_add(points[idxa].first, points[idxa].first + 1, 1);
				++idxa;
			}
			while (idxd < N && points[idxd].second < y - L){
				st.range_add(points[idxd].first, points[idxd].first + 1, -1);
				++idxd;
			}


			int ans = st.first_greater(4 * L + 1 - F);
			if (ans != -1 && y >= 0)
				return {y, ans};

			while (idxp < N && points[idxp].second <= y){
				st.range_add(points[idxp].first - L, points[idxp].first, -1);
				st.range_add(points[idxp].first + 1, points[idxp].first + L + 1, -1);
				++idxp;
			}
		}
		
		return {-1, -1};
	};

	pair<int, int> ans;
	int lo = (F - 1) / 4, hi = (N + F + 3) / 4, mid;
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;

		auto res = check(mid);
		if (res.first < 0){
			hi = mid;
		} else {
			ans = res;
			lo = mid;
		}
	}

	return {lo, ans.first, ans.second};
}
