#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

#define INF (30)

void solve(vector<int>& ans){

	vector<int> dp[4];
	for (int i = 0; i < 4; i++) dp[i].assign(INF, 0);
	dp[0][0] = dp[1][0] = dp[2][0] = dp[3][0] = 1;
	for (int i = 0; i < 30; i++){
		cout << setw(2) << i << " | ";
	}
	cout << "\n";
	for (int t = 0; t < 4; t++){
		for (int n = INF-1; n > 0; n--){
			// dp[n] = 0;
			vector<int> v(200, 0);
			for (int b = sqrt(n); b > 0 /*&& (t == 0 || b == 1)*/; b--){
				dp[t][n] += dp[max(t-1,0)][n-b*b] * (1-v[b*b]);
				v[n-b*b] = 1;
				// cout << n << " " << b*b << " " << dp[t][n] << " " << dp[max(t-1,0)][n-b*b] << "\n";
			}
			// dp[n] = (dp[n] + t) / (t+1);
		}
		for (int i = 0; i < 30; i++){
			cout << setw(2) << dp[t][i] << " | ";
		}
		cout << "\n";
	}

	ans.assign(INF, 0);
	for (int i = 0; i < INF; i++){
		ans[i] = dp[i][3];
	}
}


int main(){

	int N;
	cin >> N;
	vector<int> pre;
	solve(pre);
	int n;
	while (N--){
		cin >> n;
		cout << pre[n] << " ";
	}
	cout << "\n";

	return 0;
}