#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--){
		long long N, K;
		cin >> N >> K;

		long long sum = K * (K+1) / 2;

		if (K == 1 || N == sum || N == sum + 1){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
