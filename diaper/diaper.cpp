#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int ans = 0;

	int pee = 0, poop = 0;
	char c;
	int quantity;
	while (N--){
		cin >> quantity >> c;

		if (c == 'M')
			pee += quantity;
		else
			poop += quantity;

		if (N == 0)
			break;

		if (pee >= 50){
			pee -= 50;
			ans++;
		} else if (poop >= 80){
			poop -= 80;
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}
