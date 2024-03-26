#include <bits/stdc++.h>

using namespace std;

long long fast_pow(long long b, long long e);

int log(long long b, long long v){
	
	int lo = 0;
	int hi = 17;
	
	if (b >= 100) hi = 3;
//	cout << lo << " " << lo + 0.00001 << " " << hi << "\n";
	
	while (lo + 1 < hi){
		long long mid = (lo + hi) / 2;
//		cout << mid << "\n";
		
		long long va = fast_pow(b, mid);
		
		if (va == v) return mid;
		if (va < v){
			lo = mid;
		} else {
			hi = mid;
		}
	}
	
	return lo;
}

long long fast_pow(long long b, long long e){
	if (e <= 0) return 1;
	if (e % 2 == 0){
		long long num = fast_pow(b, e/2);
		return num*num;
	} else {
		return b * fast_pow(b, e-1);
	}
}

int main(){
	
	#ifdef EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int N;
	
	cin >> N;
	
	int ans = 0;
	
	int v;
	
//	cout << "log(2, 100) = " << (log(2, 100)) << "\n";
	
	for (int i = 1; i < N; i++){
//		cout << i << " <-> ";
//		cout << (log(i, N)) << " - ";
//		cout << (int)fast_pow(i, max(2, (log(i, N)))) << " - ";
//		cout << "\n";
		ans = max(ans, ((int)fast_pow(i, ((v = int(log(i, N))) < 2) ? 0 : v)));
	}
	
	cout << ans << "\n";
	
	return 0;
}
