#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> knapsack(int N, int S, vector<int>& H){
	vector<vector<bool>> knap(N+1, vector<bool>(S+1, 0));

	knap[0][0] = 1;
	for (int i = 0; i < N; i++){
		for (int j = 0; j <= S; j++){
			if (knap[i][j] == 0)
				continue;

			knap[i+1][j] = 1;

			if (j + H[i] <= S){
				knap[i+1][j+H[i]] = 1;
			}
		}
	}

	return knap;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, S;
	cin >> N >> S;

	vector<int> H(N);
	for (int& x : H){
		cin >> x;
	}

	auto knap1 = knapsack(N, S, H);

	reverse(H.begin(), H.end());

	auto knap2 = knapsack(N, S, H);

	vector<int> need(N, 1);

	for (int i = 0; i < N; i++){
		for (int j = 0; j <= S; j++){
			need[i] &= !(knap1[i][j] && knap2[N-i-1][S-j]);
		}
	}

	for (int x : need){
		if (x){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
