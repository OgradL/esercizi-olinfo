#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

#define mp(a, b) make_pair(a, b)
#define ld long double

long double fast_pow(long double b, int e){
	if (e <= 0) return 1.0L;
	if (e == 1) return b;

	long double v = pow(b, e/2);
	v = v * v;
	if (e%2) v *= b;

	return v;
}

struct compare{
	bool operator()(const pair<ld, pair<int, ld>>& a, const pair<ld, pair<int, ld>>& b){
		return a.first * a.second.second < b.first * b.second.second;
	}
};

void solve(){

	int N, K;
	cin >> N >> K;

	vector<ld> P(N);
	for (ld &n : P) cin >> n;

	// pair<ld, ld> = <prob_alive, idx>;
	

	priority_queue<pair<ld, pair<int, ld>>, vector<pair<ld, pair<int, ld>>>, compare> pq;
	for (int i = 0; i < N; i++) pq.push(mp(1.0L, mp(i, P[i])));

	vector<int> dead(N, 0);
	for (int i = 0; i < K; i++){
		pair<ld, pair<int, ld>> x = pq.top();
		ld p_alive = x.first;
		int idx = x.second.first;
		ld p_die = x.second.second;
		pq.pop();
		ld die_now = p_alive * p_die;
		dead[idx]++;
		pq.push(mp(p_alive - die_now, mp(idx, p_die)));
		// cout << idx << " " << p_alive << " " << die_now << " " << ans << "\n";
	}
	
	ld ans = 0.0000000000L;
	for (int i = 0; i < N; i++){
		// cout << i << " " << P[i] << " " << dead[i] << " " << fast_pow(1-P[i], dead[i]) << "\n";
		ans += 1.0L - fast_pow(1.0L-P[i], dead[i]);
	}

	long long newans = floor(ans * 1000000);
	
	cout << newans / 1000000 << "." << newans % 1000000 << "\n";

}

int main(){

	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}