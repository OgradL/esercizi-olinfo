#include <iostream>
#include <vector>
using namespace std;

int main(){

	int N;
	cin >> N;

	vector<int> P(N), C(N);
	for (int &n : P)
		cin >> n;
	
	for (int &n : C)
		cin >> n;
	

	vector<int> dp(N, 0);
	int v = 0, ans = 0;
	for (int i = N-1; i >= 0; i--){
		v = 0;
		for (int j = i+1; j < N; j++){
			if ((P[j] > P[i]) || (P[j] == C[P[i]-1]))
				v = max(dp[j], v);
		}
		v++;

		dp[i] = v;
		ans = max(ans, dp[i]);
	}


	cout << ans << "\n";

	return 0;
}
