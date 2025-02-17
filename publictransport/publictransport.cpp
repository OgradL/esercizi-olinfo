#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

struct query{
	int i0, i1, L;
	int idx;
};

struct line{
	long long m, q;
	line(long long m0 = 0, long long q0 = INF) : m(m0), q(q0) {}

	long long get(long long x){
		return m * x + q;
	}
};

struct LiChaoTree{

	int N;
	vector<line> nodes;

	LiChaoTree(int n){
		N = n;
		nodes.assign(4 * N, line(0, INF));
	}

	void update(line new_line, int u, int l, int r){
		int m = (l + r) / 2;
		int left = new_line.get(l) < nodes[u].get(l);
		int mid = new_line.get(m) < nodes[u].get(m);
		if (mid){
			swap(nodes[u], new_line);
		}
		if (r - l == 1)
			return;

		if (left == mid){
			update(new_line, u*2+1, m, r);
		} else {
			update(new_line, u * 2, l, m);
		}
	}

	long long get(int u, int l, int r, long long x){
		int m = (l + r) / 2;
		if (r - l == 1)
			return nodes[u].get(x);
		if (x < m)
			return min(nodes[u].get(x), get(u * 2, l, m, x));
		else
			return min(nodes[u].get(x), get(u*2+1, m, r, x));
	}
};

struct SegmentTree{

	struct node{
		long long val;

		void merge(const node& a, const node& b){
			val = min(a.val, b.val);
		}
	};

	int N;
	vector<node> st;

	SegmentTree(int n) : N(n) {
		st.assign(4 * n, {(long long)1e18});
	}

	SegmentTree(vector<long long>& V) : SegmentTree(V.size()) {
		build(1, 0, N, V);
	}

	void build(int u, int l, int r, vector<long long>& V){
		if (r - l == 1){
			st[u] = {V[l]};
			return;
		}
		build(2 * u, l, (l+r)/2, V);
		build(2*u+1, (l+r)/2, r, V);
		st[u].merge(st[u*2], st[u*2+1]);
	}

	void update(int u, int l, int r, int x, int y, long long val){
		if (x <= l && r <= y){
			st[u].val = val;
			return;
		}
		if (r <= x || y <= l)
			return;
		update(2 * u, l, (l+r)/2, x, y, val);
		update(2*u+1, (l+r)/2, r, x, y, val);
		st[u].merge(st[u*2], st[u*2+1]);
	}

	void update(int x, int y, long long val){
		update(1, 0, N, x, y, val);
	}

	long long get_min(int u, int l, int r, int x, int y){
		if (x <= l && r <= y){
			return st[u].val;
		}
		if (r <= x || y <= l){
			return 1e18;
		}
		return min(
			get_min(u * 2, l, (l+r)/2, x, y),
			get_min(u*2+1, (l+r)/2, r, x, y)
		);
	}

	long long get_min(int x, int y){
		return get_min(1, 0, N, x, y);
	}
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, Q;
	cin >> N >> M >> Q;
	
	vector<long long> T(N-1), S(N);
	for (long long& x : S)
		cin >> x;

	for (long long& x : T)
		cin >> x;

	vector<query> queries(Q);
	vector<long long> answer(Q, 1e18);
	int idx = 0, A, B, C, D;
	for (auto& [i0, i1, L, index] : queries){
		cin >> A >> B >> C >> D;
		i0 = min(A, C);
		i1 = max(A, C);
		L = (B - D + M) % M;
		L = min(L, M - L);
		index = idx++;
	}

	vector<long long> pref(N);
	for (int i = 1; i < N; i++){
		pref[i] = pref[i-1] + T[i-1];
	}

	LiChaoTree lct(M);

	sort(queries.begin(), queries.end(), [&](const query& a, const query& b){
		return a.i0 < b.i0;
	});

	int j = 0;
	for (int i = 0; i < N; i++){
		lct.update(line{S[i], -2*pref[i]}, 1, 0, M);

		while (j < Q && queries[j].i0 <= i){
			long long tmp = lct.get(1, 0, M, queries[j].L) + 2*pref[i];

			tmp += pref[queries[j].i1] - pref[queries[j].i0];

			answer[queries[j].idx] = min(answer[queries[j].idx], tmp);
			j++;
		}
	}

	lct = LiChaoTree(M);

	sort(queries.begin(), queries.end(), [&](const query& a, const query& b){
		return a.i1 > b.i1;
	});

	j = 0;
	for (int i = N-1; i >= 0; i--){
		lct.update(line{S[i], 2*pref[i]}, 1, 0, M);

		while (j < Q && queries[j].i1 >= i){
			long long tmp = lct.get(1, 0, M, queries[j].L) - 2*pref[i];

			tmp += pref[queries[j].i1] - pref[queries[j].i0];

			answer[queries[j].idx] = min(answer[queries[j].idx], tmp);
			j++;
		}
	}

	SegmentTree st(S);

	for (auto& [i0, i1, L, idx] : queries){
		long long tmp = st.get_min(i0, i1+1);

		tmp = tmp * L + pref[i1] - pref[i0];

		answer[idx] = min(answer[idx], tmp);
	}

	for (long long& x : answer){
		cout << x << "\n";
	}

	return 0;
}
