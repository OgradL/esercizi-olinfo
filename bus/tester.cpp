#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    srand(time(nullptr));
    
    freopen("input.txt", "w", stdout);

    int N = 100000, L = 100000, K = 3;
    
    cout << N << " " << L << "\n";

    for (int i = 0; i < N; i++){
        cout << K << " ";
        for (int j = 0; j < K; j++){
            cout << rand()%N << " ";
        }
        cout << "\n";
    }



    return 0;
}