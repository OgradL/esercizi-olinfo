#include <iostream>
#include <vector>
using namespace std;

#define sz(v) (int)(v.size())

struct Node{
	Node *L = NULL, *R = NULL;
	long long sum = 0;
	Node(){ sum = 0; L = R = NULL; }
	Node(int v){ sum = v; L = R = NULL; }
	Node(Node* nl, Node* nr){
		sum = nl->sum + nr->sum;
		L = nl;
		R = nr;
	}
	void merge(Node* nl, Node* nr){
		sum = nl->sum + nr->sum;
	}
};

int n;
vector<Node*> nodes;

void init(Node* node, int l, int r){
	if (r - l == 1){
		return;
	}

	node->L = new Node();
	node->R = new Node();

	init(node->L, l, (l+r)/2);
	init(node->R, (r+l)/2, r);

	node->merge(node->L, node->R);
}

Node* update(Node* node, int l, int r, int idx, int d){
	if (r - l == 1){
		return new Node(node->sum + d);
	}
	if ((l+r)/2 <= idx){
		return new Node(node->L, update(node->R, (l+r)/2, r, idx, d));
	} else {
		return new Node(update(node->L, l, (l+r)/2, idx, d), node->R);
	}
}

int get_sum(Node* node, int l, int r, int x, int y){
	if (x <= l && r <= y) return node->sum;
	if (l >= y || r <= x) return 0;
	return 
		get_sum(node->L, l, (l+r)/2, x, y) +
		get_sum(node->R, (l+r)/2, r, x, y);
}

void inizia(int N, int K, int V[], int R[]){
	n = N;

	Node* root = new Node();
	init(root, 0, n);

	vector<vector<int>> poss(K);
	for (int i = 0; i < N; i++){
		int type = V[i];
		poss[type].push_back(i);

		if (sz(poss[type]) >= R[type] + 0){
			root = update(root, 0, n, poss[type][sz(poss[type]) - R[type]], R[type]);
		}
		if (sz(poss[type]) >= R[type] + 1){
			root = update(root, 0, n, poss[type][sz(poss[type]) - R[type] - 1], -2 * R[type]);
		}
		if (sz(poss[type]) >= R[type] + 2){
			root = update(root, 0, n, poss[type][sz(poss[type]) - R[type] - 2], R[type]);
		}
		nodes.push_back(root);
	}
}

int istiga(int i, int j){
	return get_sum(nodes[j], 0, n, i, j + 1);
}