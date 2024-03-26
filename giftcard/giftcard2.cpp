#include <iostream>
#include <array>
using namespace std;

using ull = long long;
using u128 = ull;


ull POW(ull b, ull e, ull m){
	if (e == 0) return 1;
	ull v = POW(b, e/2, m);
	return (v * v % m) * ((e%2) ? b : 1) % m;
}

ull totient(ull m){
	return 0;
}

u128 inv(u128 i, u128 m){
	return POW(i, totient(m), m);
	return i <= 1 ? i : m - (u128)(m / i) * inv(m % i, m) % m;
}

u128 gcd(u128 a, u128 b){
	return b == 0 ? a : gcd(b, a % b);
}

array<ull, 2> solve(u128 N, u128 c1, u128 c2){
	N -= c1;
	N -= c2;

	u128 x1 = 1, x2 = 1, xm1;

	cout << N << " " << c1 << " " << c2 << " " << N%c2 << " " << inv(c1, c2) << "\n";
	xm1 = (N % c2) * inv(c1, c2) % c2;

	x1 += xm1;
	N -= c1 * xm1;

	x2 += N / c2;

	return {x1, x2};
}

int main(int argc, char** argv){

	ull N, c1, c2;
	if (argc < 4)
		cin >> N >> c1 >> c2;
	else {
		N = stoull(argv[1]);
		c1 = stoull(argv[2]);
		c2 = stoull(argv[3]);
	}

	ull g = gcd(c1, c2);
	c1 /= g;
	c2 /= g;
	N /= g;

	auto a1 = solve(N, c1, c2);
	auto a2 = solve(N, c2, c1);

	int good1 = a1[0] * c1 + a1[1] * c2 == N;
	int good2 = a2[1] * c1 + a2[0] * c2 == N;

	// if (!good1 && !good2)
	// 	return 1;

	if (a1[0] + a1[1] < a2[0] + a2[1] && good1){
		cout << a1[0] << " " << a1[1] << "\n";
		// cout << a2[1] << " " << a2[0] << "\n";
	} else {
		// cout << a1[0] << " " << a1[1] << "\n";
		cout << a2[1] << " " << a2[0] << "\n";
	}

	return 0;
}