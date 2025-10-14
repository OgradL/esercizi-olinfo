#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

long long POW(long long b, long long e){
	long long res = 1;
	while (e){
		if (e & 1){
			res = res * b % MOD;
		}
		b = b * b % MOD;
		e >>= 1;
	}
	return res;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, s, t;
	cin >> N >> s >> t;

	vector<int> cnt(30, 0);
	vector<int> A(N);
	for (int& x : A){
		cin >> x;

		for (int i = 0; i < 30; i++){
			cnt[i] += (x & (1 << i)) != 0;
		}
	}

	long long ans = 1;

	for (int i = 0; i < 30; i++){
		int si = (s & (1 << i)) != 0;
		int ti = (t & (1 << i)) != 0;
		int ones = cnt[i];
		int zero = N - ones;

		int add = si && (ones == 0 || (ones & 1) != ti);
		int disp = (ones & 1) != ti;
		int imp = (!si && (ones > 0 || ti)) || (add && zero == 0);

		if (imp){
			ans = 0;
			break;
		}

		if (!si || zero == 0){
			continue;
		}

		long long m = POW(2, zero - 1);

		if (add && !disp){
			m = MOD + m - 1;
		}

		ans = ans * m % MOD;
	}

	cout << ans << "\n";

	return 0;
}
