#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	int x, C = 0, M = 0;
	for (int i = 0; i < N; i++){
		cin >> x;
		C += min(10, x / K) + (x == 11*K);
		M += x;
	}

	M -= C * K;

	cout << C << " " << M << "\n";

	return 0;
}
