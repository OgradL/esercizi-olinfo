#include <bits/stdc++.h>

using namespace std;

int trova_massimo(int N, vector<int> V){
    int a = -10348;
    for (int i = 0; i < N; i++){
        a = max(a, V[i]);
    }
    return a;
}
