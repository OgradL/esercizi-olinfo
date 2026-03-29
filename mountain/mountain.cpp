#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> P(N);
	for (int& x : P)
		cin >> x;

	int ans = N+1;

	int b = -1;
	for (int i = 0; i < N; i++){
		ans -= P[i] > b;
		b = max(b, P[i]);
	}

	b = -1;
	for (int i = N-1; i >= 0; i--){
		ans -= P[i] > b;
		b = max(b, P[i]);
	}

	cout << ans << "\n";

	return 0;
}
