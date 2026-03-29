#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	vector<vector<int>> adj(N);
	for (int i = 0; i < N-1; i++){
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	function<pair<int, int>(int, int, int)> dfs = [&](int v, int p, int d) -> pair<int, int> {
		int cnt = 0, max_d = 0;
		for (int x : adj[v]){
			if (x == p)
				continue;
			auto c = dfs(x, v, d);
			max_d = max(max_d, c.first + 1);
			cnt += c.second;
		}

		if (max_d == d)
			cnt = 1;

		return {max_d, cnt};
	};

	int lo = -1, hi = N-1, mid;
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;

		auto c = dfs(0, 0, mid);
		if (c.second <= K){
			hi = mid;
		} else {
			lo = mid;
		}
	}

	cout << hi << "\n";

	return 0;
}
