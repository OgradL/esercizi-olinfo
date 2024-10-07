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
	int top(){
		if (q.empty()) return 1e9;
		return q.front().first;
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

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K, M, P, Q;
	cin >> N >> K >> M >> P >> Q;

	minStack<less<int>> minst[2];

	int ans = 0;
	minst[0].push(Q - P);
	for (int i = 1; i <= N; i++){
		minst[i&1].push(ans = max(-minst[i&1].top(), -minst[(i&1)^1].top() - M));

		if (i - K >= 0){
			minst[(i-K)&1].pop();
		}
	}

	cout << ans << "\n";

	return 0;
}
