#include <stdio.h>
#include <stdlib.h>

static FILE *in, *out;
static int N, Q, *T, i;
static long long *risp;

void inizia(int N, int T[]);
long long passaggio(int L, int R);

int main() {
	// in = fopen("input.txt", "r");
	// out = fopen("output.txt", "w");
	in = stdin;
	out = stdout;

	fscanf(in, "%d%d", &N, &Q);

	T = (int *)malloc(N * sizeof(int));

	for (i = 0; i < N; i++) {
		fscanf(in, "%d", T + i);
	}

	inizia(N, T);
	for (i = 0; i < Q; i++) {
		int L, R;
		fscanf(in, "%d%d", &L, &R);
		long long risp = passaggio(L, R);
		fprintf(out, "%lld\n", risp);
	}

	free(T);

	fclose(in);
	fclose(out);

	return 0;
}
