#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, Q;
	cin >> N >> Q;

	vector<int> V(N);
	for (int& x : V)
		cin >> x;

	vector<int> xorbit(30, 0), countbit(30, 0);

	auto add = [&](int x, int d = 1) -> void {
		for (int i = 0; i < 30; i++){
			if ((x >> i) & 1){
				countbit[i] += d;
				xorbit[i] ^= x;

			}
		}
	};

	for (int x : V)
		add(x);

	int ans = 0;

	for (int i = 0; i < 30; i++){
		ans = max(ans, countbit[i] - (xorbit[i] == 0));
	}

	cout << ans << "\n";

	int p, v;
	while (Q--){
		cin >> p >> v;
		--p;

		add(V[p], -1);
		V[p] = v;
		add(V[p]);

		ans = 0;

		for (int i = 0; i < 30; i++){
			ans = max(ans, countbit[i] - (xorbit[i] == 0));
		}

		cout << ans << "\n";
	}

	return 0;
}
