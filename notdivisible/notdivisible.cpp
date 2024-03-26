#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
using namespace std;

const long long maxn = 1e6 + 4;
long long BLOCK = 10;
long long BLOCK_primes = 10;

struct query{
	int l, r, idx;
};

vector<bool> active;
vector<int> depth, lg;
vector<int> tour, tin, tout;
vector<int> tour2, tin2, tout2;
vector<int> primes, is_prime;
vector<long long> V;
int timer = 0, timer2 = 0;
vector<vector<int>> G, st;
vector<int> missing_numbers, count_block;
vector<int> count_primes;

void dfs(int u, int d = 0, int p = 0){
	depth[u] = d;
	tour.push_back(u);
	tin[u] = timer++;
	tour2.push_back(u);
	tin2[u] = timer2++;
	for (int x : G[u]){
		if (x != p){
			dfs(x, d+1, u);
			tour2.push_back(u);
			timer2++;
		}
	}
	tour.push_back(u);
	tout[u] = timer++;
	tout2[u] = timer-1;
}

int is_ancestor(int u, int v){
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

void build_st(int N){
	for (int i = 0; i < N; i++)
		st[0][i] = tour2[i];
	for (int i = 1; i < 18; i++){
		for (int j = 0; j + (1 << i) < N; j++){
			if (depth[st[i-1][j]] < depth[st[i-1][j + (1 << (i-1))]])
				st[i][j] = st[i-1][j];
			else
				st[i][j] = st[i-1][j + (1 << (i-1))];
		}
	}
}

int lca(int a, int b){
	if (a == b)
		return a;
	if (tin[a] > tin[b])
		swap(a, b);
	int i = lg[tin[b] - tin[a] + 1];
	int ans = (depth[st[i][tin[a]]] < depth[st[i][tin[b] - (1 << i) + 1]]) ? st[i][tin[a]] : (st[i][tin[b] - (1 << i) + 1]);
	return ans;
}

void add(int pos){
	int number = V[tour[pos]];
	if (is_prime[number]){
		int prime_idx = is_prime[number]-1;
		if (count_primes[prime_idx]++ == 0){
			missing_numbers[prime_idx] = 0;
			count_block[prime_idx / BLOCK_primes]--;
		}
	}
}

void remove(int pos){
	int number = V[tour[pos]];
	if (is_prime[number]){
		int prime_idx = is_prime[number]-1;
		if (--count_primes[prime_idx] == 0){
			missing_numbers[prime_idx] = 1;
			count_block[prime_idx / BLOCK_primes]++;
		}
	}
}

void toggle(int pos){
	if (active[tour[pos]]) remove(pos);
	else add(pos);
	active[tour[pos]] = !active[tour[pos]];
}

int get_answer(){
	int b = 0;
	for (int i = 0; i < BLOCK_primes; i++){
		if (count_block[i]){
			b = i;
			break;
		}
	}
	for (int i = b * BLOCK_primes; i < (b+1) * BLOCK_primes; i++){
		if (missing_numbers[i])
			return primes[i];
	}
	return primes.back();
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	V.resize(N);
	for (long long& x : V)
		cin >> x;
	
	G.resize(N);
	int a, b;
	for (int i = 1; i < N; i++){
		cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	is_prime.assign(maxn, 1);
	int prime_idx = 0;
	for (int i = 2; i < maxn; i++){
		if (is_prime[i]){
			is_prime[i] = ++prime_idx;
			for (int j = i+i; j < maxn; j += i){
				is_prime[j] = 0;
			}
			primes.push_back(i);
		}
	}

	BLOCK_primes = sqrt(prime_idx) + 1;
	missing_numbers.assign(prime_idx, 1);
	count_block.assign(BLOCK_primes, BLOCK_primes);
	
	count_primes.assign(prime_idx, 0);
	tin.resize(N);
	tout.resize(N);
	tin2.resize(N);
	tout2.resize(N);
	depth.resize(N);
	dfs(0);

	active.assign(N, 0);
	N = timer;
	BLOCK = sqrt(N) + 1;

	N = timer2;
	lg.resize(N);
	lg[0] = lg[1] = 0;
	for (int i = 2; i < N; i++)
		lg[i] = lg[i/2] + 1;
	st.assign(18, vector<int>(N));
	build_st(N);

	int Q;
	cin >> Q;

	vector<query> queries(Q);
	vector<long long> answer(Q);
	for (int i = 0; i < Q; i++){
		cin >> a >> b;
		--a, --b;
		if (is_ancestor(a, b)) queries[i] = (query){tin[a], tin[b], i};
		else if (is_ancestor(b, a)) queries[i] = (query){tin[b], tin[a], i};
		else queries[i] = (query){min(tout[a], tout[b]), max(tin[a], tin[b]), i};
	}

	sort(queries.begin(), queries.end(), [&](const query& a, const query& b){
		if (a.l / BLOCK != b.l / BLOCK){
			return a.l < b.l;
		} else {
			if ((a.l / BLOCK) % 2){
				return a.r > b.r;
			} else {
				return a.r < b.r;
			}
		}
	});
	
	int curr_l = 0, curr_r = 0, nl, nr;
	toggle(0);
	for (auto [l, r, idx] : queries){
		nl = tour[l]; nr = tour[r];
		while (curr_l > l) toggle(--curr_l);
		while (curr_r < r) toggle(++curr_r);
		while (curr_l < l) toggle(curr_l++);
		while (curr_r > r) toggle(curr_r--);
		int v = lca(nl, nr);
		if (nl != v && nr != v) toggle(tin[v]);
		answer[idx] = get_answer();
		if (nl != v && nr != v) toggle(tin[v]);
	}

	for (long long x : answer)
		cout << x << '\n';

	return 0;
}