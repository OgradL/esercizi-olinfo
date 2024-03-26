#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll search(vector<ll> arr, ll x, ll lo, ll hi){
	
	while (lo + 1 < hi){
		
		ll mid = ll((lo + hi) / 2);
		
		if (arr[mid] >= x){
			hi = mid;
		} else {
			lo = mid;
		}
		
	}
	
	return lo;
}


int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	
	ll N, D;
	
	cin >> N >> D;
	
	vector<ll> P;
	P.resize(N);
	
	for (ll i = 0; i < N; i++){
		cin >> P[i];
	}
	
	ll answer = 0;
	
	for (ll i = 0; i < N - 1; i++){
		ll lo = i;
		ll hi = N;
		ll x = i;
		ll val = P[i];
		ll to_find = P[i] + D;
		
		ll result = search(P, to_find, lo, hi);
		
		ll diff = result - x;
		
		answer += diff;
		
	}
	
	
	cout << answer << "\n";
	
}

