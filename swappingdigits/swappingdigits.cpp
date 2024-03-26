#include <iostream>
#include <vector>
using namespace std;

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	if (n < 2){
		cout << (s == "0" ? 0 : -1) << "\n";
		return;
	}
	vector<int> c(10, 0);
	for (auto x : s)
		c[x-'0']++;
	int ans = 3;

	if (c[0] >= 2)
		ans = min(ans, 2 - (s[n-2] == '0') - (s[n-1] == '0'));
	
	if (c[2] >= 1 && c[5] >= 1)
		ans = min(ans, 2 - (s[n-2] == '2') - (s[n-1] == '5'));

	ans = min(ans, (s[n-2] == '5' && s[n-1] == '2') ? 1 : 3);
	
	if (c[0] >= 1 && c[5] >= 1)
		ans = min(ans, 2 - (s[n-2] == '5') - (s[n-1] == '0'));
	
	ans = min(ans, (s[n-2] == '0' && s[n-1] == '5') ? 1 : 3);

	if (c[7] >= 1 && c[5] >= 1)
		ans = min(ans, 2 - (s[n-2] == '7') - (s[n-1] == '5'));

	ans = min(ans, (s[n-2] == '5' && s[n-1] == '7') ? 1 : 3);
	
	cout << (ans == 3 ? -1 : ans) << "\n";
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