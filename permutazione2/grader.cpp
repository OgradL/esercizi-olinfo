#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define maxn 1010

static FILE *in, *out;
static int N, A, B, C;
static int pos = 0;
static int status = 1;
static int query_cnt_a = 0;
static int query_cnt_b = 0;
static int query_cnt_c = 0;
static int F[maxn], P[maxn], H[maxn], i;

void indovina(int N, int A, int B, int C, int H[]);

bool chiedi(int K) {
    query_cnt_a++;
    if (K < 0 || K > N - 1) {
        fprintf(out, "Domanda non valida"); exit(0);
    }
    return (F[K] <= pos);
}

void stato() {
    query_cnt_b++;
    status *= -1;
}

void sposta() {
    query_cnt_c++;
    pos += status;
    if (pos < 0 || pos > N - 1) {
        fprintf(out, "Posizione non valida"); exit(0);
    }
}

int main() {
    in = stdin;
    out = stdout;

    assert(fscanf(in, "%d", &N) == 1);
    assert(fscanf(in, "%d", &A) == 1);
    assert(fscanf(in, "%d", &B) == 1);
    assert(fscanf(in, "%d", &C) == 1);

    for (i = 0; i < N; i++) {
        assert(fscanf(in, "%d", &P[i]) == 1);
    }

    for (i = 0; i < N; i++) H[i] = 0;

    for (i = 0; i < N; i++) F[P[i]] = i;

    indovina(N, A, B, C, H);

    int flag = 1;
    for (i = 0; i < N; i++) {
        if (P[i] != H[i]) flag = 0;
    }

    for (i = 0; i < N; i++) {
        fprintf(out, "%d ", H[i]);
    }
    fprintf(out, "\n");

    if (flag == 1) {
        fprintf(out, "Risposta corretta: (%d, %d, %d) chiamate eseguite", query_cnt_a, query_cnt_b, query_cnt_c);
    } else {
        fprintf(out, "Risposta errata: (%d, %d, %d) chiamate eseguite", query_cnt_a, query_cnt_b, query_cnt_c);
    }

    return 0;
}
