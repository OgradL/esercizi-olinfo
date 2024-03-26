#include <bits/stdc++.h>

using namespace std;

struct ST{
	
	static constexpr long long MIN = numeric_limits<long long>::min();
	static constexpr long long MAX = numeric_limits<long long>::max();
	
	struct Node{
		int v;
		int lazy;
		
		Node(){
//			val 
			v = 0;
			lazy = false;
		}
		void join(const Node &l, const Node &r){
			v = l.v + r.v;
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
			nodes[u].v = 0;
			nodes[u].lazy = false;
		} else {
			build(2*u, l, (l+r)/2);
			build(2*u+1, (l+r)/2, r);
			nodes[u].lazy = false;
			nodes[u].join(nodes[2*u], nodes[2*u+1]);
		}
		
	}
	
	void fixLazy(int u, int l, int r){
//		cout << "fixLazy " << l << " " << r << " - " << u << " -- " << nodes[u].lazy << "\n";
		
		if (nodes[u].lazy){
			nodes[u].v = (r - l) - nodes[u].v;
			
			if (u < real_size){
				nodes[u*2].lazy = !nodes[u*2].lazy;
				nodes[u*2+1].lazy = !nodes[u*2+1].lazy;
			}
			
			nodes[u].lazy = false;
		}
		
		
	}
	
	void flip(int u, int l, int r, int x, int y){
		fixLazy(u, l, r);
		
		if (x >= r || y <= l) return;
		
		if (l >= x && y >= r) {nodes[u].lazy = !nodes[u].lazy; fixLazy(u, l, r); return;}
		
		flip(u*2, l, (l+r)/2, x, y);
		flip(u*2+1, (l+r)/2, r, x, y);
		nodes[u].join(nodes[u*2], nodes[u*2+1]);
	}
	
	void flip(int x, int y){
//		cerr << "rhe\n";
		flip(1, 0, real_size, x, y);
//		cerr << "hi\n";
	}
	
	int count(int u, int l, int r, int x, int y){
		fixLazy(u, l, r);
//		cout << l << " " << r << " - " << x << " " << y << "\n";
//		cout << nodes[6].lazyAdd << " hiern1\n";
		if (x >= r || y <= l) return 0;
//		cout << nodes[6].lazyAdd << " hiern2\n";
		if (x <= l && r <= y) {/*cout << nodes[u].v << "\n";*/ return nodes[u].v;}
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
	
//	int ji = 1;
//	int l = 2;
//	for (int i = 1; i < segtree.nodes.size(); i++){
//		cout << segtree.nodes[i].v << " ";
//		ji++;
//		if (ji == l){
//			l *= 2;
//			cout << "\n";
//		}
//	}
	
	for (int i = 0; i < Q; i++){
		
		int op, a, b;
		cin >> op >> a >> b;
		
		if (op == 0) segtree.flip(a, b + 1);
		else cout << segtree.count(a, b + 1) << "\n";
		
		/*
		ji = 1;
		l = 2;
		for (int i = 1; i < segtree.nodes.size(); i++){
			cout << segtree.nodes[i].v << " ";
			ji++;
			if (ji == l){
				l *= 2;
				cout << "\n";
			}
		}
		cout << "\n";
		ji = 1;
		l = 2;
		for (int i = 1; i < segtree.nodes.size(); i++){
			cout << segtree.nodes[i].lazyAdd << " ";
			ji++;
			if (ji == l){
				l *= 2;
				cout << "\n";
			}
		}
		*/
	}
	
	
	
}


