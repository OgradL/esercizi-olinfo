#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--){

		string s;
		cin >> s;

		int N = s.size();

		vector<array<int, 2>> pres(26, {0, 0});
		vector<string> ans;
		int ok = 1;
		for (int i = 0; i < N && ok; i++){
			if (i + 1 < N && s[i] == s[i+1]){
				ans.push_back(s.substr(i, 2));
				ok &= pres[s[i++]-'a'][1]++ == 0;
			} else {
				ans.push_back(s.substr(i, 1));
				ok &= pres[s[i]-'a'][0]++ == 0;
			}
		}

		if (ok){
			for (string& x : ans)
				cout << x << ' ';
			cout << '\n';
		} else {
			cout << "-1\n";
		}
	}

	return 0;
}
