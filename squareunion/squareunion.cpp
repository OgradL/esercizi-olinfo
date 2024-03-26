#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<long long> X(N), R(N);
	for (long long& x : X)
		cin >> x;
	for (long long& x : R)
		cin >> x;
	
	set<pair<long long, long long>> Q;
	multiset<long long, greater<long long>> P;
	P.insert(0);

	for (int i = 0; i < N; i++)
		Q.insert({X[i]-R[i], i}), Q.insert({X[i]+R[i], i});

	vector<int> seen(N, 0);
	long long ans = 0;
	long long last = 0, r = 0;
	for (auto it = Q.begin(); it != Q.end(); ++it){
		ans += (it->first - last) * r * 2;
		if (seen[it->second]++){
			P.erase(P.find(R[it->second]));
		} else {
			P.insert(R[it->second]);
		}
		last = it->first;
		r = *P.begin();
	}
	
	cout << ans << "\n";

	return 0;
}