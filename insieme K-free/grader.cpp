#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define MAXN 100000

static FILE *fr, *fw;

static int n, k, i;
static int insieme[MAXN+1];

int Trova(int n, int k, int* insieme);

int main(){
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(2 == fscanf(fr, "%d %d", &n, &k));
    for(i=0; i<n; i++)
        assert(1 == fscanf(fr, "%d", insieme+i));

    fprintf(fw, "%d\n", Trova(n, k, insieme));

    fclose(fr);
    fclose(fw);
    return 0;
}
