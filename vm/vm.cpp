//Scrivi qui il tuo codice
#include <iostream>
#include <vector>
using namespace std;

long long aggiorna(int N, vector<int> A, vector<int> B){
    
    long long sum = 0;
    
    for (int i = N - 2; i >= 0; i--){
        int curr = A[i];
        int m = A[i+1];
        
        int diff = m - curr;
        if (diff >= B[i]){
            
            int times = diff / B[i];
            
            sum += times;
            A[i] += B[i] * times;
        }
    }
    
    return sum;
}