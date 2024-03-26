#include <stdio.h>
#include <assert.h>

#define MAXN 1000010

int update_copyright(int N, char S[]) {
    
    for (int i = 0; i < N; i++){
    	
    	if (S[i] == 'C'){
    		if (S[i + 1] = 'o')
		}
    	
    	
    	
	}
    
    
    return N;
}


char S[MAXN];

int main() {
    //FILE *fr, *fw;
    int N, i;

#ifdef EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //fr = fopen("input.txt", "r");
    //fw = fopen("output.txt", "w");
#else
    //fr = stdin;
    //fw = stdout;
#endif
    assert(1 == scanf("%d\n", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%c", &S[i]));

    N = update_copyright(N, S);

    printf("%d\n", N);
    for(i=0; i<N; i++)
        printf("%c", S[i]);
    //fclose(fr);
    //fclose(fw);
    return 0;
}

