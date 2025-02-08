#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, M, A;
	cin >> N >> M >> A;

	long long ans = 0;
	for (long long i = 1; i * i <= A; i++){
		if (A % i == 0){
			ans += (N <= i) && (M <= A/i);
			ans += (M <= i) && (N <= A/i);

			if (i * i == A)
				ans -= (N <= i) && (M <= i);
		}
	}

	cout << ans << "\n";

	return 0;
}
