#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;
	cin >> N >> M;

	vector<int> C(N), P(N);

	for (int& x : C)
		cin >> x;

	for (int& x : P)
		cin >> x;

	int best = 0;

	for (int i = 0; i < N; i++){
		if ((C[i] & 1) == 0 && C[i] > best && P[i] <= M)
			best = C[i];
	}

	cout << best << "\n";

	return 0;
}
