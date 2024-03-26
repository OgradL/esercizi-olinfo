#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static int nextInt(){
	int n=0 , ch=getchar();
	while( ch < '0' ) ch=getchar();
	while( ch >= '0' ) n = (n<<3)+(n<<1) + ch-'0', ch=getchar();
	return n;
}


static int h[100005];

long long stima(int N, int*);

int main(){
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
	
	int N = nextInt();
	int i;
	
	for(i = 0; i < N; ++i)
		h[i] = nextInt();
	
	printf("%lld\n", stima(N,h));
	
	return 0;
}
