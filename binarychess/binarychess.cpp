#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct DSU{
	vector<long long> parent, sizes;
	DSU(int N){
		parent.assign(N+1, -1);
		sizes.assign(N+1, 1);
		for (int i = 0; i <= N; i++)
			parent[i] = i;
	}
	int find_parent(int v){
		if (parent[v] == -1) return -1;
		if (parent[v] == v) return v;
		return parent[v] = find_parent(parent[v]);
	}
	int onion_set(int a, int b){
		a = find_parent(a);
		b = find_parent(b);
		if (a != b){
			if (sizes[a] < sizes[b])
				swap(a, b);
			parent[b] = a;
			sizes[a] += sizes[b];
			return 1;
		}
		return 0;
	}
};

const long long MOD = 1e9 + 7;

long long POW(long long b, long long e){
	if (e == 0) return 1;
	long long v = POW(b, e/2);
	return (v * v % MOD) * (e&1?b:1) % MOD;
}

void join(int& a, int i, DSU& dsu){
	if (a == 0)
		a = i;
	else
		dsu.onion_set(i, a);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int R, C, N;
	cin >> R >> C >> N;

	DSU dsu(N);

	unordered_map<int, int> col, row, diag1, diag2;

	int r, c;
	for (int i = 1; i <= N; i++){
		cin >> r >> c;

		int& co = col[c];
		int& ro = row[r];
		int& d1 = diag1[r-c];
		int& d2 = diag2[r+c];
		
		join(co, i, dsu);
		join(ro, i, dsu);
		join(d1, i, dsu);
		join(d2, i, dsu);
	}

	int count = 0;
	vector<int> v(N+1);
	for (int i = 1; i <= N; i++){
		count += v[dsu.find_parent(i)]++ == 0;
	}

	cout << POW(2, count) << "\n";

	return 0;
}