#include <deque>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<int>> map(N, vector<int>(M));
	for (auto& x : map){
		for (auto& y : x){
			cin >> y;
		}
	}

	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};

	function<int(int)> check = [&](int cutoff) -> int {
		deque<pair<int, int>> q;

		vector<vector<int>> d(N, vector<int>(M, 2e6));
		d[0][0] = 0;
		q.push_front({0, 0});

		while (!q.empty()){
			auto [i, j] = q.front();
			q.pop_front();

			for (int k = 0; k < 4; k++){
				int ni = i + dx[k];
				int nj = j + dy[k];

				if (ni < 0 || ni >= N) continue;
				if (nj < 0 || nj >= M) continue;

				int scale = abs(map[i][j] - map[ni][nj]) > cutoff;

				if (d[i][j] + scale < d[ni][nj]){
					d[ni][nj] = d[i][j] + scale;

					if (scale){
						q.push_back({ni, nj});
					} else {
						q.push_front({ni, nj});
					}
				}
			}
		}

		return d[N-1][M-1] <= K;
	};

	int lo = -1, hi = 1e6, mid;
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;

		if (check(mid)){
			hi = mid;
		} else {
			lo = mid;
		}
	}

	cout << hi << "\n";

	return 0;
}
