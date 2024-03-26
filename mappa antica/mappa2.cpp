#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int find_ans(int N, vector<string>& M){

	queue<pair<pair<int, int>, int>> q;
	q.push({{0, 0}, 1});

	vector<vector<int>> visited(N, vector<int>(N, 0));

	int i, j, d;
	pair<pair<int, int>, int> p;
	while (!q.empty()){
		p = q.front();
		q.pop();

		i = p.first.first;
		j = p.first.second;
		d = p.second;

		if (i >= N || i < 0) continue;
		if (j >= N || j < 0) continue;
		if (i == N-1 && j == N-1) break;
		if (visited[i][j]) continue;
		visited[i][j] = 1;

		if (M[i][j] == '+') continue;

		q.push({{i+1, j}, d+1});
		q.push({{i-1, j}, d+1});
		q.push({{i, j+1}, d+1});
		q.push({{i, j-1}, d+1});
		q.push({{i+1, j+1}, d+1});
		q.push({{i+1, j-1}, d+1});
		q.push({{i-1, j+1}, d+1});
		q.push({{i-1, j-1}, d+1});
	}
	
	return p.second;
}

int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N;
	cin >> N;

	vector<string> M(N);
	for (string &s : M) cin >> s;

	int ans = find_ans(N, M);

	cout << ans << "\n";

	return 0;
}