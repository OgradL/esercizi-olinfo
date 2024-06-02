#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct point{
	long long x, y;
	point operator+(point a){
		return point{x + a.x, y + a.y};
	}
	point operator-(point a){
		return point{x - a.x, y - a.y};
	}
	bool operator<(const point& a) const{
		if (x == a.x)
			return y < a.y;
		return x < a.x;
	}
};

long long sign(long long x){
	if (x < 0LL)
		return -1;
	if (x > 0LL)
		return 1;
	return 0;
}

long long dot(point a, point b){
	return a.x * b.x + a.y * b.y;
}

long long dotsign(point a, point b){
	__int128_t ax = a.x;
	__int128_t ay = a.y;
	__int128_t bx = b.x;
	__int128_t by = b.y;
	__int128_t ans = ax * bx + ay * by;
	if (ans < 0)
		return -1;
	if (ans > 0)
		return 1;
	return 0;
}

long long cross(point a, point b){
	return a.x * b.y - a.y * b.x;
}

long long crosssign(point a, point b){
	__int128_t ax = a.x;
	__int128_t ay = a.y;
	__int128_t bx = b.x;
	__int128_t by = b.y;
	__int128_t ans = ax * by - ay * bx;
	if (ans < 0)
		return -1;
	if (ans > 0)
		return 1;
	return 0;
}

vector<point> hull, vecs;

void add_line(long long k, long long b){
	point nw = {k, b};
	while (!vecs.empty() && dotsign(vecs.back(), nw - hull.back()) > 0){
		hull.pop_back();
		vecs.pop_back();
	}
	if (!hull.empty()){
		point tmp = nw - hull.back();
		vecs.push_back(point{-tmp.y, tmp.x});
	}
	hull.push_back(nw);
}

long long get(long long x){
	point query = {x, 1};
	auto it = lower_bound(vecs.begin(), vecs.end(), query, [](point a, point b){
		return crosssign(a, b) < 0;
	});
	return dot(query, hull[it - vecs.begin()]);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<long long> H(N);
	for (long long& x : H)
		cin >> x;

	set<point> rette;
	for (int i = 0; i < N-1; i++)
		rette.insert(point{H[i+1] - H[i], i*(H[i]-H[i+1]) + H[i]});

	for (auto x : rette)
		add_line(x.x, x.y);

	for (int i = 0; i < N; i++){
		cout << max(0LL, get(i) - H[i]) << " ";
	}
	cout << "\n";

	return 0;
}
