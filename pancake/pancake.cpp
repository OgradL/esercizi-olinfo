#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int pre[362881];
int gi = 0;

void f(int n, int& i){
	if (n == 1) return;
	f(n - 1, i);
	
	for (int j = 1; j < n; j++){
		pre[i++] = n;
		f(n - 1, i);
	}
}

void prepara(int N){
	int i = 0;
	f(N, i);
	pre[i] = 1;
}

int ribalta(){
	gi++;
	return pre[gi - 1];
}