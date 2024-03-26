#include <iostream>
#include <vector>
using namespace std;

struct Node{
	long long sum = 0, lazyAdd = 0;
	Node *L = NULL, *R = NULL;
	int l, r;
	Node(int l_ = 0, int r_ = 0){
		sum = 0;
		L = NULL;
		R = NULL;
		lazyAdd = 0;
		l = l_;
		r = r_;
	}
	Node(Node* node, int l_ = 0, int r_ = 0){
		sum = node->sum;
		lazyAdd = node->lazyAdd;
		L = node->L;
		R = node->R;
		l = l_;
		r = r_;
	}
	Node(Node* node, long long add, int l_ = 0, int r_ = 0){
		sum = node->sum;
		lazyAdd = node->lazyAdd + add;
		L = node->L;
		R = node->R;
		l = l_;
		r = r_;
	}
	Node(Node* pl, Node* pr, int l_ = 0, int r_ = 0){
		L = pl;
		R = pr;
		l = l_;
		r = r_;
		merge();
	}
	Node(long long s, Node *L_ = NULL, Node *R_ = NULL, int l_ = 0, int r_ = 0){
		sum = s;
		L = L_;
		R = R_;
		lazyAdd = 0;
		l = l_;
		r = r_;
	}
	void merge(){
		int mid = (l+r) / 2;
		sum = L->sum + R->sum + L->lazyAdd * (mid - l) + R->lazyAdd * (r - mid);
		lazyAdd = 0;
	}
};

int n;
vector<Node*> nodes;
void init(Node* node, int l, int r, vector<int>& V){
	if (r - l == 1){
		node->sum = V[l];
		return;
	}

	node->L = new Node(l, (l+r)/2);
	node->R = new Node((l+r)/2, r);

	init(node->L, l, (l+r)/2, V);
	init(node->R, (r+l)/2, r, V);

	node->merge();
}

void fix_lazy(Node*& node, int l, int r){
	if (node->lazyAdd == 0)
		return;
	
	Node* newnode = node;
	newnode->sum += node->lazyAdd * (r - l);
	if (r - l > 1){
		Node *prevr = node->R, *prevl = node->L;
		newnode->L = new Node(l, (l+r)/2);
		newnode->R = new Node((l+r)/2, r);

		newnode->L->L = prevl->L;
		newnode->L->R = prevl->R;
		newnode->L->sum = prevl->sum;
		newnode->L->lazyAdd += prevl->lazyAdd + node->lazyAdd;

		newnode->R->L = prevr->L;
		newnode->R->R = prevr->R;
		newnode->R->sum = prevr->sum;
		newnode->R->lazyAdd += prevr->lazyAdd + node->lazyAdd;
	}
	newnode->lazyAdd = 0;
	node = newnode;
}

Node* update(Node *node, int l, int r, int x, int y, long long v){
	fix_lazy(node, l, r);
	if (r <= x || y <= l) return node;
	if (x <= l && r <= y) {
		Node* nn = new Node(node, v, l, r);
		fix_lazy(nn, l, r);
		return nn;
	}
	return new Node(
		update(node->L, l, (l+r)/2, x, y, v),
		update(node->R, (l+r)/2, r, x, y, v),
		l, r
	);
}

Node* make_copy(Node* node, Node* copy, int l, int r, int x, int y){
	if (r <= x || y <= l) return new Node(node, l, r);
	if (x <= l && r <= y) return new Node(copy, l, r);

	return new Node(
		make_copy(node->L, copy->L, l, (l+r)/2, x, y),
		make_copy(node->R, copy->R, (l+r)/2, r, x, y),
		l, r
	);
}

long long get_sum(Node* node, int l, int r, int x, int y){
	fix_lazy(node, l, r);
	if (r <= x || y <= l) return 0;
	if (x <= l && r <= y) {
		return node->sum;
	}
	return get_sum(node->L, l, (l+r)/2, x, y) + 
		   get_sum(node->R, (l+r)/2, r, x, y);
}

vector<Node*> roots;

void inizia(int N, vector<int> A){
	n = A.size();

	roots.push_back(new Node(0, N));
	init(roots[0], 0, N, A);
}

void incrementa(int l, int r, int x){
	roots.push_back(update(roots.back(), 0, n, l, r, x));
}

void resetta(int l, int r, int v){
	roots.push_back(make_copy(roots.back(), roots[v], 0, n, l, r));
}

long long somma(int l, int r){
	return get_sum(roots.back(), 0, n, l, r);
}
