#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define INF 1e9+10

int main(int argc, char** argv){

	// if (argc >= 2){
	// 	freopen(argv[1], "r", stdin);
	// }

	long long N, R, T, L;
	cin >> N >> R >> T >> L;

	vector<int> X(N);
	for (int &i: X) cin >> i;
	X.push_back(L);

	vector<vector<int>> memo(N + 1, vector<int>(R + 2, INF));

	memo[0][0] = X[0];

	for (int i = 1; i <= N; i++){
		for (int j = 0; j <= R; j++){
			if (memo[i-1][j] != INF){
				int time = memo[i-1][j];
				int stop_time = 0;
				if ((time / T) % 2){
					stop_time = time % T;
					stop_time = T - stop_time;
				}
				memo[i][j] = min(memo[i][j], time + stop_time + X[i] - X[i-1]);
				// cout << time << " " << (time % stop_time) << " " << stop_time << " " << memo[i][j] << " <----\n";

				if (j <= R && stop_time > 0)
					memo[i][j+1] = min(memo[i][j+1], time + X[i] - X[i-1]);
				// cout << memo[i][j] << " ";
			} else {
				// cout << memo[i][j] << " ";
				break;
			}
		}
		// cout << "\n";
	}

	

	int ans = INF;
	// cout << "ANS: \n";
	for (int i = 0; i <= R; i++){
		// cout << memo[N][i] << "\n";
		ans = min(ans, memo[N][i]);
	}

	cout << ans << "\n";

	return 0;
}