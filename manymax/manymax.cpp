#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MOD = 1e9 + 7;

struct query{
	int l, r, k;
};

struct node{
	long long v;
	int c;
	int left;
	int right;
};


const int SIZE = 2e7;
node nodes[SIZE];
int pre_i = 0;
inline int get_node(){
	int idx = pre_i++;
	nodes[idx].v = 1;
	nodes[idx].c = 0;
	nodes[idx].left = -1;
	nodes[idx].right = -1;
	return idx;
}

int get_node(node& copy){
	int idx = pre_i++;
	nodes[idx].v = copy.v;
	nodes[idx].c = copy.c;
	nodes[idx].left = copy.left;
	nodes[idx].right = copy.right;
	return idx;
}

int get_node(node& copy, long long m){
	int idx = get_node(copy);
	nodes[idx].v *= m;
	nodes[idx].v %= MOD;
	nodes[idx].c++;
	return idx;
}

int get_node(int left, int right){
	int idx = get_node();
	nodes[idx].left = left;
	nodes[idx].right = right;
	nodes[idx].c = nodes[left].c + nodes[right].c;
	nodes[idx].v = nodes[left].v * nodes[right].v % MOD;
	return idx;
}


int st_size;
vector<int> roots;

void build(int n, int l, int r){
	if (r - l <= 1){
		// nothing, yay!
		return;
	}
	nodes[n].left = get_node();
	nodes[n].right = get_node();
	build(nodes[n].left, l, (l+r)/2);
	build(nodes[n].right, (l+r)/2, r);
}

void init(int N){
	st_size = 1;
	while (st_size < N)
		st_size *= 2;

	roots.push_back(get_node());
	build(roots[0], 0, st_size);
}

int get_count(int n1, int n2, int l, int r, int& k){
	int c = nodes[n2].c - nodes[n1].c;
	if (c <= k){
		k -= c;
		return l;
	}

	int a = get_count(nodes[n1].right, nodes[n2].right, (l+r)/2, r, k);
	if (k == 0)
		return a;
	int b = get_count(nodes[n1].left, nodes[n2].left, l, (l+r)/2, k);
	return b;
}

int get_count(int l, int r, int k){
	return get_count(roots[l], roots[r], 0, st_size, k);
}

int mul(int n, int l, int r, int idx, long long v){
	if (r - l <= 1){
		return get_node(nodes[n], v);
	}
	if ((l+r)/2 > idx){
		return get_node(mul(nodes[n].left, l, (l+r)/2, idx, v), nodes[n].right);
	} else {
		return get_node(nodes[n].left, mul(nodes[n].right, (l+r)/2, r, idx, v));
	}
}

void mul(int idx, long long v){
	int n = roots.back();
	int new_node = mul(n, 0, st_size, idx, v);
	roots.push_back(new_node);
}

long long get_prod(int n, int l, int r, int x){
	if (r <= x)
		return 1;
	if (x <= l)
		return nodes[n].v;
	return  get_prod(nodes[n].left, l, (l+r)/2, x) *
		get_prod(nodes[n].right, (l+r)/2, r, x) % MOD;
}

long long get_prod(int x, int v){
	return get_prod(roots[v], 0, st_size, x);
}

long long POW(long long b, long long e){
	long long ans = 1;
	while (e){
		if (e & 1)
			ans = ans * b % MOD;;
		b = b * b % MOD;
		e /= 2;
	}
	return ans;
}

long long inv(long long x){
	return POW(x, MOD-2);
}

long long get_answer(int l, int r, int k){
	int x = get_count(l, r, k);
	long long a = get_prod(x, l);
	long long b = get_prod(x, r);
	long long ans = b * inv(a) % MOD;
	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, Q;
	cin >> N >> Q;

	vector<int> V(N);
	for (int& x : V)
		cin >> x;

	vector<int> comp = V, count(200001, 0), og(N);
	sort(comp.begin(), comp.end());
	for (int i = 0; i < N; i++){
		og[i] = V[i];
		V[i] = lower_bound(comp.begin(), comp.end(), V[i]) - comp.begin();
		V[i] += count[V[i]]++;
	}

	vector<query> queries(Q);
	int i = 0;
	for (query& x : queries){
		cin >> x.l >> x.r >> x.k;
		++x.r;
	}

	vector<long long> answer(Q);
	init(N);
	for (int i = 0; i < N; i++){
		mul(V[i], og[i]);
	}

	int idx = 0;
	for (auto [l, r, k] : queries){
		answer[idx++] = get_answer(l, r, k);
	}

	for (long long& x : answer)
		cout << x << "\n";

	return 0;
}
