#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

static constexpr long long MIN = numeric_limits<long long>::min();
static constexpr long long MAX = numeric_limits<long long>::max();

struct ST{
	
	struct Node{
		ll sum;
		ll mi;
		ll lazySet;
		ll lazyAdd;
		
		Node(){
			sum = 0;
			mi = MAX;
			lazySet = MIN;
			lazyAdd = 0;
		}
		void join(const Node &l, const Node &r){
			mi = min(l.mi, r.mi);
			sum = l.sum + r.sum;
		}
	};
	
	int n, real_size;
	vector<Node> nodes;
	
	vector<Node> actual;
	
	ST(vector<ll> data){
		
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
	
	void fixLazy(int u, int l, int r){
		
		if (nodes[u].lazyAdd == 0 && nodes[u].lazySet == MIN) return;
		
		if (nodes[u].lazySet != MIN) {
			nodes[u].mi = nodes[u].lazySet;
			nodes[u].sum = nodes[u].lazySet * (r - l);
			
			if (u < real_size){
				nodes[u*2].lazySet = nodes[u].lazySet;
				nodes[u*2].lazyAdd = 0;
				
				nodes[u*2+1].lazySet = nodes[u].lazySet;
				nodes[u*2+1].lazyAdd = 0;
			}
			nodes[u].lazySet = MIN;
		}
		if (nodes[u].lazyAdd != 0){
			nodes[u].mi += nodes[u].lazyAdd;
			nodes[u].sum += nodes[u].lazyAdd * (r - l);
			
			if (u < real_size){
				nodes[u*2].lazyAdd += nodes[u].lazyAdd;
				
				nodes[u*2+1].lazyAdd += nodes[u].lazyAdd;
			}
			nodes[u].lazyAdd = 0;
		} 
		
	}
	
	void build(int u, int l, int r, vector<ll>& data){
		
		if (r - l == 1){
			if (l < data.size()){
				nodes[u].mi = data[l];
				nodes[u].sum = data[l];
			} else {
				nodes[u].mi = MAX;
				nodes[u].sum = 0;
			}
		} else {
			build(2*u, l, (l+r)/2, data);
			build(2*u+1, (l+r)/2, r, data);
			nodes[u].join(nodes[2*u], nodes[2*u+1]);
		}
		
	}
	
	void update(int pos, int x){
		
		int u = real_size + pos;
		nodes[u].mi = x;
		nodes[u].sum = x;
		
		while(u > 1){
			
			u /= 2;
			nodes[u].join(nodes[2*u], nodes[2*u+1]);
			
		}
		
	}
	
	ll getmin(int u, int l, int r, int x, int y){
		fixLazy(u, l, r);
		if (x >= r || y <= l) return MAX;
		
		if (l >= x && r <= y) return nodes[u].mi;
		
		return min(
			getmin(2*u, l, (l+r)/2, x, y),
			getmin(2*u+1, (l+r)/2, r, x, y)
		);
		
	}
	
	ll getmin(int x, int y){
		
		return getmin(1, 0, real_size, x, y);
		
	}
	
	
	// get sum
	
	ll getsum(int u, int l, int r, int x, int y){
		fixLazy(u, l, r);
		if (x >= r || y <= l) return 0;
		
		if (l >= x && r <= y) return nodes[u].sum;
		
		return getsum(2*u, l, (l+r)/2, x, y) + getsum(2*u+1, (l+r)/2, r, x, y);
		
	}
	
	ll getsum(int x, int y){
		
		return getsum(1, 0, real_size, x, y);
		
	}
	
	
	// set range
	
	void setrange(int u, int l, int r, int x, int y, ll num){
		fixLazy(u, l, r);
		if (x >= r || y <= l) return;
		
		if (l >= x && r <= y) {
			nodes[u].lazySet = num;
			nodes[u].lazyAdd = 0;
			fixLazy(u, l, r);
			return;
		}
		
		
		setrange(2*u, l, (l+r)/2, x, y, num);
		setrange(2*u+1, (l+r)/2, r, x, y, num);
		nodes[u].join(nodes[2*u], nodes[2*u+1]);
		
	}
	
	void setrange(int x, int y, ll num){
		
		setrange(1, 0, real_size, x, y, num);
		
	}
	
	
	// add range
	
	void addrange(int u, int l, int r, int x, int y, ll num){
		fixLazy(u, l, r);
		if (x >= r || y <= l) return;
		
		if (l >= x && r <= y) {
			nodes[u].lazyAdd += num;
			fixLazy(u, l, r);
			return;
		}
		
		addrange(2*u, l, (l+r)/2, x, y, num);
		addrange(2*u+1, (l+r)/2, r, x, y, num);
		nodes[u].join(nodes[2*u], nodes[2*u+1]);
		
	}
	
	void addrange(int x, int y, ll num){
		
		addrange(1, 0, real_size, x, y, num);
		
	}
	
	
	// lower bound
	
	int lowerbound(int u, int l, int r, int x, int y, ll num){
		fixLazy(u, l, r);
//		cout << "help " << u << " " << l << " " << r << "\n";
		if (y <= l || x >= r || nodes[u].mi > num) return -1;
//		cout << "eu\n";
		if (r - l <= 1){
			return l;
		}
		
		int le = lowerbound(u*2, l, (l+r)/2, x, y, num);
		if (le != -1) return le;
		
		int ri = lowerbound(u*2+1, (l+r)/2, r, x, y, num);
		return ri;
		
	}
	
	int lowerbound(int x, int y, ll num){
		
		return lowerbound(1, 0, real_size, x, y, num);
		
	}
	
	
	void print(){
		cout << "tree: \n";
		int ji = 1;
		int l = 2;
		for (int i = 1; i < nodes.size(); i++){
			cout << nodes[i].mi << " ";
			ji++;
			if (ji == l){
				l *= 2;
				cout << "\n";
			}
		}
	}
	
};



ST A;

void init(vector<long long> a) {
	
	A = ST(a);
	
}

ll get_sum(int l, int r) {
	
	return A.getsum(l, r);
	
}

void add(int l, int r, ll x) {
	
	A.addrange(l, r, x);
	
}

void set_range(int l, int r, long long x) {
	
	A.setrange(l, r, x);
	
}

ll get_min(int l, int r) {
	
	return A.getmin(l, r);
	
}

int lower_bound(int l, int r, long long x) {
	
	return A.lowerbound(l, r, x);
	
}