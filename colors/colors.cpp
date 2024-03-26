#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define MOD (long long)(1e9+7)

int main(){
	
	cin.sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	int v;
	vector<int> m(min(N, K)+2, 0);
	m[0] = K;
	long long ans = 1;
	for (int i = 0; i < N; i++){
		cin >> v;
		ans *= m[v];
		m[v+1]++;
		m[v]--;
		ans = ans % MOD;
	}

	cout << ans << "\n";

	return 0;
}