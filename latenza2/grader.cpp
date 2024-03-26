#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int M;
static int* A;
static int* B;
static int* L;
static int res;

// Declaring functions
int latenza(int N, int M, int* A, int* B, int* L);

int main() {
	fr = stdin;
	fw = stdout;

	// Iterators used in for loops
	int i0;

	// Reading input
	fscanf(fr, "%d %d", &N, &M);
	A = (int*)malloc(M * sizeof(int));
	B = (int*)malloc(M * sizeof(int));
		L = (int*)malloc(M * sizeof(int));
	for (i0 = 0; i0 < M; i0++) {
		fscanf(fr, "%d %d %d", &A[i0], &B[i0], &L[i0]);
	}

	// Calling functions
	res = latenza(N, M, A, B, L);

	// Writing output
	fprintf(fw, "%d\n", res);
	
	fclose(fr);
	fclose(fw);
	return 0;
}
