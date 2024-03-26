#include <iostream>
#include <vector>
using namespace std;

const long long b = 69420;
const long long M = 1e9 + 7;
const long long maxn = 1e5 + 42;

long long pref[maxn], pw[maxn], pinv[maxn];
vector<int> sieve[maxn];

long long POW(long long b, long long e){
	if (e == 0) return 1;
	long long v = POW(b, e/2);
	return (v * v % M) * (e&1?b:1) % M;
}

long long inv(long long x){
	return POW(x%M, M - 2);
}

long long get_hash(int l, int r){
	return (M + pref[r+1] - (pref[l] * pw[r - l + 1] % M)) % M;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	string s;
	cin >> s;

	pw[0] = 1;
	for (int i = 1; i < maxn; i++)
		pw[i] = pw[i-1] * b % M;
	
	pinv[0] = 0;
	for (int i = 1; i < maxn; i++){
		pinv[i] = inv(pw[i] - 1);
	}

	pref[0] = 0;
	for (int i = 1; i <= N; i++)
		pref[i] = (pref[i-1] * b + s[i-1]) % M;

	for (int i = 1; i <= N; i++){
		for (int j = i+i; j <= N; j+=i){
			sieve[j].push_back(i);
		}
	}

	int Q;
	cin >> Q;

	int l, r;
	int ok;
	long long hash1, hash2, mol;
	while (Q--){
		cin >> l >> r;
		ok = 0;
		hash1 = get_hash(l, r);
		for (int d : sieve[r - l + 1]){
			hash2 = get_hash(l, l + d - 1);
			mol = pw[r - l + 1] - 1;
			mol = mol * pinv[d] % M;
			hash2 = hash2 * mol % M;
			ok |= hash1 == hash2;
		}
		cout << (ok ? "YES\n" : "NO\n");
	}

	return 0;
}