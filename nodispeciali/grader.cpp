#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int trova_sede(int, int, int[], int[], int[], int[]);

int main()
{
    int n, k;
    FILE *in = stdin, *out = stdout;
    assert(fscanf(in, "%d%d", &n, &k) == 2);

    int *u = (int*)calloc(n-1, sizeof(int));
    int *v = (int*)calloc(n-1, sizeof(int));
    int *w = (int*)calloc(n-1, sizeof(int));
    int *s = (int*)calloc(k, sizeof(int));

    for(int i=0; i<k; i++)
      assert(fscanf(in, "%d", s + i) == 1);

    for(int i=0; i<n-1; i++)
      assert(fscanf(in, "%d%d%d", u + i, v + i, w + i) == 3);

    int answ = trova_sede(n, k, u, v, w, s);
    fprintf(out, "%d\n", answ);

    free(u);
    free(v);
    free(w);
    free(s);

    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;
}
