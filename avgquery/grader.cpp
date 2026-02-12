#include <iostream>
#include <vector>
using namespace std;

void inizia(int N, vector<int> A);
void aggiorna(int P, int C);
int consiglio(int L, int R, int K);

int main() {
	int N, Q;
	cin >> N >> Q;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	inizia(N, A);

	for (int i = 0; i < Q; i++) {
		int t; cin >> t;
		if (t == 0) {
			int P, C;
			cin >> P >> C;
			aggiorna(P, C);
		} else {
			int L, R, K;
			cin >> L >> R >> K;
			cout << consiglio(L, R, K) << '\n';
		}
	}
}
