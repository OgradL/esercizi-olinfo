#include <iostream>
using namespace std;


struct Treap{
	int val;
	Treap *L, *R;
	long long pri;
	int sz;

	Treap(int x = 0): val(x), pri(rand()), sz(1), L(NULL), R(NULL) {}

	Treap* assign(Treap* l, Treap* r) {
		L = l;
		R = r;

		sz = 
			(L ? L->sz : 0) +
			1 +
			(R ? R->sz : 0);

		return this;
	}
};

Treap alloc[10000042];
int alloc_idx = 0;
Treap* next_node(int val = 0){
	alloc[alloc_idx].L = NULL;
	alloc[alloc_idx].R = NULL;
	alloc[alloc_idx].pri = rand();
	alloc[alloc_idx].sz = 1;
	alloc[alloc_idx].val = val;
	++alloc_idx;
	return &alloc[alloc_idx-1];
}

int get_sz(Treap* root){
	if (root == NULL) return 0;
	return root->sz;
}


pair<Treap*, Treap*> split(Treap* root, int idx){
	if (root == NULL)
		return {NULL, NULL};

	if (idx < get_sz(root->L)){
		auto [LL, LR] = split(root->L, idx);

		return {LL, root->assign(LR, root->R)};
	} else {
		auto [RL, RR] = split(root->R, idx - get_sz(root->L) - 1);

		return {root->assign(root->L, RL), RR};
	}
}

Treap* merge(Treap* L, Treap* R){
	if (L == NULL) return R;
	if (R == NULL) return L;

	if (L->pri > R->pri){
		return L->assign(L->L, merge(L->R, R));
	} else {
		return R->assign(merge(L, R->L), R->R);
	}
}

Treap* get(Treap* root, int idx){
	if (get_sz(root->L) > idx)
		return get(root->L, idx);
	if (get_sz(root->L) == idx)
		return root;
	return get(root->R, idx - get_sz(root->L) - 1);
}

void insert(Treap*& root, int idx, Treap* X){
	auto [L, R] = split(root, idx);

	root = merge(merge(L, X), R);
}

Treap* remove(Treap*& root, int idx){
	auto [LX, R] = split(root, idx);
	auto [L, X] = split(LX, idx-1);

	root = merge(L, R);
	return X;
}

void heapify(Treap* root){
	Treap* ma = root;
	if (root->L && root->L->pri > ma->pri)
		ma = root->L;
	if (root->R && root->R->pri > ma->pri)
		ma = root->R;

	if (ma != root){
		swap(ma->pri, root->pri);
		heapify(ma);
	}
}

Treap* build(int N, int idx){
	if (N == 0)
		return NULL;
	int mid = N / 2;
	Treap* root = next_node(idx + mid);
	root->L = build(mid, idx);
	root->R = build(N - mid - 1, idx + mid + 1);
	heapify(root);
	root->sz = get_sz(root->L) + 1 + get_sz(root->R);
	return root;
}

Treap* root;

int main(){
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, Q;
	cin >> N >> Q;

	root = build(N, 0);

	char op;
	int i, j;
	while (Q--){
		cin >> op;

		if (op == 's'){
			cin >> i >> j;

			insert(root, j-1, remove(root, i));
		}
		if (op == 'c'){
			cin >> i;
			cout << get(root, i)->val << " ";
		}
	}
	cout << "\n";

	return 0;
}
