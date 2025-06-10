#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

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
			dfs(dfs, x, v, w + ew);
		}
	};

	dfs(dfs, 0, 0, 0);


	vector<int> pres(N, 0);
	vector<long long> s;
	int x;
	while (Q--){
		cin >> x;
		--x;
		if (pres[x]){
			s.erase(find(s.begin(), s.end(), values[x]));
		} else {
			s.push_back(values[x]);
		}

		long long ans = 0;
		for (int i = 0; i < s.size(); i++){
			for (int j = 0; j < i; j++){
				ans = max(ans, s[i] ^ s[j]);
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
