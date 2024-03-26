#include <iostream>
using namespace std;

int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N;
	cin >> N;

	long long mi = -1e18, ma = 1e18;

	long long v, last = -1e18, t;
	for (int i = 0; i < N; i++){
		cin >> v;
		ma = min(ma, v);
		t = 2*v - ma;
		ma = 2*v - mi;
		mi = t;
		last = v;
	}


	cout << max(0LL, ma - mi + 1) << "\n";

	return 0;
}