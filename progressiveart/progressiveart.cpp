#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, L, K;
	cin >> N >> M >> L >> K;

	if (K == 0){
		cout << "YES\n";
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				cout << 'R';
			}
			cout << '\n';
		}
		return 0;
	}

	if (L % 3){
		cout << "NO\n";
		return 0;
	}

	string c(M, 'R');
	vector<string> ans(N, c);
	
	char cols[] = {'R', 'B', 'G'};
	int col = 0;

	for (int i = 0; i < L; i++){
		for (int j = 0; j < L; j++){
			if (K)
				ans[i][j] = cols[i % 3];
			else
				ans[i][j] = 'R', col = 1;
		}
	}

	if (K)
		K--;

	for (int i = L; i < N; i++){
		for (int j = 0; j < L; j++){
			if (K){
				ans[i][j] = ans[i-L][j];
			} else {
				ans[i][j] = ans[i-L+1][j];
				if (!col)
					col = ans[i-L][j] == 'R' ? 2 : 1;
				ans[i][j] = cols[col-1];
			}
		}
		if (K)
			K--;
	}

	for (int j = L; j < M; j++){
		for (int i = 0; i < N; i++){
			if (K){
				ans[i][j] = ans[i][j-L];
			} else {
				if (!col)
					col = ans[i][0] == 'R' ? 2 : 1;
				ans[i][j] = cols[col-1];
			}
			if (K && i >= L-1)
				K--;
		}
	}

	if (K){
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	for (string& x : ans){
		cout << x << '\n';
	}

	return 0;
}
