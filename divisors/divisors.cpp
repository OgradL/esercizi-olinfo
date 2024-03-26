#include <iostream>
#include <vector>
using namespace std;

long long compute(long long n){
	
	long long d = 1, s = 1, ans = 0;
	for ( ; d <= n; ){
		s = d;
		d = (n / (n / d));
		ans += (d - s + 1) * (n / d);
		d++;
	}

	return ans;
}