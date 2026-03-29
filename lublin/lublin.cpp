#include <deque>
#include <iostream>
#include <vector>
using namespace std;

struct minstack{
	deque<pair<long long, int>> q;
	int cnt_add = 0, cnt_rem = 0;

	minstack() {}

	void insert(long long x){
		while (!q.empty() && q.front().first >= x){
			q.pop_front();
		}
		q.push_back({x, cnt_add++});
	}

	void pop(){
		if (q.empty())
			return;
		if (q.front().second == cnt_rem++)
			q.pop_front();
	}

	long long get_min(){
		if (q.empty())
			return 1e9;
		return q.front().first;
	}
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> A(N-1);
	for (int& x : A)
		cin >> x;

	const int M = 320;

	vector<minstack> dp(M);
	// dp[i][j] = min cost to reach next shop with i clothes and j cold

	for (int i = 2; i < M; i++){
		for (int j = 0; j < i; j++){
			dp[i].insert(1e18);
		}
	}
	dp[1].insert(0);

	for (int i = 0; i < N-1; i++){
		for (int j = M-1; j > 0; j--){
			dp[j].insert(min(dp[j].get_min() + 1, dp[j-1].get_min() + 1 + A[i]));
			dp[j].pop();
		}
	}

	long long ans = 1e18;
	for (int i = 1; i < M; i++){
		ans = min(ans, dp[i].get_min());
	}

	cout << ans << "\n";

	return 0;
}
