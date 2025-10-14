#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

void bucket_sort(int M, vector<int>& arr, function<int(int)> cmp){
	vector<vector<int>> buckets(M);

	for (int x : arr){
		buckets[cmp(x)].push_back(x);
	}

	int idx = 0;
	for (int i = 0; i < M; i++){
		for (int x : buckets[i]){
			arr[idx++] = x;
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> cost(24, vector<int>(24, 0));

	int i, j, a, b;
	while (M--){
		cin >> i >> j >> a >> b;
		--i, --j;

		cost[i][j] = a;
		cost[j][i] = b;
	}

	vector<int> masks(1 << N);
	vector<int> masks12(1 << 12);

	iota(masks.begin(), masks.end(), 0);
	iota(masks12.begin(), masks12.end(), 0);

	bucket_sort(N+1, masks, [&](int mask){
		return __builtin_popcount(mask);
	});

	bucket_sort(13, masks12, [&](int mask){
		return __builtin_popcount(mask);
	});


	int mask1 = 0b000000000000111111111111;
	int mask2 = 0b111111111111000000000000;

	vector<vector<int>> mask_cost1(N, vector<int>(1 << 12, 0));
	vector<vector<int>> mask_cost2(N, vector<int>(1 << 12, 0));

	for (int i = 0; i < N; i++){
		for (int mask : masks12){
			if (mask == 0)
				continue;

			int b = mask & -mask;

			int c1 = cost[i][31 - __builtin_clz(b)];
			int c2 = cost[i][12 + 31 - __builtin_clz(b)];

			int m = mask ^ b;

			mask_cost1[i][mask] = mask_cost1[i][m] + c1;
			mask_cost2[i][mask] = mask_cost2[i][m] + c2;
		}
	}

	vector<int> suff(1 << N, 1e9);
	suff[0] = 0;

	for (int mask : masks){
		for (int i = 0; i < N; i++){
			if (mask & (1 << i))
				continue;

			int c = suff[mask];
			c += mask_cost1[i][mask & mask1];
			c += mask_cost2[i][(mask & mask2) >> 12];

			suff[mask | (1 << i)] = min(suff[mask | (1 << i)], c);
		}
	}

	cout << suff[(1 << N) - 1] << "\n";

	return 0;
}
