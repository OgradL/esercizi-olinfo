#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct fenwick{

	int N;
	vector<long long> fen;

	fenwick(int n){
		N = n+1;
		fen.assign(N, -1e18);
	}

	void update(int idx, long long x){
		for (++idx; idx < N; idx += idx & -idx)
			fen[idx] = max(fen[idx], x);
	}

	long long get_max(int idx){
		long long res = -1e18;
		for (++idx; idx > 0; idx -= idx & -idx)
			res = max(res, fen[idx]);
		return res;
	}
};

void solve(){
	
	int N;
	cin >> N;

	vector<int> A(N);
	for (int& x : A)
		cin >> x;

	auto orig = A, comp = A;
	sort(comp.begin(), comp.end());
	for (int& x : A){
		x = lower_bound(comp.begin(), comp.end(), x) - comp.begin();
	}

	fenwick fen0(N), fen1(N);

	long long ans = 0;
	for (int i = 0; i < N; i++){
		long long v0 = ans - comp[A[i]];
		long long v1 = ans + comp[A[i]];

		ans = max(ans, fen0.get_max(A[i]) + comp[A[i]]);
		ans = max(ans, fen1.get_max(N-A[i]-1) - comp[A[i]]);
		
		fen0.update(A[i], v0);
		fen1.update(N-A[i]-1, v1);
	}
	
	cout << ans << "\n";
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) solve();

	return 0;
}
