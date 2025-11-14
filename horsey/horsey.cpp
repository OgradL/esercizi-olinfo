#include <iostream>
#include <numeric>
using namespace std;

void solve(){
	
	long long N, M, H, W;
	cin >> N >> M >> H >> W;

	if (gcd(H, W) != 1){
		cout << "NO\n";
		return;
	}

	if (((H + W) & 1) == 0){
		cout << "NO\n";
		return;
	}

	if (N < M)
		swap(N, M);

	long long min_N = 2 * max(H, W);
	long long min_M = H + W;

	if (N < min_N || M < min_M){
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) solve();

	return 0;
}
