#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> bad(M, vector<int>(M, 0));

	for (int i = 0; i < N; i++){
		int K;
		cin >> K;

		int x;
		vector<int> S;
		while (K--){
			cin >> x;
			--x;
			for (int y : S)
				bad[x][y] = bad[y][x] = 1;
			S.push_back(x);
		}
	}

	vector<pair<int, int>> pairs;

	for (int i = 0; i < M; i++){
		for (int j = 0; j < i; j++){
			if (!bad[i][j])
				pairs.push_back({i, j});
		}
	}

	cout << pairs.size() << "\n";

	for (auto [a, b] : pairs)
		cout << a + 1 << " " << b + 1 << "\n";

	return 0;
}
