#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int S = 54;

int map(int c){
	if (c <= 'Z')
		return c - 'A';
	return 26 + c - 'a';
}

void solve(){

	int Q;
	cin >> Q;
	
	long long ans = 0, tmp;
	long long f, k, tc = 0, s, v;
	char c;
	vector<long long> count(S);
	for (int i = 0; i < S; i++) count[i] = 0;
	while (Q--){
		cin >> f >> c >> k;
		c = map(c);

		ans -= (tc - count[c]) * count[c];
		tc += f;
		count[c] += f;
		ans += (tc - count[c]) * count[c];

		tmp = ans;
		auto sorted = count;
		sort(sorted.begin(), sorted.end(), less<long long>());
		s = 0;
		for (int i = 0; i < S-1 && k > 0; i++){
			if (!sorted[i]) continue;
			tmp -= (tc - sorted[i]) * sorted[i];
			tc -= sorted[i];
			tmp -= (tc - sorted[S-1]) * sorted[S-1];
			tc -= sorted[S-1];
			sorted[i] -= v = min(sorted[i], k);
			sorted[S-1] += v;
			k -= v;
			s += v;
			tc += sorted[S-1];
			tmp += (tc - sorted[S-1]) * sorted[S-1];
			tc += sorted[i];
			tmp += (tc - sorted[i]) * sorted[i];
		}
		cout << tmp << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) solve();

	return 0;
}