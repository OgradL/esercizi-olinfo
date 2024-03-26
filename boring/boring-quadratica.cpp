//Scrivi qui il tuo codice
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define MOD (long long)(1e9+7)
#define INF (long long)(1e18)

long long fast_pow(long long b, long long e, long long m){
	if (e == 0) return 1;
	
	long long v = fast_pow(b, e/2, m);
	v = v * v; v = v % m;
	if (e%2) v *= b;
	return v % m;
}

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N, Q;
	cin >> N;
	
	vector<pair<long long, long long>> A(N+1, {0, 0});
	
	for (int i = 1; i <= N; i++) {
		cin >> A[i].first;
	}

	cin >> Q;
	while (Q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;

			long long ans = A[x].first * fast_pow(x, A[x].second, MOD);

			cout << ans % MOD << endl;
		} else {
			int x, y, b, c;
			cin >> x >> y >> b >> c;
			for (int j = x; j <= y; j++) {
				if (c - A[j].second >= 20){
					A[j] = {b, c};
				} else if (A[j].first < fast_pow(j, c - A[j].second, INF) * b) A[j] = {b, c};
			}
		}
	}

	return 0;
}