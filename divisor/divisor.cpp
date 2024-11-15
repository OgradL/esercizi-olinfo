#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--){
		long long A, B, K;
		cin >> A >> B >> K;

		auto check = [&](int x) -> bool {
			long long i = (A + K) / x;
			i = x * i - A;
			return (A + i) % x == 0 && (B + K - i) % x == 0 && i >= 0;
		};

		long long V = A + B + K;

		long long ans = 1;
		for (long long i = 2; i * i <= V; i++){
			if (check(i))
				ans = max(ans, i);
			if (check(V / i))
				ans = max(ans, V / i);
		}

		cout << ans << "\n";
	}

	return 0;
}
