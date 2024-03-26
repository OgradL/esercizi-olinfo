#include <iostream>
using namespace std;

long long MOD = 1e9 + 7;

int main(){

	int N, M;
	cin >> N >> M;

	long long l = -1, n, ans = 1;
	for (int i = 0; i < M; i++){
		cin >> n;
		ans = ans * (N + (n == l)) % MOD;
		l = n;
		cout << ans << "\n";
	}

	return 0;
}