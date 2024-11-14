#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N;
	cin >> N;

	long long lo = 0, hi = 1817, mid;
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;
		if ((mid * (mid + 1) * (2 * mid + 1)) <= N * 6){
			lo = mid;
		} else {
			hi = mid;
		}
	}

	cout << lo << "\n";

	return 0;
}
