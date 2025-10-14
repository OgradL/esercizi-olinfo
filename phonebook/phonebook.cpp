#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int ans = 0;

	string phone;
	while (N--){
		cin >> phone;

		if (phone.substr(0, 3) == "+39"){
			if (phone.size() == 12 || phone.size() == 13){
				ans++;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
