#include <iostream>
#include <vector>
using namespace std;

void solve(){
	int A, B;
	cin >> A >> B;

	if (A < 33 || A > 53 || B >= 53){
		cout << "-1 -1\n";
		return;
	}

	vector<pair<int, int>> ans;

	int a, b;
	while (B > 30 || A > 33){
		a = min(A - 33, 10);
		b = 11;
		ans.push_back({a, b});
		A -= a;
		B -= b;
	}

	if (B < 0){
		cout << "-1 -1\n";
		return;
	}

	while (A > 0){
		a = 11;
		b = min(B, 10);
		ans.push_back({a, b});
		A -= a;
		B -= b;
	}

	for (auto [x, y] : ans){
		cout << x << " " << y << "\n";
	}
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
