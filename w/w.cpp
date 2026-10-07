#include <queue>
#include <vector>
#include <iostream>
using namespace std;

long long estrai(int N, long long K, vector<int> A, vector<int> Q) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	long long best = 1e18, t = 0;
	long long scavato = 0;

	for (int i = 0; i < N; i++){
		scavato += A[i] * 1LL * Q[i];
		t += A[i];

		pq.push({Q[i], A[i]});

		while (scavato >= K && !pq.empty()){
			auto [qq, aa] = pq.top();
			pq.pop();

			scavato -= qq * 1LL * aa;
			t -= aa;

			long long need = (K - scavato + qq - 1) / qq;

			need = max(need, 1LL);
			scavato += qq * need;
			t += need;

			if (need > 1){
				pq.push({qq, need});
				break;
			}
		}

		if (scavato >= K)
			best = min(best, t);
	}

	return best;
}




// GRADER DI ESEMPIO
// NON MODIFICARE AL DI SOTTO DI QUESTA LINEA

#ifndef EVAL
int main() {
	int N;
	long long K;

	cin >> N >> K;

	vector<int> A(N), Q(N);
	for(int &x: A) cin >> x;
	for(int &x: Q) cin >> x;

	cout << estrai(N, K, A, Q) << endl;
}
#endif
