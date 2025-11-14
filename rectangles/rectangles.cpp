#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int A, B, C;
	cin >> A >> B >> C;

	int a = min({A, B, C});
	int c = max({A, B, C});
	int b = A + B + C - a - c;

	if (a == c){
		cout << "1\n";
	} else if (a == b || b == c){
		cout << "3\n";
	} else {
		cout << "6\n";
	}

	return 0;
}
