#include <iostream>
using namespace std;

using int128 = __int128_t;

int128 extended_euclidean_algorithm(int128 a, int128 b, int128& x, int128& y){
	if (b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int128 x1 = 0, y1 = 0;
	int128 d = extended_euclidean_algorithm(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

long long solve(int128 x0, int128 y0, int128 x1, int128 y1, int128 Vx, int128 Vy, int128 H2, int128 W2, int128 T){

	// { x0 + Vx*t == x1 (mod 2W)
	// { y0 + Vy*t == y1 (mod 2H)
	// <=>
	// { t == (x1 - x0)*Vx^-1 (mod 2W)
	// { t == (y1 - y0)*Vy^-1 (mod 2H)

	int128 inv1, inv2;

	int128 gx = extended_euclidean_algorithm(Vx, W2, inv1, inv2);
	int128 Ax = (((x1 - x0) * inv1 % W2) + W2) % W2;

	int128 gy = extended_euclidean_algorithm(Vy, H2, inv1, inv2);
	int128 Ay = (((y1 - y0) * inv1 % H2) + H2) % H2;

	// check if possible
	if ((x1 - x0) % gx){
		return 0;
	}
	if ((y1 - y0) % gy){
		return 0;
	}

	Ax /= gx;
	W2 /= gx;

	Ay /= gy;
	H2 /= gy;

	// { t == Ax (mod 2W)
	// { t == Ay (mod 2H)

	int128 g = extended_euclidean_algorithm(W2, H2, inv1, inv2);
	int128 L = H2 / g * W2;

	if ((Ay - Ax) % g){
		return 0;
	}

	// t == Ax + inv1*(Ay - Ax)/g*W2   (mod L)
	// t = c + kL

	int128 c = Ax + ((inv1 * ((Ay - Ax) / g)) % (H2 / g)) * W2;
	c = c % L;
	c = c + L;
	c = c % L;

	// count possible t <= T

	if (c > T)
		return 0;

	long long ans = (T - c) / L + 1;

	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long W, H, T;
	cin >> W >> H >> T;

	long long x1, y1, Vx, Vy;
	cin >> x1 >> y1 >> Vx >> Vy;

	long long x2, y2;
	int128 a, b;
	int128 g = extended_euclidean_algorithm(abs(Vx), abs(Vy), a, b);

	Vx /= g;
	Vy /= g;
	T *= g;

	cin >> x2 >> y2;

	if (Vx < 0){
		Vx = -Vx;
		x1 = 2*W - x1;
		x2 = 2*W - x2;
	}
	if (Vy < 0){
		Vy = -Vy;
		y1 = 2*H - y1;
		y2 = 2*H - y2;
	}

	long long ans = 0;

	ans += solve(x1, y1, x2, y2, Vx, Vy, 2*H, 2*W, T);
	ans += solve(x1, y1, 2*W-x2, y2, Vx, Vy, 2*H, 2*W, T);
	ans += solve(x1, y1, x2, 2*H-y2, Vx, Vy, 2*H, 2*W, T);
	ans += solve(x1, y1, 2*W-x2, 2*H-y2, Vx, Vy, 2*H, 2*W, T);

	cout << ans << "\n";

	return 0;
}
