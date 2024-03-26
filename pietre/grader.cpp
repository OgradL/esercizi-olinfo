#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXN 1000000
int Trova(int N, int G);

static FILE *fin, *fout;
static int N, G;
static int maxd;
static int peso[2*MAXN+1];
static int domande;

static void termina(int x){
	fclose(fin);
	fclose(fout);
	exit(x);
}

int Confronta(int a, int b){
	if(a < 1 || a > 2*N || b < 1 || b > 2*N || a == b){
		fprintf(fout, "Hai chiamato la funzione Confronta con parametri errati.\n");
		termina(0);
	}
	domande++;
	if(domande > maxd){
		fprintf(fout, "Hai chiamato troppe volte la funzione Confronta.\n");
		termina(0);
	}
	if(peso[a] < peso[b]) return 0;
	return 1;
}

int main(){	
	// fin = fopen("input.txt", "r");
	// fout = fopen("output.txt", "w");
	fin = stdin;
	fout = stdout;
	assert(2 == fscanf(fin, "%d%d", &N, &G));
	assert(1 == fscanf(fin, "%d", &maxd));
	int i;
	for(i=1; i<=2*N; i++){
		// assert(1 == fscanf(fin, " %d ", peso+i));
		fscanf(stdin, "%d", &peso[i]);
		// fprintf(stdout, "%d\n", *(peso+i));
		// fflush(stdout);
	}
	domande = 0;
	int ans = Trova(N, G);
	fprintf(fout, "Domande effettuate = %d\n", domande);
	fprintf(fout, "Risposta = %d\n", ans);
	termina(0);
	return 0;
}
