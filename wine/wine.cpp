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

	auto count_subarrays = [&](long long sum){
		long long i = 0, j = 0, s = 0, count = 0, last = 0;
		while (i < N){
			if (i == j){
				s += V[j++];
				last = 1;
			} else if (s > sum){
				s -= V[i++];
			} else if (j == N){
				s -= V[i++];
			} else {
				s += V[j++];
				last = 1;
			}
			if (s <= sum && i < j && last){
				count += j - i;
				last = 0;
			}
		}

		return count;
	};

	long long lo = 0, hi = 1e15, mid, count_smaller = 0;
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;
		if (count_subarrays(mid) < K){
			lo = mid;
		} else {
			hi = mid;
		}
	}
	long long cost = hi;
	count_smaller = count_subarrays(cost-1);

	K -= count_smaller;
	long long i = 0, j = 0, s = 0;
	while (i < N){
		if (i == j){
			s += V[j++];
		} else if (s > cost){
			s -= V[i++];
		} else if (j == N){
			s -= V[i++];
		} else {
			s += V[j++];
		}
		if (s == cost)
			K--;
		if (s == cost && K <= 0){
			cout << i << " " << j-1 << "\n";
			break;
		}
	}

	return 0;
}
