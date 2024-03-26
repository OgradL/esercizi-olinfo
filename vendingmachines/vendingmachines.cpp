//Scrivi qui il tuo codice
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define MOD 666013

int main(){
    
    int T;
    cin >> T;
    
    while (T--){
        
        int N, Q;
        cin >> N >> Q;
        
        vector<int> P(N);
        for (int &i: P) cin >> i;
        
        int idx, sum = 0, hacked = 0;
        while (Q--){
            cin >> idx;
            
            if (idx > 0){
                sum += idx;
            } else {
                sum -= P[-idx-1];
            }
            if (sum < 0){
                hacked = true;
            }
            
        }
        
        if (hacked){
            cout << "HACKER\n";
        } else {
            cout << "OK\n";
        }
        
    }

    return 0;
}