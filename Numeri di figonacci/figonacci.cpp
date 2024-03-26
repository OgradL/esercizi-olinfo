#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> figNum;

int init(int N, int M){
	ll last = 0;
	ll diff = -1;
	for (int i = 2; i <= N; i++){
		ll dummy = ((last % M) * ((i - 1) % M)) % M - diff % M;
		diff += last;
		last = dummy;
	}
	return (last % M + M) % M;
}

ll fig(ll N){
	
}

int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N, M;
	
	cin >> N >> M;
	
	cout << init(N, M) << "\n";
	
	return 0;
}
