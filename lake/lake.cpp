#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<string> S(N);
	for (string& s : S)
		cin >> s;

	int ans = 0;
	for (int i = 1; i < N-1; i++){
		for (int j = 1; j < M-1; j++){
			if (S[i][j] == '#'){
				ans += S[i-1][j] == '.';
				ans += S[i+1][j] == '.';
				ans += S[i][j-1] == '.';
				ans += S[i][j+1] == '.';
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
