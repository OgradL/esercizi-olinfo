#include <iomanip>
#include <iomanip>
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

void solve(){

	int N, K;
	cin >> N >> K;

	priority_queue<pair<long double, long double>> pq;

	long double P;
	for (int i = 0; i < N; i++){
		cin >> P;
		pq.push({P, P});
	}

	long double ans = 0;
	while (K--){
		auto [kill, die] = pq.top();
		pq.pop();

		ans += kill;

		pq.push({kill * (1.0 - die), die});
	}

	cout << fixed << setprecision(6) << floor(ans * 1000000) / 1000000 << "\n"; // newans / 1000000 << "." << newans % 1000000 << "\n";
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;

	while (T--) solve();

    return 0;
}
