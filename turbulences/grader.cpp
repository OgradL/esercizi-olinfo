#include <iostream>
#include <vector>

using namespace std;

long long revenue(int N, int K, vector<long long> A);

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	// If you prefer file IO, uncomment the following two lines.
	//
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int N;
	cin >> N;
	int K;
	cin >> K;

	vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << revenue(N, K, A) << endl;

	return 0;
}
