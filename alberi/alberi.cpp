#include <stdio.h>
#include <assert.h>
#define MAXN 1000010

static int N,i ;
static int preordine [MAXN] ;
static int postordine[MAXN] ;
static int simmetrica[MAXN] ;

struct node{
	node *dx, *sx;
	int label;
	node(int v){
		label = v;
		dx = NULL;
		sx = NULL;
	}
	node(){
		label = -1;
		dx = NULL;
		sx = NULL;
	};
};

#include <unordered_map>
#include <iostream>
#include <stdlib.h>

node *newnode1, *newnode2;
int rec(node* nodo, int& r, int l1, int r1, int *pre, int *post, std::unordered_map<int, int>& m){
	// std::cerr << r << " (" << post[r] << ") " << l1 << " " << r1;
	if (r1-l1 < 0){
		nodo->label = -1;
		r++;
		return l1;
	}
	
	int v = post[r];
	int sep = m[v];
	if (sep < l1){
		nodo->label = -1;
		r++;
		return l1;
	}
	// std::cerr << " - " << v << " " << sep << "\n";
	// std::cerr << "1\n";
	//newnode1 = node(-1);
	//newnode2 = node(-1);
	//nodo->dx = &newnode1;
	//nodo->sx = &newnode2;
	nodo->dx = (node*)malloc(sizeof(node));
	nodo->sx = (node*)malloc(sizeof(node));
	nodo->label = v;
	// nodo destra
	// std::cerr << "2\n";
	int sep2 = rec(nodo->dx, --r, sep+1, r1, pre, post, m);
	
	// nodo sinistra
	// std::cerr << "3\n";
	rec(nodo->sx, --r, l1+1, sep2-1, pre, post, m);
	
	// fprintf(stderr, "nodo %d -> sx: %d | dx: %d\n", nodo->label, nodo->sx->label, nodo->dx->label);
	
	return sep;
}

void print_tree(node* nodo, int& i, int *simm){
	if (nodo == NULL || nodo->label == -1) return;
	//std::cerr << nodo->label << " - " << nodo->sx << " " << nodo->dx << "\n";
	// fprintf(stderr, "%d - %p %p\n", nodo->label, nodo->sx, nodo->dx);
	// fprintf(stderr, "sx:\n");
	print_tree(nodo->sx, i, simm);
	simm[i++] = nodo->label;
	// fprintf(stderr, "dx:\n");
	print_tree(nodo->dx, i, simm);
}

void visita(int N, int *PRE, int *POST, int *SIMM){
	std::unordered_map<int, int> pre;
	for (int i = 0; i < N; i++)
		pre[PRE[i]] = i;
	
	node tree = node(POST[N-1]);
	
	int i2 = N-1;
	rec(&tree, i2, 0, N-1, PRE, POST, pre);
	// std::cerr << "finito\n";
	int i = 0;
	print_tree(&tree, i, SIMM);
}

int main(){
	FILE *fin, *fout;
	#ifdef EVAL
		assert(fin = fopen("input.txt", "r"));
		assert(fout = fopen("output.txt", "w"));
	#else
		fin = stdin;
		fout = stdout;
	#endif
	assert(1==fscanf(fin, "%d", &N));

	for( i = 0 ; i < N ; i++ ) assert( 1 == fscanf(fin,"%d",preordine+i) );
	for( i = 0 ; i < N ; i++ ) assert( 1 == fscanf(fin,"%d",postordine+i) );

	visita(N,preordine,postordine,simmetrica);

	for( i = 0 ; i < N ; i++ ) fprintf(fout,"%d ",simmetrica[i]);
	fprintf(fout,"\n");

	return 0;
}

