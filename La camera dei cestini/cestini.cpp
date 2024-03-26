#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > cestini;


void inizia(int N, int M) {
    
    cestini.resize(M);
    
    cestini[0].resize(N);
    
    for (int i = 0; i < N; i++){
        cestini[0][i] = i;
    }
    
    
}

void sposta(int a, int b) {
    int ogg = cestini[a].back();
    cestini[a].pop_back();
    
    cestini[b].push_back(ogg);
}

int controlla(int a, int i) {
    if (i < cestini[a].size())
    	return cestini[a][i];
    return -1;
}