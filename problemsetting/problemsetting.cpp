#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--){
		int N;
		cin >> N;

		vector<long long> A(N), B(N-1);
		for (long long& x : A)
			cin >> x;
		for (long long& x : B)
			cin >> x;
		B.push_back(0);

		long long lo = 0, hi = 2e9 + 42, mid;
		while (lo + 1 < hi){
			mid = (lo + hi) / 2;
			
			bool ok = true;
			long long carry = 0;
			for (int i = 0; i < N && ok; i++){
				ok &= (A[i] + B[i] + carry) >= mid;
				carry = B[i] - max(0LL, mid - carry - A[i]);
			}

			if (ok){
				lo = mid;
			} else {
				hi = mid;
			}
		}

		cout << lo << "\n";
	}


	return 0;
}
