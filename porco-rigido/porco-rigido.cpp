#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N = 26;

	multiset<pair<int, int>, greater<pair<int, int>>> S;
	int g = 0;
	vector<int> A(N);
	for (int& x : A){
		cin >> x;
		g = gcd(g, x);
	}

	for (int i = 0; i < N; i++){
		if (A[i])
			S.insert({A[i]/g, i});
	}

	vector<array<int, 2>> ops;

	while (S.size() > 1){

		while (prev(S.end())->first == 0){
			S.erase(prev(S.end()));
		}
		if (S.size() == 1)
			break;

		if (S.begin()->first < 2*next(S.begin())->first){
			auto p = *S.begin();
			S.erase(S.begin());
			ops.push_back({p.second, S.begin()->second});
			p.first -= S.begin()->first;
			S.insert(p);
		} else {
			auto p = *S.rbegin();
			while ((p.first & 1) == 0){
				p.first /= 2;
				ops.push_back({p.second, p.second});
			}
			S.erase(prev(S.end()));
			S.insert(p);

			if ((S.begin()->first & 1) == 1){
				p = *S.begin();
				S.erase(S.begin());
				ops.push_back({p.second, S.rbegin()->second});
				p.first -= S.rbegin()->first;
				S.insert(p);
				continue;
			}

			p = *S.begin();
			S.erase(S.begin());
			p.first /= 2;
			ops.push_back({p.second, p.second});
			S.insert(p);
		}
	}

	ops.push_back({S.begin()->second, g*S.begin()->first});

	cout << ops.size() << "\n";
	cout << char('a' + ops.back()[0]) << "=" << ops.back()[1] << "\n";

	ops.pop_back();
	reverse(ops.begin(), ops.end());

	for (auto [a, b] : ops){
		cout << char('a' + a) << "+=" << char('a' + b) << "\n";
	}

	return 0;
}
