#include <string>
#include <vector>
using namespace std;

int N;
string T;

int sassocartaforbice2int(char c){
	if (c == 'S')
		return 0;
	if (c == 'C')
		return 1;
	if (c == 'F')
		return 2;
	return -1;
}

vector<long long> sz, par, cnt[3];

int get_par(int x){
	if (x == par[x])
		return x;
	return par[x] = get_par(par[x]);
}

void onion_set(int a, int b){
	a = get_par(a);
	b = get_par(b);

	if (a != b){
		if (sz[a] < sz[b])
			swap(a, b);
		sz[a] += sz[b];
		par[b] = a;
		cnt[0][a] += cnt[0][b];
		cnt[1][a] += cnt[1][b];
		cnt[2][a] += cnt[2][b];
	}
}

void organizza(int N, string T) {
	::N = N;
	::T = T;

	sz.assign(N, 1);
	par.assign(N, 0);
	cnt[0].assign(N, 0);
	cnt[1].assign(N, 0);
	cnt[2].assign(N, 0);

	for (int i = 0; i < N; i++){
		par[i] = i;
		cnt[sassocartaforbice2int(T[i])][i] = 1;
	}
}

int sfida(int a, int b) {
	int orig_a = a, orig_b = b;

	a = get_par(a);
	b = get_par(b);

	long long score_a = cnt[0][a] * cnt[2][b] + cnt[1][a] * cnt[0][b] + cnt[2][a] * cnt[1][b];
	long long score_b = cnt[0][b] * cnt[2][a] + cnt[1][b] * cnt[0][a] + cnt[2][b] * cnt[1][a];

	if (score_a > score_b){
		return orig_a;
	}
	if (score_a < score_b){
		return orig_b;
	}
	return -1;
}

void allea(int a, int b) {
	onion_set(a, b);
}
