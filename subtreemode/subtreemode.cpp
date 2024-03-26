#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> max_pi(const pair<int, int>& a, const pair<int, int>& b){
	if (a.first == b.first)
		if (a.second < b.second)
			return a;
		else
			return b;
	if (a.first > b.first) return a;
	return b;
}


struct Node{
	pair<int, int> ma;
	Node *left = NULL, *right = NULL;
	Node(){
		ma = {0, 0};
		left = NULL;
		right = NULL;
	}
	Node(Node* l, Node* r){
		left = l;
		right = r;
		ma = max_pi(left->ma, right->ma);
	}
	Node(pair<int, int> s, Node *left_ = NULL, Node *right_ = NULL){
		ma = s;
		left = left_;
		right = right_;
	}
	void merge(Node* a, Node* b){
		ma = max_pi(a->ma, b->ma);
	}
};


vector<Node*> nodes;
void init(Node* node, int l, int r, vector<long long>& V){
	if (r - l == 1){
		node->ma = {V[l], l};
		return;
	}

	node->left = new Node();
	node->right = new Node();
 
	init(node->left, l, (l+r)/2, V);
	init(node->right, (r+l)/2, r, V);

	node->merge(node->left, node->right);
}

Node* update(Node *node, int l, int r, int k, long long x){
	if (r - l == 1){
		return new Node({x, l});
	}
	if ((l+r)/2 <= k){
		return new Node(node->left, update(node->right, (l+r)/2, r, k, x));
	} else {
		return new Node(update(node->left, l, (l+r)/2, k, x), node->right);
	}
}

void make_copy(int k){
	Node *new_node = new Node(nodes[k]->ma, nodes[k]->left, nodes[k]->right);
	nodes.push_back(new_node);
}

pair<int, int> get_max(Node* node, int l, int r, int x, int y){
	if (r <= x || y <= l) return {0, l};
	if (x <= l && r <= y) return node->ma;
	return max_pi(get_max(node->left, l, (l+r)/2, x, y),
				  get_max(node->right, (l+r)/2, r, x, y));
}


int tour_idx = 0;
vector<int> tour, fin, fout;
void dfs(int u, vector<vector<int>>& G, vector<int>& V, int p = -1){
	fin[u] = tour_idx;
	tour[tour_idx++] = V[u];
	for (int& x : G[u])
		if (x != p)
			dfs(x, G, V, u);
	fout[u] = tour_idx;
}

vector<int> solve(int n, vector<int> p, vector<int> a) {

	vector<vector<int>> G(n);

	for (int i = 0; i < n-1; i++){
		G[p[i]].push_back(i);
	}

	tour.resize(n);
	fin.resize(n);
	fout.resize(n);
	dfs(0, G, a);


	nodes.push_back(new Node());
	vector<long long> zeros(n, 0);
	init(nodes[0], 0, n, zeros);
	
	nodes[0] = update(nodes[0], 0, n, tour[0], 1);
	vector<int> last(n, -1);
	last[tour[0]] = 0;
	
	for (int i = 1; i < n; i++){
		make_copy(i-1);
		if (last[tour[i]] != -1)
			nodes[i] = update(nodes[i], 0, n, last[tour[i]], 0);
		last[tour[i]] = i;
		nodes[i] = update(nodes[i], 0, n, i, 1);
	}

	vector<int> ans(n);

	for (int i = 0; i < n; i++){
		ans[i] = get_max(nodes[fout[i]-1], 0, n, fin[i], fout[i]).second;
	}

	return ans;
}
