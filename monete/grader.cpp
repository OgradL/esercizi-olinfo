#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define MAXN 100000

static int N;
static int v[MAXN];

int monete(int N, int v[]);

int main() {
	FILE* in = stdin;
	FILE* out = stdout;

	assert( 1 == fscanf(in, "%d", &N) );
	
	int i;
	for (i = 0; i < N; i++)
		assert( 1 == fscanf(in, "%d", &v[i]) );
	
	fprintf(out, "%d\n", monete(N, v));
	
	fclose(in);
	fclose(out);
	
	return EXIT_SUCCESS;
}
