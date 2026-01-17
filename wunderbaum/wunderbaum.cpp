#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int L, N;
	cin >> L >> N;

	int left[] = {0, 1, 3, 6, 8, 9};
	
	int ans = L + N / 6 * 12 + left[N % 6];

	cout << ans << "\n";

	return 0;
}
