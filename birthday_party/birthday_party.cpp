#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> gifts(M);

	long long sum = 0;
	int x;
	for (int i = 0; i < N; i++){
		cin >> x;

		sum += x;
		gifts[x % M].push_back(x);
	}

	for (auto& y : gifts){
		sort(y.begin(), y.end());
	}

	vector<vector<long long>> knapsack(M, vector<long long>(M, 1e18));
	knapsack[0][0] = 0;

	for (int mod = 0; mod < M; mod++){
		for (int i = 0; i < min(M, (int)gifts[mod].size()); i++){
			int val = gifts[mod][i];

			auto new_knapsack = knapsack;
			for (int i0 = 0; i0 < M; i0++){
				for (int i1 = 0; i1 < M; i1++){
					int new_i0 = i0 + 1;
					if (new_i0 >= M)
						new_i0 -= M;

					int new_i1 = i1 + mod;
					if (new_i1 >= M)
						new_i1 -= M;

					new_knapsack[new_i0][new_i1] = min(new_knapsack[new_i0][new_i1], knapsack[i0][i1] + val);
				}
			}

			knapsack = new_knapsack;
		}
	}

	cout << sum - knapsack[N % M][sum % M] << "\n";

	return 0;
}
