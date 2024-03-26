#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct pt {
	double x, y;
};

int orientation(pt a, pt b, pt c) {
	double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
	if (v < 0) return -1; // clockwise
	if (v > 0) return +1; // counter-clockwise
	return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
	int o = orientation(a, b, c);
	return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& a, bool include_collinear = false) {
	pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
		return make_pair(a.y, a.x) < make_pair(b.y, b.x);
	});
	sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
		int o = orientation(p0, a, b);
		if (o == 0)
			return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
				< (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
		return o < 0;
	});
	if (include_collinear) {
		int i = (int)a.size()-1;
		while (i >= 0 && collinear(p0, a[i], a.back())) i--;
		reverse(a.begin()+i+1, a.end());
	}

	vector<pt> st;
	for (int i = 0; i < (int)a.size(); i++) {
		while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
			st.pop_back();
		st.push_back(a[i]);
	}

	a = st;
}

vector<int> trovacerchi(int N, vector<int> X, vector<int> Y){
	unordered_map<int, unordered_map<int, int>> idx;
	vector<pt> points(N);
	for (int i = 0; i < N; i++){
		points[i] = (pt) {X[i], Y[i]};
		idx[X[i]][Y[i]] = i;
	}
	points.push_back((pt) {0, 0});
	
	convex_hull(points, false);
	
	vector<int> ans;
	for (int i = 0; i < points.size(); i++){
		if (points[i].x != 0 || points[i].y != 0)
			ans.push_back(idx[points[i].x][points[i].y]);
	}
	return ans;
}