#include <iostream>
#include <vector>
using namespace std;

int scarto(vector<long long>& P, long long N, long long K, long long C){
	long long ex = N * K;
	long long sum = 0, s = 0;
	for (auto& x : P)
		sum += x, s += min(C, x-1);
	
	if (ex < sum){
		return (sum - ex) <= s;
	} else {
		return (ex - sum) <= N * C;
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long N, K;
	cin >> N >> K;
	
	vector<long long> P(N);
	for (auto& x : P)
		cin >> x;
	
	int lo = 0, hi = 1e9+42, mid;
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;
		if (scarto(P, N, K, mid))
			hi = mid;
		else
			lo = mid;
	}
	
	cout << (scarto(P, N, K, 0) ? 0 : lo+1) << "\n";
	
	return 0;
}