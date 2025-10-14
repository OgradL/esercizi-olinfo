#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	map<int, int> cnt;
	long long ans = 0;

	int x, y;
	for (int i = 0; i < N; i++){
		cin >> x >> y;

		ans += cnt[x - y]++;
	}

	cout << ans << "\n";

	return 0;
}
