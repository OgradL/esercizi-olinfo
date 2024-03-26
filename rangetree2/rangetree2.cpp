#include <bits/stdc++.h>

using namespace std;

struct ST{
	
	static constexpr long long MIN = numeric_limits<long long>::min();
	static constexpr long long MAX = numeric_limits<long long>::max();
	
	struct Node{
		vector<int> v = {1, 0, 0};
		int lazy;
		
		Node(){
//			val 
			v = {1, 0, 0};
			lazy = 0;
		}
		void join(const Node &l, const Node &r){
			v[0] = l.v[0] + r.v[0];
			v[1] = l.v[1] + r.v[1];
			v[2] = l.v[2] + r.v[2];
  		}
	};
	
	int n, real_size;
	vector<Node> nodes;
	
	ST(int siz){
		
		n = siz;
		
		real_size = 1;
		while (real_size < n)
			real_size *= 2;
		
		nodes.assign(2 * real_size, Node());
		
		build(1, 0, real_size);
	}
	
	void build(int u, int l, int r){
		
		if (r - l == 1){
			nodes[u].v = {1, 0, 0};
			nodes[u].lazy = 0;
		} else {
			build(2*u, l, (l+r)/2);
			build(2*u+1, (l+r)/2, r);
			nodes[u].lazy = 0;
			nodes[u].join(nodes[2*u], nodes[2*u+1]);
		}
		
	}
	
	void fixLazy(int u, int l, int r){
//		cout << "fixLazy " << l << " " << r << " - " << u << " -- " << nodes[u].lazy << "\n";
		
		if (nodes[u].lazy % 3 > 0){
			nodes[u].lazy %= 3;
			
			for (int i = 0; i < nodes[u].lazy; i++){
				int ex = nodes[u].v[2];
				nodes[u].v[2] = nodes[u].v[1];
				nodes[u].v[1] = nodes[u].v[0];
				nodes[u].v[0] = ex;
			}
			
			if (u < real_size){
				nodes[u*2].lazy += nodes[u].lazy;
				nodes[u*2+1].lazy += nodes[u].lazy;
			}
			
			nodes[u].lazy = 0;
		}
		
		
	}
	
	void add(int u, int l, int r, int x, int y){
		
		if (x >= r || y <= l) return;
		
		if (l >= x && y >= r) {nodes[u].lazy++; fixLazy(u, l, r); return;}
		
		fixLazy(u, l, r);
		
		add(u*2, l, (l+r)/2, x, y);
		add(u*2+1, (l+r)/2, r, x, y);
		fixLazy(u*2, l, (l+r)/2);
		fixLazy(u*2 + 1, (l+r)/2, r);
		nodes[u].join(nodes[u*2], nodes[u*2+1]);
	}
	
	void add(int x, int y){
//		cerr << "rhe\n";
		add(1, 0, real_size, x, y);
//		cerr << "hi\n";
	}
	
	int count(int u, int l, int r, int x, int y){
//		cout << l << " " << r << " - " << x << " " << y << "\n";
//		cout << nodes[6].lazyAdd << " hiern1\n";
		if (x >= r || y <= l) return 0;
		fixLazy(u, l, r);
//		cout << nodes[6].lazyAdd << " hiern2\n";
		if (x <= l && r <= y) {/*cout << nodes[u].v << "\n";*/ return nodes[u].v[0];}
//		cout << nodes[6].lazyAdd << " hiern3\n";
		return count(u*2, l, (l+r)/2, x, y) + count(u*2+1, (l+r)/2, r, x, y);
	}
	
	int count(int x, int y){
		return count(1, 0, real_size, x, y);
	}
};

int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N, Q;
	
	cin >> N >> Q;
	
	ST segtree(N);
	
	for (int i = 0; i < Q; i++){
		
		int op, a, b;
		cin >> op >> a >> b;
		
		if (op == 0) segtree.add(a, b + 1);
		else cout << segtree.count(a, b + 1) << "\n";
	}
	
	
	
}


