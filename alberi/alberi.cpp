#include <iostream>
#include <vector>
#include <array>
using namespace std;

long long carica(int N, int K, vector<int> A) {

	array<long long, 2> dp = {A[0], A[0] + K};

	for (int i = 1; i < N; i++){
		dp = {A[i] + min(dp[0], dp[1]), K + min(dp[0] + A[i], dp[1] + (A[i] - A[i-1]))};
	}

	return min(dp[0], dp[1]);
}

// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> A(N);
	for (int &a: A) cin >> a;

	cout << carica(N, K, A) << endl;

	return 0;
}

#endif
