#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static FILE *in, *out;
static int N;
static int prev_query = 0;
static int query_cnt = 0;

int indovina();

bool chiedi(int X) {
	query_cnt++;
	bool ans = (X ^ N) < (prev_query ^ N);
	prev_query = X;
	return ans;
}

int main() {
	in = stdin;
	out = stdout;

	fscanf(in, "%d", &N);

	int res = indovina();
	if (res == N) {
		fprintf(out, "Risposta corretta: %d chiamate eseguite", query_cnt);
	} else {
		fprintf(out, "Risposta sbagliata");
	}

	return 0;
}
