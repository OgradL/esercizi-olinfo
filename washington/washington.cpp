#include <iostream>
using namespace std;

pair<int, int> conv(string q, char x, int y){
	pair<int, int> ans;
	if (q[0] == 'N'){
		ans.second = y;
	} else {
		ans.second = y - 26;
		if (y == 0)
			ans.second = 0;
	}
	if (q[1] == 'E'){
		ans.first = x - 'A';
	} else {
		ans.first = 'A' - x;
	}
	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--){
		string q;
		char x;
		int y;
		cin >> q >> x >> y;

		auto c1 = conv(q, x, y);

		cin >> q >> x >> y;

		auto c2 = conv(q, x, y);

		cout << abs(c1.first - c2.first) + abs(c1.second - c2.second) << "\n";
	}

	return 0;
}
