#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	long long ans = 0, curr, x;
	while (N--){
		cin >> x;
		curr = 1;
		while (curr - 1 < x){
			curr *= 2;
		}
		ans += curr - x - 1;
	}

	cout << ans << "\n";

	return 0;
}
