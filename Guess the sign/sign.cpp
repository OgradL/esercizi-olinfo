#include <stdio.h>
#include <assert.h>

long long abs(long long A){
    if (A < 0){
        A = A * -1;
    }
    
    return A;
    
}

char solve(long long A, long long B) {
	
    long long sommaPositiva = abs(abs(A) - abs(B) + 1);
    
    if (A < 0 && B < 0){
        //printf("%c\n", 's');
        if (sommaPositiva % 2 == 0){
            if (sommaPositiva == 0){
                //printf("%c\n", 't');
                return '-';
            }
            //printf("%c\n", 'p');
            return '+';
        } else{
            return '-';
        }
    } else if (A > 0 && B > 0){
        return '+';
    } else{
        return '0';
    }
    
}

int main() {
	
	freopen("input output/input2.txt", "r", stdin);
	//freopen("input output/output0.txt", "w", stdout);
	
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        long long A, B;
        scanf("%lld%lld", &A, &B);
        printf("%c\n", solve(A, B));
    }

    return 0;
}
