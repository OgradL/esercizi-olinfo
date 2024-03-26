#include <iostream>
#include <vector>
using namespace std;

struct Node{
	long long mi;
	Node(){}
	Node(long long x) : mi(x) {}
	void merge(const Node& a, const Node& b){
		mi = min(a.mi, b.mi);
	}
};

struct ST{
	int n;
	vector<Node> nodes;

	ST(vector<long long>& V){

		n = V.size();
		nodes.assign(4 * n, Node());

		build(1, 0, n, V);
	}

	void build(int u, int l, int r, vector<long long>& V){
		if (r - l == 1){
			nodes[u] = Node(l < n ? V[l] : 0);
			return;
		}

		build(2 * u, l, (l+r)/2, V);
		build(2*u+1, (l+r)/2, r, V);
		nodes[u].merge(nodes[u*2], nodes[u*2+1]);
	}

	int right_bound(int u, int l, int r, int x, int y, long long val){
		if (r <= x || y <= l) return -1;
		if (nodes[u].mi > val) return -1;
		if (r - l == 1) return l;

		int right = right_bound(u*2+1, (l+r)/2, r, x, y, val);
		if (right != -1) return right;

		int left = right_bound(u * 2, l, (l+r)/2, x, y, val);
		return left;
	}

	int right_bound(int x, int y, long long val){
		return right_bound(1, 0, n, x, y, val);
	}
};

int check(long long diffidenza, ST& segtree, vector<long long>& pref, int N, int K){
	int p = 0;
	for (int i = 0; i < K && p < N; i++){
		int r = segtree.right_bound(p, N+1, diffidenza + pref[p]);
		p = r + 1;
	}
	return p == N;
}

long long stalkera(int N, int K, vector<int> S){

	vector<long long> pref(N+1);
	pref[0] = 0;
	for (int i = 0; i < N; i++)
		pref[i+1] = pref[i] + S[i];
	
	ST segtree(pref);

	long long lo = -10, hi = 10, mid;
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;
		if (check(mid, segtree, pref, N, K))
			hi = mid;
		else
			lo = mid;
	}

	return hi;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> S(N);
    for (auto &s: S) {
        cin >> s;
    }

    cout << stalkera(N, K, S) << '\n';
}
