#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	string S;
	cin >> S;

	vector<int> cnt(26, 0);
	for (char c : S)
		++cnt[c - 'a'];

	for (int i = 0; i < 26; i++){
		if (cnt[i] & 1)
			cout << (char)('a' + i) << "\n";
	}

	return 0;
}
