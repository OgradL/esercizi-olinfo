#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int lo, hi, pos;
	cin >> lo >> hi >> pos;

	string ops;
	cin >> ops;

	int ok = 1;
	for (char c : ops){
		if (c == 'U'){
			pos++;
		}
		if (c == 'D'){
			pos--;
		}
		if (c == '0'){
			pos = 0;
		}

		ok &= lo <= pos && pos <= hi;
	}

	if (ok){
		cout << pos << "\n";
	} else {
		cout << "error\n";
	}

	return 0;
}
