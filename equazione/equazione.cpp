#include <iostream>
#include <vector>
using namespace std;

long long c(long long x){
	int ans = 0;
	while (x >= 1){
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

long long calc(long long x){
	if (x > 1e9+1000)
		return 1e18+1000;
	return x * x + c(x) * x;
}

long long stima(long long N){

	long long lo = 0, hi = 1e18, mid;
	while (lo + 10000 < hi){
		mid = (lo + hi) / 2;

		if (calc(mid) < N){
			lo = mid;
		} else {
			hi = mid;
		}
	}
	
	for (long long i = max(lo - 10000, 0LL); i <= hi + 10000; i++){
		if (calc(i) == N)
			return i;
	}
	
	return -1;
}

int main() {
	
	long long n;
	cin >> n;
	
	cout << stima(n) << "\n";
	
	return 0;
}