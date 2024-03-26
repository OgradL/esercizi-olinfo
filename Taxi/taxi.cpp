//Scrivi qui il tuo codice
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N;
    
    cin >> N;
    
    vector<int> C(N);
    
    for (int i = 0; i < N; i++){
        cin >> C[i];
    }
    
    int currentPrice = C[0];
    int tot = C[0];
    
    for (int i = 1; i < N; i++){
        currentPrice++;
        
        if (currentPrice > C[i])
            currentPrice = C[i];
        
        tot += currentPrice;
    }
    
    cout << tot;
    
    
}