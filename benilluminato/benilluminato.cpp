#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int illumina(int N, int M, vector<int> H, vector<int> A, vector<int> B, vector<int> L) {

	vector<vector<pair<int, int>>> adj(N), adj2(N);
	for (int i = 0; i < M; i++){
		adj[A[i]].push_back({B[i], L[i]});
		adj[B[i]].push_back({A[i], L[i]});
	}

	vector<int> abbattuto(N, 0);

	auto dfs = [&](auto&& dfs, int v, int p) -> void {
		for (auto [x, d] : adj[v]){
			if (x == p) continue;
			if (abbattuto[x]) continue;
			if (H[x] <= d){
				abbattuto[x] = 1;
				dfs(dfs, x, v);
			}
		}
	};

	for (int i = 0; i < M; i++){
		int a = A[i], b = B[i], l = L[i];

		int aab = !abbattuto[a] && H[a] <= l;
		int bab = !abbattuto[b] && H[b] <= l;

		if (aab && bab){
			if (H[a] + H[b] <= l){
				abbattuto[a] = abbattuto[b] = 1;
				dfs(dfs, a, b);
				dfs(dfs, b, a);
			} else {
				adj2[a].push_back({b, i});
				adj2[b].push_back({a, i});
			}
		} else if (aab && !bab){
			abbattuto[a] = 1;
			dfs(dfs, a, b);
		} else if (!aab && bab){
			abbattuto[b] = 1;
			dfs(dfs, b, a);
		}
	}

	int ans = count(abbattuto.begin(), abbattuto.end(), 1);

	vector<int> seen(N, 0);

	auto dfs2 = [&](auto&& dfs2, int v, int p) -> pair<int, int> {
		seen[v] = 1;
		int cnt = 1, cyc = 0;
		for (auto [x, d] : adj2[v]){
			if (x == p)
				continue;
			if (seen[x]){
				cyc = 1;
				continue;
			}
			auto r = dfs2(dfs2, x, v);
			cnt += r.first;
			cyc |= r.second;
		}
		return {cnt, cyc};
	};

	for (int i = 0; i < N; i++){
		if (!abbattuto[i] && !seen[i]){
			auto r = dfs2(dfs2, i, -1);
			ans += r.first - 1 + r.second;
		}
	}

	return ans;
}

// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL

int main() {
	int N; cin >> N;
	int M; cin >> M;

	vector<int> H(N);
	for (int i = 0; i < N; ++i)
		cin >> H[i];

	vector<int> A(M), B(M), L(M);
	for (int i = 0; i < M; ++i)
		cin >> A[i] >> B[i] >> L[i];

	cout << illumina(N, M, H, A, B, L) << "\n";
}

#endif
