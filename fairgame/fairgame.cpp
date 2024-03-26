#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template<class comp = less<int>>
struct minStack{
	deque<pair<int, int>> q;
	int cnt_added = 0;
	int cnt_removed = 0;
	minStack(){
		q.clear();
		cnt_added = 0;
		cnt_removed = 0;
	}
	pair<int, int> top(){
		if (q.empty()) return {1e9, 1e9};
		return q.front();
	}
	void push(int new_element){
		while (!q.empty() && !comp{}(q.back().first, new_element))
			q.pop_back();
		q.push_back({new_element, cnt_added});
		cnt_added++;
	}
	void pop(){
		if (!q.empty() && q.front().second == cnt_removed)
			q.pop_front();
		cnt_removed++;
	}
};

int main(){

	int N, K, M, P, Q;
	cin >> N >> K >> M >> P >> Q;

	minStack<less<int>> minst[2];

	vector<int> dp(N+1, 0);
	dp[0] = P - Q;
	int k = 0;
	for (int i = 1; i < N; i++){
		int a = -dp[k] - ((i-k)%2)*M;
		int b = 1e9;
		if (i-k!=1)
			b = dp[k+1] - ((i-k-1)%2)*M;
		int c = dp[i-1] - M;
		int d = 1e9;
		if (i>1)
			d = dp[i-2];

		dp[i] = max(max(a, b), max(c, d));
		cout << a << " " << b << " " << c << " " << d << " - " << dp[i] << " " << i << " " << k << "\n";
		if (i - k > K){
			k++;
		}
	}

	cout << dp[N] << "\n";

	return 0;
}