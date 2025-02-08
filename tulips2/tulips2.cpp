#include <iostream>
#include <vector>
using namespace std;

long long dot(long long x0, long long y0, long long x1, long long y1){
	return x0 * x1 + y0 * y1;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long x0, y0, x1, y1, x2, y2, x3, y3;
	cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	int N;
	cin >> N;

	int ans = 0, x, y;
	while (N--){
		cin >> x >> y;

		int acute = 0, obtuse = 0;
		long long d0 = dot(x0 - x, y0 - y, x1 - x, y1 - y);
		long long d1 = dot(x1 - x, y1 - y, x2 - x, y2 - y);
		long long d2 = dot(x2 - x, y2 - y, x3 - x, y3 - y);
		long long d3 = dot(x3 - x, y3 - y, x0 - x, y0 - y);

		obtuse += (d0 < 0) + (d1 < 0) + (d2 < 0) + (d3 < 0);
		acute += (d0 > 0) + (d1 > 0) + (d2 > 0) + (d3 > 0);

		ans += acute == 2 && obtuse == 2;
	}

	cout << ans << "\n";

	return 0;
}
