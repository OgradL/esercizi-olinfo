#include <bits/stdc++.h>
#define con(x) (cerr << __LINE__ << ": " << #x << ' ' << (x) << endl, (x))
#define vis() (cerr << __LINE__ << endl)
#define ll long long
#define f first
#define s second
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;

long long inv(long long i, long long m) {
	return i <= 1 ? i : m - (long long)(m/i) * inv(m % i, m) % m;
}

int main(){
	ifstream in("input.txt");
	ofstream out("input.txt");

	ll mod = 1e9 + 7;
	ll N; cin >> N;

	vector<ll> C(1e6+1);

	C[0] = 1;
	for(int n=0; n<1e6; n++){
		C[n+1] = ((4*n + 2LL) * C[n])%mod;
		C[n+1] = (C[n+1] * inv(n + 2LL, mod))% mod;
	}

	ll ris = 0;
	for(int l=N-1, r=0; l>r; l--, r++){
		ris = (ris + (C[l] * C[r])%mod)%mod;
	}

	cout << ris;
}

