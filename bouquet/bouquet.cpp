#include <vector>
using namespace std;

int componi(int N, int J, vector<int> F) {
	int lo = 0, hi = 1e9, mid;
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;
		long long cost = 0;
		for (int x : F){
			cost += max(0, mid - x);
		}

		if (cost <= J){
			lo = mid;
		} else {
			hi = mid;
		}
	}

	return lo;
}
