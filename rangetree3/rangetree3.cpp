#include <iostream>
#include <vector>
#include <limits>
using namespace std;


const static constexpr long long MAX = numeric_limits<long long>::max();
const static constexpr long long MIN = numeric_limits<long long>::min();


long long max(initializer_list<long long> Tl){

	vector<long long> arr;
	arr.insert(arr.begin(), Tl.begin(), Tl.end());

	long long ma = MIN;
	int size = arr.size();

	for (int i = 0; i < size; i++){
		if (arr[i] > ma){
			ma = arr[i];
		}
	}

	return ma;
}


struct Node{
	long long val;
	long long sum;
	long long lsm;
	long long lsr;
	long long lsl;
	Node(){
		val = 0;
		sum = 0;
		lsm = MIN;
		lsr = MIN;
		lsl = MIN;
	}
	void join(const Node& a, const Node& b){
		val = 0;
		sum = a.sum + b.sum;
		lsr = max({b.lsr, b.sum + a.lsr});
		lsl = max({a.lsl, a.sum + b.lsl});
		lsm = max({a.lsm, b.lsm, a.lsr + b.lsl, lsr, lsl});
	}
	long long get_max(){
		return max({lsl, lsm, lsr});
	}
	void set(int num){
		val = num;
		sum = num;
		lsm = num;
		lsr = num;
		lsl = num;
	}
};

struct ST{
	
	int real_size, n;
	vector<Node> nodes;
	
	ST(vector<int>& A){
		
		n = A.size();
		
		real_size = 1;
		while (real_size < n)
			real_size *= 2;
		
		nodes.assign(2 * real_size, Node());
		
		build(1, 0, real_size, A);
	}
	
	void build(int u, int l, int r, vector<int>& A){
		
		if (r - l == 1){
			nodes[u].set(((l < n)?(A[l]):(0)));
		} else {
			build(u * 2, l, (l+r)/2, A);
			build(u*2+1, (l+r)/2, r, A);
			nodes[u].join(nodes[u*2], nodes[u*2+1]);
		}
		
	}
	
	void update(int pos, int val){
		
		int u = real_size + pos;
		nodes[u].set(val);
		
		while(u > 1){
			
			u /= 2;
			nodes[u].join(nodes[2*u], nodes[2*u+1]);
			
		}
		
	}
	
	
	Node get_sub_max(int u, int l, int r, int x, int y){
		
		if (r <= x || l >= y) return Node();
		
		if (l >= x && r <= y) return nodes[u];
		
		Node n;
		n.join(
			get_sub_max(u * 2, l, (l+r)/2, x, y),
			get_sub_max(u*2+1, (l+r)/2, r, x, y)
		);
		return n;
	}
	
	long long get_sub_max(int x, int y){
		return get_sub_max(1, 0, real_size, x, y).get_max();
	}
};

int main(){
	
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	
	int N, Q;
	
	cin >> N;
	vector<int> A(N);
	for (int &i: A) cin >> i;

	ST segtree(A);

	cin >> Q;
	
	while (Q--){
		
		int op, a, b;
		cin >> op >> a >> b;
		
		if (op == 0) segtree.update(a - 1, b);
		else cout << segtree.get_sub_max(a - 1, b) << "\n";
	}
	
	
	
}