#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, C, W;
	cin >> N >> C >> W;

	vector<long long> T(N);
	for (auto& x : T)
		cin >> x;

	sort(T.rbegin(), T.rend());

	long long ans = W;
	int idx = 0;
	while (idx < N){
		int left = C;
		long long t = 0;
		while (left-- && idx < N){
			t = max(t, T[idx]);
			idx++;
		}
		if (idx < N){
			t = max(W, t);
		}
		ans += t;
	}

	cout << ans << "\n";

	return 0;
}
