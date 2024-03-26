#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void solve(){
	int A, B;
	cin >> A >> B;

	if (A < 33 || A > 53 || B >= 53){
		cout << "-1 -1\n";
	} else {
		int a, b;
		for (int i = 0; i < 2; i++){
			a = min(A - 33, 10);
			b = min(B, 11);
			if (b == 11){
				cout << a << " " << b << "\n";
				A -= a;
				B -= b;
			}
		}
		for (int i = 0; i < 3; i++){
			a = 11;
			b = min(B, 10);
			cout << a << " " << b << "\n";
			A -= a;
			B -= b;
		}
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