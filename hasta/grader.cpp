#include <cstdio>
#include <cassert>
#include <cstdlib>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int K;
static int i;
static int j;
static int Q;
static int* V;
static int* R;

// Declaring functions
void inizia(int N,int K, int V[], int R[]);
int istiga(int i,int j);

int main() {
	fr = stdin;
	fw = stdout;

	// Reading input
	fscanf(fr,"%d %d",&N,&K);
	V = (int*)malloc((N) * sizeof(int));
	for (int i0 = 0; i0 < N; i0++) {
		fscanf(fr, " %d", &V[i0]);
	}
	R = (int*)malloc((K) * sizeof(int));
	for (int i0 = 0; i0 < K; i0++) {
		fscanf(fr, " %d", &R[i0]);
	}

	// Calling functions
	inizia(N,K,V,R);
	fscanf(fr,"%d",&Q);
	// Writing output
	while (Q--) {
		fscanf(fr,"%d %d",&i,&j);
		fprintf(fw,"%d ",istiga(i,j));
	}
	fprintf(fw,"\n");

	fclose(fr);
	fclose(fw);
	return 0;
}
