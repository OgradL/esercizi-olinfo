#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string S;
	cin >> S;

	vector<pair<char, string>> alphabet = {
		{'a', "alpha"}, 
		{'b', "bravo"},
		{'c', "charlie"},
		{'d', "delta"},
		{'e', "echo"},
		{'f', "foxtrot"},
		{'g', "golf"},
		{'h', "hotel"},
		{'i', "india"},
		{'j', "juliett"},
		{'k', "kilo"},
		{'l', "lima"},
		{'m', "mike"},
		{'n', "november"},
		{'o', "oscar"},
		{'p', "papa"},
		{'q', "quebec"},
		{'r', "romeo"},
		{'s', "sierra"},
		{'t', "tango"},
		{'u', "uniform"},
		{'v', "victor"},
		{'w', "whiskey"},
		{'x', "xray"},
		{'y', "yankee"},
		{'z', "zulu"}
	};

	int i = 0;
	string ans;
	while (i < S.size()){
		for (auto [c, s] : alphabet){
			if (S.substr(i, s.size()) == s){
				ans += c;
				i += s.size();
				break;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
