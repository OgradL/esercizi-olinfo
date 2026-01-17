#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, P;
	cin >> N >> P;

	vector<int> S(N), F(N);
	for (int& x : S)
		cin >> x;
	for (int& x : F)
		cin >> x;

	vector<int> sweets;

	for (int i = 0; i < N; i++){
		if (F[i] == P)
			sweets.push_back(S[i]);
	}

	sort(sweets.begin(), sweets.end());

	int Q;
	cin >> Q;

	int l, r, k;
	while (Q--){
		cin >> l >> r >> k;

		auto lb = lower_bound(sweets.begin(), sweets.end(), l);
		auto ub = lower_bound(sweets.begin(), sweets.end(), r);

		if (ub - lb >= k){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
