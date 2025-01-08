#include <stdio.h>
#include <assert.h>
#define MAXN 10005

static int freccia[MAXN];
static int N,i;

int Gira(int N, int* freccia);

int main(){
	FILE *in, *out;
	assert(in = fopen("input.txt", "r"));
	assert(out = fopen("output.txt", "w"));

	assert(1==fscanf(in, "%d", &N));
	for( i = 0; i < N; ++i)
		assert(1==fscanf(in, "%d", freccia + i));
	fprintf(out, "%d\n", Gira(N,freccia));
	return 0;
}
