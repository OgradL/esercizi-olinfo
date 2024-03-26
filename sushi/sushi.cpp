#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct plate{
	int A, B, C;
};

int main(){

	int N;
	cin >> N;

	vector<plate> P(N);
	for (auto& x : P)
		cin >> x.A >> x.B >> x.C;
	
	auto compplate = [](const plate& a, const plate& b){
		return a.A < b.A;
	};

	sort(P.begin(), P.end(), compplate);

	vector<int> dp(N+1, 0);

	int m = 0;
	for (auto x : P){
		int i1 = lower_bound(P.begin(), P.end(), (plate){x.A, 0, 0}, compplate) - P.begin();
		int i2 = lower_bound(P.begin(), P.end(), (plate){x.A + x.C, 0, 0}, compplate) - P.begin();
		if (i1 >= N)
			continue;
		m = max(m, dp[i1]);
		if (i2 > N)
			continue;
		dp[i2] = max(dp[i2], m + x.B);
	}
	
	m = max(m, dp[N]);

	cout << m << "\n";

	return 0;
}