#include <stdio.h>
using namespace std;
#define MAXN 1000000

// input data
int N;
long long int P[MAXN];

int main() {
    
    freopen("input output/input1.txt", "r", stdin);
    //freopen("input output/output0.txt", "w", stdout);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    
    for (int i = 0; i < N; i++)
        scanf("%lld", &P[i]);
    
    long long int currentPrice = 0;
    long long int somma = 0;
    
    for (int u = 0; u < N; u++){
        
        if (P[u] > currentPrice){
            somma = somma + P[u];
            currentPrice = P[u];
        }
        
        
    }
    
    
    long long res = 42LL;

    printf("%lld\n", somma);
    return 0;
}
