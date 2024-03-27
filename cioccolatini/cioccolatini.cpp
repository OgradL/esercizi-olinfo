#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct query{
	int l, r, idx;
};

int BLOCK, BLOCK2;

vector<vector<int>> G, bl;
vector<int> tour, tin, tout;
int timer = 0;
vector<int> c;
vector<int> active;
vector<int> count_nums;
vector<int> block_count;
vector<int> compressed;
vector<int> invcompressed;

void dfs(int u, int p){
	bl[u][0] = p;
	for (int i = 1; i < 20; i++)
		bl[u][i] = bl[bl[u][i-1]][i-1];
	
	tin[u] = timer++;
	tour.push_back(u);
	for (int x : G[u]){
		if (x != p)
			dfs(x, u);
	}
	tout[u] = timer++;
	tour.push_back(u);
}

bool is_ancestor(int a, int b){
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b){
	if (is_ancestor(a, b))
		return a;
	if (is_ancestor(b, a))
		return b;
	for (int i = 19; i >= 0; i--)
		if (!is_ancestor(bl[a][i], b))
			a = bl[a][i];
	return bl[a][0];
}

void add(int pos){
	int u = tour[pos];
	int v = c[u];
	int idx = compressed[v];
	block_count[idx / BLOCK2]--;
	count_nums[idx]--;
}

void remove(int pos){
	int u = tour[pos];
	int v = c[u];
	int idx = compressed[v];
	block_count[idx / BLOCK2]++;
	count_nums[idx]++;
}

void toggle(int pos){
	if (!active[tour[pos]]) add(pos);
	else remove(pos);
	active[tour[pos]] = !active[tour[pos]];
}

int get_answer(){
	int b = 0;
	for (int i = 0; i < BLOCK2; i++){
		if (block_count[i]){
			b = i;
			break;
		}
	}
	for (int i = BLOCK2 * b; i < BLOCK2 * (b+1); i++){
		if (count_nums[i])
			return invcompressed[i];
	}
	return 0;
}

vector<int> raccogli(int N, int Q, vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &L, vector<int> &T){
	c = C;
	int maxc = *max_element(C.begin(), C.end());

	G.resize(N);
	for (int i = 0; i < N-1; i++){
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	tout.resize(N);
	tin.resize(N);
	bl.assign(N, vector<int>(20, 0));

	dfs(0, 0);

	vector<query> queries;
	for (int i = 0; i < Q; i++){
		if (tin[L[i]] > tin[T[i]])
			swap(L[i], T[i]);
		query q = {L[i], T[i], i};
		if (tout[L[i]] < tin[T[i]])
			q = {tout[L[i]], tin[T[i]]+1, i};
		else
			q = {tin[L[i]], tin[T[i]]+1, i};
		queries.push_back(q);
	}

	BLOCK = sqrt(N);
	BLOCK2 = sqrt(tour.size());

	sort(queries.begin(), queries.end(), [](const query& a, const query& b){
		if (a.l / BLOCK != b.l / BLOCK){
			return a.l < b.l;
		} else {
			if ((a.l / BLOCK) % 2 == 0)
				return a.r < b.r;
			else
				return a.r > b.r;
		}
	});

	active.assign(tour.size(), 0);
	block_count.assign(BLOCK2, 0);
	count_nums.assign(N, 0);

	vector<pair<int, int>> nums;
	for (int i = 0; i < N; i++){
		nums.push_back({C[i], i});
	}

	sort(nums.begin(), nums.end(), [](pair<int, int> a, pair<int, int> b){
		return a.first > b.first;
	});

	compressed.assign(maxc+1, 0);
	invcompressed.assign(N, 0);
	for (int i = 0; i < N; i++){
		compressed[nums[i].first] = i;
		invcompressed[i] = nums[i].first;
	}
	for (int i = 0; i < N; i++)
		remove(tin[i]);

	vector<int> answer(Q, 0);
	int curr_l = 0, curr_r = 0;
	for (auto [l, r, idx] : queries){
		while (curr_r < r) toggle(curr_r++);
		while (curr_l > l) toggle(--curr_l);
		while (curr_r > r) toggle(--curr_r);
		while (curr_l < l) toggle(curr_l++);

		int v = lca(tour[l], tour[r]);
		if (tour[l] != v && tour[r] != v) toggle(tin[v]);
		answer[idx] = get_answer();
		if (tour[l] != v && tour[r] != v) toggle(tin[v]);
	}

	return answer;
}