#include <iostream>
#include <vector>
using namespace std;

struct Node{
	long long sum = 0, lazyAdd = 0;
	Node *left = NULL, *right = NULL;
	Node(){
		sum = 0;
		left = NULL;
		right = NULL;
		lazyAdd = 0;
	}
	Node(Node* node){
		sum = node->sum;
		lazyAdd = node->lazyAdd;
		left = node->left;
		right = node->right;
	}
	Node(Node* node, long long add){
		sum = node->sum;
		lazyAdd = node->lazyAdd + add;
		left = node->left;
		right = node->right;
	}
	Node(Node* l, Node* r){
		left = l;
		right = r;
		sum = left->sum + right->sum;
		lazyAdd = 0;
	}
	Node(long long s, Node *left_ = NULL, Node *right_ = NULL){
		sum = s;
		left = left_;
		right = right_;
		lazyAdd = 0;
	}
	void merge(Node* a, Node* b){
		sum = a->sum + b->sum;
	}
};


// vector<Node> preAlloc(12500000);
// int lastNode = 0;
// inline Node* get_new_node() {
// 	lastNode++;
// 	return &preAlloc[lastNode - 1];
// }

int n;
vector<Node*> nodes;
void init(Node* node, int l, int r, vector<int>& V){
	if (r - l == 1){
		node->sum = V[l];
		return;
	}

	node->left = new Node();
	node->right = new Node();

	init(node->left, l, (l+r)/2, V);
	init(node->right, (r+l)/2, r, V);

	node->merge(node->left, node->right);
}

void fix_lazy(Node* node, int l, int r){
	if (r - l == 1){
		node->sum += node->lazyAdd;
		node->lazyAdd = 0;
	} else {
		node->right->lazyAdd += node->lazyAdd;
		node->left->lazyAdd += node->lazyAdd;
		node->sum += node->lazyAdd * (r - l);
		node->lazyAdd = 0;
	}
}

Node* update(Node *node, int l, int r, int x, int y, long long v){
	fix_lazy(node, l, r);
	if (r <= x || y <= l) return new Node(node);
	if (x <= l && r <= y) {
		Node* nn = new Node(node, v);
		fix_lazy(nn, l, r);
		return nn;
	}

	return new Node(
		update(node->left, l, (l+r)/2, x, y, v),
		update(node->right, (l+r)/2, r, x, y, v)
	);
}

Node* make_copy(Node* node, Node* copy, int l, int r, int x, int y){
	fix_lazy(node, l, r);
	if (r <= x || y <= l) return new Node(node);
	if (x <= l && r <= y) return new Node(copy);

	return new Node(
		make_copy(node->left, copy->left, l, (l+r)/2, x, y),
		make_copy(node->right, copy->right, (l+r)/2, r, x, y)
	);
}

long long get_sum(Node* node, int l, int r, int x, int y){
	fix_lazy(node, l, r);
	if (r <= x || y <= l) return 0;
	if (x <= l && r <= y) return node->sum;
	return get_sum(node->left, l, (l+r)/2, x, y) + 
		   get_sum(node->right, (l+r)/2, r, x, y);
}

void print(Node* node, int l = 0, int r = n, int d = 0){
	if (node == NULL) return;
	fix_lazy(node, l, r);
	for (int i = 0; i < d; i++) cout << "\t";
	cout << "l:(\n";
	print(node->left, l, (l+r)/2, d+1);
	for (int i = 0; i < d; i++) cout << "\t";
	cout << ")\n";
	for (int i = 0; i < d; i++) cout << "\t";
	cout << node->sum << " \n";
	for (int i = 0; i < d; i++) cout << "\t";
	cout << "r:(\n";
	print(node->right, (l+r)/2, r, d+1);
	for (int i = 0; i < d; i++) cout << "\t";
	cout << ")\n";
}


vector<Node*> roots;

void inizia(int N, vector<int> A){
	n = A.size();

	roots.push_back(new Node());
	init(roots[0], 0, N, A);
	// print(roots.back());
}

void incrementa(int l, int r, int x){
	roots.push_back(update(roots.back(), 0, n, l, r, x));
	// print(roots.back());
}

void resetta(int l, int r, int v){
	roots.push_back(make_copy(roots.back(), roots[v], 0, n, l, r));
	// print(roots.back());
}

long long somma(int l, int r){
	return get_sum(roots.back(), 0, n, l, r);
}
