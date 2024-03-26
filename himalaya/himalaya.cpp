#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

static constexpr long long MIN = numeric_limits<int>::min();
static constexpr long long MAX = numeric_limits<int>::max();

struct Node{
	int ma;
	
	Node(){
		ma = MIN;
	}
	void join(const Node &l, const Node &r){
		ma = max(l.ma, r.ma);
	}
};

struct ST{
	
	int n, real_size;
	vector<Node> nodes;
	
	ST(vector<int> data){
		
		n = data.size();
		
		real_size = 1;
		while (real_size < n)
			real_size *= 2;
		
		nodes.assign(2 * real_size, Node());
		
		build(1, 0, real_size, data);
	}
	
	ST(){
		// cool
	}
	
	void build(int u, int l, int r, vector<int>& data){
		
		if (r - l == 1){
			if (l < n){
				nodes[u].ma = data[l];
			} else {
				nodes[u].ma = MAX;
			}
		} else {
			build(2 * u, l, (l+r)/2, data);
			build(2*u+1, (l+r)/2, r, data);
			nodes[u].join(nodes[2*u], nodes[2*u+1]);
		}
		
	}
	
	
	// lower bound
	
	int lowerbound(int u, int l, int r, int x, int y, ll num){
//		cout << "help " << u << " " << l << " " << r << "\n";
		if (y <= l || x >= r || nodes[u].ma <= num) return -1;
//		cout << "eu\n";
		if (r - l <= 1){
			return l;
		}
		
		int le = lowerbound(u * 2, l, (l+r)/2, x, y, num);
		if (le != -1) return le;
		
		int ri = lowerbound(u*2+1, (l+r)/2, r, x, y, num);
		return ri;
		
	}
	
	int lowerbound(int x, int y, ll num){
		
		return lowerbound(1, 0, real_size, x, y, num);
		
	}
	
};


int main(){
	
	cin.tie(0);
	cin.sync_with_stdio(false);
	cout.tie(0);
	cout.sync_with_stdio(false);
	
	long long N, M, V, G = 10;
	cin >> N >> M >> V;
	
	vector<int> H(N);
	for (int &n : H) cin >> n;
	
	ST segtree = ST(H);
	
	int e = V * V / (G * 2), v;
	for (int i = 0; i < N-1; i++){
		v = segtree.lowerbound(i, N, H[i]+e);
		cout << ((v!=-1)?(v-1):(N-1)) << " ";
	}
	cout << N-1 << "\n";
	
	return 0;
}