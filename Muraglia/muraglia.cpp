#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e9+10;
const int MIN = -MAX;

struct Node{
	int mi;
	int ma;

	Node(){
		mi = MAX;
		ma = MIN;
	}
	
	Node(int v){
		ma = mi = v;
	}
	
	void join(const Node& a, const Node& b){
		ma = max(a.ma, b.ma);
		mi = min(a.mi, b.mi);
	}
};

struct ST{
	vector<Node> nodes;
	int n, real_size;

	ST(){
		// cool
	}

	ST(vector<int> V){
		real_size = 1;
		n = V.size();

		while (real_size < n)
			real_size *= 2;
		
		nodes.assign(2 * real_size, Node());

		build(1, 0, real_size, V);
	}

	void build(int u, int l, int r, vector<int>& V){
		if (r - l > 1){
			build(u * 2, l, (l+r)/2, V);
			build(u*2+1, (l+r)/2, r, V);
			nodes[u].join(nodes[u*2], nodes[u*2+1]);
		} else {
			if (l < n){
				nodes[u].mi = nodes[u].ma = V[l];
			}
		}
	}
	
	void update(int pos, int val){
		int u = real_size + pos;
		nodes[u].mi = nodes[u].ma = val;
		u /= 2;
		while (u >= 1){
			nodes[u].join(nodes[u*2], nodes[u*2+1]);
			u /= 2;
		}
	}

	int lower_bound(int u, int l, int r, int x, int y, int v){
		// cout << u << " " << l << " " << r << " " << x << " " << y << " " << v << "\n"; 
		if (y <= l || r <= x) return -1;

		if (x <= l && r <= y){
			if (nodes[u].mi > v) return l;
			if (nodes[u].ma <= v) return -1;
		}
		
		int le = lower_bound(u * 2, l, (l+r)/2, x, y, v);
		if (le != -1) return le;
		int ri = lower_bound(u*2+1, (l+r)/2, r, x, y, v);
		return ri;
	}

	int reverse_lower_bound(int u, int l, int r, int x, int y, int v){
		// cout << u << " " << l << " " << r << " " << x << " " << y << " " << v << "\n"; 
		if (y <= l || r <= x) return -1;
		if (x <= l && r <= y){
			if (nodes[u].mi > v) return r-1;
			if (nodes[u].ma <= v) return -1;
		}
		
		int ri = reverse_lower_bound(u*2+1, (l+r)/2, r, x, y, v);
		if (ri != -1) return ri;
		int le = reverse_lower_bound(u * 2, l, (l+r)/2, x, y, v);
		return le;
	}

	pair<int, int> query(int x){
		pair<int, int> p;
		// cout << "normal " << real_size << " " << x << " " << nodes[real_size + x].mi << " " << nodes[real_size + x].ma << "\n";
		// for (int i = 0; i < n; i++) cout << nodes[real_size + i].mi << " ";
		// cout << "\n";
		p.second = lower_bound(1, 0, real_size, x+1, n, nodes[real_size+x].mi);
		if (p.second == -1) p.second = n-1;
		// cout << "yes\n";
		// cout << "notnor " << real_size << " " << x << " " << nodes[real_size + x].mi << " " << nodes[real_size + x].ma << "\n";
		p.first = reverse_lower_bound(1, 0, real_size, 0, x, nodes[real_size+x].mi);
		if (p.first == -1) p.first = 0;
		// cout << "no\n\n\n";
		return p;
	}

};

ST segtree;
void inizializza(int N, vector<int> H){
	segtree = ST(H);
}

void cambia(int x, int h){
	segtree.update(x, h);
}

pair<int, int> chiedi(int x){
	return segtree.query(x);
}