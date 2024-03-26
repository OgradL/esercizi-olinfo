//Scrivi qui il tuo codice
#include <bits/stdc++.h>
#include <stdio.h>
#include <assert.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
    
    FILE *fr, *fw;
    
    
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    ull N, K;
    
    assert(2 == fscanf(fr, "%lld %lld", &N, &K));
    //cin >> N >> K;
    
    unordered_map<ull, int> m;
    unordered_map<ull, ll> cont;
    
    //vector<ull> numbers(N);
    
    /*
    for (int i = 0; i < N; i++){
        cin >> numbers[i];
        cont[numbers[i]]++;
    }
    */
    
    ull curr;
    
    ull ans = 0;
    
    for (int i = 0; i < N; i++){
        assert(1 == fscanf(fr, "%lld", &curr));
        //cout << curr << "\n";
        //cin >> curr;
        cont[curr]++;
        
        if (m[curr] == 2) continue;
        
        //cont[curr]--;
        
        if (m[curr] == 0) m[curr] = 1;
        
        ull idx = K / curr;
        
        //cout << curr << " " << idx << " - \n";// << m[idx] << "\n";
        
        if (idx * curr == K && m[idx] == 1){
            
            if (curr == idx){
                ll d = cont[idx];
                ans += (1 * (d - 1));// / 2;
                ans = ans % 1000000007;
                //m[idx] = 2;
                //cont[idx] = 0;
                //cout << "sus\n";
            } else {
                
                //cont[idx]--;
                //cont[curr]--;
                
                ull add = cont[idx];
                
                //m[curr] = 2;
                
                //m[idx] = 2;
                
                //cout << curr << " " << idx << "\n";
                
                ans += add;
                ans = ans % 1000000007;
            }
        }
        
        
    }
    
    fprintf(fw, "%lld\n", ans);
    
}

/*

6 9
1 6 3 2 3 3
-> 3


4 12
2 4 3 6
-> 2


8 1000000000000
40000000000 125000000000 1600000000 10000000000 100 25 625 8
-> 4


*/
