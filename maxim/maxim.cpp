#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){

	int N, K;
	cin >> N >> K;

	vector<int> V(N);
	for (int &n : V) cin >> n;

	multiset<int> s;
	for (int i = 0; i < K; i++){
		s.insert(V[i]);
	}
	int ma = *prev(s.end());
	vector<int> pref(N, ma);
	for (int i = 1; i < N-K+1; i++){
		s.erase(V[i-1]);
		s.insert(V[i+K-1]);
		pref[i] = *prev(s.end());
	}

	int ans = 0;
	for (int i = 0; i < N; i++){
		ans = max(ans,
					max(
						pref[max(i-K, 0)],
						pref[min(i+1, N-K)]
					) - V[i]
				);
	}

	cout << ans << "\n";

	return 0;
}