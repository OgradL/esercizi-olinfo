#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long M = 1e9 + 7;
long long fact[100001];
long long invfact[100001];

long long POW(long long b, long long e){
	if (e == 0) return 1;
	long long v = POW(b, e/2);
	return (v * v % M) * (e&1?b:1) % M;
}

long long inv(long long x){
	return POW(x, M-2);
}

long long binomial(long long a, long long b){
	long long ret = fact[a];
	ret = ret * invfact[b] % M;
	ret = ret * invfact[a-b] % M;
	return ret;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fact[0] = fact[1] = 1;
	for (int i = 2; i < 100001; i++)
		fact[i] = fact[i-1] * i % M;

	invfact[0] = invfact[1] = 1;
	for (int i = 2; i < 100001; i++)
		invfact[i] = inv(fact[i]);

	int N;
	cin >> N;

	vector<int> c(N, 0);
	vector<vector<int>> occ(N+1);

	vector<int> V(N);
	for (int& x : V)
		cin >> x;
	
	sort(V.begin(), V.end(), [](int a, int b){
		return a < b;
	});

	int x;
	for (int i = 0; i < N; i++){
		x = lower_bound(V.begin(), V.end(), V[i]) - V.begin();
		c[x]++;
		occ[c[x]].push_back(x);
	}

	long long ans = 0, tmp;
	for (int k = 1; k < occ.size(); k++){
		tmp = 1;
		for (int n : occ[k]){
			tmp *= (1 + binomial(c[n], k)) % M;
			tmp %= M;
		}
		ans += M + tmp - 1;
		ans %= M;
	}

	ans = (ans + 1) % M;
	
	cout << ans << "\n";

	return 0;
}