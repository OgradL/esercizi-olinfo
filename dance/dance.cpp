#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, D;
	cin >> N >> D;

	vector<int> A(N), B(N);
	for (int& x : A)
		cin >> x;

	for (int& x : B)
		cin >> x;

	int ok = 1;
	for (int i = 0; ok && i < N; i++){
		ok &= B[i] - A[i] <= D;
	}

	cout << (ok ? "YES" : "NO") << "\n";

	return 0;
}
