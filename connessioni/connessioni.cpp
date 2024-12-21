#include <iostream>

int count;
int parent[200001], sz[200001];

int get(int x){
	if (parent[x] == x) return x;
	return parent[x] = get(parent[x]);
}

void inizia(int N) {
	count = N;
	for (int i = 0; i < N; ++i)
		parent[i] = i, sz[i] = 1;
}

int collega(int X, int Y) {
	X = get(X);
	Y = get(Y);
	if (X != Y){
		if (sz[X] < sz[Y])
			std::swap(X, Y);
		sz[X] += sz[Y];
		parent[Y] = X;
		--count;
	}
	return count;
}
