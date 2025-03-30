#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int X, Y;
	cin >> X >> Y;

	int winner = (abs(X - Y) == 1) && (min(X, Y) % 2 == 0);

	if (winner){
		cout << "N\n" << flush;
	} else {
		cout << "C\n" << flush;

		if (X > Y){
			X = Y - ((Y & 1) * 2 - 1);
		} else {
			Y = X - ((X & 1) * 2 - 1);
		}

		cout << X << " " << Y << "\n" << flush;
	}

	while (X + Y > 1){
		cin >> X >> Y;

		if (X > Y){
			X = Y - ((Y & 1) * 2 - 1);
		} else {
			Y = X - ((X & 1) * 2 - 1);
		}

		cout << X << " " << Y << "\n" << flush;
	}

	return 0;
}
