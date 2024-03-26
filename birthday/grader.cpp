#include <cstdio>
#include <cassert>
#include <cstdlib>

static FILE *fr, *fw;

static int N;
static bool* V;
static int i;

bool accesa(){return V[i];}
void accendi(){V[i]=true;}
void soffia(){V[i]=false;}
void gira_sinistra(){if(i==0)i=N;--i;}
void gira_destra(){++i;if(i==N)i=0;}


int conta();

int main() {
    // fr = fopen("input.txt", "r");
	fr = stdin;

	// Reading input
	assert(fscanf(fr, "%d", &N)==1);
	V = (bool*)malloc((N) * sizeof(bool));
	for (int i0 = 0; i0 < N; i0++) {
		int x;
		assert(fscanf(fr, "%d", &x)==1);
		V[i0] = x;
	}
    fclose(fr);

	// Calling functions
	i = 0;
	int answer = conta();

	// Writing output
    // fw = fopen("output.txt", "w");
	fw = stdout;
	fprintf(fw, "%d\n",answer);
    fclose(fw);
    return 0;
}
