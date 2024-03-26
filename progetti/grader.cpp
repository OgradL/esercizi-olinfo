#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int K;
static int risultato;

// Declaring functions
int progetti(int N, int K);

int main() {
	fr = stdin;
	fw = stdout;

	// Reading input
    fscanf(fr, "%d %d", &N, &K);

	// Calling functions
	risultato = progetti(N, K);

	// Writing output
    fprintf(fw, "%d\n", risultato);
	
	fclose(fr);
	fclose(fw);
	return 0;
}
