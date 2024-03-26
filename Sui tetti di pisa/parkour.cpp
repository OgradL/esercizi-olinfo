#include <bits/stdc++.h>

using namespace std;

static constexpr long long MIN = numeric_limits<int>::min();
static constexpr long long MAX = numeric_limits<int>::max();

struct ST{
	
	struct Node{
		int mi;
		
		Node(){
			mi = MAX;
		}
		void join(const Node &l, const Node &r){
			mi = min(l.mi, r.mi);
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
			nodes[u].mi = MAX;
		} else {
			build(2*u, l, (l+r)/2);
			build(2*u+1, (l+r)/2, r);
			nodes[u].join(nodes[2*u], nodes[2*u+1]);
		}
		
	}
	
	void update(int pos, int x){
		
		int u = real_size + pos;
		nodes[u].mi = x;
		
		while(u > 1){
			
			u /= 2;
			nodes[u].join(nodes[2*u], nodes[2*u+1]);
			
		}
		
	}
	
	int get_idx(int pos){
		return nodes[real_size + pos].mi;
	}
	
	int get_min(int u, int l, int r, int x, int y){
		
		if (x >= r || y <= l) return MAX;
		
		if (x <= l && r <= y) {return nodes[u].mi;}
		
		return min(
			get_min(u*2, l, (l+r)/2, x, y),
			get_min(u*2+1, (l+r)/2, r, x, y)
		);
	}
	
	int get_min(int x, int y){
		return get_min(1, 0, real_size, x, y);;
	}
};

int salta(int N, vector<int> S, vector<int> A, vector<int> B){
	
	ST segtree(N);
	
	for (int i = N - 1; i >= 0; i--){
		int val;
		
		if (i + B[i] >= N) {
			segtree.update(i, S[i]);
		} else {
			int passi = segtree.get_min(i + A[i], i + B[i] + 1);
			val = max(passi, S[i]);
			segtree.update(i, val);
		}
	}
	
	return segtree.get_idx(0);
}


int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N;
	
	cin >> N;
	
	vector<int> S(N), A(N), B(N);
	
	
	for (int i = 0; i < N; i++){
		cin >> S[i] >> A[i] >> B[i];
	}
	
	cout << salta(N, S, A, B) << "\n";
	
}


