#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool check_x(int x, int y, int n, int m, vector<vector<int>> grid) {
	int prima = grid[x][y];
	grid[x][y] = true;
	for (int i = -2; i <= 0; i++) {


		bool a, b, c, d;
		a = ( 		// Case 1: row
				x + i >= 0 && x + i + 2 < n
				&& grid[x + i][y] && grid[x + i + 1][y] && grid[x + i + 2][y]
			);
		// cerr << "a\n";
		b = (      // Case 2: column
				y + i >= 0 && y + i + 2 < m
				&& grid[x][y + i] && grid[x][y + i + 1] && grid[x][y + i + 2]
			);
		// cerr << "b\n";
		c = (      // Case 3: down-right diagonal
				x + i >= 0 && x + i + 2 < n && y + i >= 0 && y + i + 2 < m
				&& grid[x + i][y + i] && grid[x + i + 1][y + i + 1] && grid[x + i + 2][y + i + 2]
			);
		// cerr << "c\n";
		d = (      // Case 4: down-left diagonal
				x + i >= 0 && x + i + 2 < n && y - i - 2 >= 0 && y - i < m
				&& grid[x + i][y - i] && grid[x + i + 1][y - i - 1] && grid[x + i + 2][y - i - 2]
			);
		// cerr << "d\n";

		// cout << x+i << " " << y << " - " << x+i+2 << " " << y << " " << a << "\n";
		// cout << x << " " << y+i << " - " << x << " " << y+i+2 << " " << b << "\n";
		// cout << x+i << " " << y+i << " - " << x+i+2 << " " << y+i+2 << " " << c << "\n";
		// cout << x+i << " " << y-i << " - " << x+i+2 << " " << y-i-2 << " " << d << "\n";


		if (a || b || c || d) {
			grid[x][y] = prima;
			return false;
		}
	}
	grid[x][y] = prima;
	return true;
}

int gioca(int x, int y, int N, int M, vector<vector<int>> &grid, int current, int currentMax) {
	if (x >= N) return gioca(0, y + 1, N, M, grid, current, currentMax);
	if (y >= M) return current;
	
	if (grid[x][y] == true) return gioca(x + 1, y, N, M, grid, current, currentMax);
	if (current + ceil(((N * M) - ((N * y) + x)) * 2.0 / 3.0) < currentMax) return -1;
	
	bool canPlace = check_x(x, y, N, M, grid);
	int ma = 0;
	if (canPlace) {
		grid[x][y] = 1;
		ma = gioca(x + 1, y, N, M, grid, current + 1, currentMax);
		grid[x][y] = 0;
	}
	ma = max(ma, gioca(x + 1, y, N, M, grid, current, max(currentMax, ma)));
	return ma;
}
int main() {
#ifdef EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int N, M, t;
	scanf("%d %d", &N, &M);
	vector<vector<int>> grid(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			scanf("%d", &grid[i][j]);
		}
	}
	int result = gioca(0, 0, N, M, grid, 0, 0);
	printf("%d\n", result);
	return 0;
}