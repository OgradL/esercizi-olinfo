#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	long long int N, M, A, B;
	cin >> N >> M >> A >> B;

	long long ans = 0;

	ans = min({
		N * A,
		N / M * B + (N % M) * A,
		(N + M - 1) / M * B
	});

	cout << ans << "\n";
}