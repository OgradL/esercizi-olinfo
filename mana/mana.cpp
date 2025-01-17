#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	vector<int> rest;
	array<int, 2> a;
	cin >> a[1];

	for (int i = 1; i < N; i++){
		cin >> a[0];
		sort(a.begin(), a.end());
		rest.push_back(a[0]);
	}

	long long ans = 0;
	ans += accumulate(rest.begin(), rest.end(), 0LL) * (K / rest.size());
	ans += accumulate(rest.begin(), rest.begin() + (K % rest.size()), 0LL);

	cout << ans << "\n";

	return 0;
}
