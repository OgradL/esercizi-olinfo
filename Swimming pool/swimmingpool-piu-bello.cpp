#include <iostream>
#include <vector>
using namespace std;

int main(){

	int N;
	cin >> N;

	vector<int> P(N);
	for (int &n : P) cin >> n;

	int l = P[0], r = P[N-1], res = 1e9;
	for (int i = 0; i < N; i++){
		int d = max(
			abs(P[i] - l),
			abs(P[i] - r)
		);
		
		res = min(res, d);
	}

	cout << res << "\n";

	return 0;
}