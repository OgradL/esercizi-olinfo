#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, Q;
	cin >> N >> Q;

	vector<int> V(N);
	for (int& x : V)
		cin >> x;

	vector<vector<int>> conn(20, vector<int>(20, 1e9));
	vector<vector<int>> bits(N);

	for (int i = 0; i < N; i++){
		for (int j = 0; j < 20; j++){
			if (V[i] & (1<<j))
				bits[i].push_back(j);
		}

		for (int i0 : bits[i]){
			for (int i1 : bits[i]){
				conn[i0][i1] = 1;
			}
		}
	}

	for (int i = 0; i < 20; i++){
		conn[i][i] = 0;
	}

	for (int k = 0; k < 20; k++){
		for (int i = 0; i < 20; i++){
			for (int j = 0; j < 20; j++){
				for (int i0 = 0; i0 < 20; i0++){
					conn[i][j] = min(conn[i][j], conn[i][i0] + conn[i0][j]);
				}
			}
		}
	}

	int a, b;
	while (Q--){
		cin >> a >> b;
		--a, --b;

		int ans = 1e9;
		
		for (int i0 : bits[a]){
			for (int i1 : bits[b]){
				ans = min(ans, conn[i0][i1]);
			}
		}

		if (ans == 1e9)
			ans = -2;

		cout << ans + 1 << "\n";
	}


	return 0;
}
