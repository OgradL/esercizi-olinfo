#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, K;
	cin >> N >> K;

	vector<long long> V(N);
	for (long long& x : V)
		cin >> x;


	long long lo = -1e18, hi = 1e18, mid;
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;

		long long cost = 0, curr = 0;
		for (int i = 0; cost <= K && i < N; i++){
			curr = max(curr + V[i], V[i]);
			cost += max(0LL, curr - mid);
			curr = min(curr, mid);
		}

		if (cost <= K){
			hi = mid;
		} else {
			lo = mid;
		}
	}

	cout << hi << "\n";

	return 0;
}
