#include <iostream>
#include <vector>
#include <math.h>
#include <tuple>
using namespace std;

struct trie{
	trie* next[2];
	int best = 0;
};

vector<trie> pre_alloc(3e6);
int alloc_idx = 0;

trie* new_node(){
	trie* node = &pre_alloc[alloc_idx];
	++alloc_idx;

	node->best = 0;
	node->next[0] = node->next[1] = NULL;

	return node;
}

trie* new_node(trie* l, trie* r){
	trie* node = new_node();

	node->next[0] = l;
	node->next[1] = r;

	if (l){
		node->best = max(node->best, l->best);
	}
	if (r){
		node->best = max(node->best, r->best);
	}

	return node;
}

trie* new_node(int b){
	trie* node = new_node();

	node->best = b;
	
	return node;
}

vector<trie*> roots;
vector<int> history;

trie* insert(trie* root, trie* opposite, int x, int len = 30){
	if (len < 0){
		return new_node(
			max(root->best, opposite ? x : 0)
		);
	}

	int bit = 1 << len;
	int b = (x & bit) >> len;


	trie* other = NULL;
	if (opposite != NULL){
		if (opposite->next[!b] != NULL){
			other = opposite->next[!b];
			x |= bit;
		} else if (opposite->next[b] != NULL){
			other = opposite->next[b];
			x &= ~bit;
		}
	}

	trie* next_branch = root->next[b];
	if (root->next[b] == NULL){
		next_branch = new_node();
	}

	if (b){
		return new_node(
			root->next[0],
			insert(next_branch, other, x, len-1)
		);
	} else {
		return new_node(
			insert(next_branch, other, x, len-1),
			root->next[1]
		);
	}
}

void insert(int x){
	history.push_back(alloc_idx);
	trie* this_root = roots.back();
	trie* new_root = insert(this_root, this_root, x);
	roots.push_back(new_root);
}

int get_answer(){
	if (roots.empty())
		return 0;
	return roots.back()->best;
}

void rollback(){
	alloc_idx = history.back();
	history.pop_back();
	roots.pop_back();
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, Q;
	cin >> N >> Q;

	vector<vector<pair<long long, long long>>> adj(N);
	long long a, b, w;
	for (int i = 0; i < N-1; i++){
		cin >> a >> b >> w;
		--a, --b;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	
	vector<long long> values(N);
	auto dfs = [&](auto&& dfs, int v, int p, long long w) -> void {
		values[v] = w;
		for (auto [x, ew] : adj[v]){
			if (x == p) continue;
			dfs(dfs, x, v, w ^ ew);
		}
	};

	dfs(dfs, 0, 0, 0);

	vector<tuple<int, int, int>> queries;

	vector<int> pres(N, -1);
	int x;
	for (int idx = 0; idx < Q; idx++){
		cin >> x;
		--x;
		if (pres[x] != -1){
			queries.push_back(tuple<int, int, int>(x, pres[x], idx));
			pres[x] = -1;
		} else {
			pres[x] = idx;
		}
	}
	
	for (int i = 0; i < N; i++){
		if (pres[i] != -1)
			queries.push_back(tuple<int, int, int>(i, pres[i], Q));
	}

	int sz = 1<<int(ceil(log2(Q)));

	vector<vector<int>> updates(2*sz);

	for (auto [x, l, r] : queries){
		for (l += sz, r += sz; l < r; l /= 2, r /= 2){
			if (l & 1) updates[l++].push_back(x);
			if (r & 1) updates[--r].push_back(x);
		}
	}

	vector<int> answer(Q, 0);
	
	auto dfs2 = [&](auto&& dfs2, int v, int l, int r) -> void {
		if (r - l < 1)
			return;

		for (int x : updates[v]){
			insert(values[x]);
		}

		if (r - l == 1){
			if (l < Q)
				answer[l] = get_answer();
		} else {
			dfs2(dfs2, 2 * v, l, (l+r)/2);
			dfs2(dfs2, 2*v+1, (l+r)/2, r);
		}

		for (int x : updates[v]){
			rollback();
		}
	};

	roots.push_back(new trie());
	dfs2(dfs2, 1, 0, sz);

	for (int x : answer){
		cout << x << '\n';
	}
	cout << "\n";

	return 0;
}
