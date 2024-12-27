#include <iostream>
#include <vector>
#include <set>
using namespace std;

string ask(string q){
	cout << "? " << q << endl;
	string ans;
	cin >> ans;
	return ans;
}

void solve(){

	string alph = "abcdefghijklmnopqrstuvwxyz";

	set<char> letters;

	for (int i = 0; i < 5; i++){
		string s = ask(alph.substr(i*5, 5));
		for (int j = 0; j < 5; j++){
			if (s[j] != 'W')
				letters.insert('a' + j + 5*i);
		}
	}

	if (letters.size() < 5)
		letters.insert('z');

	string ans(5, *letters.rbegin());
	for (char c : letters){
		if (c == *letters.rbegin())
			break;
		string q(5, c);
		string r = ask(q);
		for (int i = 0; i < 5; i++){
			if (r[i] == 'G')
				ans[i] = c;
		}
	}

	cout << "! " << ans << endl;
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
