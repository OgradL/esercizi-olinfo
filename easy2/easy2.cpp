#include <assert.h>
#include <stdio.h>

#include<iostream>  
using namespace std;

int N;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    scanf("%d", &N);

    int valueA[N]{};
    int valueB[N]{};
    int result[N]{};
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &valueA[i]);
        scanf("%d", &valueB[i]);
        result[i] = valueA[i] + valueB[i];
    }

    int max = -1000;
    
    for (int y = 0; y < N; y++) {
        //printf("%d\n", result[y]);
        
        if (result[y] % 2 == 0){
            if (result[y] > max){
                max = result[y];
            }
        }
        if (max == -1000){
            max = -1;
        }
        
    }
    
    printf("%d", max);
    
    return 0;
}
