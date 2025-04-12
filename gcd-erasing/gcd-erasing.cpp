#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int ans = 0;
	vector<int> sieve(N+1, 0);
	for (int i = 2; i <= N; i++){
		if (sieve[i]) continue;
		ans++;
		for (int j = i+i; j <= N; j += i)
			sieve[j] = 1;
	}

	cout << ans << "\n";

	return 0;
}
