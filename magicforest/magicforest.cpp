#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

long long MOD = 1e9 + 7;

struct edge{
	int s[2], c;
};

int main(){

	int N, M;
	cin >> N >> M;

	vector<edge> edges;
	int a, b, c;
	for (int i = 0; i < M; i++){
		cin >> a >> b >> c;
		edges.push_back((edge){a, b, c});
	}

	sort(edges.begin(), edges.end(), [](edge& a, edge& b){
		return a.c < b.c;
	});

	array<vector<long long>, 2> dp;
	dp[0].resize(N);
	dp[1].resize(N);
	long long ans = 0;
	int k = 0;
	long long lastc = 0;
	for (auto e : edges){
		if (e.c == lastc + 1){
			dp[k&1].assign(N, 0);
		}
	}

	cout << ans << "\n";

	return 0;
}