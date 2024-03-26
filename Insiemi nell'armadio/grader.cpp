#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

int conta(int N, vector<int> D);

int main() {
	// se vuoi leggere da file decommenta queste due linee
	// assert(freopen("input2.txt", "r", stdin));
	// assert(freopen("output.txt", "w", stdout));

	int n;
	cin >> n;

	vector<int> d(n);
	for (auto &x : d)
		cin >> x;

	int ans = conta(n, d);
	cout << ans << '\n';
}
