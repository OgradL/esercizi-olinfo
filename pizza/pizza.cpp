#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using pll = pair<long long, long long>;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, Q;
	cin >> N >> M >> Q;

	vector<long long> A(N), B(N);
	for (int i = 0; i < N; i++){
		cin >> A[i] >> B[i];
	}

	vector<int> pizzas(M, 0);
	for (int& x : pizzas){
		int K;
		cin >> K;

		int i;
		while (K--){
			cin >> i;
			x += 1 << i;
		}
	}

	vector<long long> D(1<<N, 1e18);
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	
	for (int x : pizzas){
		D[x] = 0;
		pq.push({0, x});
	}

	vector<int> seen(1<<N, 0);

	while (!pq.empty()){
		auto [d, x] = pq.top();
		pq.pop();

		if (seen[x]) continue;
		seen[x] = 1;

		for (int i = 0; i < N; i++){
			long long cost = (x & (1 << i)) ? B[i] : A[i];
			int v = x ^ (1 << i);
			if (d + cost < D[v]){
				D[v] = d + cost;
				pq.push({D[v], v});
			}
		}
	}

	while (Q--){
		int K, x = 0;
		cin >> K;

		int i;
		while (K--){
			cin >> i;
			x += 1 << i;
		}

		cout << D[x] << "\n";
	}

	return 0;
}
