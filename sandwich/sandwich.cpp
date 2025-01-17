#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<long long> st;

void set(int i, long long x) {
	i += n;
	for (st[i] = max(st[i], x); i > 1; i >>= 1){
		st[i >> 1] = max(st[i], st[i ^ 1]);
	}
}

long long query(int l, int r){
	long long ans = -1;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1){
		if (l & 1) ans = max(ans, st[l++]);
		if (r & 1) ans = max(ans, st[--r]);
	}
	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N;
	cin >> N;

	vector<long long> V(N);
	for (long long& x : V)
		cin >> x;

	vector<long long> pref(N+1, 0);
	for (int i = 0; i < N; i++){
		pref[i+1] = pref[i] + V[i];
	}

	vector<long long> comp = pref;
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());

	for (long long& x : pref){
		x = lower_bound(comp.begin(), comp.end(), x) - comp.begin();
	}

	n = comp.size();
	st.assign(4 * n, 0);

	int last = 0;
	long long mi = 0;
	for (int i = 1; i <= N; i++){
		int a = query(0, pref[i]);
		if (mi < pref[i])
			set(pref[i], a + 1);
		mi = min(mi, pref[i]);
	}
	
	cout << query(pref[N], pref[N]+1) << "\n";

	return 0;
}
