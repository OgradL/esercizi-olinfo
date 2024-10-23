#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MOD = 1e9 + 7;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> A(N), B(N);
	for (int& x : A)
		cin >> x;
	for (int& x : B)
		cin >> x;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	long long ans = 1;
	int j = 0;
	for (int i = 0; i < N; i++){
		while (j < N && B[j] <= A[i])
			j++;

		ans = ans * (j - i) % MOD;
	}

	cout << ans << "\n";

	return 0;
}
