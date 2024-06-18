#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using pi = pair<int, int>;

void solve(){

	long long N, K;
	cin >> N >> K;


	vector<long long> A(N), B(N);

	for (long long& x : A)
		cin >> x;

	for (long long& x : B)
		cin >> x;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	vector<pair<pi, pi>> groups, new_groups, aux_idx;
	groups.push_back({{0, N}, {0, N}});
	long long magic_value = 0;
	for (int i = 61; i >= 0; i--){
		long long count[2];
		count[0] = count[1] = 0;
		new_groups.clear();
		aux_idx.clear();
		for (auto [p0, p1] : groups){
			long long a0 = lower_bound(
				A.begin() + p0.first,
				A.begin() + p0.second,
				1LL << i,
				[](long long a, long long v){ return (a & v) == 0; }
			) - A.begin() - p0.first;
			long long a1 = p0.second - p0.first - a0;

			long long b0 = lower_bound(
				B.begin() + p1.first,
				B.begin() + p1.second,
				1LL << i,
				[](long long a, long long v){ return (a & v) == 0; }
			) - B.begin() - p1.first;
			long long b1 = p1.second - p1.first - b0;
			aux_idx.push_back({{a0, a1}, {b0, b1}});

			count[0] += a0 * b0 + a1 * b1;
			count[1] += a0 * b1 + a1 * b0;
		}
		if (count[0] >= K){
			magic_value += 0LL << i;
			for (int j = 0; j < groups.size(); j++){
				auto [p0, p1] = groups[j];
				auto [a0, a1] = aux_idx[j].first;
				auto [b0, b1] = aux_idx[j].second;
				if (a0 != 0 && b0 != 0)
					new_groups.push_back({{p0.first, p0.first + a0},
							      {p1.first, p1.first + b0}});
				if (a1 != 0 && b1 != 0)
					new_groups.push_back({{p0.first + a0, p0.second},
							      {p1.first + b0, p1.second}});
			}
		} else {
			magic_value += 1LL << i;
			K -= count[0];
			for (int j = 0; j < groups.size(); j++){
				auto [p0, p1] = groups[j];
				auto [a0, a1] = aux_idx[j].first;
				auto [b0, b1] = aux_idx[j].second;
				if (a0 != 0 && b1 != 0)
					new_groups.push_back({{p0.first, p0.first + a0},
							      {p1.first + b0, p1.second}});
				if (a1 != 0 && b0 != 0)
					new_groups.push_back({{p0.first + a0, p0.second},
							      {p1.first, p1.first + b0}});
			}
		}
		groups = new_groups;
	}

	cout << magic_value << "\n";
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) solve();

	return 0;
}
