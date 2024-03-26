#include <iostream>
#include <vector>
using namespace std;

pair<long long, long long> dfs(int v, int p, vector<vector<pair<long long, long long>>>& G){
	
	pair<long long, long long> ans = {v, 0};
	for (auto x : G[v]){
		if (x.first != p){
			auto d = dfs(x.first, v, G);
			d.second += x.second;
			if (d.second > ans.second)
				ans = d;
		}
	}
	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	long long sum = 0;
	vector<vector<pair<long long, long long>>> G(N);
	long long a, b, c;
	for (int i = 1; i < N; i++){
		cin >> a >> b >> c;
		sum += c;
		--a, --b;
		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}

	if (K == 1){
		cout << 2 * sum << "\n";
	} else {
		auto d = dfs(0, -1, G);
		d = dfs(d.first, -1, G);
		d = dfs(d.first, -1, G);
		cout << 2 * sum - d.second << "\n";
	}


	return 0;
}