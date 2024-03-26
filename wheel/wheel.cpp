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
		if (q.empty()) return 0;
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

	int N;
	cin >> N;

	vector<int> V(2*N);
	for (int &n : V)
		cin >> n;
	
	minStack<less<int>> minst;
	minStack<greater<int>> maxst;

	for (int i = 0; i < N; i++){
		minst.push(V[i]);
		maxst.push(V[i+N]);
	}

	vector<pair<int, int>> pref(2*N);
	pref[0] = {minst.top(), maxst.top()};
	for (int i = 0; i < 2*N; i++){
		minst.pop();
		minst.push(V[(i+N)%(2*N)]);

		maxst.pop();
		maxst.push(V[i]);

		pref[i+1%(2*N)] = {minst.top(), maxst.top()};
	}


	int Q;
	cin >> Q;

	int t, p = 0;
	while (Q--){
		cin >> t;
		p = (2*N + p - t) % (2*N);
		cout << pref[p].first << " " << pref[p].second << "\n";
	}
	

	return 0;
}