#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define INF 1e18+10

int main(){

	int N, K;
	cin >> N >> K;
	vector<int> T(N);
	for (int &i : T) cin >> i;

	int idx = 12 * 3 * K;

	vector<vector<vector<long long>>> dp(K, vector<vector<long long>>(36 * N, vector<long long>(3, -INF)));

	long long tmp;
	for (int i = 0; i < K; i++){
		for (int j = 0; j < 36 * N; j++){
			for (int k = 0; k < 3; k++){

			}
		}
	}
	long long ans = 42;
	cout << ans << "\n";

	return 0;
}