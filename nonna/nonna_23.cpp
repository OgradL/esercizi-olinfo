#include <iostream>
#include <vector>
using namespace std;

#define infinite 5000000001LL

vector<int> valori;

int N, K;

long long f(int n, long long k, vector<vector<int>> &memo) {
	
	if (k <= 0) return -k;
	
	if (n == N) return infinite;
	
	if (memo[k][n] != -1) return memo[k][n];
	
	int eat = f(n + 1, k - valori[n], memo);
	
	if (eat == 0) {
		memo[k][n] = eat;
		return eat;
	}
	
	int donteat = f(n + 1, k, memo);
	int mi = min(eat, donteat);
	
	memo[k][n] = mi;
	
	return mi;
}

int main() {
	#ifdef EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	cin >> N >> K;
	
	valori.resize(N);
	
	for (int i = 0; i < N; i++) {
		cin >> valori[i];
	}
	
	vector<vector<int>> memo(K + 1, vector<int>(N, -1));
	cout << K + f(0, K, memo) << "\n";

}
