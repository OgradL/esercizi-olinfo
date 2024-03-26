#include <iostream>
#include <vector>

using namespace std;

int solve(int N, int M, int K, vector<int> A, vector<int> B);

int main() {
	ios_base::sync_with_stdio(false);
	// If you prefer file IO, uncomment the following two lines.
	//
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int N, M, K;
	cin >> N >> M >> K;

	vector<int> A(N);
	vector<int> B(M);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	cout << solve(N, M, K, A, B) << endl;

	return 0;
}
