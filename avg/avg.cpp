#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, K;
	cin >> N >> K;

	vector<long long> P(N);
	for (auto& x : P)
		cin >> x;

	long long exsum = N * K;
	long long sum = accumulate(P.begin(), P.end(), 0LL);

	if (sum == exsum){
		cout << "0\n";
	} else if (sum < exsum){
		cout << "1\n";
	} else {
		sort(P.rbegin(), P.rend());
		int i = 0;
		for (; sum > exsum; i++)
			sum -= P[i] - 1;
		cout << i << "\n";
	}

	return 0;
}