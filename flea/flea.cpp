#include <iostream>
using namespace std;

int main(){

	int N;
	cin >> N;

	string s;
	cin >> s;

	int l = 0, r = 0;

	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'L'){
			l++;
		} else {
			r++;
		}
	}

	cout << abs(r - l) << "\n";

	return 0;
}