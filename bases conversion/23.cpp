/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

// constraints
#define MAXT 10000

// input data
int T, i;
int N[MAXT];

int toTwo(int n){
    int count = 0;
    while (n != 0){
        count += n % 2;
        n /= 2;
    }
    return count;
}
int toTre(int n){
    int count = 0;
    while (n != 0){
        count += n % 3;
        n /= 3;
    }
    return count;
}


int main() {
//  uncomment the following lines if you want to read/write from files
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &T));
    for(i=0; i<T; i++) {
        assert(1 == scanf("%d", &N[i]));
        int count = 0;
        for (int j = 1; j <= N[i]; j++){
            //cout << "\npop" << count << " " << toTwo(j) << " " << toTre(j) << "\n";
            if (toTwo(j) == toTre(j)){
                count++;
            }
        }
        printf("%d ", count);
    }
    printf("\n");
    return 0;
}