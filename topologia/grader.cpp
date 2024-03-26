#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define MAXM 100000

static FILE *fr, *fw;

static int n, m, i;
static int a[MAXM+1], b[MAXM+1], t[3];

void Analizza(int n, int m, int a[], int b[], int t[]);

int main(){
	fr = stdin;
	fw = stdout;

	assert(2 == fscanf(fr, "%d%d", &n, &m));
	for(i=0; i<m; i++)
		assert(2 == fscanf(fr, "%d%d", a+i, b+i));

	Analizza(n, m, a, b, t);
	fprintf(fw, "%d %d %d\n", t[0], t[1], t[2]);

	fclose(fr);
	fclose(fw);
	return 0;
}
