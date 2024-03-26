#include <bits/stdc++.h>

using namespace std;

#define MAX_GRADE 10


int* countingSort(int N, int* array) {
    int tmp[MAX_GRADE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < N; i++) {
        tmp[array[i] - 1]++;
    }
    int index = 0;
    for (int i = 0; i < MAX_GRADE; i++) {
        for (int j = 0; j < tmp[i]; j++) {
            // We modify the array in place
            // to use less memory.
            array[index] = i + 1;
            index++;
        }
    }
    return array;
}

bool associabili(int N, int* v1, int* v2){
    v1 = countingSort(N, v1);
    v2 = countingSort(N, v2);
    
    for (int i = 0; i < N; i++){
        if (v1[i] >= v2[i]){
            return false;
        }
    }
    return true;
    
    
}