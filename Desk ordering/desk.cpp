#include <stdio.h>
#include <assert.h>

#define MAXN 1000000

int abs(int A){
    if (A < 0){
        A = A * -1;
    }
    return A;
}

int clamp(int A, int min, int max){
	if (A < min){
		A = min;
	}
	if (A > max){
		A = max;
	}
	return A;
}

int posiziona(int N, int L, int H[]) {
    
    int minIndex = 0;
    int min[2];
    int max[3];
    
    for (int j = 0; j < N - L + 1; j++){
        minIndex = 0;
        
        //if ()
        
        
        if (H[j] > min[minIndex]){
            min[minIndex] = H[j];
        }
        
    }
    
    
    
    return (int)(abs(min[0] - min[1]) / 2);
}


int H[MAXN];

int main() {
    FILE *fr, *fw;
    int N, L, i;

#ifdef EVAL
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
#else
    fr = stdin;
    fw = stdout;
#endif
    assert(2 == fscanf(fr, "%d %d", &N, &L));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &H[i]));

    fprintf(fw, "%d\n", posiziona(N, L, H));
    fclose(fr);
    fclose(fw);
    return 0;
}

/*

4 4
9 13 10 15



5 3
5 15 22 10 8


*/
