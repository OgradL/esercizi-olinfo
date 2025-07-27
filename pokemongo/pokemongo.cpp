#include <vector>
using namespace std;

bool attack(int);

int n, k;
vector<vector<int>> cnt_moves, pre;


void init(int N, int K) {
	n = N;
	k = K;

	cnt_moves.assign(K + 1, vector<int>(N + 1, -1));
	pre.assign(K + 1, vector<int>(N + 1, -1));

	// cnt_moves[0].assign(N + 1, 1);
	pre[0].assign(N + 1, 0);
	pre[1].assign(N + 1, 0);
	for (int i = 0; i <= N; i++){
		cnt_moves[1][i] = i;
	}

	for (int i = 2; i <= K; i++){
		int i0 = 1;
		cnt_moves[i][1] = 1;
		pre[i][1] = 0;
		int last = 1;
		for (int j = 2; j <= N; j++){
			while (i0 && cnt_moves[i-1][i0] == cnt_moves[i][last])
				i0++;
			if (i0 + last < j){
				last = j-1;
			}
			cnt_moves[i][j] = cnt_moves[i][last] + 1;
			pre[i][j] = i0 - 1;
		}
	}
}

int new_pokemon() {
	int lo = 0, hi = n, mid;
	int lives = k;

	while (lo + 1 < hi){
		mid = lo + pre[lives][hi - lo];
		mid = max(0, min(n-1, mid));

		if (attack(mid)){
			lo = mid + 1;
		} else {
			hi = mid;
			lives--;
		}
	}

	if (lo < hi && attack(lo))
		return hi;

	return lo;
}
