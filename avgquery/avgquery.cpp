#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;

struct Treap{
	long long val, sum;
	long long pri;
	int sz;
	int left;
	int right;
};

const int N_NODES = 5e6;

vector<Treap> treap_nodes(N_NODES);
int alloc_idx = 1;
int get_node(long long v = 0){
	treap_nodes[alloc_idx].val = v;
	treap_nodes[alloc_idx].sum = v;
	treap_nodes[alloc_idx].pri = rand();
	treap_nodes[alloc_idx].sz = 1;
	treap_nodes[alloc_idx].left = 0;
	treap_nodes[alloc_idx].right = 0;
	++alloc_idx;
	assert(alloc_idx < N_NODES);
	return alloc_idx - 1;
};

int get_sz(int p){
	if (p)
		return treap_nodes[p].sz;
	return 0;
}

long long get_node_sum(int p){
	if (p)
		return treap_nodes[p].sum;
	return 0;
}

int join(int p, int a, int b){
	treap_nodes[p].left = a;
	treap_nodes[p].right = b;
	treap_nodes[p].sz = 1 + get_sz(a) + get_sz(b);
	treap_nodes[p].sum = treap_nodes[p].val + get_node_sum(a) + get_node_sum(b);
	return p;
}

pair<int, int> split(int node, long long x){
	if (!node)
		return {0, 0};
	if (treap_nodes[node].val <= x){
		auto [RL, RR] = split(treap_nodes[node].right, x);
		join(node, treap_nodes[node].left, RL);
		return {node, RR};
	} else {
		auto [LL, LR] = split(treap_nodes[node].left, x);
		join(node, LR, treap_nodes[node].right);
		return {LL, node};
	}
}

pair<int, int> split_by_index(int node, int idx){
	if (!node)
		return {0, 0};
	if (get_sz(treap_nodes[node].left) < idx){
		auto [RL, RR] = split_by_index(treap_nodes[node].right, idx - get_sz(treap_nodes[node].left) - 1);
		join(node, treap_nodes[node].left, RL);
		return {node, RR};
	} else {
		auto [LL, LR] = split_by_index(treap_nodes[node].left, idx);
		join(node, LR, treap_nodes[node].right);
		return {LL, node};
	}
}

int merge(int a, int b){
	if (!a) return b;
	if (!b) return a;
	if (treap_nodes[a].pri < treap_nodes[b].pri){
		join(b, merge(a, treap_nodes[b].left), treap_nodes[b].right);
		return b;
	} else {
		join(a, treap_nodes[a].left, merge(treap_nodes[a].right, b));
		return a;
	}
}

int insert(int node, long long val){
	int v = get_node(val);
	auto [L, R] = split(node, val);
	L = merge(L, v);
	return merge(L, R);
}

int remove(int node, long long val){
	auto [LX, R] = split(node, val);
	auto [L, X] = split_by_index(LX, get_sz(LX)-1);

	assert(get_sz(X) == 1);
	return merge(L, R);
}

pair<long long, long long> get_sum(int node, long long x){
	if (!node)
		return {0, 0};

	long long sum = 0, count = 0;
	if (treap_nodes[node].val >= x){
		sum += treap_nodes[node].val;
		sum += get_node_sum(treap_nodes[node].right);
		count += get_sz(treap_nodes[node].right) + 1;

		auto [s, c] = get_sum(treap_nodes[node].left, x);
		sum += s;
		count += c;
	} else {
		auto [s, c] = get_sum(treap_nodes[node].right, x);
		sum += s;
		count += c;
	}

	return {sum, count};
}

map<int, int> freq;
vector<long long> values;
vector<int> nodes;
int n;

void heapify(int root){
	int ma = root;
	if (treap_nodes[root].left && treap_nodes[treap_nodes[root].left].pri > treap_nodes[ma].pri)
		ma = treap_nodes[root].left;
	if (treap_nodes[root].right && treap_nodes[treap_nodes[root].right].pri > treap_nodes[ma].pri)
		ma = treap_nodes[root].right;

	if (ma != root){
		swap(treap_nodes[ma].pri, treap_nodes[root].pri);
		heapify(ma);
	}
}

