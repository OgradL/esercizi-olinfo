#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int ans = 2*N, x;

	while (N--){
		cin >> x;
		ans += x;
	}

	cout << ans << "\n";

	return 0;
}
