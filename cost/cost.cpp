#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const long long MOD = 1000003;

int solve(int N, int M, int K, vector<int> A, vector<int> B){
	vector<long long> v;
	v.reserve(N + M);
	for (int i = 0; i < N; i++){
		v.push_back(i);
	}
	for (int j = 0; j < M; j++){
		v.push_back(j + N);
	}
	
	sort(v.begin(), v.end(), [&](long long a, long long b){
		long long c = (a < N) ? A[a] : B[a - N];
		long long d = (b < N) ? A[b] : B[b - N];
		return c > d;
	});
	
	long long ansa = (long long)(M)*M % MOD, ansb = (long long)(N)*N % MOD;
	set<long long> sa, sb;
	sa.insert(-1);
	sa.insert(N);
	sb.insert(-1);
	sb.insert(M);

	long long ans = 0, t1, t2, t3, t4, t5;
	for (long long& x : v){
		if (x < N){
			auto it = sa.lower_bound(x);
			long long p = *prev(it), d = *it;

			t1 = ansa % MOD;
			t2 = ansa * 2 * (x - p - 1) % MOD;
			t3 = ansa * 2 * (d - x - 1) % MOD;
			t4 = ansa * 2 * ((d - x - 1) * (x - p - 1) % MOD) % MOD;

			t5 = (t1 + t2 + t3 + t4) % MOD;
			ans += t5 * A[x] % MOD;
			ans = ans % MOD;

			ansb = MOD + ansb - ((d - p - 1) * (d - p - 1) % MOD);
			ansb = MOD + ansb + ((x - p - 1) * (x - p - 1) % MOD) + ((d - x - 1) * (d - x - 1) % MOD);
			ansb = ansb % MOD;
			sa.insert(x);
		} else {
			x -= N;
			auto it = sb.lower_bound(x);
			long long p = *prev(it), d = *it;

			t1 = ansb % MOD;
			t2 = ansb * 2 * (x - p - 1) % MOD;
			t3 = ansb * 2 * (d - x - 1) % MOD;
			t4 = ansb * 2 * ((d - x - 1) * (x - p - 1) % MOD) % MOD;

			t5 = (t1 + t2 + t3 + t4) % MOD;
			ans += t5 * B[x] % MOD;
			ans = ans % MOD;

			ansa = MOD + ansa - ((d - p - 1) * (d - p - 1) % MOD);
			ansa = MOD + ansa + ((x - p - 1) * (x - p - 1) % MOD) + ((d - x - 1) * (d - x - 1) % MOD);
			ansa = ansa % MOD;
			sb.insert(x);
		}
	}

	return ans;
}