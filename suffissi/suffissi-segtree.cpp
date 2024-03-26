#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

struct Node{
	vector<int> nums;
	int distinct = 0;
	Node(){
		distinct = 0;
	}
	Node(int n){
		nums.push_back(n);
		distinct = 1;
	}
	void merge(const Node& a, const Node& b){
		nums = vector<int>(0);
		int la = a.nums.size();
		int lb = b.nums.size();
		nums.reserve(la + lb);
		int ia = 0, ib = 0;
		while (ia < la || ib < lb){
			if (ia == la){
				nums.push_back(b.nums[ib++]);
			}
			else if (ib == lb){
				nums.push_back(a.nums[ia++]);
			}
			else if (a.nums[ia] < b.nums[ib]){
				nums.push_back(a.nums[ia++]);
			} else if (a.nums[ia] > b.nums[ib]){
				nums.push_back(b.nums[ib++]);
			} else if (a.nums[ia] == b.nums[ib]){
				nums.push_back(a.nums[ia]);
				ia++;
				ib++;
			}
		}
		distinct = nums.size();
	}
};

struct ST{

	int n, real_size;
	vector<Node> nodes;

	ST(vector<int>& V){
		n = V.size();

		real_size = 1;
		while (real_size < n)
			real_size *= 2;
		
		nodes.assign(2 * real_size, Node());

		build(1, 0, real_size, V);
	}

	void build(int u, int l, int r, vector<int>& V){
		if (r-l == 1){
			if (l < n)
				nodes[u] = Node(V[l]);
			else
				nodes[u] = Node();
		} else {
			build(u * 2, l, (l+r)/2, V);
			build(u*2+1, (l+r)/2, r, V);
			nodes[u].merge(nodes[u*2], nodes[u*2+1]);
		}
	}

	Node get_ans(int u, int l, int r, int x, int y){

		if (r <= x || l >= y){
			return Node();
		}

		if (x <= l && r <= y){
			return nodes[u];
		}

		Node ans;
		ans.merge(
			get_ans(u * 2, l, (l+r)/2, x, y),
			get_ans(u*2+1, (l+r)/2, r, x, y)
		);
		return ans;
	}

	int get_ans(int x){
		Node ans = get_ans(1, 0, real_size, x, real_size);
		return ans.distinct;
	}

};


int main(){

	int N, M;
	cin >> N >> M;

	vector<int> A(N);
	for (int &n : A) cin >> n;

	ST segtree(A);

	int b;
	while (M--){
		cin >> b;
		cout << segtree.get_ans(b-1) << "\n";
	}

	return 0;
}