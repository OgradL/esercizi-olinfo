#include <iostream>
#include <vector>
using namespace std;

int main(){

	long long K, E, N;
	cin >> K >> E >> N;


	long long p = 0, i = 0, n;
	for (int d = 1; d <= 18; d++){
		long long lo = 1, hi = 1LL<<60, mid;

		while (lo + 1 < hi){
			mid = (lo + hi) / 2;
			long long v = mid;
			for (int i = 1; i < E; i++){
				v *= mid;
				if (to_string(v).size() > d){
					hi = mid;
					break;
				}
			}
			if (to_string(v).size() <= d){
				lo = mid;
			}
		}
		n = p + (i - lo) * d;
		if (n >= N){
			cout << i + (N - p) / d << "\n";
			break;
		}
		p = n;
		i = lo;
	}

	return 0;
}