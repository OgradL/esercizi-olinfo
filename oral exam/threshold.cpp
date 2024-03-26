//Scrivi qui il tuo codice
#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

/**
WARNING!
Please check carefully this template!
To achieve full score in this problem, this template ***needs to be adjusted***. 
**/

#define MAXN 10000

int res[100];

int main() {
    FILE *fr, *fw;
    int N;
    int current = 0;
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
//    cin >> N;
    for(int i = 0; i < N; i++){
        assert(1 == fscanf(fr, "%d", &current));
//        cin >> current;
        
        //for (int j = 0; j <= current; j++){
        res[current]++;
        //}
        
        
    }
    
    int sum = 0;
    for (int i = 100; i >= 0; i--){
        sum += res[i];
        fprintf(fw, "%d ", sum);
//        cout << sum << " ";
    }
        //sum += res[i];

    fclose(fr);
    fclose(fw);
    return 0;
}
