#include <bits/stdc++.h>
using namespace std;
bool isSafe(int x, int y, vector<vector<bool>> &arr, int N, int M) {
	if (x >= 2) {
		if (y >= 2) {
			if (arr[y - 1][x - 1] == 1 && arr[y - 2][x - 2] == 1)
				return false;
		}
		if (M - y - 1 >= 2) {
			if (arr[y + 1][x - 1] == 1 && arr[y + 2][x - 2] == 1)
				return false;
		}
		if (arr[y][x - 1] == 1 && arr[y][x - 2] == 1)
			return false;
	}
	if (N - x - 1 >= 2) {
		if (y >= 2) {
			if (arr[y - 1][x + 1] == 1 && arr[y - 2][x + 2] == 1)
				return false;
		}
		if (M - y - 1 >= 2) {
			if (arr[y + 1][x + 1] == 1 && arr[y + 2][x + 2] == 1)
				return false;
		}
		if (arr[y][x + 1] == 1 && arr[y][x + 2] == 1)
			return false;
	}
	if (y >= 2) {
		if (arr[y - 1][x] == 1 && arr[y - 2][x] == 1)
			return false;
	}
	if (M - y - 1 >= 2) {
		if (arr[y + 1][x] == 1 && arr[y + 2][x] == 1)
			return false;
	}
	return true;
}
int gioca(int x, int y, int N, int M, vector<vector<bool>> &arr, int current, int currentMax) {
	if (x >= N) return gioca(0, y + 1, N, M, arr, current, currentMax);
	if (y >= M) return current;
	if (current + (N * M) - ((N * y) + x) < currentMax) return -INT_MAX;
	bool canPlace = isSafe(x, y, arr, N, M);
	int ma = 0;
	if (canPlace) {
		arr[y][x] = 1;
		ma = gioca(x + 1, y, N, M, arr, current + 1, max(currentMax, ma));
		arr[y][x] = 0;
	}
	ma = max(ma, gioca(x + 1, y, N, M, arr, current, max(currentMax, ma)));
	return ma;
}
int main() {
#ifdef EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<bool>> arr(M, vector<bool>(N, 0));
	int result = gioca(0, 0, N, M, arr, 0, 0);
	printf("%d\n", result);
}