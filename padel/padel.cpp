#include <iostream>
#include <vector>
using namespace std;

void solve(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> V(N);
	for (int& x : V)
		cin >> x;

	int res = 0;
	for (int start = 0; start < N; start++){
		int pa = 0, pb = 0;
		int ans = 0;
		for (int i = start; i < N; i++){
			pa += V[i] == 1;
			pb += V[i] == 2;

			if (max(pa, pb) >= 4 && max(pa, pb) - min(pa, pb) >= 2){
				pa = pb = 0;
				ans++;
			}
		}
		res = max(ans, res);
	}

	cout << res << "\n";
}

int main(){

	int T;
	cin >> T;

	while (T--) solve();

	return 0;
}
