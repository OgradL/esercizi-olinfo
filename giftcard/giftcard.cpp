#include <iostream>
using namespace std;

using ull = __int128_t;

ull mod(ull a, ull b) {
	return ((a % b) + b) % b;
}

ull extended_euclid(ull a, ull b, ull &x, ull &y){
	ull xx = y = 0;
	ull yy = x = 1;
	while (b) {
		ull q = a / b;
		ull t = b;
		b = a % b;
		a = t;
		t = xx;
		xx = x - q * xx;
		x = t;
		t = yy;
		yy = y - q * yy;
		y = t;
	}
	return a;
}

ull gcd(ull a, ull b) {
	ull tmp;
	while (b) {
		a %= b;
		tmp = a;
		a = b;
		b = tmp;
	}
	return a;
}

ull mod_inverse(ull a, ull n){
	ull x, y;
	ull d = extended_euclid(a, n, x, y);
	if (d > 1)
		return -1;
	return mod(x, n);
}

void linear_diophantine(ull a, ull b, ull c, ull &x, ull &y){
	x = c * mod_inverse(a, b);
	y = (c - a * x) / b;
}

int shift_solution(ull& x, ull& y, ull a, ull b, ull cnt){
	x += cnt * b;
	y -= cnt * a;
	return 1;
}

int main(){

	unsigned long long inN, inc1, inc2;
	cin >> inN >> inc1 >> inc2;

	ull N = inN;
	ull c1 = inc1;
	ull c2 = inc2;

	ull g = gcd(c1, c2);
	N /= g;
	c1 /= g;
	c2 /= g;

	ull x1, y1;
	linear_diophantine(c1, c2, N, x1, y1);
	shift_solution(x1, y1, c1, c2, (1 - x1) / c2);
	if (x1 < 1)
		shift_solution(x1, y1, c1, c2, 1);

	int bad1 = (c1 * x1 + c2 * y1) != N;
	// bad1 |= x1 <= 0 | y1 <= 0;

	ull x2, y2;
	swap(c1, c2);
	linear_diophantine(c1, c2, N, x2, y2);
	shift_solution(x2, y2, c1, c2, (1 - x2) / c2);
	if (x2 < 1)
		shift_solution(x2, y2, c1, c2, 1);
	swap(x2, y2);
	swap(c1, c2);

	int bad2 = (c1 * x2 + c2 * y2) != N;
	// bad2 |= x2 <= 0 || y2 <= 0;

	unsigned long long ansx, ansy;

	// if (bad1 && bad2)
	// 	return 1;

	if ((x1 + y1 <= x2 + y2) && !bad1){
		ansx = x1;
		ansy = y1;
	} else {
		ansx = x2;
		ansy = y2;
	}
	
	cout << ansx << " " << ansy << "\n";

	return 0;
}