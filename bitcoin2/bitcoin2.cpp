#include <iostream>
#include <vector>
using namespace std;

int main(){

	int N;
	cin >> N;

	vector<int> V(N);
	for (int &n : V) cin >> n;

	vector<vector<pair<int, int>>> dp(N, vector<pair<int, int>>(2));

	// dp[posizione][preso/nonpreso] = {min, max}
	dp[0][0] = {V[0], 1e9};
	dp[0][1] = {-1e9, 1e9};
	for (int i = 1; i < N; i++){
		
	}

	return 0;
}