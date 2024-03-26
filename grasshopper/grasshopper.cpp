#include <iostream>
#include <vector>
using namespace std;

int dfs(int n, vector<vector<int>>& G, vector<vector<int>>& v, int count){
	if (v[n][count]) return 0;

	v[n][count] = 1;

	int s = 0;

	for (auto i : G[n]){
		s += dfs(i, G, v, !count);
	}
	
	return s + count;
}

int main(){

	int N, M;
	cin >> N >> M;

	vector<vector<int>> G(N);

	int a, b;
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		G[a].push_back(b);
	}

	vector<vector<int>> v(N, vector<int>(2, 0));

	int ans = dfs(0, G, v, 1);

	cout << ans << "\n";

	return 0;
}