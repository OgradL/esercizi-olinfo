#include <iostream>
#include <vector>
#include <limits>
using namespace std;

template<typename T = long long>
struct Node{
	constexpr static const T MAX = numeric_limits<T>::max();
	constexpr static const T MIN = numeric_limits<T>::min();

	T sum;
	T mi;
	T lazySet;
	T lazyAdd;
	
	Node(){
		sum = 0;
		mi = MAX;
		lazySet = MIN;
		lazyAdd = 0;
	}
	void merge(const Node &l, const Node &r){
		mi = min(l.mi, r.mi);
		sum = l.sum + r.sum;
	}
};

template<typename T = long long>
struct ST{
	
	constexpr static const T MAX = numeric_limits<T>::max();
	constexpr static const T MIN = numeric_limits<T>::min();

	int n, real_size;
	vector<Node<T>> nodes;
	
	ST(vector<T> data){
		
		n = data.size();
		
		real_size = 1;
		while (real_size < n)
			real_size *= 2;
		
		nodes.assign(2 * real_size, Node<T>());
		
		build(1, 0, real_size, data);
	}
	
	ST(){
		// cool
	}
	
	void fixLazyAll(int u, int l, int r, int x, int y){
		if (x >= r || y <= l) return;
		fixLazy(u, l, r);
		if (r - l > 1){
			fixLazyAll(u * 2, l, (l+r)/2, x, y);
			fixLazyAll(u*2+1, (l+r)/2, r, x, y);
		}
	}

	void fixLazyAll(int x = 0, int y = -1){
		y = y == -1 ? real_size : y;
		fixLazyAll(1, 0, real_size, x, y);
	}

	void fixLazy(int u, int l, int r){
		
		if (nodes[u].lazyAdd == 0 && nodes[u].lazySet == MIN) return;
		
		if (nodes[u].lazySet != MIN){
			nodes[u].mi = nodes[u].lazySet;
			nodes[u].sum = nodes[u].lazySet * (r - l);
			
			if (u < real_size){
				nodes[u * 2].lazySet = nodes[u].lazySet;
				nodes[u * 2].lazyAdd = 0;
				
				nodes[u*2+1].lazySet = nodes[u].lazySet;
				nodes[u*2+1].lazyAdd = 0;
			}
			nodes[u].lazySet = MIN;
		}
		if (nodes[u].lazyAdd != 0){
			nodes[u].mi += nodes[u].lazyAdd;
			nodes[u].sum += nodes[u].lazyAdd * (r - l);
			
			if (u < real_size){
				nodes[u * 2].lazyAdd += nodes[u].lazyAdd;
				
				nodes[u*2+1].lazyAdd += nodes[u].lazyAdd;
			}
			nodes[u].lazyAdd = 0;
		}
	}
	
	void build(int u, int l, int r, vector<T>& data){
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
			nodes[u].merge(nodes[2*u], nodes[2*u+1]);
		}
	}
	
	T getsum(int u, int l, int r, int x, int y){
		fixLazy(u, l, r);
		if (r <= x || l >= y) return 0;
		if (x <= l && r <= y) return nodes[u].sum;
		
		return getsum(2*u, l, (l+r)/2, x, y) + getsum(2*u+1, (l+r)/2, r, x, y);
	}
	
	T getsum(int x, int y){
		return getsum(1, 0, real_size, x, y);
	}
	
	
	void setrange(int u, int l, int r, int x, int y, T num){
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
		nodes[u].merge(nodes[2*u], nodes[2*u+1]);
	}
	
	void setrange(int x, int y, T num){
		setrange(1, 0, real_size, x, y, num);
	}
	
};

vector<int> tin, tout, tour;
int eut = 0;

void dfs(int v, vector<vector<int>>& G){
	tin[v] = eut++;
	for (auto x : G[v])
		dfs(x, G);
	tout[v] = eut;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int D, P, E;
	cin >> D >> P >> E;

	vector<vector<int>> G(D + P);
	int a;
	for (int i = 0; i < D + P; i++){
		cin >> a;
		if (a != -1)
			G[a].push_back(i);
	}

	tin.resize(D + P);
	tout.resize(D + P);
	dfs(0, G);
	tour.resize(eut);

	ST<int> segtree(tour);

	int t, id;
	while (E--){
		cin >> t >> id;
		if (t == 0){
			segtree.setrange(tin[id], tout[id], 0);
		}
		if (t == 1){
			segtree.setrange(tin[id], tout[id], 1);
		}
		if (t == 2){
			cout << segtree.getsum(tin[id], tout[id]) << "\n";
		}
	}

	return 0;
}