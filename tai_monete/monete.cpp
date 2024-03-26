#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

struct minStack{
	deque<pair<int, int>> q;
	int cnt_added = 0;
	int cnt_removed = 0;
	minStack(){
		q.clear();
		cnt_added = 0;
		cnt_removed = 0;
	}
	int get_min(){
		if (q.empty()) return 0;
		return q.front().first;
	}
	void add_elem(int new_element){
		while (!q.empty() && q.back().first > new_element)
			q.pop_back();
		q.push_back({new_element, cnt_added});
		cnt_added++;
	}
	void remove_elem(){
		if (!q.empty() && q.front().second == cnt_removed)
			q.pop_front();
		cnt_removed++;
	}
};

int best_score(int N, int K, vector<int> &monete){

	vector<int> pref(N, 0);
	pref[0] = monete[0];
	for (int i = 1; i < N; i++){
		pref[i] = pref[i-1] + monete[i];
	}

	minStack ms;
	ms.add_elem(0);

	int v;
	for (int i = 0; i < N; i++){
		v = pref[i] - ms.get_min();
		ms.add_elem(v);
		if (i+1 >= K)
			ms.remove_elem();
	}

	return v;
}