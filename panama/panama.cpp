#include <iostream>
#include <vector>
#include <random>
using namespace std;

#define ll long long

const static constexpr ll MAX = 1e15+10;
const static constexpr ll MIN = -1e15-10;


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
	
	long long query(int x, int y){
		return get_sub_max(1, 0, real_size, x, y).get_max();
	}

    
	void print(){
		cout << "\n\n TREE: \n";
		int ji = 1;
		int l = 2;
		for (int i = 1; i < nodes.size(); i++){
			cout << "{ " << nodes[i].lsl << " " << nodes[i].lsm << " " << nodes[i].lsr << " " << nodes[i].sum << "} ";
			ji++;
			if (ji == l){
				l *= 2;
				cout << "\n";
			}
		}
        cout << "\n\n";
	}

};



int main(){

    int N, Q;
    cin >> N >> Q;

    vector<int> V1(N), V2(N);
    for (int i = 0; i < N; i++){
        cin >> V1[i];
        V2[i] = V1[i];
    }

    for (int i = 0; i < N; i++){
        V1[i] = V1[i]*((i%2==0)?(1):(-1));
        // cout << V1[i] << " ";
    }
    // cout << "\n";
    for (int i = 0; i < N; i++){
        V2[i] = V2[i]*((i%2==1)?(1):(-1));
        // cout << V2[i] << " ";
    }
    // cout << "\n";

    ST segtree1(V1);
    ST segtree2(V2);

    ll a1, a2;

    int op, x, y;
    while (Q--){
        cin >> op >> x >> y;
        
        if (op == 1){
            segtree1.update(x-1, y*((x%2==1)?(1):(-1)));
            segtree2.update(x-1, y*((x%2==0)?(1):(-1)));
        } else {
            // cout << "query su " << x-1 << " - " << y-1 << "\n";
            a1 = segtree1.query(x-1, y);
            a2 = segtree2.query(x-1, y);
            // segtree1.print();
            // segtree2.print();
            // cout << a1 << " " << a2 << "\n";
            cout << max(a1, a2) << "\n";
        }
    }


    return 0;
}