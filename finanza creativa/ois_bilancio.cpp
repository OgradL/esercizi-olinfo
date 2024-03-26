#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector<int> U(N);

	vector<int> C(N-K);

	for (int i = 0; i < N; i++) {
		cin >> U[i];
	}

	int len = N - K - 1;
	C[0] = U[0];
	int Ci = 0;

	int i = 1;
	while (i < N) {
		while (Ci >= 0 && U[i] < C[Ci] && K > 0) {
			Ci--;
			K--;
		}
		if (Ci < len) {
			Ci++;
			C[Ci] = U[i];
		} else {
			K--;
		}
		i++;
	}

	for (int c: C) {
		cout << c << " ";
	}

	return 0;
}
