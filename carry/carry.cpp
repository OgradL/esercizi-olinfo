#include <iostream>
#include <vector>
using namespace std;

const long long b = 2;
const long long MOD = 1e9 + 7;

long long get_hash(int l, int r, vector<long long>& pref, vector<long long>& pw){
	return (MOD + pref[r + 1] - pref[l] * pw[r - l + 1] % MOD) % MOD;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	string s1, s2;
	cin >> s1;
	cin >> s2;

	for (char& c : s2)
		c = '1' - c + '0';

	vector<long long> pref1(N+1), pref2(N+1), pw(N+1, 1);
	pref1[0] = pref2[0] = 0;
	for (int i = 0; i < N; i++)
		pref1[i+1] = (pref1[i] * b + s1[i] - '0') % MOD,
		pref2[i+1] = (pref2[i] * b + s2[i] - '0') % MOD,
		pw[i+1] = pw[i] * b % MOD;
	
	int Q;
	cin >> Q;

	int a, b, l;
	while (Q--){
		cin >> a >> b >> l;

		int lo = -1, hi = l, mid;
		while (lo + 1 < hi){
			mid = (lo + hi) / 2;
			if (get_hash(a, a + mid, pref1, pw) == get_hash(b, b + mid, pref2, pw))
				lo = mid;
			else
				hi = mid;
		}
		if (lo == l-1)
			cout << "1 ";
		else
			cout << (char)('0' + '1' - s1[a + lo + 1]) << ' ';
	}
	cout << "\n";

	return 0;
}