#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 100000

// input data
int N, i;
int P[MAXN];

int min = MAXN;
int max = 0;

int abs(int A){
    if (A < 0){
        A = A * -1;
    }
    return A;
}



int main() {
	
	freopen("input output/input1.txt", "r", stdin);
	//freopen("input output/output0.txt", "w", stdout);
	
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    for(i = 0; i < N; i++)
        scanf("%d", &P[i]);
    
    
    
    // per ogni posizione dell'allenatore
    for (i = 0; i < N; i++){
        max = 0;

        
        max = abs(P[i] - P[0]);
        
        if (abs(P[i] - P[N - 1]) > max){
        	max = abs(P[i] - P[N - 1]);
		}
        
        if (max < min){
            min = max;
        }
        
    }
    
    
    printf("%d\n", min);
    return 0;
}
