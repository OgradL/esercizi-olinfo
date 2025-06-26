#include <iostream>
#include <assert.h>
using namespace std;

bool examine(int X, int Y);
void solution(int Xc, int Yc);

int n;
int queries = 0;
bool ask(int X, int Y){
	if (X < 1 || X > n) return false;
	if (Y < 1 || Y > n) return false;
	queries++;
	if (queries > 300)
		exit(1);
	return examine(X, Y);
}

void find_centre(int N, int Xi, int Yi){
	n = N;
	int lo = 0, hi = 1, mid;
	int dx1, dx2, dy1, dy2, M;

	// y up
	lo = 0, hi = 1;
	while (true){
		if (ask(Xi, Yi + hi)){
			lo = hi;
			hi *= 2;
		} else {
			break;
		}
	}

	while (lo + 1 < hi){
		mid = (lo+hi) / 2;
		if (ask(Xi, Yi + mid))
			lo = mid;
		else
			hi = mid;
	}
	dy1 = lo;

	// y down
	lo = 0, hi = 1;
	while (true){
		if (ask(Xi, Yi - hi)){
			lo = hi;
			hi *= 2;
		} else {
			break;
		}
	}

	while (lo + 1 < hi){
		mid = (lo+hi) / 2;
		if (ask(Xi, Yi - mid))
			lo = mid;
		else
			hi = mid;
	}
	dy2 = lo;

	M = dy1 + dy2 + 1;


	// x right
	lo = 0, hi = 1;
	while (true){
		if (ask(Xi + hi, Yi)){
			lo = hi;
			hi *= 2;
		} else {
			break;
		}
	}

	while (lo + 1 < hi){
		mid = (lo+hi) / 2;
		if (ask(Xi + mid, Yi))
			lo = mid;
		else
			hi = mid;
	}
	dx1 = lo;

	// x left
	lo = 0, hi = 1;
	while (true){
		if (ask(Xi - hi, Yi)){
			lo = hi;
			hi *= 2;
		} else {
			break;
		}
	}

	while (lo + 1 < hi){
		mid = (lo+hi) / 2;
		if (ask(Xi - mid, Yi))
			lo = mid;
		else
			hi = mid;
	}
	dx2 = lo;

	int u1, u2, r1, r2;
	u1 = ask(Xi, Yi + 2 * M);
	u2 = ask(Xi, Yi + 4 * M);
	r1 = ask(Xi + 2 * M, Yi);
	r2 = ask(Xi + 4 * M, Yi);

	Yi += M * (u1 + u2 - 1) * 2;

	Xi += M * (r1 + r2 - 1) * 2;


	Xi -= dx2;
	Yi -= dy2;

	Xi += M/2;
	Yi += M/2;

	solution(Xi, Yi);
}
