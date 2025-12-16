#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int mod = 998244353;    
const int root = 15311432;    
const int root_1 = 469870224;    
const int root_pw = 1 << 23;

long long POW(long long b, long long e, long long mod){
	long long res = 1;
	while (e){
		if (e & 1){
			res = res * b % mod;
		}
		b = b * b % mod;
		e >>= 1;
	}
	return res;
}

long long inverse(long long x){
	return POW(x, mod - 2, mod);
}

void fft(vector<int>& a, bool invert){
	int n = a.size();

	for (int i = 1, j = 0; i < n; i++){
		int bit = n >> 1;
		for (; j & bit; bit >>= 1)
			j ^= bit;
		j ^= bit;

		if (i < j)
			swap(a[i], a[j]);
	}

	for (int len = 2; len <= n; len <<= 1){
		int wlen = invert ? root_1 : root;
		for (int i = len; i < root_pw; i <<= 1)
			wlen = (int)(1LL * wlen * wlen % mod);

		for (int i = 0; i < n; i += len){
			int w = 1;
			for (int j = 0; j < len / 2; j++){
				int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
				a[i+j] = u + v < mod ? u + v : u + v - mod;
				a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
				w = (int)(1LL * w * wlen % mod);
			}
		}
	}

	if (invert){
		int n_1 = inverse(n);
		for (int & x : a)
			x = (int)(1LL * x * n_1 % mod);
	}
}


vector<int> multiply(vector<int> const& a, vector<int> const& b){
	vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while (n < a.size() + b.size()) 
		n <<= 1;
	fa.resize(n);
	fb.resize(n);

	fft(fa, false);
	fft(fb, false);
	for (int i = 0; i < n; i++)
		fa[i] = (int)(1LL * fa[i] * fb[i] % mod);
	fft(fa, true);
	return fa;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, Q;
	cin >> N >> Q;

	string S;
	cin >> S;

	vector<int> A, T, C, G;

	for (int c : S){
		A.push_back(c == 'A');
		T.push_back(c == 'T');
		C.push_back(c == 'C');
		G.push_back(c == 'G');
	}

	reverse(T.begin(), T.end());
	reverse(G.begin(), G.end());

	vector<int> at = multiply(A, T);
	vector<int> cg = multiply(C, G);

	vector<long long> cnt(N, 0);
	for (int i = 0; i < 2*N-1; i++){
		cnt[abs(N-i-1)] += at[i] + cg[i];
	}

	vector<long long> pref(N+1, 0);
	for (int i = 0; i < N; i++){
		pref[i+1] = pref[i] + cnt[i];
	}

	int l, r;
	while (Q--){
		cin >> l >> r;

		long long ans = pref[r+1] - pref[l];

		cout << ans << "\n";
	}

	return 0;
}
