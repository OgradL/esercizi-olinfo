#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct SegmentTree{


};

struct event{
	int x, y, type;
};

array<int, 3> find_plus(int N, int S, int F, vector<int> y, vector<int> x){

	vector<event> events;
	for (int i = 0; i < N; i++){
		events.push_back({x, y, 0});
	}

	sort(events.begin(), events.end(), [](event a, event b){
		if (a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	});


	SegmentTree st;
	for (event e : events){
		st.range_add(e.y - F, e.y + F, 1);
		st.range_add(e.y, e.y+1, 1);
		int max = st.get_max(0, S);
	}

	return {0, 1, 2};
}
