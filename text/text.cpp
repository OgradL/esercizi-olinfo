#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){

	int N, K;
	cin >> N >> K;

	vector<string> S(N);

	for (auto &s : S) cin >> s;

	vector<vector<int>> mem(K, vector<int>(26, 0));

	for (int i = 0; i < K; i++){
		for (int j = 0; j < N; j++){
			mem[i][S[j][i]-'a']++;
		}
	}

	int ans = 0, max_d = 1e9;
	for (int i = 0; i < N; i++){
		int d = 0;
		for (int j = 0; j < K; j++){
			d += N - mem[j][S[i][j]-'a'];
		}
		if (d < max_d){
			max_d = d;
			ans = i;
		}
	}

	cout << ans << "\n";

	return 0;
}