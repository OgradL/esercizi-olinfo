#include <iostream>
#include <vector>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int dfs(int x, int y, int R, int C, vector<vector<int>>& M){
	if (x < 0 || x >= R)
		return 0;
	if (y < 0 || y >= C)
		return 0;
	if (M[x][y] == 0) return 0;
	M[x][y] = 0;
	
	int val = 0;
	for (int i = 0; i < 4; i++){
		int v = dfs(x + dx[i], y + dy[i], R, C, M);
		val = min(val, v);
	}

	if (x == 0 || x == R-1)
		return -1;
	if (y == 0 || y == C-1)
		return -1;
	if (val == -1)
		return -1;
	return 1;
}

int main(){

	int R, C;
	cin >> R >> C;

	vector<vector<int>> M(R, vector<int>(C));
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> M[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			ans += dfs(i, j, R, C, M) == 1;
		}
	}
	
	cout << ans << "\n";

	return 0;
}