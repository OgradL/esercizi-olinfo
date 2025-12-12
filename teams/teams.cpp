#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int A, B;
	cin >> A >> B;

	int teams = 0;

	while (A && B){
		if (A < B)
			swap(A, B);
		if (A >= 3 && B >= 1){
			B -= 1;
			A -= 3;
			teams++;
		} else if (A >= 2 && B >= 2){
			A -= 2;
			B -= 2;
			teams++;
		} else {
			break;
		}
	}

	cout << teams << "\n";

	return 0;
}
