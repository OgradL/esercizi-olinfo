#include <iostream>
using namespace std;

#define ll long long

ll ric(ll num, int cifre, int N, int M){
	if (cifre > N) return 0;

	ll ans = num % M;

	if (num % 10 != 3)
		ans = max(ans, ric(num * 10 + 3, cifre + 1, N, M));

	if (num % 10 != 6)
		ans = max(ans, ric(num * 10 + 6, cifre + 1, N, M));
	
	if (num % 10 != 9)
		ans = max(ans, ric(num * 10 + 9, cifre + 1, N, M));

	return ans;
}

int main(){

	#ifdef EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int T;
	cin >> T;
	while (T--){

		int N, M;
		cin >> N >> M;

		ll ans = 0;

		ans = max(ans, ric(3, 1, N, M));

		ans = max(ans, ric(6, 1, N, M));
	
		ans = max(ans, ric(9, 1, N, M));

		cout << ans << "\n";
	}

	return 0;
}
