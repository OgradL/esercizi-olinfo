#include <stdio.h>
#define MAXN 100000
#define MAXM 100000

static int A[MAXM];
static int B[MAXM];
static int H[MAXM];
static long long risposta[MAXN+1];
static FILE *fr;
static FILE *fw;

void risolvi(int N, int M, int A[], int B[], int H[], long long risposta[]);

int main() {
	fr = stdin;
	fw = stdout;

	int N, M;
	fscanf(fr, "%d", &N);
	fscanf(fr, "%d", &M);
	int i;
	for (i = 0; i < M; i++) {
		fscanf(fr, "%d", &A[i]);
		fscanf(fr, "%d", &B[i]);
		fscanf(fr, "%d", &H[i]);
	}

	risolvi(N, M, A, B, H, risposta);

	for(i = 1; i <= N; i++) {
		fprintf(fw, "%lld\n", risposta[i]);
	}
	return 0;
}
