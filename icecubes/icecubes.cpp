#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int ans = 0;

	int x;
	while (N--){
		cin >> x;
		ans += max(0, x-1);
	}

	cout << ans << "\n";

	return 0;
}
