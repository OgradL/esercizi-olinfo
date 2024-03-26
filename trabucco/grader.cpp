#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 2000

static int N, M, K;
static int X[MAXN * MAXN], Y[MAXN * MAXN];

int ContaPercorsi(int, int, int, int*, int*);

int main() {
	FILE * fin, * fout;
	fin = stdin;
	fout = stdout;
	assert(fscanf(fin, "%d%d%d", &N, &M, &K) == 3);
	int k;
	for(k = 0; k < K; ++k) {
		assert(fscanf(fin, "%d%d", X + k, Y + k) == 2);
	}
	fprintf(fout, "%d\n", ContaPercorsi(N, M, K, X, Y));
	
	return EXIT_SUCCESS;
}
