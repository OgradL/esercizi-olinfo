#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct Node{
	Node *L, *R;
	long long lazyAdd;
	long long sum;
	Node(){
		L = R = NULL;
		lazyAdd = sum = 0;
	}
	Node(Node* nodo){
		L = nodo->L;
		R = nodo->R;
		lazyAdd = nodo->lazyAdd;
		sum = nodo->sum;
	}
	Node(Node* left, Node* right){
		L = left;
		R = right;
		sum = L->sum + R->sum;
	}
	void merge(Node* left, Node* right){
		sum = left->sum + right->sum;
	}
};

vector<Node*> prealloc(1500000);
int prealloc_idx = 0;
Node* get_new_node(){
	prealloc_idx++;
	return prealloc[prealloc_idx-1];
}

void fix_lazy(Node* root, int l, int r){
	if (root->lazyAdd == 0)
		return;

	if (r - l <= 1){
		root->lazyAdd = 0;
		return;
	}

	root->L = new Node(root->L);
	root->L->lazyAdd += root->lazyAdd;
	root->L->sum += 

	root->R = new Node(root->R);
	root->R->lazyAdd += root->lazyAdd;

	root->lazyAdd = 0;
}

int real_size;
int n;
void build(Node* root, int l, int r, vector<int>& A){
	if (r - l == 1){
		if (l < n)
			root->sum = A[l];
	} else {
		root->L = new Node();
		build(root->L, l, (l+r)/2, A);

		root->R = new Node();
		build(root->R, (l+r)/2, r, A);

		root->merge(root->L, root->R);
	}
}

Node* range_add(Node* root, int l, int r, int x, int y, long long val){
	fix_lazy(root, l, r);
	if (x <= l && r <= y){
		Node* new_root = new Node(root);
		new_root->lazyAdd += val;
		fix_lazy(new_root, l, r);
		return new_root;
	}
	if (r <= x || y <= l){
		return root;
	}
	return new Node(
		range_add(root->L, l, (l+r)/2, x, y, val),
		range_add(root->R, (l+r)/2, r, x, y, val)
	);
}

Node* range_reset(Node* root, Node* copyroot, int l, int r, int x, int y){
	fix_lazy(root, l, r);
	fix_lazy(copyroot, l, r);
	if (x <= l && r <= y){
		Node* new_root = new Node(copyroot);
		return new_root;
	}
	if (r <= x || y <= l){
		Node* new_root = new Node(root);
		return new_root;
	}
	return new Node(
		range_reset(root->L, copyroot->L, l, (l+r)/2, x, y),
		range_reset(root->R, copyroot->R, (l+r)/2, r, x, y)
	);
}

long long get_sum(Node* root, int l, int r, int x, int y){
	fix_lazy(root, l, r);
	if (x <= l && r <= y){
		return root->sum;
	}
	if (r <= x || y <= l){
		return 0;
	}
	return
		get_sum(root->L, l, (l+r)/2, x, y) +
		get_sum(root->R, (l+r)/2, r, x, y);
}

vector<Node*> versioni;

void inizia(int N, vector<int> A){
	Node* root = new Node();
	real_size = 1<<(int)(ceil(log2(N)));
	n = N;
	build(root, 0, real_size, A);
	versioni.push_back(root);
}

void incrementa(int l, int r, int x){
	Node* new_root = range_add(versioni.back(), 0, real_size, l, r, x);
	versioni.push_back(new_root);
}

void resetta(int l, int r, int v){
	Node* new_root = range_reset(versioni.back(), versioni[v], 0, real_size, l, r);
	versioni.push_back(new_root);
}

long long somma(int l, int r){
	return get_sum(versioni.back(), 0, real_size, l, r);
}

