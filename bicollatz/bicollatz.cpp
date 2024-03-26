#include <iostream>
using namespace std;

int main(){	

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int A, B, count = 0;
	cin >> A >> B;

	while (A != 1 || B != 1){
		if (A%2==0 && B%2==0){
			A /= 2;
			B /= 2;
		}
		if (A%2 && B%2){
			A = A * 3 + 1;
			B = B * 3 + 1;
		}
		if (A%2) A += 3;
		if (B%2) B += 3;
		count++;
	}


	cout << count << "\n";


	return 0;
}