int build(int N, int idx, vector<int>& V){
	if (N == 0)
		return 0;
	int mid = N / 2;
	int node_idx = idx + mid;
	if (node_idx >= n)
		node_idx = 0;
	int root = get_node(V[node_idx]);
	treap_nodes[root].left = build(mid, idx, V);
	treap_nodes[root].right = build(N - mid - 1, idx + mid + 1, V);
	heapify(root);
	return join(root, treap_nodes[root].left, treap_nodes[root].right);
}

void build(vector<int>& A){
	for (int i = 0; i < n; i++){
		nodes[n+i] = get_node(A[i]);
	}
	for (int i = n-1; i > 0; i--){
		int sz0 = get_sz(nodes[i<<1]);
		int sz1 = get_sz(nodes[i<<1|1]);
		int sz = sz0 + sz1;
		int idx = i;
		while (idx < n)
			idx <<= 1;
		idx -= n;

		// sort(A.begin() + idx, A.begin() + idx + sz);

		vector<int> new_vals;
		int i0 = idx, i1 = idx + sz0;
		int end0 = i0 + sz0, end1 = i1 + sz1;
		while (i0 < end0 || i1 < end1){
			if (i0 == end0)
				new_vals.push_back(A[i1++]);
			else if (i1 == end1)
				new_vals.push_back(A[i0++]);
			else if (A[i0] < A[i1])
				new_vals.push_back(A[i0++]);
			else
				new_vals.push_back(A[i1++]);
		}

		for (int j = 0; j < sz; j++){
			A[j+idx] = new_vals[j];
		}

		nodes[i] = build(sz, idx, A);
	}
}

pair<long long, long long> query(int l, int r, long long x){
	l += n;
	r += n;
	long long sum = 0, count = 0;
	for (; l < r; l >>= 1, r >>= 1){
		if (l & 1){
			auto [this_sum, this_count] = get_sum(nodes[l], x);
			sum += this_sum;
			count += this_count;
			++l;
		}
		if (r & 1){
			--r;
			auto [this_sum, this_count] = get_sum(nodes[r], x);
			sum += this_sum;
			count += this_count;
		}
	}
	return {sum, count};
}

void update(int idx, long long v, long long old_val){
	for (idx+=n; idx >= 1; idx >>= 1){
		nodes[idx] = insert(nodes[idx], v);
		nodes[idx] = remove(nodes[idx], old_val);
	}
}

void inizia(int N, vector<int> A){
	n = 1;
	while (n < N)
		n <<= 1;
	nodes.assign(2*n, 0);
	values.resize(n);
	for (int i = 0; i < n; i++){
		if (i == A.size())
			A.push_back(0);
		values[i] = A[i];
		freq[A[i]]++;
	}
	build(A);
}

void aggiorna(int P, int C){
	freq[values[P]]--;
	freq[C]++;
	update(P, C, values[P]);
	values[P] = C;
}

int consiglio(int L, int R, int K){
	if (K == 0)
		return -1;
	auto total_sum = query(L, R, 0).first;
	long long ex = K * 1LL * (R - L);
	if (total_sum < ex)
		return 1;
	if (total_sum == ex)
		return 0;

	long long lo = 0, hi = 1e9 + 42, mid, ans = -1;
	long long s = 0, c = 0;
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;

		auto [current_sum, count] = query(L, R, mid);
		long long nsum = total_sum - current_sum + count;

		if (nsum > ex)
			hi = mid;
		else
			lo = mid, s = current_sum, c = count, ans = count;
	}

	long long lo1 = 0, hi1 = freq[lo]+1, mid1;
	while (lo1 + 1 < hi1){
		mid1 = (lo1 + hi1) / 2;

		long long nsum = total_sum - (s - lo * mid1) + c - mid1;
		if (nsum > ex)
			lo1 = mid1;
		else
			hi1 = mid1, ans = min(ans, c - mid1);
	}

	return ans;
}
