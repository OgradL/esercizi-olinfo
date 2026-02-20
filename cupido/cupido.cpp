#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	set<pair<int, int>> pairs;

	auto check = [&](int id, int a) -> int {
		if (id > a)
			swap(id, a);
		return pairs.count({id, a});
	};

	auto add = [&](int id, int a) -> void {
		if (id > a)
			swap(id, a);
		pairs.insert({id, a});
	};

	int ans = 0;
	int id, a, b, c;
	for (int i = 0; i < N; i++){
		cin >> id >> a >> b >> c;

		ans += check(id, a);
		ans += check(id, b);
		ans += check(id, c);


		add(id, a);
		add(id, b);
		add(id, c);
	}

	cout << ans << "\n";

	return 0;
}
