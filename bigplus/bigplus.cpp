#include <array>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct point{
	int y, x, r;
};

int n, s, f;
vector<vector<int>> pref;

long long get_area(int x0, int y0, int x1, int y1){
	// if (x0 > x1)
	// 	swap(x0, x1);
	// if (y0 > y1)
	// 	swap(y0, y1);
	
	if (x1 < 0)
		return 0;
	if (y1 < 0)
		return 0;

	if (x1 >= s)
		x1 = s-1;
	if (y1 >= s)
		y1 = s-1;
	
	long long ans = pref[y1][x1];
	
	if (x0 > 0)
		ans -= pref[y1][x0-1];
	
	if (y0 > 0)
		ans -= pref[y0-1][x1];
	
	if (x0 > 0 && y0 > 0)
		ans += pref[y0-1][x0-1];
	
	return ans;
}


void calc_area(vector<int>& y, vector<int>& x){
	pref.assign(s, vector<int>(s, 0));
	for (int i = 0; i < n; i++){
		pref[y[i]][x[i]]++;
	}
	// cout << pref[0][0] << " ";
	for (int i = 1; i < s; i++){
		pref[i][0] += pref[i-1][0];
		pref[0][i] += pref[0][i-1];
		// cout << pref[0][i] << " ";
	}
	// cout << "\n";
	for (int i = 1; i < s; i++){
		// cout << pref[i][0] << " ";
		for (int j = 1; j < s; j++){
			pref[i][j] += pref[i-1][j] + pref[i][j-1] -
							pref[i-1][j-1];
			// cout << pref[i][j] << " ";
		}
		// cout << "\n";
	}
}

int try_center(int y, int x){
	long long lo = 0, hi = (n+f)/4+2, mid, area;
	while (lo + 1 < hi){
		mid = (lo + hi) / 2;
		area = 0;
		area += get_area(x - mid, y, x, y);
		area += get_area(x, y, x + mid, y);
		area += get_area(x, y - mid, x, y);
		area += get_area(x, y, x, y + mid);
		area -= 3 * get_area(x, y, x, y);
		if ((4*mid+1) <= (area + f))
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}

point best(point a, point b){
	if (a.r > b.r)
		return a;
	if (a.r < b.r)
		return b;
	if (make_pair(a.y, a.x) < make_pair(b.y, b.x))
		return a;
	return b;
}

array<int, 3> find_plus(int N, int S, int F, vector<int> y, vector<int> x){
	n = N;
	s = S;
	f = F;
	int v;

	calc_area(y, x);
	point ans = {0, 0, 0};
	for (int i = 0; i < N; i++){
		for (int j = i+1; j < N; j++){
			if (v = try_center(y[i], x[j])){
				ans = best(ans, (point){y[i], x[j], v});
			}
			if (v = try_center(y[j], x[i])){
				ans = best(ans, (point){y[j], x[i], v});
			}
		}
	}
	array<int, 3> ansarr = {ans.r, ans.y, ans.x};
	return ansarr;
}