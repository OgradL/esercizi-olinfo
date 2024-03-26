#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int M;
static int* A;
static int* B;
static int res;

// Declaring functions
int paper(int N, int M, int* from, int* to);

int main() {
	fr = stdin;
	fw = stdout;

	// Iterators used in for loops
	int i0;

	// Reading input
        fscanf(fr, "%d %d", &N, &M);
	A = (int*)malloc(M * sizeof(int));
	B = (int*)malloc(M * sizeof(int));
	for (i0 = 0; i0 < M; i0++) {
            fscanf(fr, "%d %d", &A[i0], &B[i0]);
	}

	// Calling functions
	res = paper(N, M, A, B);

	// Writing output
        fprintf(fw, "%d\n", res);
	
	fclose(fr);
	fclose(fw);
	return 0;
}
