#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int M;
static int result;
static int* T;

// Declaring functions
int gpu(int N, int M, int T[]);

int main() {
    fr = stdin;
    fw = stdout;

    // Iterators used in for loops
    int i0;

    // Reading input
    fscanf(fr, "%d %d", &N, &M);
    T = (int*)malloc(N * sizeof(int));
    for (i0 = 0; i0 < N; i0++) {
        fscanf(fr, "%d", &T[i0]);
    }

    // Calling functions
    result = gpu(N, M, T);

    // Writing output
    fprintf(fw, "%d\n", result);

    fclose(fr);
    fclose(fw);
    return 0;
}
