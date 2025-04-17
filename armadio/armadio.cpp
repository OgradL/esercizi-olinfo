#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 4000001;
void evadi(int Q, vector<int>& N){

	vector<long long> phi(MAXN);
	vector<long long> bpf(MAXN, MAXN);
	phi[0] = 0;
	phi[1] = 1;
	for (int i = 0; i < MAXN; i++)
		phi[i] = i;

	for (int i = 2; i < MAXN; i++) {
		if (phi[i] == i) {
			for (int j = i; j < MAXN; j += i)
				phi[j] -= phi[j] / i, bpf[j] = i;
		}
	}
	

	for (int& x : N){
		long long ans = 0;

		auto find_divisors = [&](auto&& find_divisors, long long v, long long m = 1){
			if (v == 1){
				if (m > 2)
					ans += phi[m - 1];
				return;
			}
			
			long long p = bpf[v];
			int count = 0;
			while (bpf[v] == p)
				v /= p, count++;
			
			for (int i = 0; i <= count; i++){
				find_divisors(find_divisors, v, m);
				m *= p;
			}
		};

		find_divisors(find_divisors, x);

		x = ans;
	}
}
