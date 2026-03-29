#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> C(N);
	for (int& x : C)
		cin >> x;

	long long imb = 0;
	int best = 0;

	for (int i = 0; i < N; i++){
		int prv = i == 0 ? 0 : C[i-1];
		int nxt = i == N-1 ? 1e9+1 : C[i+1];

		imb += max(0, prv - C[i]);

		if (prv <= C[i] && C[i] >= nxt){
			best = max(best, (C[i] - nxt) - max(0, prv - nxt));
		}

		if (prv >= C[i] && C[i] <= nxt){
			best = max(best, (prv - C[i]) - max(0, prv - nxt));
		}
	}

	cout << imb - best << "\n";

	return 0;
}
