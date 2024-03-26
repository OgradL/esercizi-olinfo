#include <stdio.h>


int A[4], B[4];

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    scanf("%d.%d.%d.%d", &A[0], &A[1], &A[2], &A[3]);
    scanf("%d.%d.%d.%d", &B[0], &B[1], &B[2], &B[3]);
    
    long long C[4];
    
    for (int i = 0; i < 4; i++){
    	C[i] = B[i] - A[i];
	}
	
    long long result = 0;
    
    result = 1 + C[0] * 256 * 256 * 256 + C[1] * 256 * 256 + C[2] * 256 + C[3];
    
    
    printf("%lld\n", result);
    return 0;
}
