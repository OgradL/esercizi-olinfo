#include <iostream>
#include <vector>
using namespace std;

void solve(){

	int N, M;
	cin >> N >> M;

	vector<string> map(N);
	int i0 = 1e9, i1 = 0, j0 = 1e9, j1 = 0;
	int count = 0;
	for (int i = 0; i < N; i++){
		cin >> map[i];
		for (int j = 0; j < M; j++){
			if (map[i][j] == '1'){
				i0 = min(i0, i);
				i1 = max(i1, i);
				j0 = min(j0, j);
				j1 = max(j1, j);
				count++;
			}
		}
	}
	int c = 0;
	for (int i = i0; i <= i1; i++){
		for (int j = j0; j <= j1; j++){
			c += map[i][j] == '1';
		}
	}
	cout << (c == count && c == (i1-i0+1)*(j1-j0+1) && count != 0) << '\n';
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) solve();

	return 0;
}