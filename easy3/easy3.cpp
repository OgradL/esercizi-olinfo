#include<assert.h>
#include<iostream>
#include<stdio.h>
#include<time.h>
//#include<chrono>
using namespace std;
//using namespace std::chrono;

int N;
//milliseconds startTime, endTime, elapsed;

int main()
{
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    //startTime = duration_cast< milliseconds >(
    //system_clock::now().time_since_epoch()
    //);
    //printf("%f\n", startTime);
    
    scanf("%d", &N);
    
    
    
    
    int numGrandi;
    if (N < 3){
        numGrandi = N;
    } else{
        numGrandi = 3;
    }
    
    int grandi[numGrandi]{};
    int maxx = -1000;
    //bool stop = false;
    int current = 0;
    int index = 0;
    int min = 10000000;
    
        for (int e = 0; e < N; e++){
            
            scanf("%d", &current);
            
            min = 10000000;
            for (int y = 0; y < numGrandi; y++){
                if (grandi[y] < min){
                    min = grandi[y];
                    index = y;
                }
            }
            
            if (current > grandi[index]){
                grandi[index] = current;
            }
            
        }
    
    int somma;
    int max = -1;
    
    for (int r = 0; r < numGrandi; r++){
        for (int t = 0; t < numGrandi; t++){
            if (t == r){
                continue;
            }
            //printf("%d", r);
            //printf("%d", t);
            somma = grandi[r] + grandi[t];
            
            if (somma % 2 == 0){
                if (somma > max){
                    max = somma;
                }
            }
            if (max == -1000){
                max = -1;
            }
            
            
        }
        
    }
    
    printf("%d\n", max);
    //endTime = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
    //printf("%f\n", endTime);
    //elapsed = endTime - startTime;
    //printf("%f", elapsed);
    
    return 0;
}